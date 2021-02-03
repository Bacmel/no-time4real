#include "lidar.hpp"
#include "pantilt.hpp"
#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

#define LIMIT 10

typedef struct
{
	bool allume;
	Donnee d;

	pthread_t thread_switch;
	pthread_t thread_lidar;
	pthread_t thread_pantilt;

	pthread_mutex_t mutex_allume;
	pthread_mutex_t mutex_d;
}Projet;

static Projet projet = 
{
	.allume = true,
	.mutex_allume = PTHREAD_MUTEX_INITIALIZER,
	.mutex_d = PTHREAD_MUTEX_INITIALIZER,
};

static void * fn_switch(void* p_data);
static void * fn_lidar(void* p_data);
static void * fn_pantilt(void* p_data);

int main()
{

	int ret = pthread_create(& projet.thread_switch, NULL, fn_switch, NULL);
	if(ret)
	{
		fprintf(stderr, "%s", strerror(ret));
	}
	ret = pthread_create(& projet.thread_lidar, NULL, fn_lidar, NULL);
	if(ret)
	{
		fprintf(stderr, "%s", strerror(ret));
	}
	ret = pthread_create(& projet.thread_pantilt, NULL, fn_pantilt, NULL);
	if(ret)
	{
		fprintf(stderr, "%s", strerror(ret));
	}

	pthread_join(projet.thread_switch, NULL);
	pthread_join(projet.thread_lidar, NULL);
	pthread_join(projet.thread_pantilt, NULL);

	return 0;
}

static void * fn_switch(void* p_data)
{	
	do
	{			
	}while(getchar() != ' ');
	pthread_mutex_lock(& projet.mutex_allume);
	projet.allume = false;
	pthread_mutex_unlock(& projet.mutex_allume);
}

static void * fn_lidar(void* p_data)
{
	bool start;
	Lidar lidar;
	lidar.start();
	do
	{
		lidar.update();
		pthread_mutex_lock(& projet.mutex_d);
		projet.d = lidar.getDonnee();
		pthread_mutex_unlock(& projet.mutex_d);
		pthread_mutex_lock(& projet.mutex_allume);
		start = projet.allume;
		pthread_mutex_unlock(& projet.mutex_allume);		
	}while(start);
	lidar.stop();
}

static void * fn_pantilt(void* p_data)
{
	bool start;
	PanTilt pantilt;
	Donnee d;
	do
	{
		pthread_mutex_lock(& projet.mutex_d);
		d = projet.d;
		pthread_mutex_unlock(& projet.mutex_d);
		if(d.distance < LIMIT)
		{
			pantilt.orientation(d.step);
			pantilt.parisienne();
			// pantilt.inclinaison(50);
			// pantilt.getImage();
		}
		pthread_mutex_lock(& projet.mutex_allume);
		start = projet.allume;
		pthread_mutex_unlock(& projet.mutex_allume);
	}while(start);
}

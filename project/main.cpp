#include "lidar.hpp"
#include "pantilt.hpp"
#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

#define LIMIT 10.0

typedef struct
{
	Donnee d;
	
	pthread_t thread_lidar;
	pthread_t thread_pantilt;
	
	pthread_mutex_t mutex_d;
}Projet;

static Projet projet = 
{
	.mutex_d = PTHREAD_MUTEX_INITIALIZER,
}

static void * fn_lidar(void* p_data);
static void * fn_pantilt(void* p_data);

static pthread_mutex_t mutex

int main()
{
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

	pthread_join(projet.thread_lidar, NULL);
	pthread_join(projet.thread_pantilt, NULL);

	return 0;
}

static void * fn_lidar(void* p_data)
{
	Lidar lidar;
	lidar.start();
	do
	{
		lidar.update();
		pthread_mutex_lock(& projet.mutex_d);
		projet.d = lidar.getDonnee();
		pthread_mutex_unlock(& projet.mutex_d);
	}while(true);
	lidar.stop();
}

static void * fn_pantilt(void* p_data)
{
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
		}
	}while(true);
}

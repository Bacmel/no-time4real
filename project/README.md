# Projet Temps Réel
Le but de ce projet est de réaliser un lidar et une figure de notre choix avec une caméra pantilt.

## Guide d'utilsation
Il faudra tout d'abord compiler le projet grâce au makefile pour cela taper la commande 
```
sudo make
```
Nous utilisons dans notre projet un driver, qu'il faudra inserer dans le kernel à chaque fois que vous voulez executer le code. Cela ce fait grâce a la commande :
```
sudo insmod driver_interruption.ko
```
Il faudra au préalable le supprimer du kernel avant chaque compilation  avec :
```
sudo rmmod driver_interruption.mod
```
Enfin pour exécuter le code, taper :
```
sudo ./main
```



## Architecture

Le projet se compose de deux dossier : 
* Un dossier **src** contenant les fichiers cpp.
* Un dossier **include** contenant les headers.
* Le Makefile, le main ainsi que le driver_interruption se situe à l'extérieur.

Le dossier **src** possède sept classes : 
* **encoder** : récupère le nombre d'interruptions detecter par le driver, cela correspond aux pas de l'encoder.
* **capteur**: récupère et gère les données du capteur infrarouge.
* **moteur**: gère la connexion et la rotation du moteur cc.
* **servo**: gère la connexion et la rotation des servos moteurs.
* **camera**: gère la connexion de la camera et récupère le flux de données.
* **pantilt**: classe qui combine servo et camera.
* **lidar**: classe qui combine encoder, capteur et moteur.

Pour plus de renseignement vous pouvez également consulter le diagramme UML **UML_TR** présent dans le dossier **projet**.

## Problémes rencontrés

Malheureusement les problèmes rencontrés ont été nombreux. Ils ont plutôt étaient liés au matériel et à conception de la maquette.
* Le capteur délivre une assez mauvaise précision.
* Certains servos moteurs ne fonctionnaient pas.
* Moteur cc pas assez puissant pour supporter le poids du capteur.
* Câbles qui gênent le fonctionnement du matériel (friction, blocage et faux contact)

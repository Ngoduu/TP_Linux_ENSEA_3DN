# TP_Linux_ENSEA_3DN

1.1 Préparation de la carte SD
1.2 Démarrage
1.3 Connexion au système

Loggez-vous à nouveau. L’image copiée précédemment n’occupe pas la tota- lité de la carte SD. Quelle est la taille occupée ? 
La taille est de 3Go

1.3.3 Configuration réseau

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/961203e7-07b3-4882-be1a-7cf638e07b21)
sudo

Éditer le fichier /etc/network/interfaces de la manière suivante : 

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/ad297a15-e884-4b62-ac2f-f2841040a4ba)

ensuite on va rebooter la machine et cette fois @ip risque de changer.

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/07ab528b-18d3-4f6f-a084-f489f83c9c83)

la nouvelle @ip est : 192.168.88.58

Pour verfier le bon focntionnement, on va pinger la carte avec le PC : 

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/ed1be171-9a15-4e37-9382-ca0eb9f7b96e)

On a bien une liaison

1.4 Découverte de la cible
1.4.1 Exploration des dossiers /sys/class et /proc
Explorez un peu votre environnement, par exemple : 
/sys/class/leds/fpga_ledX/

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/389da991-fef8-4da8-afa4-07da23de31dc)

Dans ce ficher on a la possibilité de changer son état et faire un trigger.

le ficher /proc/iomem 

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/757af758-01e8-447a-9f8c-09c1f987b945)

ici on peut trouver des @ des different liaisons et memoires

1.4.2 Compilation croisée

1.4.3 Hello world !

Réalisez un programme "Hello World !", compilez-le et testez-le sur la carte SoC.

on va faire un ficher hello.c avec vscode : 

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/3a69c668-30cd-4e9e-a950-797f834687fe)

ensuite on va le compiler avec VM et executer directement sur la cible : 

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/2f1088b7-6868-4d69-a97e-eaf0ede0c7be)

ensuite on va lancer la commade sur la carte : 

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/889fa171-7ce0-44bf-a6f3-861b2b7a22fd)

1.4.4 Accès au matériel

Un certain nombre de drivers sont fournis. Comme tous les drivers sous Linux, ils sont accessible sous forme de fichiers. Par exemple pour allumer l’une des LED rouge de la carte, il suffit d’écrire un ’1’ dans le bon fichier

on va essayer d'allumer 2 leds : 

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/2da3f0ce-5aa1-45dd-b73d-1ad6e061f707)

1.4.5 Chenillard (Et oui, encore !)

Plutôt que de passer par la commande echo, on peut écrire un programme C qui va ouvrir et écrire dans ces fichiers. Écrire un programme en C qui réalise un chenillard

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/fef84649-3f66-4709-ac06-7840f3d84920)

ensuite on va faire les memes etapes pour compiler et executer sur la carte : 

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/5149076b-8646-4336-b4fa-d8492eeadedb)

2 Modules kernel (TP2)
2.1 Accès aux registres

Avant de travailler avec les modules, on va créer un programme qui accède directement aux registres depuis l’espace utilisateur.
![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/0b2e029c-dbeb-4d79-be45-ae24f013e950)

on va essayer d'allumer LED 8
![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/eb6c8bd7-1508-4142-aa76-5bd8137a1e6a)
on a bien acces aux registre LED
2.2 Compilation de module noyau sur la VM
On va recupere les fichers hello.c et makefile sur moodle 

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/736a04e5-c4d8-49fb-a9be-fab7e4c265ba)

On va utiliser la commande make pour compiler, il va generer un ficher .ko

ensuite la commande sudo insmod hellokernel.ko pour l'executer : 

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/f4c4e91e-9c94-4834-953d-abd999cb2707)

pour decharger le module on va utiliser la commande rmmod hellokernel.ko

Pour la suite, on va tester les programmes suivants 
— utilisation de paramètres au chargement du module

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/ca3e3380-7797-469c-b1ad-ba94a5c226ef)

voici le resuktat sur VM : 

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/51701883-a5b3-4020-8509-081f4fcc8e49)


— création d’un entrée dans /proc

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/2a43e635-c4a5-4472-abf6-0270a4a52bb9)



![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/e6d51b6c-2f4a-45d4-b679-daa699ab45a6)

voici le messages dans proc

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/b9ebfbd9-3c19-4b99-91f2-0f90e638a15c)

comme nous avons pas envoyé des messages on a rien de particulier.

on va essayer d'envoyer un message : 

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/540e07cb-c0dc-470d-ba86-5f5a4e627384)

le message est recu 

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/6b84baef-4f44-4ba6-87dd-5c1486c606a9)

utilisation d’un timer

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/aa35df02-bd86-48e8-87e6-9fae2acb3a11)

On ma creer un ficher .ko du timer

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/90fd560f-3002-4bff-87f3-38e82b5a7772)

On ne puet pas faire la compilation sur le terminal du pc car les fromats ne sont pas comptatible donc on va le tester directeent sur le VM

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/68a69c3b-a819-4141-a0a7-447abf05e436)

le module timer marhe bien et avons lancé un timer pendant 2s

On enleve le module timer

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/12405c71-54ee-44d4-9fd5-0aa7f9b6fcc5)

2.3 CrossCompilation de modules noyau

2.3.0 Récupération du Noyau Terasic (c’est déjà fait dans la VM !)

2.3.1 Préparation de la compilation

2.3.2 Récupéreation de la configuration actuelle du noyau

2.3.3 Hello World

Nous allons refaire le manip pour un program hello world mais cette fois avec un compilateur de la carte, voici le ficher .ko 

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/697709d3-64f6-4665-a00b-972c07dfb5bd)

Test sur la carte

![image](https://github.com/Ngoduu/TP_Linux_ENSEA_3DN/assets/145014223/99ac18f9-98a2-4782-a3d9-ec52c33fe843)

nous avons bien reussi la cross compilation



















































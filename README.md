PlexiBot
============
Code source Arduino pour le robot PlexiBot

Hardware
---------

### Liste du matériel utilisé

 - SainSmart UNO (cf. http://www.sainsmart.com/sainsmart-uno-atmega328p-pu-atmega8u2-microcontroller-for-arduino.html pour plus de détails)
 - SainSmart graphique LCD4884 Shield (cf http://www.dfrobot.com/wiki/index.php/LCD4884_Shield_For_Arduino_(SKU:DFR0092) pour plus de détails)
 - SainSmart Prototype Shield
 - Télémètre Ultrason  HC-SR04 (cf. https://zestedesavoir.com/tutoriels/343/realiser-un-telemetre-a-ultrasons/ pour plus de détails)
 - TBS2651 Chassis voiture Arduino 2WD (cf. https://www.amazon.fr/TBS2651-Chassis-voiture-intelligent-encodeur/dp/B018FYECCE/275-0012099-1686634?ie=UTF8&*Version*=1&*entries*=0 pour plus de détails)
 - Contrôleur de Deux Moteurs 2A, 6-15V I2C Grove Seeedstudio (cf. http://www.robotshop.com/eu/fr/controleur-moteurs-2a-6-15v-grove-seeedstudio.html pour plus de détails). Les dipswitces 1 à 4 sont tous vers le haut, l'adresse sur le bus I2C est alors `0x0F`.
 
### Connexions

*todo*
 
 Software
-------------

### Installation

Installer la bibliothèque *libraries\LCD4884.zip* dans l'environnement Arduino (testé en version 1.6.8)


### Test de bon fonctionnement

Pour tester le bon fonctionnement de l'écran LCD, et du joystick de navigation, télécharger le sketch *demo_lcd\demo_lcd.ino* 
dans le microcontroleur, et naviguer avec le curseur.

Pour tester le bon fonctionnement du pilotage des moteurs, télécharger le sketch *test_moteur\test_moteur.ino* 
dans le microcontroleur.

Pour tester le bon fonctionnement du télémètre à ultrason, télécharger le sketch *test_ultrason\test_ultrason.ino* 
dans le microcontroleur.

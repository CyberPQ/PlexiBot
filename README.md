PlexiBot
============
Code source Arduino pour le robot PlexiBot

Hardware
---------

 - SainSmart UNO (cf. http://www.sainsmart.com/sainsmart-uno-atmega328p-pu-atmega8u2-microcontroller-for-arduino.html pour plus de détails)
 - SainSmart graphique LCD4884 Shield (cf http://www.dfrobot.com/wiki/index.php/LCD4884_Shield_For_Arduino_(SKU:DFR0092) pour plus de détails)
 - SainSmart Prototype Shield
 - HC-SR04, ultrasons
 - TBS2651 Chassis voiture Arduino 2WD (cf. https://www.amazon.fr/TBS2651-Chassis-voiture-intelligent-encodeur/dp/B018FYECCE/275-0012099-1686634?ie=UTF8&*Version*=1&*entries*=0 pour plus de détails)


Software
-------------

###Installation

Installer la bibliothèque *libraries\LCD4884.zip* dans l'environnement Arduino (testé en version 1.6.8)


###Test de bon fonctionnement

Pour tester le bon fonctionnement de l'écran LCD, et du joystick de navigation, télécharger le sketch *demo_lcd\demo_lcd.ino* 
dans le microcontroleur, et naviguer avec le curseur.

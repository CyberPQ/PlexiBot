/* Ping))) Sensor

   This sketch reads a PING))) ultrasonic rangefinder and returns the
   distance to the closest object in range. To do this, it sends a pulse
   to the sensor to initiate a reading, then listens for a pulse
   to return.  The length of the returning pulse is proportional to
   the distance of the object from the sensor.

   The circuit:
	* +V connection of the PING))) attached to +5V
	* GND connection of the PING))) attached to ground
	* SIG connection of the PING))) attached to digital pin 7

   http://www.arduino.cc/en/Tutorial/Ping

   created 3 Nov 2008
   by David A. Mellis
   modified 30 Aug 2011
   by Tom Igoe

   This example code is in the public domain.

 */
 #include "LCD4884.h"
 
#define VITESSE 340 //vitesse du son 340 m/s
 
const int USTrig = 8; // Déclencheur sur la broche 8
const int USEcho = 9; // Réception sur la broche 9

char buffer[10];

void setup()
{
	lcd.LCD_init();
	lcd.LCD_clear();
  
    pinMode(USTrig, OUTPUT);
    pinMode(USEcho, INPUT);

    digitalWrite(USTrig, LOW);
	
	Serial.begin(115200);

    lcd.LCD_write_string(0, 0, "test ultrason ", MENU_HIGHLIGHT );
	lcd.LCD_write_string(20, 5, "(en cm)", MENU_NORMAL );
	Serial.println("== test ultrason ==");
}

void loop()
{
   
   
   // 1. Un état haut de 10 microsecondes est mis sur la broche "Trig"
   digitalWrite(USTrig, HIGH);
   delayMicroseconds(10); //on attend 10 µs
   // 2. On remet à l’état bas la broche Trig
   digitalWrite(USTrig, LOW);

   // 3. On lit la durée d’état haut sur la broche "Echo"
   unsigned long duree = pulseIn(USEcho, HIGH);

   if(duree > 30000)
   {
      // si la durée est supérieure à 30ms, l'onde est perdue
	  lcd.LCD_write_string(0, 3, "Onde perdue, mesure échouée !", MENU_NORMAL );
      Serial.println("Onde perdue, mesure échouée !");
   }
   else
   {
      // 4. On divise cette durée par deux pour n'avoir qu'un trajet
      duree = duree/2;

      // 5. On calcule la distance avec la formule d=v*t
      float temps = duree/1000000.0; //on met en secondes
      float distance = temps*VITESSE; //on multiplie par la vitesse, d=t*v

      // 6. On affiche la distance
      Serial.print("Duree = ");
      Serial.println(temps); //affiche le temps de vol d'un trajet en secondes
      Serial.print("Distance = ");
      Serial.println(distance); //affiche la distance mesurée (en mètres)
	  
	  itoa(distance*100, buffer, 10);
	  lcd.LCD_write_string(30, 3, "       ", MENU_NORMAL ); //pour effacer l'ancienne valeur
	  lcd.LCD_write_string(30, 3, "       ", MENU_NORMAL ); //pour effacer l'ancienne valeur
	  lcd.LCD_write_string(30, 3, buffer, MENU_NORMAL );
   }

   // petite pause
   delay(250);
}
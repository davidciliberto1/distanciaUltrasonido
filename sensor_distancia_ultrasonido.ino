#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2); 
int sensorTemp;
float temperatura;
int trig = 10;
int eco =  9;
int led = 11;
int buzz = 12;
int distancia;
int duracion;
void setup() {
  lcd.begin(16, 2);
pinMode(trig, OUTPUT);
pinMode(eco, INPUT);
pinMode(led, OUTPUT);
pinMode(buzz, OUTPUT);
Serial.begin(9600);
}
void loop() {
  
  lcd.setCursor(0,0);
 
  
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  duracion = pulseIn(eco, HIGH);
  distancia = duracion / 58.2;
  Serial.println(distancia);
  delay(200);
   
   if(distancia <= 40 && distancia >= 0) {
     digitalWrite(buzz, HIGH);
    delay(distancia * 4);
    digitalWrite(buzz, LOW);
    digitalWrite(led, HIGH);
    delay(distancia * 10);
    digitalWrite(led, LOW);
      lcd.print(distancia);
      lcd.print(" ");

  }
  else {
          lcd.print(distancia);

  }
    lcd.setCursor(0,1);

  sensorTemp = analogRead(A0);
 temperatura = ((sensorTemp * 5000.0) / 1023) / 100;
  Serial.println(temperatura, 1);
        lcd.print(temperatura);
    
}

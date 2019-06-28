#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>


#define DHTPIN 9
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(19200);
  pinMode(13,OUTPUT);
}

void loop() {
  Serial.println ("Encender Bomba");
  digitalWrite(13, HIGH);
  delay (2000);// put your main code here, to run repeatedly:
  Serial.println ("Apagar Bomba");
  digitalWrite(13, LOW);
  delay (2000);
}

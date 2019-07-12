#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <stdio.h>
#include <stdbool.h>

#define DHTPIN 9
#define DHTTYPE DHT11
#define DHTPIN2 10
#define DHTPIN3 11

#define SI 1
#define NO 0

#define SEGDIA 86400000
#define SEGHIGH 10000
#define SEGSUS 5000

DHT dht(DHTPIN,DHTTYPE);

DHT dht2(DHTPIN2,DHTTYPE);
DHT dht3(DHTPIN3,DHTTYPE);

void setup()
{
  //BOMBA1
  dht.begin();
  Serial.begin(115200);
  pinMode(DHTPIN,OUTPUT);
  
  //BOMBA2
  
  
  //HIGROMETRO  
  Serial.begin(115200);


  

}

void loop()
{
   int lectura = analogRead(A0);
   int porcentaje = map(lectura, 1023, 0,0, 100);
   Serial.print("La lectura de humedad es: ");
   Serial.print(lectura); 
   Serial.print(" de 1023 segun los valores de humedad de la tablatura para dht Arduino"); 
   Serial.println(" ");
   
   Serial.print("El porcentaje de la humedad es del: ");
   Serial.print(porcentaje);
   Serial.print("%");
   Serial.println(" ");
 
   int condicion;
   int *ptr;
   ptr=&condicion;

  
  
   //lectura entre 1000-1023

 if (lectura>= 1000) {
  Serial.println("El sensor esta desconectado o fuera del suelo");
  Serial.println("Se desactivara el sistema de riego");
  digitalWrite(DHTPIN, LOW);
  *ptr=NO;
  
  
  }
 else if (lectura<1000 && lectura>=600)
 {
  Serial.println("El suelo esta seco");
  Serial.println("Se iniciara el sistema de riego");
  digitalWrite(DHTPIN, HIGH);

  delay(SEGHIGH);

  digitalWrite(9, LOW);
  *ptr=SI;
  
  }
 else if(lectura <600 && lectura >= 370)
 {
  Serial.println("El suelo esta humedo");
  Serial.println("El sistema de riego se desactivara");
  digitalWrite(DHTPIN, LOW);

  *ptr=SI;
  }
 else if (lectura <370) {
  Serial.println("El sensor esta sumergido en agua");
  Serial.println("El sistema de riego se desactivara");
  digitalWrite(DHTPIN, LOW);
  *ptr=NO;
  }

  if(condicion=SI)
  {
    digitalWrite(DHTPIN2, HIGH);
    digitalWrite(DHTPIN3, HIGH);
    delay(SEGSUS);
    digitalWrite(DHTPIN2, LOW);
    digitalWrite(DHTPIN3, LOW);
    Serial.println("Se activara el riego diario de los dos sustratos");
    }
  else if(condicion=NO){
    digitalWrite(DHTPIN2, LOW);
    digitalWrite(DHTPIN3, LOW);
     Serial.println("No se activara el riego diario de los dos sustratos");
    }
  
  
  
  //el sistema de riego se ejecuta una vez al dia
 delay(SEGDIA);
}

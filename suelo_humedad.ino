#include <DHT.h>
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
 int lectura = analogRead(A0);

 Serial.print("La lectura es: ");
 Serial.println(lectura);

//lectura entre 1000-1023

 if (lectura>= 1000) {
  Serial.println("El sensor esta desconecado o fuera del suelo");
  }
 else if (lectura<1000 && lectura>=600)
 {
  Serial.println("El suelo esta seco");
  }
 else if(lectura <600 && lectura >= 370)
 {
  Serial.println("El suelo esta humedo");
  }
 else if (lectura <370) {
  Serial.println("El sensor esta sumergido en agua");
  }
  
delay(2000);

int porcentaje = map(lectura, 1023, 0,0, 100);

Serial.print("La humedad es del: ");
Serial.println(porcentaje);
Serial.println("%");
}

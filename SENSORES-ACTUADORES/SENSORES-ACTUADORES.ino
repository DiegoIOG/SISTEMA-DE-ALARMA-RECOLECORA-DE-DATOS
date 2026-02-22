#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int luz = A0;
const int vibracion = 3;
const int llama = 4;
const int buzzer = 5;
const int rele = 6;

const int rojo = 9;
const int verde = 10;
const int azul = 11;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(vibracion, INPUT);
  pinMode(llama, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(rele, OUTPUT);

  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
}

void loop() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int nivelLuz = analogRead(luz);
  int vib = digitalRead(vibracion);
  int fire = digitalRead(llama);

  bool alarma = false;

  if (temp >= 30 || fire == HIGH|| vib == HIGH) {
    alarma = true;
  }

  if (alarma) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(rele, HIGH);

    analogWrite(rojo, 50);
    analogWrite(verde, 0);
    analogWrite(azul, 0 );
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(rele, LOW);

    analogWrite(rojo, 0 );
    analogWrite(verde, 20);
    analogWrite(azul, 0);
  }

  // Enviar datos en formato CSV para SQL
  //Tempeartura
  Serial.print(temp);
  Serial.print(",");
  //Humedad
  Serial.print(hum);
  Serial.print(",");
  //Luz
  Serial.print(nivelLuz);
  Serial.print(",");
  //Vibracion
  Serial.print(vib);
  Serial.print(",");
  //Fuego
  Serial.println(fire);

  delay(2000);
}
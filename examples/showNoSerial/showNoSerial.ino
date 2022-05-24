#include <HC-SR04.h>

HC-SR04 sensor(3, 2);//Trig //Echo

void setup() {
  Serial.begin(9600);
}
void loop() {
  float distanciaM = sensor.getDistanceM();
  int distanciaCM = sensor.getDistanceCM();
  Serial.print("Distancia em Metros: ");
  Serial.println(distanciaM);
  Serial.print("Distancia em Centimetros: ");
  Serial.println(distanciaCM);
  delay(100);
}

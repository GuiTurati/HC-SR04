#include "HC04.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"

//Instanciasao
HC04::HC04(byte pinTrig, byte pinEcho) {
	pinoTrig = pinTrig;
	pinoEcho = pinEcho;
	pinMode(pinoTrig, OUTPUT);
	pinMode(pinoEcho, INPUT);
	resultadoM = 0;
	resultadoCM = 0;
}


// Funcoes da Biblioteca
float HC04::getDistanceM() {
	resultadoM = 0;
	digitalWrite(pinoTrig, LOW);
	delayMicroseconds(2);
	digitalWrite(pinoTrig, HIGH);
	delayMicroseconds(10);
	digitalWrite(pinoTrig, LOW);
	resultadoM = (pulseIn(pinoEcho, HIGH)/58.0);
	return resultadoM / 100;
}  
int HC04::getDistanceCM() {
	resultadoCM = 0;
	digitalWrite(pinoTrig, LOW);
	delayMicroseconds(2);
	digitalWrite(pinoTrig, HIGH);
	delayMicroseconds(10);
	digitalWrite(pinoTrig, LOW);
	resultadoCM = pulseIn(pinoEcho, HIGH)/58.0;
	return resultadoCM;
}  
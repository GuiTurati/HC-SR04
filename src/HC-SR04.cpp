#include "HC-SR04.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"

//Instanciasao
HC-SR04::HC-SR04(byte pinTrig, byte pinEcho) {
	pinoTrig = pinTrig;
	pinoEcho = pinEcho;
	pinMode(pinoTrig, OUTPUT);
	pinMode(pinoEcho, INPUT);
	resultadoM = 0;
	resultadoCM = 0;
}


// Funcoes da Biblioteca
float HC-SR04::getDistanceM() {
	resultadoM = 0;
	digitalWrite(pinoTrig, LOW);
	delayMicroseconds(2);
	digitalWrite(pinoTrig, HIGH);
	delayMicroseconds(10);
	digitalWrite(pinoTrig, LOW);
	resultadoM = (pulseIn(pinoEcho, HIGH)/58.0);
	if (resultadoM > 2 && resultadoM < 400) {
		return resultadoM / 100;
	} else if (resultadoM < 2 || resultadoM > 400) {
		return 0;
	}
}  
int HC-SR04::getDistanceCM() {
	resultadoCM = 0;
	digitalWrite(pinoTrig, LOW);
	delayMicroseconds(2);
	digitalWrite(pinoTrig, HIGH);
	delayMicroseconds(10);
	digitalWrite(pinoTrig, LOW);
	resultadoCM = pulseIn(pinoEcho, HIGH)/58.0;
	if (resultadoCM > 2 && resultadoCM < 400) {
		return resultadoCM;
	} else if (resultadoCM < 2 || resultadoCM > 400) {
		return 0;
	}
}  
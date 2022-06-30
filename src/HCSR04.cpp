#include "HCSR04.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"

//Instanciasao
HCSR04::HCSR04(byte pinTrig, byte pinEcho) {
	pinoTrig = pinTrig;
	pinoEcho = pinEcho;
	pinMode(pinoTrig, OUTPUT);
	pinMode(pinoEcho, INPUT);
	resultadoM = 0;
	resultadoCM = 0;
}


// Funcoes da Biblioteca
float HCSR04::getDistanceM() {
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
int HCSR04::getDistanceCM() {
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
#ifndef HC-SR04_h
#define HC-SR04_h

#include "Arduino.h"

class HC-SR04 {
  public:
    HC-SR04(byte pinTrig, byte pinEcho);
	float getDistanceM();
	int getDistanceCM();
  private:
    byte pinoTrig;
	byte pinoEcho;
	float resultadoM;
	float resultadoCM;
};

#endif
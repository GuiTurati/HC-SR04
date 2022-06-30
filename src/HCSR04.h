#ifndef HCSR04_h
#define HCSR04_h

#include "Arduino.h"

class HCSR04 {
  public:
    HCSR04(byte pinTrig, byte pinEcho);
	float getDistanceM();
	int getDistanceCM();
  private:
    byte pinoTrig;
	byte pinoEcho;
	float resultadoM;
	float resultadoCM;
};

#endif
#ifndef HC04_h
#define HC04_h

#include "Arduino.h"

class HC04 {
  public:
    HC04(byte pinTrig, byte pinEcho);
	float getDistanceM();
	int getDistanceCM();
  private:
    byte pinoTrig;
	byte pinoEcho;
	float resultadoM;
	float resultadoCM;
};

#endif
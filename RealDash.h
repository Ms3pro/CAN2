#ifndef REALDASH_H
#define REALDASH_H

#include <Arduino.h>

extern int seconds, pw1, pw2, rpm;

void SendCANFramesToRealDash();
void SendCANFrameToRealDash(unsigned long canFrameId, const byte* frameData);

#endif

#ifndef REVOLUTION_IR_H
#define REVOLUTION_IR_H

#include "Util.h"

uint IR;
uint IR2;

task Start_IR()
{
    IR = 0;
    IR2 = 0;

    while(1)
    {
        IR = SensorValue[IR_Sensor];
        IR2 = SensorValue[IR_Back];
        nxtDisplayBigTextLine(0, "IR: %i", IR);
        nxtDisplayBigTextLine(6, "IR2: %i", IR2);
    }
}

#endif

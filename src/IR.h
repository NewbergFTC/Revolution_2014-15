#ifndef REVOLUTION_IR_H
#define REVOLUTION_IR_H

#include "Util.h"

uint IR;

task Start_IR()
{
    IR = 0;

    while(1)
    {
        IR = SensorValue[IR_Sensor];
        nxtDisplayBigTextLine(0, "IR: %i", IR);
    }
}

#endif

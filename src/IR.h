#ifndef REVOLUTION_IR_H
#define REVOLUTION_IR_H

#include "Util.h"

#define IR_SECTOR_NULL  (0)
#define IR_SECTOR_ONE   (1)
#define IR_SECTOR_TWO   (2)
#define IR_SECTOR_THREE (3)
#define IR_SECTOR_FOUR  (4)
#define IR_SECTOR_FIVE  (5)
#define IR_SECTOR_SIX   (6)
#define IR_SECTOR_SEVEN (7)
#define IR_SECTOR_EIGHT (8)
#define IR_SECTOR_NINE  (9)

uint IR;

task Start_IR()
{
	IR = IR_SECTOR_NULL;

  while(1)
  {
    IR = SensorValue[IR_Sensor];
  }
}

#endif

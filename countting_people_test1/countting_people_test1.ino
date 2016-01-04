#include "Timer.h"

Timer t;

int flagIn = 0;
int flagOut = 0;
int countPeopleIn = 0;
int countPeopleOut = 0;
int count = 0;
float countP = 0;
float samplingTime = 50;
float timePeriod = 350;
int idleCount = 0;


void countUpdate();

void countPeopleInFunc ();
int countPeopleOutFunc ();

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);

  int tickEvent = t.every(50, countPeopleInFunc);
}
  
void loop() {
  //read the pushbutton value into a variable
 // int sensorVal = digitalRead(2);
  //print out the value of the pushbutton
 // Serial.println(tempInt);
 t.update();

}


void countUpdate() {
  idleCount = 0;
  countP += count * samplingTime / timePeriod ; //ceil?

  double temp = 0;
  temp = countP;
  int tempInt = round(temp);
//  Multistate_Input_Present_Value_Set(0,tempInt);

  //printf(" countP: %d\n", tempInt);
    Serial.println(tempInt);

  count = 0;
  countPeopleIn = 0;
  countPeopleOut = 0;
  flagIn = 0;
  flagOut = 0;
}

void countPeopleInFunc () {

  int x = digitalRead(2);

  if (x == 0 )
    {
      idleCount = 0;
      if (flagOut == 0)
      {
        flagIn = 1;
        countPeopleIn += 1;
      }
      else {
        countPeopleOut -= 1;
        count -= 1;
        if(countPeopleOut ==0 )
           flagOut = 0;
      }
    }
  else
  {
    idleCount +=1;
    if(idleCount >= 40 )
    {
      countUpdate();
    }
  }

//printf(" countIn: %d\n", countPeopleIn);
countPeopleOutFunc();
  }

int countPeopleOutFunc () {

  int x = digitalRead(7);

  if (x == 0 )
    {
      idleCount = 0;
      if (flagIn == 0)
      {
        flagOut = 1;
        countPeopleOut += 1;
      }
      else {
        countPeopleIn -= 1;
        count += 1;
        if(countPeopleIn ==0 )
           flagIn = 0;
      }
    }
  else
  {
    idleCount +=1;
    if(idleCount >= 40 )
    {
      countUpdate();
    }
  }
//printf(" countOut: %d\n", countPeopleOut);
  }
  



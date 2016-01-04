int sensA;                      //    Declaring VARIABLES
int sensB;
//int thresh;
int ctr=0;
//int lights=9;
//int sens_cutoff=A2;
//int relay=2;

void setup()
{

Serial.begin(9600);
pinMode(2, INPUT_PULLUP);
pinMode(7, INPUT_PULLUP);
}

void loop() 
{
sensA = digitalRead(2);                        // READ SENSOR A AND B
sensB= digitalRead(7);
//thresh = 300;                                  // !!!!!!!!!!!!!!!   CHANGE THE VALUE OF THRESHOLD ACCORDING TO THE AMBIENT LIGHT
if(sensA==0 && sensB == 1)
{
ctr=ctr+1;                                      //  INCREMENT
delay(900);
}
else{ctr=ctr;
}

if(sensA==1 && sensB == 0)
{
ctr=ctr-1;                                       // DECREMENT
delay(900);
}
else
{
  ctr=ctr;
}

Serial.println("sensA is :  ");                          // PRINT ALL THE VALUES AND COUNTER 
Serial.println(sensA   ); 
Serial.println("      sensB is :  ");
Serial.println(sensB    );
Serial.println("     counter :  "); 
Serial.println(ctr); 

}



int sensA;                      //    Declaring VARIABLES
int sensB;
int thresh;
int ctr=0;
int lights=9;
int sens_cutoff=A2;
int relay=2;
void setup()
{

Serial.begin(9600);

}

void loop() 
{
sensA = analogRead(A0);                        // READ SENSOR A AND B
sensB= analogRead(A1);
thresh = 300;                                  // !!!!!!!!!!!!!!!   CHANGE THE VALUE OF THRESHOLD ACCORDING TO THE AMBIENT LIGHT
if(sensA<thresh && sensB>thresh)
{
ctr=ctr+1;                                      //  INCREMENT
delay(100);
}
else{ctr=ctr;
}

if(sensA>thresh && sensB<thresh)
{
ctr=ctr-1;                                       // DECREMENT
delay(100);
}
else
{
  ctr=ctr;
}

Serial.print("sensA is :  ");                          // PRINT ALL THE VALUES AND COUNTER 
Serial.print(sensA   ); 
Serial.print("      sensB is :  ");
Serial.print(sensB    );
Serial.print("     counter :  "); 
Serial.print(ctr); 
Serial.print("  thresh val : ");
Serial.println(thresh);
}



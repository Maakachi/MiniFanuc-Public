#include <Servo.h>
#include <Arduino.h>


long microsecondsToInches(long microseconds);
long microsecondsToCentimeters(long microseconds); 

int savedpos(int jav);

long previousmillis = 0;
#define interval 2000

//Ultrasound sensor pin configuration
const int pingPin = 3; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 4; // Echo Pin of Ultrasonic Sensor
long duration, inches, cm;//To store inch and cm data from ultrasonic sensor


Servo servo1;     //created the object for the servos
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

int servo1pos, servo2pos, servo3pos, servo4pos, servo5pos, servo6pos;
int servo1SP[100],servo2SP[100],servo3SP[100],servo4SP[100],servo5SP[100],servo6SP[100];

char data;
char liar='S';// to store the bluetooth command
int organ=0;

int spdturn,m,index;

void setup() 
{ 
  servo1.attach(10); // PWM pin for servo motors
  servo2.attach(9);
  servo3.attach(8);
  servo4.attach(7);
  servo5.attach(6);
  servo6.attach(5);

  pinMode(pingPin, OUTPUT); // sensor setup
  pinMode(echoPin, INPUT);

   
  
 
  Serial.begin(9600); // setting the baud rate at 9600
}

   
void loop() 
{  
  uint8_t i;

   
if(Serial.available()>0)
{
  data = Serial.read();
  Serial.print("\n");
  Serial.print("\n");
  Serial.print("Data = ");
  Serial.print(data);
  Serial.print("\n");
  Serial.print("Index = ");
  Serial.print(index);
  Serial.print("\n");
  Serial.print(servo1pos);
  Serial.print("\n");  
  Serial.print(servo2pos);
  Serial.print("\n");  
  Serial.print(servo3pos);
  Serial.print("\n");  
  Serial.print(servo4pos);
  Serial.print("\n");  
  Serial.print(servo5pos);
  Serial.print("\n");  
  Serial.print(servo6pos);
  Serial.print("\n");  

}





switch (data)
{
     
     case 'A':  if (servo1pos>359)          // servo1 positive direction
                {
                  data = 'S';
                  break;
                }
                servo1.write(servo1pos);  
                servo1pos++;
                delay(20);                    
                break;
               
     case 'a':  if (servo1pos<1)          // servo1 negative direction
                {
                  data = 'S';
                  break;
                }
                servo1.write(servo1pos);  
                servo1pos--; 
                delay(20);                       
                break;

    case 'B':  if (servo2pos>359)          // servo2 positive direction
                {
                  data = 'S';
                  break;
                }
                servo2.write(servo2pos);  
                servo2pos++;
                delay(20);                    
                break;
               
     case 'b':  if (servo2pos<1)          // servo2 negative direction
                {
                  data = 'S';
                  break;
                }
                servo2.write(servo2pos);  
                servo2pos--; 
                delay(20);                       
                break;

     case 'C':  if (servo3pos>359)          // servo3 positive direction
                {
                  data = 'S';
                  break;
                }
                servo3.write(servo3pos);  
                servo3pos++;
                delay(20);                    
                break;
               
     case 'c':  if (servo3pos<1)          // servo3 negative direction
                {
                  data = 'S';
                  break;
                }
                servo3.write(servo3pos);  
                servo3pos--; 
                delay(20);                       
                break;

     case 'D':  if (servo4pos>359)          // servo4 positive direction
                {
                  data = 'S';
                  break;
                }
                servo4.write(servo4pos);  
                servo4pos++;
                delay(20);                    
                break;
               
     case 'd':  if (servo4pos<1)          // servo4 negative direction
                {
                  data = 'S';
                  break;
                }
                servo4.write(servo4pos);  
                servo4pos--; 
                delay(20);                       
                break;

     case 'E':  if (servo5pos>359)          // servo5 positive direction
                {
                  data = 'S';
                  break;
                }
                servo5.write(servo5pos);  
                servo5pos++;
                delay(20);                    
                break;
               
     case 'e':  if (servo5pos<1)          // servo5 negative direction
                {
                  data = 'S';
                  break;
                }
                servo5.write(servo5pos);  
                servo5pos--; 
                delay(20);                       
                break;

     case 'F':  if (servo6pos>359)          // servo6 positive direction
                {
                  data = 'S';
                  break;
                }
                servo6.write(servo6pos);  
                servo6pos++;
                delay(20);                    
                break;
               
     case 'f':  if (servo6pos<1)          // servo6 negative direction
                {
                  data = 'S';
                  break;
                }
                servo6.write(servo6pos);  
                servo6pos--; 
                delay(20);                       
                break;

     case 'V': servo1SP[index]=servo1pos;   //teach pos
               servo2SP[index]=servo2pos;
               servo3SP[index]=servo3pos;
               servo4SP[index]=servo4pos;
               servo5SP[index]=servo5pos;
               servo6SP[index]=servo6pos;
               index++;
               data = 'S';
               break;

    case 'W':       // run
                    
                while(data!='U')
                {

                   //sending ultrasonic pulses, receiving reflected pulses and calculating distance to object
                     digitalWrite(pingPin, LOW);
                     delayMicroseconds(2);
                     digitalWrite(pingPin, HIGH);
                     delayMicroseconds(10);
                     digitalWrite(pingPin, LOW);   
                     duration = pulseIn(echoPin, HIGH);
                     inches = microsecondsToInches(duration);
                     cm = microsecondsToCentimeters(duration);
                     Serial.print("\n");
                     Serial.print(inches);
                     Serial.print("in, ");
                     Serial.print("\n");
                     Serial.print(cm);
                     Serial.print("cm");
                     Serial.print("\n");
                     Serial.println(); 

   
                 organ++;
                  if(Serial.available()>0)
                {
                  data = Serial.read();
                  Serial.print("\n");
                  Serial.print("\n");
                  Serial.print(organ);
                  Serial.print("\n");
                  Serial.print(data);
                  Serial.print("\n");
                }
                if(data=='U')    //reset array
                {
                  memset(servo1SP, 0, sizeof(servo1SP));    // Clear the array data to 0
                  memset(servo2SP, 0, sizeof(servo2SP));
                  memset(servo3SP, 0, sizeof(servo3SP));
                  memset(servo4SP, 0, sizeof(servo4SP));
                  memset(servo5SP, 0, sizeof(servo5SP));
                  memset(servo6SP, 0, sizeof(servo6SP));
                  index = 0;
                  break;
                }
                
                if(inches<10)  // if object detected then one sequence runs
                {

                   for (int i = 0; i <= index - 2; i++)
                  { 
                    if(data=='w')     //pause
                      {
                        while(data!='U')
                        {
                          Serial.print("\n\nin pause \n");
                          if(Serial.available()>0)
                          {
                            data  = Serial.read();
                          }
                          if(data=='W')
                          break;
                        }     
                      }
                     
                    if (servo1SP[i] == servo1SP[i + 1]) {       // servo1 run sequence
                      }
                      if (servo1SP[i] > servo1SP[i + 1]) 
                      {
                        for ( int j = servo1SP[i]; j >= servo1SP[i + 1]; j--) 
                        { 
                          servo1.write(j);   
                          delay(40);    
                          
                        }
                      }
                      if (servo1SP[i] < servo1SP[i + 1]) 
                      {
                        for ( int j = servo1SP[i]; j <= servo1SP[i + 1]; j++) 
                        {
                          servo1.write(j);
                          delay(40);
                          
                        }
                      }


                      if (servo2SP[i] == servo2SP[i + 1]) {      // servo2  run sequence
                      }
                      if (servo2SP[i] > servo2SP[i + 1]) 
                      {
                        for ( int j = servo2SP[i]; j >= servo2SP[i + 1]; j--) 
                        { 
                          servo2.write(j);   
                          delay(40);    
                          
                        }
                      }
                      if (servo2SP[i] < servo2SP[i + 1]) 
                      {
                        for ( int j = servo2SP[i]; j <= servo2SP[i + 1]; j++) 
                        {
                          servo2.write(j);
                          delay(40);
                          
                        }
                      }


                      if (servo3SP[i] == servo3SP[i + 1]) {       // servo3 run sequence
                      }
                      if (servo3SP[i] > servo3SP[i + 1]) 
                      {
                        for ( int j = servo3SP[i]; j >= servo3SP[i + 1]; j--) 
                        { 
                          servo3.write(j);   
                          delay(40);    
                          
                        }
                      }
                      if (servo3SP[i] < servo3SP[i + 1]) 
                      {
                        for ( int j = servo3SP[i]; j <= servo3SP[i + 1]; j++) 
                        {
                          servo3.write(j);
                          delay(40);
                          
                        }
                      }


                      if (servo4SP[i] == servo4SP[i + 1]) {      // servo4  run sequence
                      }
                      if (servo4SP[i] > servo4SP[i + 1]) 
                      {
                        for ( int j = servo4SP[i]; j >= servo4SP[i + 1]; j--) 
                        { 
                          servo4.write(j);   
                          delay(40);    
                          
                        }
                      }
                      if (servo4SP[i] < servo4SP[i + 1]) 
                      {
                        for ( int j = servo4SP[i]; j <= servo4SP[i + 1]; j++) 
                        {
                          servo4.write(j);
                          delay(40);
                          
                        }
                      }


                      if (servo5SP[i] == servo5SP[i + 1]) {       // servo5 run sequence
                      }
                      if (servo5SP[i] > servo5SP[i + 1]) 
                      {
                        for ( int j = servo5SP[i]; j >= servo5SP[i + 1]; j--) 
                        { 
                          servo5.write(j);   
                          delay(40);    
                          
                        }
                      }
                      if (servo5SP[i] < servo5SP[i + 1]) 
                      {
                        for ( int j = servo5SP[i]; j <= servo5SP[i + 1]; j++) 
                        {
                          servo5.write(j);
                          delay(40);
                          
                        }
                      }


                      if (servo6SP[i] == servo6SP[i + 1]) {      // servo6  run sequence
                      }
                      if (servo6SP[i] > servo6SP[i + 1]) 
                      {
                        for ( int j = servo6SP[i]; j >= servo6SP[i + 1]; j--) 
                        { 
                          servo6.write(j);   
                          delay(40);    
                          
                        }
                      }
                      if (servo6SP[i] < servo6SP[i + 1]) 
                      {
                        for ( int j = servo6SP[i]; j <= servo6SP[i + 1]; j++) 
                        {
                          servo6.write(j);
                          delay(40);
                          
                        }
                      }
                      
                  delay(40);
                  
                  } // one teach sequence ends
                  
                }
                else
                {
                  //Move robot arm to intial position
                    servo1pos = 80;
                    servo1.write(servo1pos);
                    servo2pos = 45;
                    servo2.write(servo2pos);
                    servo3pos = 26;
                    servo3.write(servo3pos);
                    servo4pos = 80;
                    servo4.write(servo4pos);
                    servo5pos = 14;
                    servo5.write(servo5pos);
                    servo6pos = 45;
                    servo6.write(servo6pos);
                }
                 
                  
                  
                } // looping the sequence until stop or reset is pressed   
                break;

    case 'U': memset(servo1SP, 0, sizeof(servo1SP));    // Clear the array data to 0
              memset(servo2SP, 0, sizeof(servo2SP));
              memset(servo3SP, 0, sizeof(servo3SP));
              memset(servo4SP, 0, sizeof(servo4SP));
              memset(servo5SP, 0, sizeof(servo5SP));
              memset(servo6SP, 0, sizeof(servo6SP));
              index = 0;
              break;

    
   
 }



}


long microsecondsToInches(long microseconds) 
{
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) 
{
   return microseconds / 29 / 2;
}


int savedpos(int jav)
{
  if(millis() - previousmillis >= interval)
  {
    previousmillis = millis();
    servo1.write(jav);
  }
  
}
  
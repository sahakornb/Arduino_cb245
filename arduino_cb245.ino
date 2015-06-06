#include <Servo.h> 
#include <stdlib.h> 

int flags = 0;
int buffer_count = 0;
char data[6]; 
Servo myservo;

void setup() 
{
  Serial.begin(9600); //set baud rate to 9600
  myservo.attach(A2);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);  
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
    Serial.println("HI");
}
void Print_data(char data[])
{
  for(int i = 0;i<6;i++)
  {
    Serial.print(data[i]);
  }
   buffer_count = 0;
}
void loop() 
{
  /*
   * This is a main Program
   * @param data[] is a buffer for get variable from c#
   * @param buffer_count is a number counting for check lenght buffer.
   * all buffer = 6 charactor 
   * if buffer = 5 (Recieve 6 charector)0 
   * @Example buffer data => c37v05 :: Channel = 37 and Volume = 05
   * @since : 6 June 2015.
   *
   */  
   
    if (Serial.available() > 0)   // Serial available 
      {  
           if(buffer_count<6)
           {
             char A = Serial.read();
             data[buffer_count] = A;
             buffer_count++;
           }
            
    }
    else
    { 
      if(buffer_count == 5)    // if 6 charator received.[index 0-5]
      {
        /*
         * First loop send 3 charactor 
         */
         for(int i = 0;i<3;i++)       
            radioSerial(data[i]);
        /*
         * Second loop send 3 charactor 
         */
        for(int j = 3;j<6;j++)
             ServoSerial(data[j]);
       // Reset Buffer.
       buffer_count = 0;
      }
    }
   
}

void ServoSerial(char input)
{  
  if(input == '0')
  {
      myservo.write(1);
      Serial.println(input);
      delay(15);
   }
   else if(input == '1')
   {
      myservo.write(20);
      Serial.println(input);
      delay(15);
   }
   else if(input == '2')
   {
      myservo.write(30);
      Serial.println(input);
      delay(15);
   }
   else if(input == '3')
   {
      myservo.write(50);
      Serial.println(input);
      delay(15);
   }
   else if(input == '4')
   {
      myservo.write(60);
      Serial.println(input);
      delay(15);
   }
   else if(input == '5')
   {
      myservo.write(70);
      Serial.println(input);
      delay(15);
   }
   else if(input == '6')
   {
      myservo.write(90);
      Serial.println(input);
      delay(15);
   }
   else if(input == '7')
   {
      myservo.write(100);
      Serial.println(input);
      delay(15);
   }
   else if(input == '8')
   {
      myservo.write(150);
      Serial.println(input);
      delay(15);
   }
   else if(input == '9')
   {
      myservo.write(180);
      Serial.println(input);
      delay(15);
   }
}
void radioSerial(char A)
{
  delay(500);
  if(A=='0')//ปุ่ม0
    {
     Serial.println("Show0");
     digitalWrite(8,HIGH);
     digitalWrite(6,HIGH);
     delay(180);
     digitalWrite(8,LOW);
     digitalWrite(6,LOW);
    }
    
   else if(A=='1')//ปุ่ม1
    {
     Serial.println("Show1");
     digitalWrite(7,HIGH);
     digitalWrite(3,HIGH);
     delay(180);
     digitalWrite(7,LOW);
     digitalWrite(3,LOW);
    }
    
    else if(A=='2')//ปุ่ม2
    {
     Serial.println("Show2");
     digitalWrite(8,HIGH);
     digitalWrite(3,HIGH);
     delay(180);
     digitalWrite(8,LOW);
     digitalWrite(3,LOW);
    }
    
    else if(A=='3')//ปุ่ม3
    {
     Serial.println("Show3");
     digitalWrite(9,HIGH);
     digitalWrite(3,HIGH);
     delay(180);
     digitalWrite(9,LOW);
     digitalWrite(3,LOW);
    }
      
     else if(A=='4')//ปุ่ม4
    {
     Serial.println("Show4");
     digitalWrite(7,HIGH);
     digitalWrite(4,HIGH);
     delay(180);
     digitalWrite(7,LOW);
     digitalWrite(4,LOW);
    } 
      
     else if(A=='5')//ปุ่ม5
    {
     Serial.println("Show5");
     digitalWrite(8,HIGH);
     digitalWrite(4,HIGH);
     delay(180);
     digitalWrite(8,LOW);
     digitalWrite(4,LOW);
    }
     
     else if(A=='6')//ปุ่ม6
    {
     Serial.println("Show6");
     digitalWrite(9,HIGH);
     digitalWrite(4,HIGH);
     delay(180);
     digitalWrite(9,LOW);
     digitalWrite(4,LOW);
    } 
    
    else if(A=='7')//ปุ่ม7
    {
     Serial.println("Show7");
     digitalWrite(7,HIGH);
     digitalWrite(5,HIGH);
     delay(180);
     digitalWrite(7,LOW);
     digitalWrite(5,LOW);
    }
      
    else if(A=='8')//ปุ่ม8
    {
     Serial.println("Show8");
     digitalWrite(8,HIGH);
     digitalWrite(5,HIGH);
     delay(180);
     digitalWrite(8,LOW);
     digitalWrite(5,LOW);
    } 
     
    else if(A=='9')//ปุ่ม9
    {
     Serial.println("Show9");
     digitalWrite(9,HIGH);
     digitalWrite(5,HIGH);
     delay(180);
     digitalWrite(9,LOW);
     digitalWrite(5,LOW);
    } 
    else if(A=='c')//ปุ่มC
    {
     Serial.println("ShowC");
     digitalWrite(10,HIGH);
     digitalWrite(5,HIGH);
     delay(180);
     digitalWrite(10,LOW);
     digitalWrite(5,LOW);
    } 
}



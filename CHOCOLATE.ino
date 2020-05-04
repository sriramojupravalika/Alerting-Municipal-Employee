 #include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);
int trigPin=5; 
int echoPin=4;
long duration;
int distance;

void setup()
{
   pinMode(8,OUTPUT);//g
    pinMode(3,OUTPUT);//y
    pinMode(12,OUTPUT);//r
  pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600); 
}

void loop()
{
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin,HIGH);
    distance= duration*0.0344/2;
  Serial.println(distance);
  delay (1000);
  if(distance>10)
      {
        digitalWrite(8,1);
        digitalWrite(12,0);
        digitalWrite(3,0);
        
      }
  else if (distance<=2)
      {
        digitalWrite(3,0);
        digitalWrite(12,1);
        digitalWrite(8,0);
          mySerial.println("AT+CMGF=1");//Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+919550874804\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println("HELLO THIS IS GSM MODULE 900A, BIN NO:0141 IS FILLED PLZ CLEAN IT.TQX..!");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
      
      }
 else
      {
         digitalWrite(3,1);
         digitalWrite(8,0);
         digitalWrite(12,0);
        
        
      }
}

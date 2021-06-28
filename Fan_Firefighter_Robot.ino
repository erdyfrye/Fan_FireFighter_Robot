//ultrasonik
const int trigPin = 13;
const int echoPin = 12;
const int trigPin2 = 11;
const int echoPin2 = 10;
const int trigPin3 = 9;
const int echoPin3 = 8;
long duration;
long duration2;
long duration3;
int distance;
int distance2;
int distance3;
//kipas
int INA = 7;
int INB = 6;
//motor
int ENA=3;
int ENB=5;
int IN_1 = 1;
int IN_2 = 2;
int IN_3 = 0;
int IN_4 = 4;

void setup() {
 
pinMode(INA,OUTPUT);
pinMode(INB,OUTPUT);

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
  pinMode(IN_1,OUTPUT);
  pinMode(IN_2,OUTPUT);
  pinMode(IN_3,OUTPUT);
  pinMode(IN_4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  
 
Serial.begin(9600);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
duration2= pulseIn(echoPin2, HIGH);
distance2=duration2*0.034/2;
Serial.print("Distance2: ");
Serial.println(distance2);
digitalWrite(trigPin3, LOW);
delayMicroseconds(2);
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);
duration3= pulseIn(echoPin3, HIGH);
distance3=duration3*0.034/2;
Serial.print("Distance3: ");
Serial.println(distance3);
  
   if((distance>10)&&(distance2>10)&&(distance3>10))
   {
    maju();
   }
   if(distance<15)
   {
    berhenti();
    if((distance2>15)&&(distance3>15))
    {
      kiri();
       if((distance2<15)&&(distance3>15))
      {
        kiri();
      }
      else if((distance2>15)&&(distance3<15))
      {
        kanan();
      }
    }
    
   }
   if(((distance>15)||(distance<15))&&(distance2<15)&&(distance3>15))
   {
    kiri();
   }
   if(((distance>15)||(distance<15))&&(distance2>15)&&(distance3<15))
   {
    kanan();
   }
   
  if ((distance < 15)&&(distance2 < 15)&&(distance3 < 15))
  {
    berhenti();
    delay(1000);
    mundur();
  }
   if(analogRead(A0)< 500 )
   {
     berhenti();
     delay(1000);
    digitalWrite(INA,LOW);
    digitalWrite(INB,HIGH);
   
   }
  else
   {
    digitalWrite(INA,LOW);
    digitalWrite(INB,LOW);
   }

}
 void maju()
  {
 analogWrite(ENA, 255);
 analogWrite(ENB, 90);
 digitalWrite(IN_1, HIGH);
 digitalWrite(IN_2, LOW);
 digitalWrite(IN_3, HIGH);
 digitalWrite(IN_4, LOW);
  }
  void kanan()
  {
 analogWrite(ENA, 255);
 analogWrite(ENB, 0);
    digitalWrite(IN_1, HIGH);
 digitalWrite(IN_2, LOW);
 digitalWrite(IN_3, LOW);
 digitalWrite(IN_4, LOW);
  }
  void kiri()
  {
 analogWrite(ENA, 0);
 analogWrite(ENB, 255);
 digitalWrite(IN_1, LOW);
 digitalWrite(IN_2, LOW);
 digitalWrite(IN_3, HIGH);
 digitalWrite(IN_4, LOW);
  }
  void berhenti()
  {
    
 analogWrite(ENA, 0);
 analogWrite(ENB, 0);
 digitalWrite(IN_1, LOW);
 digitalWrite(IN_2, LOW);
 digitalWrite(IN_3, LOW);
 digitalWrite(IN_4, LOW);
  }
  void mundur()
  {
 analogWrite(ENA, 255);
 analogWrite(ENB, 255);
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
  }

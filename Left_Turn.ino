 int tri1 = 23;
int echopin1 = 22;

int tri2 = 25;
int echopin2 = 24;

int tri3 = 29;
int echopin3 = 28;

int tri4 = 33;
int echopin4 = 32;

long duration1 ,cm1;
long duration2 ,cm2;
long duration3 ,cm3;
long duration4 ,cm4;

int IN1= 2;
int IN2= 3;
int EN1= 4;
int IN3= 5;
int IN4= 6;
int EN2= 7;
int IN5= 36;
int IN6= 37;
int IN7= 38;
int IN8= 39;

//int EN1= 42;
//int EN2= 43;
int EN3= 44;
int EN4= 45;




void setup() {

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(IN5,OUTPUT);
  pinMode(IN6,OUTPUT);
  pinMode(IN7,OUTPUT);
  pinMode(IN8,OUTPUT);
  pinMode(EN1,OUTPUT);
  pinMode(EN2,OUTPUT);
  pinMode(EN3,OUTPUT);
  pinMode(EN4,OUTPUT);
  

Serial.begin(9600);


}

void loop() {

  pinMode(tri1, OUTPUT); // Use to triger the PING sensor
  digitalWrite(tri1, LOW);
  delayMicroseconds(2);
  digitalWrite(tri1, HIGH);
  delayMicroseconds(5);
  digitalWrite(tri1, LOW);

  pinMode(echopin1, INPUT);
  duration1 = pulseIn(echopin1, HIGH);

  cm1 = microsecondsToCentimeters(duration1);  //Function for getting distance in CMS
  Serial.print(cm1);
  Serial.print("    ");

  pinMode(tri2, OUTPUT);
  digitalWrite(tri2, LOW);
  delayMicroseconds(2);
  digitalWrite(tri2, HIGH);
  delayMicroseconds(5);
  digitalWrite(tri2, LOW);

  pinMode(echopin2, INPUT);
  duration2 = pulseIn(echopin2, HIGH);

  cm2 = microsecondsToCentimeters(duration2);
  Serial.print(cm2);
  Serial.print("    ");


pinMode(tri3, OUTPUT);
  digitalWrite(tri3, LOW);
  delayMicroseconds(2);
  digitalWrite(tri3, HIGH);
  delayMicroseconds(5);
  digitalWrite(tri3, LOW);

  pinMode(echopin3, INPUT);
  duration3 = pulseIn(echopin3, HIGH);

 cm3 = microsecondsToCentimeters(duration3);
  Serial.print(cm3);
  Serial.print("    ");

  pinMode(tri4, OUTPUT);
  digitalWrite(tri4, LOW);
  delayMicroseconds(2);
  digitalWrite(tri4, HIGH);
  delayMicroseconds(5);
  digitalWrite(tri4, LOW);

  pinMode(echopin4, INPUT);
  duration4 = pulseIn(echopin4, HIGH);

  cm4 = microsecondsToCentimeters(duration4);
  Serial.print(cm4);
  Serial.print("    ");
Serial.println();

  if(cm1 <=20)
  {
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(EN1,50);
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);//function to stop motor
  analogWrite(EN2,255);
  delay(5000);
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(EN1,255);  // For max speed.
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(EN2,255);
  delay(20000);
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(EN1,255);
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);//function to stop motor
  analogWrite(EN2,50);
  delay(5000);
  
   digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(EN1,255);  // For max speed.
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(EN2,255);
  delay(20000);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(EN1,255);
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);//function to stop motor
  analogWrite(EN2,50);
  delay(5000);
  
  
   digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(EN1,255);  // For max speed.
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(EN2,255);
  delay(20000);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(EN1,50);
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);//function to stop motor
  analogWrite(EN2,255);
  delay(5000);

  
  }
  else
  {
    
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(EN1,255);  // For max speed.
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(EN2,255); // To run motor in forward direction
  }

 
  
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}


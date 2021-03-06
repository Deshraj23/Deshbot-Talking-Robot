#include <LiquidCrystal.h>// initialize the library by associating any needed LCD interface pin
                          // with the arduino pin number it is connected to
const int rs = A4, en = A3, d4 = A2, d5 = A1, d6 = A0, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
byte datarx;
int moter1 = 8;
int moter2 = 9;
int moter3 = 7;
int moter4 = 6;
const int trigPin = A1;// Defines Tirg
const int echoPin = A2;// and Echo pins of the Ultrasonic Sensor
const int sw1=10,sw2=11,buzzer=12;
long duration;// Variables for the duration and the distance
int distance;
 void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" Deshbot Shield "); // Print a message to the LCD.
  Serial.begin(9600);    // initialize serial:
  pinMode(moter1, OUTPUT);
  pinMode(moter2, OUTPUT);
  pinMode(moter3, OUTPUT);
  pinMode(moter4, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  Serial.println("Please Welcome");
  delay(1000);
    Serial.println("i am Deshbot version 2.0");
    delay(2000);
    Serial.println("You will be safe and sound during this journey");
    delay(3000);
    Serial.println("Please be patient I will try to help you fully");
    delay(3000);
    Serial.println("my master Miss Chaandni Dhimaan will attend you shortly");
    delay(3000);
    }
void loop() {

  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
//  Serial.print(i); // Sends the current degree into the Serial Port
 // Serial.print("this is diatance"); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
 // Serial.print(distance); // Sends the distance value into the Serial Port
 // Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  
  if(distance<10)
  {
    Serial.println("Obstacle Detected");
    delay(2000);
    Serial.println("Stopping robot");
   delay(2000);
   
    digitalWrite(moter1, LOW); 
 digitalWrite(moter2,LOW); 
 digitalWrite(moter3, LOW);  /////////stop
 digitalWrite(moter4, LOW);
 delay(1000);
 Serial.println("Moving backwards");
 delay(2000);
for(int i=0;i<10;i++)
    { digitalWrite(moter1, LOW); 
 digitalWrite(moter2, HIGH); 
 digitalWrite(moter3, LOW); /////////back
 digitalWrite(moter4, HIGH);
 
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  delay(1000);
  Serial.println("Now Moving left");
  delay(2000);
 digitalWrite(moter1, LOW); 
 digitalWrite(moter2, LOW); 
 digitalWrite(moter3, LOW); /////////left
 digitalWrite(moter4, HIGH);
 delay(500);
 Serial.println("Stopping robot");
delay(2000);
 digitalWrite(moter1, LOW); 
 digitalWrite(moter2,LOW); 
 digitalWrite(moter3, LOW); /////////stop
 digitalWrite(moter4, LOW);
  }

  else{
    delay(2000);
 Serial.println("No Obstacle Detected");
  delay(2000);
    Serial.println("Moving Forward");
    delay(2000);
  digitalWrite(moter1, HIGH); 
 digitalWrite(moter2, LOW); 
 digitalWrite(moter3, HIGH); /////////Forward
 digitalWrite(moter4, LOW); 
    
  }

  
  }

int calculateDistance(){ // Function for calculating the distance
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}

#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "TMPLFWn9T8iM"
#define BLYNK_DEVICE_NAME "LED"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "raixlY-4XzH4aSG7UNozWetgOBSjNw0-";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Redmi 9 Power";
char pass[] = "RaVI@6129";


//......................motor................................
#define SC1 D0 // ena1 pin of motor driver/speed control of motor 1
#define SC2 D5 // ena2 pin of motor driver/speed control of motor 2
#define M1 D1 // motor1 wire 1
#define M2 D2 // motor1 wire 2
#define M3 D3 // motor2 wire 1
#define M4 D4 // motor2 wire 2
#define trigPin D3 //declaring trigger pin
#define echoPin D4 //declaring echo pin

long duration; // declaring variable for storing time 
int distance; // declaring variable for storing distance 
String command = "";
int spd=1023;


//....................forward()....................
void forward()
{
  analogWrite(SC1, spd); // writing the speed to left motor
  analogWrite(SC2, spd); // writing the speed to right motor
  // left motor forward direction
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  //right motor forward direction
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
  delay(50);
  Serial.println("FORWARD");
}
//....................backward()....................
void backward()
{
  analogWrite(SC1, spd); // writing the speed to left motor
  analogWrite(SC2, spd); // writing the speed to right motor
  // left motor backward direction
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  //right motor backward direction
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  delay(50);
  Serial.println("BACKWARD");
}
//....................left()....................
void left()
{
  analogWrite(SC1, spd); // writing the speed to left motor
  analogWrite(SC2, spd); // writing the speed to right motor
  // left motor backward direction
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  //right motor forward direction
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
  delay(50);
  Serial.println("LEFT");
}
//....................right()....................
void right()
{
  analogWrite(SC1, spd); // writing the speed to left motor
  analogWrite(SC2, spd); // writing the speed to right motor
  // left motor forward direction
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  //right motor backward direction
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  delay(50);
  Serial.println("RIGHT");
}
//....................STOP()....................
void STOP()
{
 
  analogWrite(SC1, spd); // writing the speed to left motor
  analogWrite(SC2, spd); // writing the speed to right motor
  // left motor stop
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  //right motor stop
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
  delay(50);
  Serial.println("STOP");
}

void setup()
{
  pinMode(SC1,OUTPUT);
  pinMode(SC2,OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  // initially stop the motor
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

BLYNK_WRITE(V0){
  command = param.asStr();
//  Serial.println(command);
}

void loop()
{
  Blynk.run();
   if(command == "FORWARD")
  {
    forward();
    delay(5000);
//    Serial.println(command);
    command = "STOP"; 
  }
  else if(command == "BACKWARD")
  {
    backward();
    delay(5000);
//    Serial.println(command);
    command = "STOP";
  }
  else if(command == "LEFT")
  {
    left();
    delay(5000);
//    Serial.println(command);
    command = "STOP";
  }
  else if(command == "RIGHT")
  {
    right();
    delay(5000);
//    Serial.println(command);
    command = "STOP";
  }
  else
  {
    STOP();
//    Serial.println("Bot is Stopping");
  }
  
}

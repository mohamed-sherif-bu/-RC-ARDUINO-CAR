#include <LiquidCrystal.h> 
LiquidCrystal lcd(10, 9, 7, 6, 5, 4); 
const int trigPin = 12;
const int echoPin = 11;

int redLED = 8;
int buzzer = 13;
long duration;
int distanceCm;

void setup() {
  
  lcd.begin(16, 2); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
 }
 
void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.0344 / 2;
  
  lcd.setCursor(0, 0); 
  lcd.print("Distance: "); 
  lcd.print(distanceCm);
  lcd.print(" cm");
  delay(10);

  if(distanceCm <= 10){
      digitalWrite(redLED, HIGH);
    }
  else if(distanceCm <= 5){
  digitalWrite(redLED, HIGH);
  digitalWrite(buzzer, HIGH);
  }
  else {
      digitalWrite(redLED, LOW);
      digitalWrite(buzzer, LOW);
    }
}

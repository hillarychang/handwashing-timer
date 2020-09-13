#include <TimerOne.h>
#include <LiquidCrystal.h>
#define trigger 7
#define echo 6

float duration=0, distance=0;

LiquidCrystal lcd (0,1,2,3,4,5);
signed short minutes, seconds;
char timeline[16];
int tim = 250;

volatile int minutesTens= 0;
volatile int minutesOnes = 0;
volatile int secondsTens =  0;
volatile int secondsOnes = 0;


const int Red = 10;
const int Red2 = 12;
const int Red3 = 9; //lone red LED
const int Green = 13;
const int Yellow = 11;

const int trigPin = 6;
const int echoPin = 7;



void setup() {
  pinMode (Red, OUTPUT);
  pinMode (Red2, OUTPUT);
  pinMode (Red3,OUTPUT);
  pinMode (Green,OUTPUT);
  pinMode (Yellow,OUTPUT);
  pinMode (trigger, OUTPUT);
  pinMode (echoPin, OUTPUT);

  lcd.begin(16,2);
 
  lcd.print('use soap!');
  delay(tim);
  lcd.clear();

  Serial.begin(115200);

   pinMode(trigger,OUTPUT);
   pinMode(echo,INPUT);
   
  // put your setup code here, to run once:
}

void loop() {
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  duration=pulseIn(echo,HIGH);
  distance=(duration/2)*0.0343;

  if (distance<20){
    digitalWrite(Red2,HIGH);
    digitalWrite(Red,HIGH);
  }
  else{
    digitalWrite(Red2,LOW);
    digitalWrite(Red,LOW);
  }

  digitalWrite(Green,HIGH);
  delay(17000);
  digitalWrite(Yellow,HIGH);
  digitalWrite(Green,LOW);
  delay(3000);
  digitalWrite(Red3,HIGH);
  digitalWrite(Yellow,LOW);

   
  lcd.setCursor(0,1);
  sprintf(timeline,"%0.2d mins %0.2d secs", minutes, seconds);
  lcd.print(timeline);

   delay(1000);
   seconds++;

    if (seconds==60)
    {
      seconds=0;
      minutes++;
    }

    
  // put your main code here, to run repeatedly:

}

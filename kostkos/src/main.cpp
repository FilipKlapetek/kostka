#include <Arduino.h>

int button = 2;
int bottomLeft = 3;
int middleLeft = 4;
int upperLeft = 5;
int middle = 6;
int bottomRight = 7;
int middleRight = 8;
int upperRight = 9;
int state = 0;
long randNumber;

void setup(){
  pinMode(bottomLeft, OUTPUT);
  pinMode(middleLeft, OUTPUT);
  pinMode(upperLeft, OUTPUT);
  pinMode(middle, OUTPUT);
  pinMode(bottomRight, OUTPUT);
  pinMode(middleRight, OUTPUT);
  pinMode(upperRight, OUTPUT);
  
  pinMode(button, INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void six()
{
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(middleLeft, HIGH);
  digitalWrite(upperLeft, HIGH);
  digitalWrite(bottomRight, HIGH);
  digitalWrite(middleRight, HIGH);
  digitalWrite(upperRight, HIGH);
}

void five()
{
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(middleLeft, LOW);
  digitalWrite(upperLeft, HIGH);
  digitalWrite(middle, HIGH);
  digitalWrite(bottomRight, HIGH);
  digitalWrite(middleRight, LOW);
  digitalWrite(upperRight, HIGH);
}

void four()
{
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(middleLeft, LOW);
  digitalWrite(upperLeft, HIGH);
  digitalWrite(bottomRight, HIGH);
  digitalWrite(middleRight, LOW);
  digitalWrite(upperRight, HIGH);
}

void three()
{
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(middleLeft, LOW);
  digitalWrite(upperLeft, LOW);
  digitalWrite(middle, HIGH);
  digitalWrite(bottomRight, LOW);
  digitalWrite(middleRight, LOW);
  digitalWrite(upperRight, HIGH);
}

void two()
{
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(middleLeft, LOW);
  digitalWrite(upperLeft, LOW);
  digitalWrite(bottomRight, LOW);
  digitalWrite(middleRight, LOW);
  digitalWrite(upperRight, HIGH);
}

void one()
{
  digitalWrite(bottomLeft, LOW);
  digitalWrite(middleLeft, LOW);
  digitalWrite(upperLeft, LOW);
  digitalWrite(bottomRight, LOW);
  digitalWrite(middle, HIGH);
  digitalWrite(middleRight, LOW);
  digitalWrite(upperRight, LOW);
}

void clearAll()
{
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(middleLeft, HIGH);
  digitalWrite(upperLeft, HIGH);
  digitalWrite(bottomRight, HIGH);
  digitalWrite(middleRight, HIGH);
  digitalWrite(upperRight, HIGH);
}

void loop(){
  //Read our button if high then run dice
  if (digitalRead(button) == HIGH && state == 0){
    state = 1;
    randNumber = random(1, 7);
    delay(100);
    Serial.println(randNumber);

    if (randNumber == 6){
      six();
    }
    if (randNumber == 5){
      five();
    }
    if (randNumber == 4){
      four();
    }
    if (randNumber == 3){
      three();
    }
    if (randNumber == 2){
      two();
    }
    if (randNumber == 1){
      one();
    }
    delay(4000);
    clearAll();
    state = 0;
  }
}


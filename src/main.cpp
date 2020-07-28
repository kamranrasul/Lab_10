#include <Arduino.h>

// Pin Array definition
int8_t ledPin[6] = { 2, 3, 4, 7, 8, 9 };

// pattern
int8_t count1 = 0;
int8_t count2 = 5;

// flag for up and down streams
bool flag = false;

// setting Pins for Output
void pinSetup()
{
  // setting Pins for Output
  for (int i = 0; i < 6; i++)
  {
    // setting Pin for OUTPUT
    pinMode(ledPin[i], OUTPUT);
  }
}

// write LOW on output ping
void writeLow()
{
  // setting Pins to Low
  for (int i = 0; i < 6; i++)
  {
    // setting Pin for OUTPUT
    pinMode(ledPin[i], OUTPUT);

    // setting all Pins to LOW
    digitalWrite(ledPin[i], LOW);
  }
}

// function for writing HIGH on the Pins
void digitalWriteHigh(int a, int b)
{
  writeLow();
  digitalWrite(ledPin[a], HIGH);
  digitalWrite(ledPin[b], HIGH);
}

void setup()
{
  // setting up serial
  Serial.begin(115200);
  pinSetup();
  writeLow();
}

void loop()
{
  // step1
  digitalWriteHigh(0, 5);
  delay(15000);

  // step2
  digitalWriteHigh(1, 5);
  delay(5000);

  // step3
  digitalWriteHigh(2, 3);
  delay(15000);

  // step4
  digitalWriteHigh(2, 4);
  delay(5000);
}
#include <Arduino.h>

// Pin Array definition
int8_t ledPin[6] = {2, 3, 4, 7, 8, 9};

// only running the step Once
bool step1 = true;
bool step2 = false;
bool step3 = false;
bool step4 = false;

// timmings storage
unsigned long patternStep = millis() + 15000;

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
    // setting all Pins to LOW
    digitalWrite(ledPin[i], LOW);
  }
}

// function for writing HIGH on the Pins
void digitalWriteHigh(int light1, int light2)
{
  writeLow();
  digitalWrite(ledPin[light1], HIGH);
  digitalWrite(ledPin[light2], HIGH);
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
  if ((millis() < patternStep) && step1)
  {
    // step
    digitalWriteHigh(0, 5);
    step1 = false;
    step2 = true;
    patternStep = millis();
    Serial.println("******* START *******\n -> Step1 Active");
  }
  else if ((millis() > (patternStep + 5000)) && step2)
  {
    // step2
    digitalWriteHigh(1, 5);
    step2 = false;
    step3 = true;
    patternStep = millis();
    Serial.println(" -> Step2 Active");
  }
  else if ((millis() > (patternStep + 2000)) && step3)
  {
    // step3
    digitalWriteHigh(2, 3);
    step3 = false;
    step4 = true;
    patternStep = millis();
    Serial.println(" -> Step3 Active");
  }
  else if ((millis() > (patternStep + 25000)) && step4)
  {
    // step4
    digitalWriteHigh(2, 4);
    step4 = false;
    patternStep = millis();
    Serial.println(" -> Step4 Active");
  }
  else if (!step1 && !step2 && !step3 && !step4)
  {
    Serial.println("****** STEP RESET ******\n");
    patternStep = millis() + 15000;
    step1 = true;
    step2 = false;
    step3 = false;
    step4 = false;
  }
}
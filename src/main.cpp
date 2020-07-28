#include <Arduino.h>

// Pin Array definition
int8_t ledPin[8] = {2, 3, 4, 5, 6, 7, 8, 9};

// pattern
int8_t count1 = 0;
int8_t count2 = 7;

// flag for up and down streams
bool flag = true;

void setup()
{
  // setting up serial
  Serial.begin(115200);

  // setting Pins for Output
  for (int i = 0; i < 8; i++)
  {
    // setting Pin for OUTPUT
    pinMode(ledPin[i], OUTPUT);

    // setting all Pins to LOW
    digitalWrite(ledPin[i], LOW);
  }
}

void loop()
{
  // when all LED up, start counting down
  for (int i = 0; i < 8; i++)
  {
    // resetting Pins for count down
    digitalWrite(ledPin[i], LOW);
  }

  // setting the Pins as required
  digitalWrite(ledPin[flag ? count1++ : count1--], HIGH);
  digitalWrite(ledPin[flag ? count2-- : count2++], HIGH);

  // switching from down to up count
  flag = count1 == 3 ? false : flag;

  // switching from up to down count
  flag = count1 == 0 ? true : flag;

  Serial.print("Count1: ");
  Serial.println(count1);

  Serial.print("Count2: ");
  Serial.println(count2);

  // wait for 1 second
  delay(500);
}
#include <Arduino.h>

// Pin Array definition
int8_t ledPin[8] = {2, 3, 4, 5, 6, 7, 8, 9};

// pattern
int8_t count = 3;

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

  // switching count up/down
  flag = count == 3 ? true : (count == 0 ? false : flag);

  // setting the Pins as required
  digitalWrite(ledPin[3 - count], HIGH);
  digitalWrite(ledPin[4 + count], HIGH);

  // changing the count value
  count = flag ? --count : ++count;

  Serial.print("Count: ");
  Serial.println(count);

  // wait for 1 second
  delay(1000);
}
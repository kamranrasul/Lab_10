#include <Arduino.h>
 
// Pin Array definition
int8_t ledPin[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
 
// pattern
int8_t count = 0;
 
// flag for up and down streams
bool flag = false;
 
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
  digitalWrite(ledPin[flag ? count-- : count++], flag ? LOW : HIGH);
 
  // switching from down to up count
  flag = count == -1 ? count = 0 : flag;
 
  // switching from up to down count
  flag = count == 8 ? count = 7 : flag;
 
  // writing the pin to serial
  Serial.println(count);
 
  // wait for 1 second
  delay(500);
}
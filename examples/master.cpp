// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

#include <Arduino.h>
#include <wireextender.h>

void send_a_request(int address, int numBytes);

WireExtender ext;



void send_a_request(int address, int numBytes){
   Wire.requestFrom(address, numBytes);    // request 6 bytes from slave device #2

    while(Wire.available())    // slave may send less than requested
    { 
        char c = Wire.read(); // receive a byte as character
        Serial.print(c);         // print the character
    }
}



void setup()
{
      pinMode(13,OUTPUT);
      Wire.begin();        // join i2c bus (address optional for master)
      Serial.begin(9600);  // start serial for output
}

int count;
void loop()
{
  double var = ext.get_value(2);
  Serial.println(var);
  delay(100);

  digitalWrite(13,HIGH);
  delay(100);
  digitalWrite(13,LOW);
  Serial.print("Master is working: ");
  count ++;
  Serial.println(count);
}


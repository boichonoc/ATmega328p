/*
 * ProjectMain.cpp
 *
 * Created: 10/13/2014 8:42:09 PM
 */ 

#include "ProjectMain.h"

void setup()
{
	pinMode(13,OUTPUT);
	Serial.begin(9600);
	Serial.print("Hello World!");
}

void loop()
{
	digitalWrite(13,LOW);
	delay(1000);	
	digitalWrite(13,HIGH);
	delay(1000);
	Serial.println("123456789..");	
}

#define pirPin 13

/* 
 *  
 Membuat program untuk menyalakan lampu (ON/OFF) menggunakan PIR Sensor. Jika PIR
mendeteksi ada benda, maka lampu akan menyala dan jika dalam 5 detik sensor PIR tidak mendetaksi
adanya benda, maka lampu mati.

*/

//int calibrationTime = 30;//untuk hardware
long unsigned int lowIn; // yg dipakai +
long unsigned int pause = 5000; //jeda pembacaan sensor 5s
boolean lockLow = true;
boolean takeLowTime;
int PIRValue = 0;

void setup()
{
Serial.begin(9600);
pinMode(pirPin, INPUT);
pinMode(12, OUTPUT); //Letak LED
}

void loop()
{
PIRSensor();
}

void PIRSensor()
{
if(digitalRead(pirPin) == HIGH)
{
if(lockLow)
{
PIRValue = 1;
lockLow = false;
Serial.println("Motion detected.");
digitalWrite(12,1);
delay(50);
}
takeLowTime = true;
}
if(digitalRead(pirPin) == LOW)
{
if(takeLowTime){lowIn = millis();takeLowTime = false;}
if(!lockLow && millis() - lowIn > pause) //Akan looping sampai nilai melebihi pause
{
PIRValue = 0;
lockLow = true;
Serial.println("Motion ended.");
digitalWrite(12,0);
delay(50);
}
}
}

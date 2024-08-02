# Mount Connect

## Objective

Design an advanced trekkong pole with an ability to connect other trekking pole with the help of Long-Range technology.

## Abstract 
When people go on trekking, there is no way to communicate with the other people. so, we propose a LoRa based local mesh network system through which people on different location on the trek can communicate through text messages and share GPRS location in text message. Basically, LoRa modules have a special ability of extremely long range. Its node length can go up to 10 Km. we will embed the whole setup in the pole.

## Framework
 ###  * Arduino IDE ,ESP Module 8266 , Node MCU , LoRa Module


## Reciever Code 

 ``` C++
#include <LoRa.h>
#define SS 15
#define RST 16
#define DIO0 2
void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Receiver Host");
  LoRa.setPins(SS, RST, DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa Error");
    while (1);
  }
}
void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Receiving Data: ");
    while (LoRa.available()) {
      String data = LoRa.readString();
      Serial.println(data);
    }
  }
}
```

## Sender Code 
``` C++

#include <LoRa.h>
#define SS 15
#define RST 16
#define DIO0 2
#define button D4
int data = 1;
void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);


  while (!Serial)
    ;
  Serial.println("Sender Host");
  LoRa.setPins(SS, RST, DIO0);
  if (!LoRa.begin(433E6)) {
    // Serial.println("LoRa Error");
    delay(100);
    while (1)1
      ;
  }
}
void loop() {
  int buttonState = digitalRead(button);
  if (buttonState == LOW) {
    Serial.print("Sending Data: ");
    Serial.println(data);
    LoRa.beginPacket();
    LoRa.print(data);
    LoRa.endPacket();
    delay(3000);
  }
}

```

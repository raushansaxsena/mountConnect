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
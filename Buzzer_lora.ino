#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <LoRa.h>

#define BLYNK_TEMPLATE_ID "TMPL3y-Citkdd"
#define BLYNK_TEMPLATE_NAME "nodemcu"
#define BLYNK_AUTH_TOKEN "iI91vMFVMLowox5u26sU2tdDt6ZGQRQcz"

#define SS 15
#define RST 16
#define DIO0 2
#define BUZZER_PIN D3

char auth[] = "iI91vMFVMLowox5u2sU2tdDt6ZGQRQcz";
char ssid[] = "Error:404";
char pass[] = "etdu2615";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  Blynk.begin(auth, ssid, pass);

  pinMode(BUZZER_PIN, OUTPUT); // set buzzer pin as output
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
      Blynk.virtualWrite(V7," Agrim : I Need help");
      digitalWrite(BUZZER_PIN, HIGH); // turn on buzzer
      delay(1000); // beep for 100ms
      digitalWrite(BUZZER_PIN, LOW); // turn off buzzer
    }
  }
}

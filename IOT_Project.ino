#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>
#include "MAX30100_PulseOximeter.h"

const char* ssid = "Redmi 10A";
const char* password = "kavisaran2426";

const char* apiKey = "E4NV36VDL9CYRGEB";
unsigned long channelID = 2933580;
WiFiClient client;

PulseOximeter pox;
#define REPORTING_PERIOD_MS 15000
uint32_t lastUpdate = 0;

#define DHTPIN D0
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ WiFi connected!");

  ThingSpeak.begin(client);

  if (!pox.begin()) {
    Serial.println("❌ MAX30100 initialization failed");
    while (1);
  }
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
  Serial.println("✅ MAX30100 initialized");

  dht.begin();
  Serial.println("✅ DHT11 initialized");
}

void loop() {
  pox.update();

  if (millis() - lastUpdate >= REPORTING_PERIOD_MS) {
    float bpm = pox.getHeartRate();
    float spo2 = pox.getSpO2();
    float temperature = dht.readTemperature();

    Serial.println("📡 Sending to ThingSpeak:");
    Serial.print("💓 BPM: "); Serial.println(bpm);
    Serial.print("🩸 SpO2: "); Serial.println(spo2);
    Serial.print("🌡️ Temp: "); Serial.println(temperature);

    ThingSpeak.setField(1, bpm);
    ThingSpeak.setField(2, spo2);
    ThingSpeak.setField(3, temperature);

    int response = ThingSpeak.writeFields(channelID, apiKey);
    if (response == 200) {
      Serial.println("✅ Data sent to ThingSpeak!\n");
    } else {
      Serial.print("❌ Error sending data: ");
      Serial.println(response);
    }

    lastUpdate = millis();
  }
}

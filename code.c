#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int gasSensor = A0;
int buzzer = 14; // D5

// WiFi
char ssid[] = "vivo Y100A";
char pass[] = "kb123456";

// ThingSpeak
const char* server = "http://api.thingspeak.com/update";
String apiKey = "WCU82GBIW9ZLWKSO";

// delay control
unsigned long lastSendTime = 0;

void setup() {
  Serial.begin(115200);

  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("CO2 Monitor");
  delay(2000);
  lcd.clear();

  // WiFi connect
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi Connected");
}

void loop() {
  int value = analogRead(gasSensor);

  Serial.println(value);

  lcd.setCursor(0,0);
  lcd.print("CO2 Level:");

  lcd.setCursor(0,1);
  lcd.print("Value: ");
  lcd.print(value);
  lcd.print("   ");

  if (value > 250) {
    lcd.setCursor(10,1);
    lcd.print("HIGH");

    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(300);
  } else {
    digitalWrite(buzzer, LOW);
    delay(800);
  }

  // 🌐 ThingSpeak send (15 sec gap recommended)
  if (millis() - lastSendTime > 15000) {
    if (WiFi.status() == WL_CONNECTED) {
      WiFiClient client;
      HTTPClient http;

      String url = server;
      url += "?api_key=" + apiKey;
      url += "&field1=" + String(value);

      http.begin(client, url);
      http.GET();
      http.end();

      Serial.println("Data sent to ThingSpeak");
    }
    lastSendTime = millis();
  }
}

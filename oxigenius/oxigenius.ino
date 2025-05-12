#include <ArduinoJson.h>

void setup() {
  Serial.begin(9600); //baud rate: 9600
  delay(30000); //30s warmup time
}

void loop() {
  JsonDocument doc;
  doc["airQ"] = analogRead(A0); //avg value under "normal" conditions: 43-45; max when exposed to CO2 (breathing): 63;
  doc["ph"] = analogRead(A1);
  doc["temp"] = analogRead(A2);
  
  serializeJsonPretty(doc, Serial);
  delay(15000); //send data every 15s
}

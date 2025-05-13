#include <ArduinoJson.h>

void setup() {
  Serial.begin(9600); //baud rate: 9600
  delay(60000); //60s warmup time
}

void loop() {
  JsonDocument doc;
  //insert analog values from sensors into JSON doc
  doc["airQ"] = analogRead(A0); 
  doc["ph"] = analogRead(A1);
  doc["temp"] = analogRead(A2);
  
  serializeJsonPretty(doc, Serial);
  delay(15000); //send data every 15s
}

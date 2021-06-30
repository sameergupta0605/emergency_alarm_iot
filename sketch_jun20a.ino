#define _DEBUG_
#define DISABLE_TLS
#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>

#define USERNAME "sameergupta"
#define DEVICE_ID "nm0"
#define DEVICE_CREDENTIAL "ZXfSckK+rD9oC&u!"

#define SSID "Homenet"
#define SSID_PASSWORD "homenet@123"

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
int pushPin = 12; //  Pin 6 on Node MCU 
int val = 0;     // variable for reading the pin status
 
void setup() {
  
  thing.add_wifi(SSID, SSID_PASSWORD);
  
  pinMode(pushPin, INPUT_PULLUP);// declare pushbutton as input
  Serial.begin(9600);

 
}

void loop() {
 val = digitalRead(pushPin);
  Serial.println(val);// read input value
  if (val == LOW) {         // check if the input is HIGH (button released)
    
      thing.handle();
      thing.call_endpoint("email");
      delay(5000);
  }
  
}

 
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLV03I-aVm"
#define BLYNK_DEVICE_NAME "MARC1"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD

// Define Relay Pins
#define r1 5
#define r2 4
#define r3 0
#define r4 2

// Define Switch Pins
#define s1 14
#define s2 12
#define s3 13
#define s4 3

// Switch Flags
bool SWITCH5_FLAG = 1;
bool SWITCH6_FLAG = 1;
bool SWITCH7_FLAG = 1;
bool SWITCH8_FLAG = 1;

// Default Relay State
bool relay1 = LOW;
bool relay2 = LOW;
bool relay3 = LOW;
bool relay4 = LOW;



#include "BlynkEdgent.h"

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  relay1 = pinValue;
  Serial.print("Relay1 - ");Serial.println(pinValue);
  digitalWrite(r1 , pinValue);
  // process received value
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  relay2 = pinValue;
  Serial.print("Relay2 - ");Serial.println(pinValue);
  digitalWrite(r2 , pinValue);
  // process received value
}

BLYNK_WRITE(V3)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  relay3 = pinValue;
  Serial.print("Relay3 - ");Serial.println(pinValue);
  digitalWrite(r3 , pinValue);
  // process received value
}

BLYNK_WRITE(V4)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  relay4 = pinValue;
  Serial.print("Relay4 - ");Serial.println(pinValue);
  digitalWrite(r4 , pinValue);
  // process received value
}

void setup()
{
  Serial.begin(115200);
  delay(100);
  
  pinMode(s1, INPUT_PULLUP);
  pinMode(s2, INPUT_PULLUP);
  pinMode(s3, INPUT_PULLUP);
  pinMode(s4, INPUT_PULLUP);

  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);

  digitalWrite(r1, 0);
  digitalWrite(r2, 0);
  digitalWrite(r3, 0);
  digitalWrite(r4, 0);
  
  BlynkEdgent.begin();
}

void loop() {
    BlynkEdgent.run();
    swfeedback();
}

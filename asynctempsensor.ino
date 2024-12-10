#define DEBUG_MSG(...) Serial.println(__VA_ARGS__)
#define DEBUG_MSG_(...) Serial.print(__VA_ARGS__)


#include <OneWire.h>
#include "TempSensor.h"


TempSensor temp(D1);

void setup() {
  Serial.begin(115200);
}

void loop() {
  if(temp.search()) {
    int tempRead = temp.read(millis());
    if (tempRead != TEMP_SENSOR_CONTINUE) { 
      if(tempRead == TEMP_SENSOR_OK) {
        Serial.print("Temp: ");
        Serial.println(temp.value);
      } else {
        Serial.println("fail to read");
      }
    } // else we need to wait  
  } else {
    Serial.println("not found");
  }

}

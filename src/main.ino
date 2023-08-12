

#include "o2Reg.h"

#define pinBtnUp 25
#define pinBtnMenu 33
#define pinBtnDn 32



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  delay(50);

  // WiFi-Mqtt 설정
  wmm.subscribeTo = subscribeTo;
  // required - allow WiFiMQTTManager to do it's setup
  wmm.setup(__SKETCH_NAME__);
  // optional - define a callback to handle incoming messages from MQTT
  wmm.client->setCallback(subscriptionCallback);



  // Buton Setup
  btnUp.begin(pinBtnUp);
  btnMenu.begin(pinBtnMenu);
  btnDn.begin(pinBtnDn);

  btnUp.setClickHandler(hndlr_btnUp);
  btnUp.setLongClickHandler(hndlr_btnUp);

  btnDn.setClickHandler(hndlr_btnDn);
  btnDn.setLongClickHandler(hndlr_btnDn);

  btnMenu.setClickHandler(hndlr_btnMenu);
  btnMenu.setLongClickHandler(hndlr_btnMenu);
  Serial.println("-- Button Setup");
  delay(500);

  // Network Setup
  //
  Serial.println("-- Network Setup");
  delay(500);
  //Network Check
  Serial.println("-- Network Check ");
//   CUR_MODE = RUNNING_MODE;
//  ESP_LOGW(TASK1_TAG,"hello loogoogogo from setup");
}

void loop() {
    btnUp.loop();
    btnDn.loop();
    btnMenu.loop();

  wmm.loop();

  // optional - example of publishing to MQTT a sensor reading once a 1 minute
  long now = millis();
  if (now - wmm.lastMsg > 1000) {
    wmm.lastMsg = now;
    float temperature = 70; // read sensor here
    Serial.print("Temperature: ");
    Serial.println(temperature);
    char topic[100];
    snprintf(topic, sizeof(topic), "%s%s%s", "sensor/", wmm.deviceId, "/temperature");
    wmm.client->publish(topic, String(temperature).c_str(), true);
  }

//    update_display();
}

// optional function to subscribe to MQTT topics

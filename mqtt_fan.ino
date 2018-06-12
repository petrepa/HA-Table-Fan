/* Code made by PETER REMØY PAULSEN
 * Free to use what so ever
 * Can be done better 
 * Do it better
 */


#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = ""; //Write your wifi name
const char* password =  ""; //Your wifi password
const char* mqttServer = ""; //Your MQTT broker
const int mqttPort = 1883; //Port used most often with MQTT
const char* mqttUser = ""; //Username for your broker
const char* mqttPassword = ""; //Password for your broker

#define RelaySpeed1 D1 //pin labelled d1
#define RelaySpeed2 D2 //pin labelled d2

WiFiClient espClient;
PubSubClient client(espClient);


void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  pinMode(RelaySpeed1, OUTPUT);
  digitalWrite(RelaySpeed1, HIGH);
  pinMode(RelaySpeed2, OUTPUT);
  digitalWrite(RelaySpeed2, HIGH);
  

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    if (client.connect("MQTT_fan", mqttUser, mqttPassword )) {

      Serial.println("connected");

    } else {

      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);

    }
  }

  client.publish("fan/status", "Hello from ESP8266 MQTT fan");
  client.subscribe("fan/status");

}

void callback(char* topic, byte* payload, unsigned int length) {

  Serial.print("Message arrived in topic: ");
  Serial.println(topic);

  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }

  if(*payload == 49){ //same as sending 1
    setMode1();
  }
  else if(*payload == 50){ //same as sending 2
    setMode2();
  }
  else{ //same as sending anything else than 1 and 2. Will be 0.
    setModeOff();
  }

  Serial.println();
  Serial.println("-----------------------");

}

void setMode1(){
  digitalWrite(RelaySpeed1, HIGH);
  digitalWrite(RelaySpeed2, LOW);

  Serial.println();
  Serial.print("Turning on Speed 1");
}

void setMode2(){
  digitalWrite(RelaySpeed1, LOW);
  digitalWrite(RelaySpeed2, HIGH);

  Serial.println();
  Serial.print("Turning on Speed 2");
}

void setModeOff(){
  digitalWrite(RelaySpeed1, HIGH);
  digitalWrite(RelaySpeed2, HIGH);

  Serial.println();
  Serial.print("Turning off");
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    if (client.connect("MQTT_fan", mqttUser, mqttPassword )) {

      Serial.println("connected");

    } else {

      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);

    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}


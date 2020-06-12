
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid     = "Hare krishna(2.4ghz)\0";
const char* password = "7977582925\0";

const char* mqtt_server = "192.168.29.21\0";

WiFiClient espClient;
PubSubClient client(espClient);

int redled= 0;
int greenled=4;

String redledstatus="off";
String greenledstatus="off";


// Timers auxiliar variables
long now = millis();
long lastMeasure = 0;

// Don't change the function below. This functions connects your ESP8266 to your router
void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected - ESP IP address: ");
  Serial.println(WiFi.localIP());
}


void callback(String topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();
  if(topic=="redled" && messageTemp=="on"){
    digitalWrite(redled, HIGH);
    redledstatus="on";
  }else if (topic=="redled" && messageTemp=="off"){
    digitalWrite(redled, LOW);
    redledstatus="off";
  }else if (topic=="greenled" && messageTemp=="on"){
    digitalWrite(greenled, HIGH);
    greenledstatus="on";
  }else if (topic=="greenled" && messageTemp=="off"){
    digitalWrite(greenled, LOW);
    greenledstatus="off";
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
}

// This functions reconnects your ESP8266 to your MQTT broker
// Change the function below if you want to subscribe to more topics with your ESP8266 
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    /*
     YOU MIGHT NEED TO CHANGE THIS LINE, IF YOU'RE HAVING PROBLEMS WITH MQTT MULTIPLE CONNECTIONS
     To change the ESP device ID, you will have to give a new name to the ESP8266.
     Here's how it looks:
       if (client.connect("ESP8266Client")) {
     You can do it like this:
       if (client.connect("ESP1_Office")) {
     Then, for the other ESP:
       if (client.connect("ESP2_Garage")) {
      That should solve your MQTT multiple connections problem
    */
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");  
      // Subscribe or resubscribe to a topic
      // You can subscribe to more topics (to control more LEDs in this example)
      client.subscribe("aru_trial_1");
      client.subscribe("redled");
      client.subscribe("greenled");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!client.connected()) {
    reconnect();
  }

   if(!client.loop())
    client.connect("ESP8266Client");

    String statusled= "Red: "+ redledstatus + " Green: " + greenledstatus;
    char array1[256];
    statusled.toCharArray(array1,256);

         

    client.publish("status_update", array1);

    
}

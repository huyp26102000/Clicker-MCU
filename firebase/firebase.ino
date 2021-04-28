#include <WiFi.h>
#include <FirebaseESP32.h>

#define FIREBASE_HOST "clickervinschool-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "GG7T6xb1jKWUw2JmPJtEzh3QL25YzCMYzeNgWIs6"
#define WIFI_SSID "DEE"
#define WIFI_PASSWORD "114114114"


FirebaseData firebaseData;

void setup(){
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  Initialization();
  WiFiConnection();
  
 }

int counter = 0;
float counter2 = 0.5;

void Initialization(){
  
  Serial.begin(115200); 
 }

void WiFiConnection(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop(){
  int a = digitalRead(25);
  int b = digitalRead(26);
  if(a == 1)
  {
    Firebase.setInt(firebaseData, "a/true",1);
    delay(500);
    Firebase.setInt(firebaseData, "a/true",0);
  }
  if(b == 1)
  {
    Firebase.setInt(firebaseData, "a/false",1);
    delay(500);
    Firebase.setInt(firebaseData, "a/false",0);
  }
  
  
}

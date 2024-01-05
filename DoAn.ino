#include <WiFi.h>
#include <WiFiClient.h>
#include <string.h>
#include <FirebaseESP32.h>
#include <ArduinoJson.h>
#include <ESP32Servo.h>

#define WIFI_SSID "Hiu" 
#define WIFI_PASSWORD "manhhieu" 

#define FIREBASE_HOST "dk-bang-giong-noi-3186-default-rtdb.firebaseio.com" 
#define FIREBASE_AUTH "Cl7Mg1sEGz5tRD3kOOtDWDAVo9Ht4ro6Mo7gRYX7" 
FirebaseData firebaseData;
FirebaseJson json;

Servo myServo;
int servoPin = 18;

#define TN 17
#define NC
#define Hut

void setup()
{
  pinMode (TN, OUTPUT);
  pinMode (SV, OUTPUT);
  pinMode (NC, OUTPUT);
  pinMode (Hut, OUTPUT);
  myServo.attach(servoPin);

  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.println("ket noi"); 
}

String den;
void loop() {

  if (Firebase.get(firebaseData, "/Laysp"))
  {
    if(firebaseData.dataType()=="string"){ 
      lay = firebaseData.stringData();
      if (lay == "sản phẩm 1"){
        Serial.println("san pham 1"); 
        digitalWrite(TN, HIGH);
        delay();
        digitalWrite(TN, LOW);
        myServo.
        

      }
      
    }
  }
  delay(100);
}

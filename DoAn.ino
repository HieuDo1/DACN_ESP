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

// Khai báo đối tượng FirebaseData
FirebaseData firebaseData;
FirebaseJson json;

String valueLay;
String valueGui;


#define SERVO_1_PIN 13
#define SERVO_2_PIN 15
#define SERVO_3_PIN 18
#define relay 25

// Khai báo các biến servo
Servo servo1;
Servo servo2;
Servo servo3;


void nangtay()
{
  // Điều khiển servo
  delay(50);
  servo2.write(20);
  delay(60);
  servo3.write(35);
  delay(60);
  servo2.write(0);
  delay(60);
  servo3.write(60);
  delay(50);
  Serial.println("nang tay");

}
void hatay()
{
  // Điều khiển servoư
  delay(50);
  servo3.write(35);
  delay(60);
  servo2.write(20);
  delay(100);
  servo3.write(15);
  delay(60);
  servo2.write(35);
  delay(60);
  Serial.println("ha tay");
  
}
void hut()
{
  // Hut
  digitalWrite(relay, HIGH);
  Serial.println("hut");
}
void nha()
{ 
  digitalWrite(relay, LOW);
  Serial.println("nha");
}

void xoaytrai1()
{
  servo1.write(135);
  delay(800);
  Serial.println("Xoay trai");
  
}
void xoayphai1()
{
  servo1.write(45);
  delay(800);
  Serial.println("Xoay phai");
}
void xoaytrai2()
{
  servo1.write(180);
  delay(800);
  Serial.println("Xoay trai");
  
}
void xoayphai2()
{
  servo1.write(0);
  delay(800);
  Serial.println("Xoay phai");
}

void xoaythang()
{
  servo1.write(90);
  delay(1000);
  Serial.println("Xoay thang");
 
}

void setup(){ 
  //
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("ket noi wifi"); 
  // 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.println("ket noi firebase"); 

  //
  pinMode(relay, OUTPUT);


  // Khởi tạo các chân điều khiển servo
  servo1.attach(SERVO_1_PIN);
  servo2.attach(SERVO_2_PIN);
  servo3.attach(SERVO_3_PIN);

  servo1.write(90);
  delay(100);
  
  servo2.write(0);
  delay(100);
  
  servo3.write(60);
  delay(100);
  
  // 
  digitalWrite(relay, LOW);

}

void loop() {

delay (20);

  if (Firebase.get(firebaseData, "/LenhLay"))
  {
    if(firebaseData.dataType()=="string")
    { 
      valueLay = firebaseData.stringData();
      if (valueLay == "kho1")
	      {
        Serial.println("Kho 1");
        //
        xoaytrai1();
        delay(1000);
        //
        hatay();
        delay(1000);
        //
        hut();
        delay(2000);
        //
        nangtay();
        delay(1000);
        //
        xoaythang();
        delay(1000);
        //
        hatay();
        delay(1000);
        //
        nha();
        delay(6000);
        //
        nangtay();
        delay(1000);
        //
        Firebase.setString(firebaseData, "/LenhLay"," ");
        Firebase.setString(firebaseData, "/matkhaukho1"," ");
        }
      // Kho 2
      else if (valueLay == "kho2")
	      {
        Serial.println("Kho 2");
        //
        xoayphai1();
        delay(1000);
        //
        hatay();
        delay(1000);
        //
        hut();
        delay(2000);
        //
        nangtay();
        delay(1000);
        //
        xoaythang();
        delay(1000);
        //
        hatay();
        delay(1000);
        //
        nha();
        delay(6000);
        //
        nangtay();
        delay(1000);
        //
        Firebase.setString(firebaseData, "/LenhLay"," ");
        Firebase.setString(firebaseData, "/matkhaukho2"," ");
        }
      // Kho 3
      else if (valueLay == "kho3")
	      {
        Serial.println("Kho 3");
       
        //
        xoaytrai2();
        delay(1000);
        //
        hatay();
        delay(1000);
        //
        hut();
        delay(2000);
        //
        nangtay();
        delay(1000);
        //
        xoaythang();
        delay(1000);

        //
        hatay();
        delay(1000);
        //
        nha();
        delay(6000);
        //
        nangtay();
        delay(1000);
        //
        Firebase.setString(firebaseData, "/LenhLay"," ");
        Firebase.setString(firebaseData, "/matkhaukho3"," ");
        } 
        // Kho 4
      else if (valueLay == "kho4")
	      {
        Serial.println("Kho 4");

        //
        xoayphai2();
        delay(1000);
        //
        hatay();
        delay(1000);
        //
        hut();
        delay(2000);
        //
        nangtay();
        delay(1000);
        //
        xoaythang();
        delay(1000);
        //
        hatay();
        delay(1000);
        //
        nha();
        delay(6000);
        //
        nangtay();
        delay(1000);
        //
        Firebase.setString(firebaseData, "/LenhLay"," ");
        Firebase.setString(firebaseData, "/matkhaukho4"," ");
        }
    }
  }

// Lay do
  if (Firebase.get(firebaseData, "/LenhGui"))
  {
    if(firebaseData.dataType()=="string")
    { 
      valueGui = firebaseData.stringData();
      if (valueGui == "kho 1")
	    {
        Serial.print("kho 1");
        hatay();
        delay (1000);
        hut();
        delay(2000);
        nangtay();
        delay(1000);
        xoaytrai1();
        delay(1000);
        hatay();
        delay(1000);
        nha();
        delay(6000);
        nangtay();
        delay(1000);
        xoaythang();
        delay(1000);
        Firebase.setString(firebaseData, "/LenhGui"," ");
      }
      else if (valueGui == "kho 2")
      {
        Serial.print("kho 2");
        hatay();
        delay (1000);
        hut();
        delay(2000);
        nangtay();
        delay(1000);
        xoayphai1();
        delay(1000);
        hatay();
        delay(1000);
        nha();
        delay(6000);
        nangtay();
        delay(1000);
        xoaythang();
        delay(1000);
        Firebase.setString(firebaseData, "/LenhGui"," ");
      }
      else if (valueGui == "kho 3")
      {
        Serial.print("kho 3");
        hatay();
        delay (1000);
        hut();
        delay(2000);
        nangtay();
        delay(1000);
        xoaytrai2();
        delay(1000);
        hatay();
        delay(1000);
        nha();
        delay(6000);
        nangtay();
        delay(1000);
        xoaythang();
        delay(1000);
        Firebase.setString(firebaseData, "/LenhGui"," ");
      }
      else if (valueGui == "kho 4")
      {
        Serial.print("kho 4");
        hatay();
        delay (1000);
        hut();
        delay(2000);
        nangtay();
        delay(1000);
        xoayphai2();
        delay(1000);
        hatay();
        delay(1000);
        nha();
        delay(6000);
        nangtay();
        delay(1000);
        xoaythang();
        delay(1000);
        Firebase.setString(firebaseData, "/LenhGui"," ");
      }
    }
  }
  delay(100);
}

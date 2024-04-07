#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#include "DFRobot_BloodOxygen_S.h"

#define WIFI_SSID "Test"
#define WIFI_PASSWORD "12345678"
#define API_KEY ""
#define DATABASE_URL ""
#define USER_EMAIL ""
#define USER_PASSWORD ""

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;

DFRobot_BloodOxygen_S_HardWareUart MAX30102(&Serial2, 9600);

void setup()
{

  // database sign in
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("Connecting to wifi..");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("x");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected to IP:");
  Serial.println(WiFi.localIP());

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /*if(Firebase.begin(&config, &auth)){
    Serial.println("Sign in successful");
    signupOk = true;
  }
  else{
    Serial.println("Sign in unsuccessful");
  }*/
  config.token_status_callback = tokenStatusCallback;
  Firebase.begin(&config, &auth);
  Firebase.reconnectNetwork(true);

  // sensor
  while (false == MAX30102.begin())
  {
    Serial.println("\ninit fail!");
    delay(3000);
  }
  Serial.println("init success!");
  Serial.println("start measuring...");
  MAX30102.sensorStartCollect();
}

void loop()
{

  MAX30102.getHeartbeatSPO2();
  Serial.println();
  Serial.print("Heart rate is : ");
  Serial.print(MAX30102._sHeartbeatSPO2.Heartbeat);

  Serial.println();
  MAX30102.getHeartbeatSPO2();
  Serial.print("SPO2 is : ");
  Serial.print(MAX30102._sHeartbeatSPO2.SPO2);

  if (Firebase.ready() && (millis() - sendDataPrevMillis > 5000 || sendDataPrevMillis == 0))
  {

    if (Firebase.RTDB.setInt(&fbdo, "Patients/3100/bpm", MAX30102._sHeartbeatSPO2.Heartbeat))
    {
      Serial.println("\nbpm update Successfull.");
    }
    if (Firebase.RTDB.setInt(&fbdo, "Patients/3100/spO2", MAX30102._sHeartbeatSPO2.SPO2))
    {
      Serial.println("spO2 update Successfull.");
    }
  }
  delay(2000);
}

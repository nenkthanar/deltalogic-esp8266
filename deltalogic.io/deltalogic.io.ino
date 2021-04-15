#include <FS.h> 
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Arduino_JSON.h>
#include <SoftwareSerial.h>
#include "SocketIOClient.h"
#include "program.h"
#include "deltaClient.h"

SoftwareSerial mySerial(12, 14); // RX, TX
#define LED 2
SocketIOClient socket;  
String app_token = "FQ4Ejavpf6cVvN5RZ8";
String appName = "ESP8266_2";
String host = "thanarmq.herokuapp.com";

WiFiClient espClient;
#include "comm.h"
#include "command.h"
#include "callBack.h"
#include "WiFi.h"
deltaClient delta;
    void setup() {
      pinMode(LED,OUTPUT);
      pinMode(13,OUTPUT);
      pinMode(15,OUTPUT);
      Serial.begin(115200);
      mySerial.begin(9600);
      delay(1000);
      WiFiSetup();//Method from class WiFi
      delay(1000);
      if(SPIFFS.begin())
       {
       Serial.println("SPIFFS Initialize....ok");
       }
       else
       {
       Serial.println("SPIFFS Initialization...failed");
       }
       delay(500);
      loadLogs();
      loadProgram();
      String sub_token = app_token + "/dev" ;
      String prog_token = app_token + "/program/dev";
      socket.on(sub_token,socketEvent);
      socket.on(prog_token,program);
      socket.connect(host);
     }
  void loop() {
    socket.monitor();
    serRead();
    }
   

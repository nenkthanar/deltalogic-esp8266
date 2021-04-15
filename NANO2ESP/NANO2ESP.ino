#include <Arduino_JSON.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2); // RX, TX
JSONVar JSONObj;
String JSONSerial ="";
unsigned long last_mill = 100;
void sendSerial(){
  if(JSONSerial == "sensor"){
   JSONObj["name"] = "Analog";
   JSONObj["val1"] = analogRead(A0);
   JSONObj["val2"] = analogRead(A1);
   JSONObj["val3"] = analogRead(A2);
   JSONObj["val4"] = analogRead(A3);
   JSONObj["val5"] = analogRead(A4);
   JSONObj["val6"] = analogRead(A5);
  String  JSONString = JSON.stringify(JSONObj);
  mySerial.println(JSONString);
  mySerial.flush();
  JSONObj = "";
  Serial.println("Data send");
  }
  }

unsigned long last_clear = 10;

void clearSerial(long last,bool start){
last_clear = last;
bool _start = start;
if(_start){
unsigned long cur_clear = millis();
if(cur_clear - last_clear > 1000){
  last_clear = cur_clear;
  JSONSerial ="";
  _start = false;
  Serial.println("Clear Serial");
}
}
}

 void serialRead(){
  if(mySerial.available()){
    char c = mySerial.read();
    JSONSerial += String(c);
    if(c == '\n'){
     Serial.println(JSONSerial);
     JSONSerial = "";
     mySerial.flush();
    }
    }
    }

void command(){
      if(JSONSerial == "rl1off"){
      digitalWrite(4,LOW);
       Serial.println(JSONSerial);
      delay(50);
      JSONSerial = "";
    }
    if(JSONSerial == "rl1on"){
      digitalWrite(4,HIGH);
       Serial.println(JSONSerial);
      delay(50);
      JSONSerial = "";
    }
      if(JSONSerial == "rl2off"){
      digitalWrite(5,LOW);
       Serial.println(JSONSerial);
      delay(50);
      JSONSerial = "";
    }
    if(JSONSerial == "rl2on"){
      digitalWrite(5,HIGH);
       Serial.println(JSONSerial);
      delay(50);
      JSONSerial = "";
    }
        if(JSONSerial == "rl3off"){
      digitalWrite(6,LOW);
       Serial.println(JSONSerial);
      delay(50);
      JSONSerial = "";
    }
    if(JSONSerial == "rl3on"){
      digitalWrite(6,HIGH);
       Serial.println(JSONSerial);
      delay(50);
      JSONSerial = "";
    }
     if(JSONSerial == "rl4off"){
      digitalWrite(7,LOW);
       Serial.println(JSONSerial);
      delay(50);
      JSONSerial = "";
    }
    if(JSONSerial == "rl4on"){
      digitalWrite(7,HIGH);
       Serial.println(JSONSerial);
      delay(50);
      JSONSerial = "";
    }
}
void setup() {
Serial.begin(115200);
mySerial.begin(9600);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
Serial.println("...Starting...");
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
}

void loop() {
sendSerial();
serialRead();
command();
}

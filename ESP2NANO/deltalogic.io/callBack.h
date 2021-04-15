
JSONVar myObject;
void convert(String str,char ssub[50]){
  for(int i =0;i < str.length();i++){
    ssub[i] = str[i];
  }
  }

void program(String prog){
  Serial.println(prog);
   }

void _onconnection(String str){
   if(str == app_token){
      myObject["topic"] = app_token;
      myObject["msg"] =  appName;
      String jsonString = JSON.stringify(myObject);
      socket.emit("thanarmq/response",jsonString);
      digitalWrite(LED,HIGH);
      jsonString = "";
      myObject["topic"] = app_token + "/alarm";
      myObject["msg"] =  "ESP8266_2 Alarm Connection";
      jsonString = JSON.stringify(myObject);
      //socket.emit("thanarmq/response",jsonString);
      return;
      }
      }

void CHEvent1(String str){
   if(str == "CH1"){
      mySerial.println("sensor");
      myObject["topic"] = app_token;
      myObject["msg"] = CH1;
      String jsonString = JSON.stringify(myObject);
      socket.emit("thanarmq/response",jsonString);
      return;
      }
      }

void CHEvent2(String str){
   if(str == "CH2"){
         mySerial.println("sensor");
      myObject["topic"] = app_token;
      myObject["msg"] = CH2;
      String jsonString = JSON.stringify(myObject);
      socket.emit("thanarmq/response",jsonString);
       return;
      }
      }
     
void CHEvent3(String str){
   if(str == "CH3"){
         mySerial.println("sensor");
      myObject["topic"] = app_token;
      myObject["msg"] = CH3;
      String jsonString = JSON.stringify(myObject);
      socket.emit("thanarmq/response",jsonString);
       return;
      }
      }
      
void CHEvent4(String str){
   if(str == "CH4"){
         mySerial.println("sensor");
      JSONVar myObject;
      myObject["topic"] = app_token;
      myObject["msg"] = CH4;
      String jsonString = JSON.stringify(myObject);
      socket.emit("thanarmq/response",jsonString);
      return;
      }
      }
      
void CHEvent5(String str){
   if(str == "CH5"){
         mySerial.println("sensor");
      myObject["topic"] = app_token;
      myObject["msg"] = CH5;
      String jsonString = JSON.stringify(myObject);
      socket.emit("thanarmq/response",jsonString);
      return;
      }
      }

void CHEvent6(String str){
   if(str == "CH6"){
         mySerial.println("sensor");
      myObject["topic"] = app_token;
      myObject["msg"] = CH6;
      String jsonString = JSON.stringify(myObject);
      socket.emit("thanarmq/response",jsonString);
      return;
      }
      }

void socketEvent(String message) {
   digitalWrite(LED,HIGH);
      socket.monitor();
      CHEvent1(message);
      CHEvent2(message);
      CHEvent3(message);
      CHEvent4(message);
      CHEvent5(message);
      CHEvent6(message);
      _onconnection(message);
      manualCTRL(message);
      //addProgram(payload,message);
      myObject = "";
     }

   

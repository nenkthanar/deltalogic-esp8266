  
  int CH1 = 0;
  int CH2 = 0;
  int CH3 = 0;
  int CH4 = 0;
  int CH5 = 0;
  int CH6 = 0;
  String JSONSerial = "";
  JSONVar JSONObj;
  void serRead(){
      if(mySerial.available()){
      char c = mySerial.read();
      JSONSerial += String(c);
      if(c == '\n'){
      JSONObj = JSON.parse(JSONSerial);
      CH1 = int(JSONObj["val1"]);
      CH2 = int(JSONObj["val2"]);
      CH3 = int(JSONObj["val3"]);
      CH4 = int(JSONObj["val4"]);
      CH5 = int(JSONObj["val5"]);
      CH6 = int(JSONObj["val6"]);
      JSONSerial = "";
      digitalWrite(LED,HIGH);
      JSONObj = "";
      }
      }
      }


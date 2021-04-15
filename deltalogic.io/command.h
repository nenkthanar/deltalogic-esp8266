String relayState[] = {"off","off","off","off","off","off"};

void manualCTRL(String str){
  JSONVar myObject;
  myObject["topic"] = app_token+"/button_state";
  if(str == app_token + "btn1on"){
    relayState[0] = "on";
    Serial.println("Realay1 On");
    mySerial.println("rl1on");
    myObject["msg"] =  "btn1off";
    String jsonString = JSON.stringify(myObject);
    socket.emit("thanarmq/response",jsonString);
    }
  if(str == app_token + "btn1off"){
    relayState[0] = "off";
    Serial.println("Realay1 Off");
    mySerial.println("rl1off");
    myObject["msg"] =  "btn1on";
    String jsonString = JSON.stringify(myObject);
    socket.emit("thanarmq/response",jsonString);
    }

  if(str == app_token + "btn2on"){
    relayState[1] = "on";
    Serial.println("Realay2 On");
    mySerial.println("rl2on");
    myObject["msg"] =  "btn2off";
    String jsonString = JSON.stringify(myObject);
    socket.emit("thanarmq/response",jsonString);
  }
  if(str == app_token + "btn2off"){
   relayState[1] = "off";
   Serial.println("Realay2 Off");
   mySerial.println("rl2off");
   myObject["msg"] =  "btn2on";
   String jsonString = JSON.stringify(myObject);
   socket.emit("thanarmq/response",jsonString);
  }

  if(str == app_token + "btn3on"){
   relayState[2] = "on";
    Serial.println("Realay3 On");
   mySerial.println("rl3on");
   myObject["msg"] =  "btn3off";
   String jsonString = JSON.stringify(myObject);
   socket.emit("thanarmq/response",jsonString);
  }
  if(str == app_token + "btn3off"){
   relayState[2] = "off";
    Serial.println("Realay3 Off");
   mySerial.println("rl3off");
   myObject["msg"] =  "btn3on";
   String jsonString = JSON.stringify(myObject);
   socket.emit("thanarmq/response",jsonString);
  }

  if(str == app_token + "btn4on"){
   relayState[3] = "on";
    Serial.println("Realay4 On");
   mySerial.println("rl4on");
   myObject["msg"] =  "btn4off";
   String jsonString = JSON.stringify(myObject);
   socket.emit("thanarmq/response",jsonString);
  }
  if(str == app_token + "btn4off"){
   relayState[3] = "off";
    Serial.println("Realay4 Off");
   mySerial.println("rl4off");
   myObject["msg"] =  "btn4on";
   String jsonString = JSON.stringify(myObject);
   socket.emit("thanarmq/response",jsonString);
  }

  if(str == app_token + "btn5on"){
   relayState[4] = "on";
    Serial.println("Realay5 On");
    digitalWrite(13,HIGH);
   myObject["msg"] =  "btn5off";
   String jsonString = JSON.stringify(myObject);
   socket.emit("thanarmq/response",jsonString);
  }
  if(str == app_token + "btn5off"){
   relayState[4] = "off";
    Serial.println("Realay5 Off");
     digitalWrite(13,LOW);
   myObject["msg"] =  "btn5on";
   String jsonString = JSON.stringify(myObject);
   socket.emit("thanarmq/response",jsonString);
  }

  if(str == app_token + "btn6on"){
   relayState[5] = "on";
    Serial.println("Realay6 On");
   digitalWrite(15,HIGH);
   myObject["msg"] =  "btn6off";
   String jsonString = JSON.stringify(myObject);
   socket.emit("thanarmq/response",jsonString);
  }
  if(str == app_token + "btn6off"){
   relayState[5] = "off";
    Serial.println("Realay6 Off");
   digitalWrite(15,LOW);
   myObject["msg"] =  "btn6on";
   String jsonString = JSON.stringify(myObject);
   socket.emit("thanarmq/response",jsonString);
  }
}


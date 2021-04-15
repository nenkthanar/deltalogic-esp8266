
#include "deltaClient.h"

deltaClient::deltaClient(){
  Serial.println("Starting deltalogic.io");
}

void deltaClient::eventHandler(String data){
  Serial.println(data);
}






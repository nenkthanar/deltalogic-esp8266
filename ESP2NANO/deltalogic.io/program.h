String convertByte(byte* payload,int length){
     String message = "";
     for (int i = 0; i < length; i++) {
     message = message + (char)payload[i];  //Conver *byte to String
     }
     return message;
    }
    
String loadLogs(){
    String logs = "";
    File f = SPIFFS.open("/logsdata.txt", "r");
    if (!f) {
      Serial.println("No logs data found!");
    }
    else
    {
    String str;
    for(int i=0;i<f.size();i++) 
    {
    str+=(char)f.read();
    }
    logs = str;
    f.close();  
    }
    return logs;
    }


String loadProgram(){
    String program = "";
    File f = SPIFFS.open("/program.txt", "r");
    if (!f) {
      Serial.println("No program found!");
    }
    else
    {
    String str;
    for(int i=0;i<f.size();i++) 
    {
    str+=(char)f.read();
    }
    program = str;
    f.close();  
    }
    return program;
    }
    
String convertProg(const char* data,int length){
    String out ="";
    for(int i =0;i<length;i++){
      out = out + data[i];
    }
    return out;
    }
    
void addProgram(byte* data,String msg){
    if(data[3] == 'p' && data[4] == 'r'){
     JSONVar pars;
     pars = JSON.parse(msg);
     Serial.println("Program in : " + msg);
     const char* prog = pars[0]["program"];
     Serial.println(convertProg(prog,strlen(prog)));
    }
    }


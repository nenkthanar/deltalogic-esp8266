
#ifndef deltaClient_H
#define deltaClient_H


#include "Arduino.h"

class deltaClient {
  public:
        deltaClient();
        void connection(String data);
        void analog1(String data);
        void analog2(String data);
        void analog3(String data);
        void analog4(String data);
        void analog5(String data);
        void analog6(String data);
        void amt1001(String data);
        void dht22(String data);
        void eventHandler(String data);
};

#endif // SocketIoClient_H





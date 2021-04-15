
#ifndef SocketIoClient_H
#define SocketIoClient_H

#include "Arduino.h"
#ifndef ioDebug
#define ioDebug true
#endif

#ifdef W5100
#include <Ethernet.h>
#include "SPI.h"					//For W5100
#endif

#ifdef ENC28J60
#include <UIPEthernet.h>
#include "SPI.h"					//For ENC28J60
#endif

#ifdef ESP8266
#include <ESP8266WiFi.h>			//For ESP8266
#endif

#if !defined(W5100) && !defined(ENC28J60) && !defined(ESP8266)	//If no interface is defined
#error "Please specify an interface such as W5100, ENC28J60, or ESP8266"
#error "above your includes like so : #define ESP8266 "
#endif

// Length of static data buffers
#define DATA_BUFFER_LEN 512
#define SID_LEN 24

typedef void (*functionPointer)(String data);
#define MAX_ON_HANDLERS 8
#define MAX_HOSTNAME_LEN 500
#define PING_INTERVAL 2000
class SocketIOClient {
  public:
        SocketIOClient();
        bool connect(String thehostname, int port = 80);
        bool connectHTTP(String thehostname, int port = 80);
        bool connected();
        void disconnect();
        bool reconnect(String thehostname, int port = 80);
        bool monitor();
        void emit(String id, String data);
        void on(String id, functionPointer f);
        void heartbeat(int select);
        void getREST(String path);
        void postREST(String path, String type, String data);
        void putREST(String path, String type, String data);
        void deleteREST(String path);
        private:
        void eventHandler(int index);
        void sendHandshake(char hostname[]);

        //EthernetClient internets;				//For ENC28J60 or W5100
        WiFiClient internets;			  			//For ESP8266
        bool readHandshake();
        void readLine();
        char *dataptr;
        char databuffer[DATA_BUFFER_LEN];
        char sid[SID_LEN];
        char key[28];
        char hostname[128];
        int port;

        bool waitForInput(void);
        void eatHeader(void);

        functionPointer onFunction[MAX_ON_HANDLERS];
        String onId[MAX_ON_HANDLERS];
        uint8_t onIndex = 0;
};

#endif // SocketIoClient_H





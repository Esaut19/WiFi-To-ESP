#include <ESP8266WiFi.h>
#include <strings_en.h>
#include <WiFiManager.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <Ticker.h>

#define pinLedWifi D4 //led integrado
//instancia a la clase Ticker
Ticker ticker;

void parpadeoLedWifi(){
  //estado de Led
  byte estado= digitalRead (pinLedWifi);
  digitalWrite (pinLedWifi, !estado);
   }
void conectaWiFi_EJC()
{
  // Inicia Serial
  Serial.begin(115200);
  //Modo del pin
  pinMode (pinLedWifi, OUTPUT);
  //Empezamos el temporizador
  ticker.attach (0.2, parpadeoLedWifi);

  //Creamos una instancia WifiManager
  WiFiManager wifiManager;

  //Resetear
  //WiFiManager.resetSettings();

  //Creamos AP y portal 
  //wifiManager.autoConnect ("Aukde_Syspre", "123456789");
if(!wifiManager.autoConnect("Aukde_Syspre")){
  Serial.println ("Fallo en la conexión");
  ESP.reset();
  delay(1000);
}
  Serial.println("Syspre Conectado");
  //Eliminamos el temporizador
  ticker.detach();

  //Apagamos LED
 digitalWrite (pinLedWifi, HIGH);
}
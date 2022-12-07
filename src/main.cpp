/* -------------------------------------------------------------------
* AdminESP - Angel Ropero 2022
* Sitio Web:
* e-mail: angel.ropero.pena@gmail.com
* Plataforma ESP32
* Proyecto Admin Panel Tool para el ESP32
* --------------------------------------------------------------------
*/

// -------------------------------------------------------------------
// Librerías
// -------------------------------------------------------------------
#include <Arduino.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>

// -------------------------------------------------------------------
// Archivos *.hpp - Fragmentar el código
// -------------------------------------------------------------------
#include "settings.hpp"
#include "funtions.hpp"
#include "settingsReset.hpp"
#include "settingsRead.hpp"
#include "settingsSave.hpp"
#include "esp32_wifi.hpp"
#include "esp32_mqtt.hpp"

// -------------------------------------------------------------------
// Librerías
// -------------------------------------------------------------------
void setup() {
  
  Serial.begin (115200);            //Baudrate
  setCpuFrequencyMhz (240);         //CPU Frequency
  log ("\nInfo: Iniciando Setup");  //Inicio del Log por serial
  settingPines ();                  //Configuración de los Pines
  //Inicio del SPIFFS
  if (!SPIFFS.begin(true)) {        //ATENCIÓN!!! Hay que poner el "true" dentro del begin, ya que si no da un error de que no se puede inicializar.
    log ("Error: Falló la inicialización del SPIFFS");
    //ATENCIÓN!!!! QUITAR ESTO POR DIOS...
    while (true);
  }
  //Lee los estados de los Relays
  settingsReadRelays ();
  //Paso estados a los pines Relays
  setOnOffSingle (RELAY1, Relay01_status);
  setOnOffSingle (RELAY2, Relay02_status);
  //Lee la configuración WiFi.
  settingsReadWiFi ();              //Lee la Configuración WiFi.   
  WiFi.disconnect (true);
  delay (1000);
  wifi_setup ();                    //Setup del WiFi.
  settingsReadMQTT ();              //Lee la Configuración WiFi.   
}

void loop () {
  yield ();

  if (wifi_mode == WIFI_STA) {
    wifiLoop ();
  }
  if (wifi_mode == WIFI_AP) {
    wifiAPLoop ();
  }
  // -------------------------------------------------------------------
  // MQTT
  // -------------------------------------------------------------------
  if ((WiFi.status() == WL_CONNECTED) && (wifi_mode == WIFI_STA)) {
      if (mqtt_server != 0) { 
          mqttLoop();
          if (mqttclient.connected ()) {
              if (millis() - lastMsg > mqtt_time) {
                  lastMsg = millis();
                  mqtt_publish();
              }
          }      
      }
  }
}
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
  settingsReadWiFi ();              //Lee la Configuración WiFi.   
  WiFi.disconnect (true);
  delay (1000);
  wifi_setup ();                    //Setup del WiFi.
}

void loop() {
  yield ();

  if (wifi_mode == WIFI_STA) {
    wifiLoop ();
  }
  if (wifi_mode == WIFI_AP) {
    wifiAPLoop ();
  }
}
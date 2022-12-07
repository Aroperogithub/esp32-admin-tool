/* -------------------------------------------------------------------
* AdminESP - Angel Ropero 2022
* Sitio Web:
* e-mail: angel.ropero.pena@gmail.com
* Plataforma ESP32
* Proyecto Admin Panel Tool para el ESP32
* --------------------------------------------------------------------
*/
// -------------------------------------------------------------------
// Guardar los estados de los Relays
// -------------------------------------------------------------------
boolean settingsSaveRelays (void) {
    // Guarda configuración de los Relays
    StaticJsonDocument<200> jsonConfig;
    File file = SPIFFS.open(F("/settingrelays.json"), "w+");

    if (file) {
        jsonConfig["Relay01_status"] = Relay01_status;
        jsonConfig["Relay02_status"] = Relay02_status;
        serializeJsonPretty(jsonConfig, file);
        file.close();
        log(F("Info: Estado de los Relay guardado"));
        serializeJsonPretty(jsonConfig, Serial);            //Esto es para sacar el archivo por el puerto Serie.
        return true;
    } else {
        log(F("Error: Falló el guardado del estado de los Relay"));
        return false;
    }
}

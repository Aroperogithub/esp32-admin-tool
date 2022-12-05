/* -------------------------------------------------------------------
* AdminESP - Angel Ropero 2022
* Sitio Web:
* e-mail: angel.ropero.pena@gmail.com
* Plataforma ESP32
* Proyecto Admin Panel Tool para el ESP32
* --------------------------------------------------------------------
*/

boolean settingsReadWiFi () {
    StaticJsonDocument<500> jsonConfig;                 //Se crea un Documento JSON con 500 bytes.
    File file = SPIFFS.open ("/SettingWifi.json", "r");
    if (deserializeJson (jsonConfig, file)) {
        //Si falla la lectura inicia valores por defecto
        settingResetWiFi ();
        log ("Error: Falló la lectura de la configuración WiFi, tomando valores por defecto");
        return false;
    } else {
        /* -------------------- GENERAL ----------------------------*/
        strlcpy (id, jsonConfig["id"], sizeof(id));
        bootCount = jsonConfig["boot"];
        /* -------------------- CLIENTE ----------------------------*/
        wifi_staticIP = jsonConfig["wifi_staticIP"];
        strlcpy(wifi_ssid, jsonConfig["wifi_ssid"], sizeof(wifi_ssid));
        strlcpy(wifi_password, jsonConfig["wifi_password"], sizeof(wifi_password));
        strlcpy(wifi_ip_static, jsonConfig["wifi_ip_static"], sizeof(wifi_ip_static));
        strlcpy(wifi_gateway, jsonConfig["wifi_gateway"], sizeof(wifi_gateway));
        strlcpy(wifi_subnet, jsonConfig["wifi_subnet"], sizeof(wifi_subnet));
        strlcpy(wifi_primaryDNS, jsonConfig["wifi_primaryDNS"], sizeof(wifi_primaryDNS));
        strlcpy(wifi_secondaryDNS, jsonConfig["wifi_secondaryDNS"], sizeof(wifi_secondaryDNS));
        /* ----------------------- AP ------------------------------*/
        ap_accessPoint = jsonConfig["ap_accessPoint"];
        strlcpy(ap_nameap, jsonConfig["ap_nameap"], sizeof(ap_nameap));
        strlcpy(ap_passwordap, jsonConfig["ap_passwordap"], sizeof(ap_passwordap));
        ap_canalap = jsonConfig["ap_canalap"];
        ap_hiddenap = jsonConfig["ap_hiddenap"];
        ap_connetap = jsonConfig["ap_connetap"];
        file.close ();
        log ("Info: Lectura configuración WiFi Correcta");
        return true;
    }
}
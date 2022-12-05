/* -------------------------------------------------------------------
* AdminESP - Angel Ropero 2022
* Sitio Web:
* e-mail: angel.ropero.pena@gmail.com
* Plataforma ESP32
* Proyecto Admin Panel Tool para el ESP32
* --------------------------------------------------------------------
*/

// -------------------------------------------------------------------
// Definiciones
// -------------------------------------------------------------------

#define RELAY1  27                      //GPIO27 para salida de Relay 1
#define RELAY2  26                      //GPIO26 para salida de Relay 2
#define WIFILED 12                      //GPIO12 LED indicador WiFi
#define MQTTLED 13                      //GPIO13 LED indicador MQTT

// -------------------------------------------------------------------
// Versión del Hardware
// -------------------------------------------------------------------
#define HW "ADMINESP32 v1 00000000"     //Versión del HW.

// -------------------------------------------------------------------
// Zona WiFi
// -------------------------------------------------------------------
boolean     wifi_staticIP;             //Uso de IP Estática
char        wifi_ssid[30];             //Red WiFi
char        wifi_password[30];         //Contraseña de Red WiFi
char        wifi_ip_static[15];        //IP estático
char        wifi_gateway[15];          //Gateway
char        wifi_subnet[15];           //Subred
char        wifi_primaryDNS[15];       //DNS Primario
char        wifi_secondaryDNS[15];     //DNS Secundario

// -------------------------------------------------------------------
//Zona Configuración General 
// -------------------------------------------------------------------
char        id[30];                     //ID del dispositivo
int         bootCount;                  //Número de reinicios

// -------------------------------------------------------------------
// Zona AP
// -------------------------------------------------------------------
boolean     ap_accessPoint;             //Uso de Modo AP
char        ap_nameap[30];              //SSID AP
char        ap_passwordap[63];          //Contraseña de AP
int         ap_canalap;                 //Canal AP
int         ap_hiddenap;                //Es visible o no el AP (0 - Visible / 1 - Oculto)
int         ap_connetap;                //Número de conexiones en el AP.

// Zona Otras
uint8_t ip[4];                          // Variable función convertir string a IP.
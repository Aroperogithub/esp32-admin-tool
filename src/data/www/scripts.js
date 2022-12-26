/* habilitar o deshabilitar los input a la hora de la carga del html */
function mqtt() {
    var x = document.getElementById("mqtten");
    if (x.value == "1") {
        formDisableFalse("mqtt");
    } else {
        formDisableTrue("mqtt");
    }
}
/* Habilitar input WIFI/AP segun estado */
function wifi() {
    var ip = document.getElementById("wifi_staticIPen");
    var ap = document.getElementById("ap_AP_en");
    if (ip.value == "1") {
        formDisableFalse("ip");
    } else {
        formDisableTrue("ip");
    }
    if (ap.value == "1") {
        formDisableFalse("ap");
    } else {
        formDisableTrue("ap");
    }
}
/* ------------------- Habilitar MQTT -------------------- */
function mqttenable () {
    if (document.getElementById("mqtt_enable").checked) {
        document.getElementById("mqtten").value = 1;
        formDisableFalse("mqtt");
    } else {
        document.getElementById("mqtten").value = 0;
        formDisableTrue("mqtt");
    }
}
/* ----------- Habilitar IP Estática ------------------ */
function staticIPen() {
    if (document.getElementById("wifi_staticIP").checked) {
        document.getElementById('wifi_staticIPen').value = 1;   //Cuando lo cambie a 1 debo deshabilitarlo.
        formDisableFalse("ip");                                 //Esta es la clase que debo haber definido como: class="form-control ip" y que debe ir en todos los campos a los que afecte.
    } else {
        document.getElementById('wifi_staticIPen').value = 0;   //Cuando lo cambie a 0 debo habilitarlo.
        formDisableTrue("ip");                                  //Esta es la clase que debo haber definido como: class="form-control ip" y que debe ir en todos los campos a los que afecte.
    }
}
/* ------------------- Habilitar AP -------------------- */
function apenable() {
    if (document.getElementById("ap_accessPoint").checked) {
        document.getElementById('ap_AP_en').value = 1;
        formDisableFalse("ap");
    } else {
        document.getElementById('ap_AP_en').value = 0;
        formDisableTrue("ap");
    }
}
/* -------- Habilitar AP Visible (0) No (1) ------------ */
function visibilityen() {
    if (document.getElementById("ap_hiddenap").checked) {
        document.getElementById('ap_visibility').value = 0;
    } else {
        document.getElementById('ap_visibility').value = 1;
    }
}
/* Quitar el disabled de los input */
function formDisableFalse(clase) {
    var formElement = document.getElementsByClassName(clase);
    for (var i = 0; i < formElement.length; i++)
        formElement[i].disabled = false;
}
/* Habilitar el disabled de los input */
function formDisableTrue(clase) {
    var formElement = document.getElementsByClassName(clase);
    for (var i = 0; i < formElement.length; i++)
        formElement[i].disabled = true;
}
/* Limpiar Formulario */
function clearAdmin() {
    document.getElementById("formulario").reset();
}
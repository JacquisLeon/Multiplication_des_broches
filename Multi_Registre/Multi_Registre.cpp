
#include "Multi_Registre.h"
#include "Arduino.h"

Multi_Registre::Multi_Registre(char shcp, char ds, char stcp, int nombreRegistres) {
    SHCP = shcp;
    DS = ds;
    STCP = stcp;
    this->nombreRegistres = nombreRegistres;

    pinMode(SHCP, OUTPUT);
    pinMode(DS, OUTPUT);
    pinMode(STCP, OUTPUT);

    // Allouer de la mémoire pour le tableau values en fonction du nombre de registres
    values = new uint8_t[nombreRegistres];

    // Initialiser les valeurs à 0 (LOW) pour toutes les broches de tous les registres
    for (int i = 0; i < nombreRegistres; i++) {
        values[i] = 0;
    }
}

void Multi_Registre::write(char pin, bool status) {
    if (pin >= 0 && pin < nombreRegistres * 8) {  // Vérifier si pin est dans la plage valide
        int registreIndex = pin / 8;  // Calculer l'indice du registre
        int bitIndex = pin % 8;       // Calculer l'indice du bit dans le registre

        bitWrite(values[registreIndex], bitIndex, status);  // Modifier l'état du bit spécifié

        // Écrire les valeurs mises à jour dans les registres à décalage
        digitalWrite(STCP, LOW);
        for (int i = nombreRegistres - 1; i >= 0; i--) {
            shiftOut(DS, SHCP, MSBFIRST, values[i]);  // ShiftOut les valeurs de chaque registre
        }
        digitalWrite(STCP, HIGH);
    }
}

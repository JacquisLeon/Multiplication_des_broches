

#ifndef Multi_Registre_h
#define Multi_Registre_h

#include "Arduino.h"

class Multi_Registre {
public:
    Multi_Registre(char shcp, char ds, char stcp, int nombreRegistres);
    void write(char pin, bool status);
    
private:
    int SHCP;
    int DS;
    int STCP;
    int nombreRegistres;  // Nombre de registres à décalage
    uint8_t* values;      // Tableau dynamique pour stocker les états des broches
};

#endif

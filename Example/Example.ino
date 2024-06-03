#include<Multi_Registre.h>

int shcp = 4;
int ds = 3;
int stcp = 2;
int nombre_des_registres = 3;

Multi_Registre registre(shcp,ds,stcp,nombre_des_registres);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  for(int i=0 ; i<24 ; i++)
    {
      registre.write(i,HIGH);
      delay(300);
    }
    
     for(int i=24 ; i>0 ; i--)
    {
      registre.write(i,LOW);
      delay(300);
    }
}

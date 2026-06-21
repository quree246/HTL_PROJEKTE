#include "drohne.h"
#include <string>
#include <iostream>
int drohne::naechsteseriennummer = 7000;
int drohne::anzahldrohnen = 0;
drohne::drohne(std::string modell, int akku){
    this->modell = modell;
    this->akku = akku;
    seriennummer = naechsteseriennummer;
    naechsteseriennummer++;
    anzahldrohnen++;

}
drohne::~drohne(){

    anzahldrohnen--;
    std::cout << "drohne: " << modell << " abgemeldet." << std::endl;

}
int drohne::laden(int prozent){
    if (prozent > 0 && prozent < 100)
    {
        akku += prozent;
    }
    return akku;
    
}
int drohne::fliegen(int prozent){
    if (prozent > 0)
    {
       akku -= prozent;
    }
    return akku;
    
}
int drohne::getakku(){
    return akku;
}
void drohne::ausgeben(){
    std::cout << "seriennummer: " << seriennummer << " modell: " << modell << " akku: " << akku << std::endl;
}
int drohne::getanzahldrohnen(){
    return anzahldrohnen;
}
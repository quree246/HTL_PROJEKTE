#pragma once
#include <string>

class drohne{
    private:
    std::string modell;
    int akku;
    int seriennummer;
    static int naechsteseriennummer;
    static int anzahldrohnen;
    public:

    drohne(std::string modell, int akku);
    ~drohne();
    int laden(int prozent);
    int fliegen(int prozent);
    int getakku();
    void ausgeben();
    static int getanzahldrohnen();

};
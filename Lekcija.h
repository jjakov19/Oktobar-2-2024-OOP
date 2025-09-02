#pragma once
#include <iostream>
using namespace std;
#include "IspitniMaterijal.h"
class Lekcija :
    public IspitniMaterijal
{
private:
    double duzinaStranica;
public:
    Lekcija();
    Lekcija(int oznaka, double tezina,double duzina);
    Lekcija(const Lekcija& l);
    ~Lekcija();
    ostream& Prikazi(ostream& os)override;
    void setujDuzinu(double duz) { duzinaStranica = duz; }
    double vratiDuz() { return duzinaStranica; }
    float ukVreme(float proc);
};


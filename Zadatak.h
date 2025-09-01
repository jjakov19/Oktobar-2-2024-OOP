#pragma once
#include <iostream>
using namespace std;
#include "IspitniMaterijal.h"
class Zadatak :
    public IspitniMaterijal
{
private:
    int brojLinija;
public:
    Zadatak();
    Zadatak(int oznaka, double tezina, int brojLinija);
    Zadatak(const Zadatak& z);
    ~Zadatak(){}
    ostream& Prikazi(ostream& os)override;
    void setujLinija(int lin) { brojLinija = lin; }
    double vratiLin() { return brojLinija; }
};


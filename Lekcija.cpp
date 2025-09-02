#include <iostream>
using namespace std;
#include "Lekcija.h"


Lekcija::Lekcija() :IspitniMaterijal(){
	duzinaStranica = 0;
}
Lekcija::Lekcija(int oznaka, double tezina, double duzina) :IspitniMaterijal(oznaka, tezina) {
	duzinaStranica = duzina;
}
Lekcija::Lekcija(const Lekcija& l) {
	this->oznaka = l.oznaka;
	this->tezina = l.tezina;
	this->status = l.status;
	this->duzinaStranica = l.duzinaStranica;
}
Lekcija::~Lekcija(){}
float Lekcija::ukVreme(float proc) {
	float ukVr = 0;
	ukVr = duzinaStranica * tezina * proc;
	return ukVr;
}

ostream& Lekcija::Prikazi(ostream& os) {
	os << "Oznaka: " << oznaka << " Tezina: " << tezina << " Status: " << status << " Duzina: " << duzinaStranica << endl;
	return os;
}

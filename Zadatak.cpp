#include "Zadatak.h"
#include <iostream>
using namespace std;

Zadatak::Zadatak() :IspitniMaterijal() {
	brojLinija = 0;
}
Zadatak::Zadatak(int oznaka, double tezina, int brojLinija) :IspitniMaterijal(oznaka, tezina) {
	this->brojLinija = brojLinija;
}
Zadatak::Zadatak(const Zadatak& z) {
	this->oznaka = z.oznaka;
	this->tezina = z.tezina;
	this->status = z.status;
	this->brojLinija = z.brojLinija;
}
ostream& Zadatak::Prikazi(ostream& os) {
	os << "Oznaka: " << oznaka << " Tezina: " << tezina << " Status: " << status << " Broj linija: " << brojLinija << endl;
	return os;
}

#include "IspitniMaterijal.h"
#include <iostream>
using namespace std;

IspitniMaterijal::IspitniMaterijal():oznaka(0),tezina(0),status(false){}

IspitniMaterijal::IspitniMaterijal(int oznaka, double tezina):oznaka(oznaka),tezina(tezina),status(false){}

IspitniMaterijal::IspitniMaterijal(const IspitniMaterijal& im) {
	this->oznaka = im.oznaka;
	this->tezina = im.tezina;
	this->status = im.status;
}
IspitniMaterijal::~IspitniMaterijal(){}

ostream& operator<<(ostream& os, IspitniMaterijal& im) {
	im.Prikazi(os);
	return os;
}
ostream& IspitniMaterijal::Prikazi(ostream& os) {
	os << "Oznaka: " << oznaka << " Tezina: " << tezina << " Status: " << status << endl;
	return os;
}
void IspitniMaterijal::setujStatus(bool a) {
	status = a;
}
void IspitniMaterijal::setujOznaku(int oz) {
	oznaka = oz;
}
void IspitniMaterijal::setujTezinu(double tez) {
	tezina = tez;
}
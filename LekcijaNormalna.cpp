#define _CRT_SECURE_NO_WARNINGS
#include "LekcijaNormalna.h"
#include <iostream>
using namespace std;

LekcijaNormalna::LekcijaNormalna() {
	naziv = nullptr;
	duzina = 0;
	procTez = 0;
}
LekcijaNormalna::LekcijaNormalna(const char* naz, float duz, float proc) {
	naziv = new char[strlen(naz) + 1];
	strcpy(naziv, naz);
	duzina = duz;
	procTez = proc;
}
LekcijaNormalna::LekcijaNormalna(const LekcijaNormalna& n) {
	this->naziv = new char[strlen(n.naziv) + 1];
	strcpy(this->naziv, n.naziv);
	this->duzina = n.duzina;
	this->procTez = n.procTez;
}
LekcijaNormalna::~LekcijaNormalna() {
	delete[] naziv;
}
ostream& operator<<(ostream& os, LekcijaNormalna& l) {
	l.prikazi(os);
	return os;
}
istream& operator>>(istream& ulaz, LekcijaNormalna& l) {
	l.upisi(ulaz);
	return ulaz;
}
ostream& LekcijaNormalna::prikazi(ostream& os) {
	os << "Naziv: " << naziv << " Duzina: " << duzina << " ProcTez: " << procTez << endl;
	return os;
}
istream& LekcijaNormalna::upisi(istream& is) {
	is >> this->naziv >> this->duzina >> this->procTez;
	return is;
}
void LekcijaNormalna::setujTez(float t) {
	this->procTez = t;
}
void LekcijaNormalna::setujDuz(float duz) {
	this->duzina = duz;
}
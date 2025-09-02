#define _CRT_SECURE_NO_WARNINGS
#include "LekcijaNormalna.h"
#include <iostream>
using namespace std;

LekcijaNormalna::LekcijaNormalna() {
	naziv = new char[1];
	naziv[0] = '\0';
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
	os<< naziv <<" " << duzina << " " << procTez << endl;
	return os;
}
istream& LekcijaNormalna::upisi(istream& is) {
	char tempNaziv[100];
	is >> tempNaziv >> duzina >> procTez;

	delete[] naziv;  // DODAJTE OVO!
	naziv = new char[strlen(tempNaziv) + 1];
	strcpy(naziv, tempNaziv);

	return is;
}
void LekcijaNormalna::setujTez(float t) {
	this->procTez = t;
}
void LekcijaNormalna::setujDuz(float duz) {
	this->duzina = duz;
}

LekcijaNormalna& LekcijaNormalna::operator=(const LekcijaNormalna& other) {
	if (this != &other) {
		delete[] naziv;
		this->naziv = new char[strlen(other.naziv) + 1];
		strcpy(naziv, other.naziv);
		this->duzina = other.duzina;
		this->procTez = other.procTez;
	}
	return *this;
}
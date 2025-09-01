#include "IspitPriprema.h"
#include "IspitniMaterijal.h"
#include "Zadatak.h"
#include "Lekcija.h"
#include <iostream>
using namespace std;

IspitPriprema::IspitPriprema() {
	niz = nullptr;
	maxBr = 0;
	trBr = 0;
}
IspitPriprema::IspitPriprema(int max) {
	trBr = 0;
	maxBr = max;
	niz = new IspitniMaterijal * [maxBr];
	for (int i = 0; i < maxBr; i++) {
		niz[i] = nullptr;
	}
}
IspitPriprema::IspitPriprema(const IspitPriprema& ip) {
	this->maxBr = ip.maxBr;
	this->trBr = ip.trBr;
	this->niz = new IspitniMaterijal * [this->maxBr];
	for (int i = 0; i < trBr; i++) {
		this->niz[i] =ip.niz[i];
	}
	for (int i = trBr; i < maxBr; i++) {
		this->niz[i] = nullptr;
	}
}
IspitPriprema::~IspitPriprema() {
	for (int i = 0; i < trBr; i++) {
		delete niz[i];
	}
	delete[]niz;
}
void IspitPriprema::Dodaj(IspitniMaterijal* ip) {
	if (trBr >= maxBr) {
		return;
	}
	for (int i = 0; i < trBr; i++) {
		if (niz[i]->vratiOznaku() == ip->vratiOznaku()) {
			cout << "Ne sme biti ista oznaka!" << endl;
			return;
		}
	}
	niz[trBr++] = ip;
}
ostream& operator<<(ostream& os, IspitPriprema& ip) {
	ip.print(os);
	return os;
}
ostream& IspitPriprema::print(ostream& os) {
	os << "Sadrzaj IspitPriprema: " << endl;
	for (int i = 0; i < trBr; i++) {
		niz[i]->Prikazi(os);
	}
	return os;
}
void IspitPriprema::Obrisi(int br) {
	if (br < 0) {
		return;
	}
	int indeks;
	for (int i = 0; i < trBr; i++) {
		if (niz[i]->vratiOznaku() == br && !niz[i]->vratiStatus()) {
			delete niz[i];
			indeks = i;
		}
	}
	for (int i = indeks; i < maxBr-1; i++) {
		niz[i] = niz[i+1];
	}
	trBr--;
}

void IspitPriprema::Savladaj(int br) {
	if (br < 0) {
		return;
	}
	niz[br]->setujStatus(true);
}
int IspitPriprema::UkupnoSavladanih() {
	int ukSv = 0;
	for (int i = 0; i < trBr; i++) {
		if (niz[i]->vratiStatus()) {
			ukSv++;
		}
	}
	return ukSv;
}
float IspitPriprema::UkupnoVreme(float vr) {

}
void IspitPriprema::VratiNaj(float vr, IspitniMaterijal* ptr1, IspitniMaterijal* ptr2) {

}
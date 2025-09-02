#pragma once
#include <iostream>
using namespace std;
#include "LekcijaNormalna.h"
#include <fstream>
#include <string>
template<typename T>
class Ispit {
	T* niz;
	int maxBr;
	int trBr;
public:
	Ispit();
	Ispit(int maxBr);
	Ispit(const Ispit& is);
	~Ispit();
	void Dodaj(T is);
	friend ostream& operator<<(ostream& os, Ispit& is) {
		is.Ispisi(os);
		return os;
	}
	ostream& Ispisi(ostream& os) {
		os << "Ispiti: " << endl;
		for (int i = 0; i < trBr; i++) {
			os << niz[i] << " ";
		}
		os << endl;
		return os;
	}
	void Izbaci(int redBr, int brLek);
	float Ukupno();
	int UkupniBrojVrednost(float vr,float& ukVr);
	void minMax(int poc, int kraj, T& min, T& max);
	void Sacuvaj(const char* nazivFajla);
	void Ucitaj(const char* nazivFajla);
};

template<typename T>
Ispit<T>::Ispit() {
	niz = nullptr;
	maxBr = 0;
	trBr = 0;
}
template<typename T>
Ispit<T>::Ispit(int maxBr) {
	this->maxBr = maxBr;
	trBr = 0;
	niz = new T[maxBr];
}
template<typename T>
Ispit<T>::Ispit(const Ispit& is) {
	this->maxBr = is.maxBr;
	this->trBr = is.trBr;
	this->niz = new T[maxBr];
	for (int i = 0; i < maxBr; i++) {
		this->niz[i] = is.niz[i];
	}
}
template<typename T>
Ispit<T>::~Ispit() {
	delete[] niz;
}
template<typename T>
void Ispit<T>::Dodaj(T is){
	if (trBr >= maxBr) {
		throw runtime_error("Nema mesta!");
	}
	niz[trBr++] = is;
}

template<typename T>
void Ispit<T>:: Izbaci(int redBr, int brLek) {
	if (redBr < 0 || redBr >= trBr) {
		throw runtime_error("Pogresno unet broj!");
	}
	if (redBr + brLek > trBr) { // >= treba da bude >
		throw runtime_error("Hocete da brisete vise elemenata nego sto imate!");
	}

	// Pomeri elemente unazad
	for (int i = redBr; i < trBr - brLek; i++) {
		niz[i] = niz[i + brLek];
	}
	trBr -= brLek;
}
template<typename T>
float Ispit<T>::Ukupno() {
	float uk = 0;
	for (int i = 0; i < trBr; i++) {
		uk += niz[i];
	}
	return uk;
}
template<>
float Ispit<LekcijaNormalna>::Ukupno() {
	float uk = 0;
	for (int i = 0; i < trBr; i++) {
		uk += niz[i].vratiTez();
	}
	return uk;
}

template<typename T>
int Ispit<T>::UkupniBrojVrednost(float vr, float& ukVr) {
	int brel = 0;
	for (int i = 0; i < trBr; i++) {
		if (niz[i] > vr) {
			brel++;
			ukVr += niz[i];
		}
	}
	return brel;
}
template<>
int Ispit<LekcijaNormalna>::UkupniBrojVrednost(float vr, float& ukVr) {
	int brel = 0;
	for (int i = 0; i < trBr; i++) {
		if (niz[i].vratiTez() > vr) {
			brel++;
			ukVr += niz[i].vratiTez();
		}
	}
	return brel;
}
template<typename T>
void Ispit<T>::minMax(int poc, int kraj, T& min, T& max) {
	T minimum = niz[poc];
	T maximum = niz[poc];
	T trenutno;
	for (int i = poc; i < kraj; i++) {
		trenutno = niz[i];
		if (trenutno > maximum) {
			maximum = trenutno;
			max = niz[i];
		}
		if (minimum> trenutno) {
			minimum = trenutno;
			min = niz[i];
		}
	}
}
template<>
void Ispit<LekcijaNormalna>::minMax(int poc, int kraj, LekcijaNormalna& min, LekcijaNormalna& max) {
	float minimum = niz[poc].vratiTez();
	float maximum = niz[poc].vratiTez();
	float trenutno;
	for (int i = poc + 1; i < kraj; i++) {
		trenutno = niz[i].vratiTez();
		if (trenutno > maximum) {
			maximum = trenutno;
			max = niz[i];
		}
		if (minimum > trenutno) {
			minimum = trenutno;
			min = niz[i];
		}
	}
}
template<typename T>
void Ispit<T>::Sacuvaj(const char* nazivFajla) {
		ofstream fajl(nazivFajla);
		if (!fajl.is_open()) {  // Bolje koristiti is_open() umesto good()
			throw runtime_error("Nije dobro otvoren fajl!");
		}

		for (int i = 0; i < trBr; i++) {
			fajl << niz[i];
		}

		fajl.close();
}
template<typename T>
void Ispit<T>::Ucitaj(const char* nazivFajla) {
	ifstream fajl(nazivFajla);
	if (!fajl.is_open()) {
		throw runtime_error("Nije dobro otvoren fajl!");
	}

	trBr = 0;
	T pom;

	// ?itaj dok god uspešno ?itaš podatke
	while (trBr < maxBr) {
		fajl >> pom;
		// Proveri da li je ?itanje uspešno
		if (fajl.fail()) {
			break;
		}
		niz[trBr++] = pom;
	}
	fajl.close();
	
}

#pragma once
#include <iostream>
using namespace std;
#include "IspitniMaterijal.h"
class IspitPriprema
{
private:
	IspitniMaterijal** niz;
	int trBr;
	int maxBr;
public:
	IspitPriprema();
	IspitPriprema(int max);
	IspitPriprema(const IspitPriprema& ip);
	~IspitPriprema();
	void Dodaj(IspitniMaterijal* ip);
	friend ostream& operator<<(ostream& os, IspitPriprema& ip);
	ostream& print(ostream& os);
	void Obrisi(int br);
	void Savladaj(int br);
	int UkupnoSavladanih();
	float UkupnoVreme(float vr);
	void VratiNaj(float vr, IspitniMaterijal* ptr1, IspitniMaterijal* ptr2);
};


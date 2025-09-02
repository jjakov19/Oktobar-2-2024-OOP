#include <iostream>
using namespace std;
#include "IspitniMaterijal.h"
#include "IspitPriprema.h"
#include"Lekcija.h"
#include "Zadatak.h"
#include "LekcijaNormalna.h"
#include "Ispit.h"


void zadatak1()
{
	float vJedinicno = 10;
	// 2 poena
	IspitniMaterijal* p1 = new Lekcija(1001, 2.0, 1.5);
	//p1->Prikazi();
	cout << *p1 << endl;
	// 2 poena
	IspitniMaterijal* p2 = new Zadatak(1002, 2.4, 20);
	//p2->Prikazi();
	cout << *p2 << endl;
	float tezine[] = { 1.5, 2.7, 0.8, 3.2, 1.8 };
	float duzina[] = { 1.2, 3.1, 2.5, 3.4, 4.1 };
	int kod[] = { 100, 20, 40, 50, 30 };
	IspitPriprema* pIspit = new IspitPriprema(20);
	// 2 poena
	for (int i = 0; i < 5; i++)
	{
		Lekcija* lekcija = new Lekcija(2 * i + 1, tezine[i], duzina[i]);
		pIspit->Dodaj(lekcija);
		Zadatak* zadatak = new Zadatak(2 * i + 2, tezine[i], kod[i]);
		pIspit->Dodaj(zadatak);
	}
	// 2 poena
	//pe.print();
	cout << *pIspit << endl;
	// 2 poena
	pIspit->Obrisi(3);
	//pe->print();
	cout << *pIspit << endl;
	// 2 poena
	pIspit->Savladaj(2);
	//pe->print();
	cout << *pIspit << endl;
	// 2 poena
	int sav = pIspit->UkupnoSavladanih();
	cout << sav << endl;
	// 3 poena
	float vreme = pIspit->UkupnoVreme(vJedinicno);
	cout << vreme << endl;
	// 2 poena
	IspitniMaterijal* matMin = nullptr, * matMax = nullptr;
	pIspit->VratiNaj(vJedinicno, &matMin, &matMax);
	cout << *matMin << endl << *matMax << endl;
	//matMin->Prikazi();
	//matMax->Prikazi();
	// 1 poena
	delete pIspit;
}
void zadatak2() {
	int maxPodataka = 8, brojPodataka = 8;
	// 3 boda
	// postavljanje i prihvatanje izuzetaka
	try{
		float tezine[] = { 1.5, 2.7, 3.2, 0.8, 1.8, 4.1, 2.5, 2.3, 3.6 };
		Ispit<float> ispit(maxPodataka);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++)
			ispit.Dodaj(tezine[i]);
		cout << ispit << endl; //nov.Ispisi(cout);
		// 1 bod
		ispit.Izbaci(4, 3);
		cout << ispit << endl; //nov.Ispisi(cout);
		// 1 bod
		float ukupno = ispit.Ukupno();
		cout << ukupno << endl; // 14.1
		// 1 bod
		float vrednost = 2.0; float ukupnaVrednost = 0;
		int broj = ispit.UkupniBrojVrednost(vrednost, ukupnaVrednost);
		cout << broj << " " << ukupnaVrednost << endl; // 4 11.8
		// 1 bod
		float min = 0.0; float max = 1000.0;
		ispit.minMax(1, 4, min, max);
		cout << min << " " << max << endl; // 4
		// 1 bod
		ispit.Sacuvaj("IspProst.txt");
		// 1 boda
		Ispit<int> ispUc(maxPodataka);
		ispUc.Ucitaj("IspProst.txt");
		cout << ispUc << endl; //novUcitan.Ispisi(cout);
	}
	catch(const runtime_error&e){
		cout << "Runtime error-" << e.what() << endl;
	}
	try{
		char naziv[][8] = { "prva", "druga", "treca", "cetvrta", "peta",
		"sesta", "sedma", "osma", "deveta" };
		float tezine[] = { 1.5, 2.7, 3.2, 0.8, 1.8, 4.1, 2.5, 2.3, 3.6 };
		float duzina[] = { 1.2, 3.1, 2.5, 3.4, 4.1, 1.7, 2.2, 3.7, 2.8 };
		Ispit<LekcijaNormalna> ispNor(maxPodataka);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++) {
			LekcijaNormalna lekcija(naziv[i], tezine[i], duzina[i]);
			ispNor.Dodaj(lekcija);
		}
		// 1 bod
		cout << ispNor << endl; //novVal.Ispisi(cout);
		// 1 bodova
		ispNor.Izbaci(4, 3);
		cout << ispNor << endl; //novVal.Ispisi(cout);
		// 1 bod
		float ukupno = ispNor.Ukupno();
		cout << ukupno << endl;
		// 2 bod
		float vrednost = 2.0; float ukupnaVrednost = 0;
		int broj = ispNor.UkupniBrojVrednost(vrednost, ukupnaVrednost);
		cout << broj << " " << ukupnaVrednost << endl;
		// 2 bod
		LekcijaNormalna min, max;
		ispNor.minMax(1, 4, min, max);
		cout << min << " " << max << endl;
		// 1 bod
		ispNor.Sacuvaj("IspNormal.txt");
		// 1 bod
		Ispit<LekcijaNormalna> ispNorUc(maxPodataka);
		ispNorUc.Ucitaj("IspNormalB.txt");
		cout << ispNorUc << endl; //novValUc.Ispisi(cout);
	}
	catch(const runtime_error& t){
		cout << "Runtime eroor-" << t.what() << endl;
	}
}
int main()
{
	zadatak1();
	zadatak2();
	return 0;
}
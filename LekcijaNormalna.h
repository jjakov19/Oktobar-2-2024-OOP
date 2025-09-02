#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;
class LekcijaNormalna
{
private:
	char* naziv;
	float duzina;
	float procTez;
public:
	LekcijaNormalna();
	LekcijaNormalna(const char* naz, float duz, float proc);
	LekcijaNormalna(const LekcijaNormalna& n);
	~LekcijaNormalna();
	friend ostream& operator<<(ostream& os, LekcijaNormalna& l);
	friend istream& operator>>(istream& ulaz, LekcijaNormalna& l);
	ostream& prikazi(ostream& os);
	istream& upisi(istream& is);
	float vratiTez()const { return procTez; }
	void setujTez(float t);
	float vratiDuz()const { return duzina; }
	void setujDuz(float duz);
	bool operator>(const LekcijaNormalna& lek) {
		return this->procTez > lek.procTez;
	}
	LekcijaNormalna& operator=(const LekcijaNormalna& other);
};
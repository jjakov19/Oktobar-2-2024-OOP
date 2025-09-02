#pragma once
#include <iostream>
using namespace std;
class IspitniMaterijal
{
protected:
	int oznaka;
	double tezina;
	bool status;
public:
	IspitniMaterijal();
	IspitniMaterijal(int oznaka, double tezina);
	IspitniMaterijal(const IspitniMaterijal& im);
	virtual ~IspitniMaterijal();
	friend ostream& operator<<(ostream& os, IspitniMaterijal& im);
	virtual ostream& Prikazi(ostream&os);
	virtual bool vratiStatus() { return status; }
	virtual void setujStatus(bool a);
	virtual int vratiOznaku() { return oznaka; }
	virtual void setujOznaku(int oz);
	virtual double vratiTezinu() { return tezina; }
	virtual void setujTezinu(double tez);
	virtual float ukVreme(float proc) = 0;
};


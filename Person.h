#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Medium.h"
#include <list>
#include "Book.h"


class Person
{
public:
    Person(std::string nr, std::string vorname, std::string name, char geschlecht, std::string Wohnort, std::string GebDat);
	~Person();

    const std::string getVorname() { return mVorname; }
    std::string getName() const { return mName; }
    std::string getNr() const { return mNr; }
    char getGeschlecht() const { return mGeschlecht; }
    std::string getGebDat() const { return mGebDat; }
    std::string getWohnort() const { return mWohnort; }

	void leiheAus(Medium* pMedium);
	void leiheRueck(Medium* pMedium);
	void leiheRueck();

    std::list<Medium*> getLeihBestand(){return mLeihBestand;}

private:

    std::list<Medium*> mLeihBestand;

	
    std::string mNr;
    std::string mVorname;
    std::string mName;
    char mGeschlecht;
    std::string mWohnort;
    std::string mGebDat;

	
};

#endif

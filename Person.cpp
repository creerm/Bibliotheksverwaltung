/*=====================================================
# Modul:            	Programmierung II SS17
# Uhrheber:          	Jonathan Vincent Cremer
# MatrikelNr:       	41889
# Studiengruppennummer: 16 041 01
# Projekt:          	Belegaufgabe
# letzte Änderung:	07.07.2017
=====================================================*/

#include "Person.h"
#include <iostream>



Person::Person(std::string nr, std::string vorname, std::string name, char geschlecht, std::string Wohnort, std::string GebDat)
    : mNr(nr), mVorname(vorname), mName(name), mGeschlecht(geschlecht), mWohnort(Wohnort), mGebDat(GebDat)
{

}


Person::~Person()
{
	for (std::list<Medium*>::iterator it = mLeihBestand.begin(); !mLeihBestand.empty();)
		it = mLeihBestand.erase(it);		

	mLeihBestand.clear();
}


void Person::leiheAus(Medium *pMedium)
{
    mLeihBestand.push_back(pMedium);
}

void Person::leiheRueck(Medium *pMedium)
{
	for (std::list<Medium*>::iterator it = mLeihBestand.begin(); it != mLeihBestand.end();)
	{
		if ((*it)->getNr() == pMedium->getNr()) {
			(*it)->setLeihDat("00.00.0000");
			(*it)->setFristDat("00.00.0000");
			(*it)->setEigner("00000");
			it = mLeihBestand.erase(it);
			break;
		}
		else
			++it;

	}
}
void Person::leiheRueck()
{
//entferne alle Auleihen aus der Leihliste des Kunden und aktualisiere die Verfügbarkeit der Medien (Leihdatum etc.)
	for (std::list<Medium*>::iterator it = mLeihBestand.begin(); it != mLeihBestand.end();)
	{
		(*it)->setLeihDat("00.00.0000");
		(*it)->setFristDat("00.00.0000");
		(*it)->setEigner("00000");
		it = mLeihBestand.erase(it);

		qDebug() << "ist erledigt";
	}
}

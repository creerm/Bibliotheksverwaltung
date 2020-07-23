/*=====================================================
# Modul:            	Programmierung II SS17
# Uhrheber:          	Jonathan Vincent Cremer
# MatrikelNr:       	41889
# Studiengruppennummer: 16 041 01
# Projekt:          	Belegaufgabe
# letzte Änderung:	07.07.2017
=====================================================*/

#include "CD.h"



CD::CD(std::string nr, std::string name, std::string Kuenstler, std::string label, std::string jahr)
	: mName(name), mNr(nr), mKuenstler(Kuenstler), mLabel(label), mJahr(jahr)
{
}


CD::~CD()
{
}

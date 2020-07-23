/*=====================================================
# Modul:            	Programmierung II SS17
# Uhrheber:          	Jonathan Vincent Cremer
# MatrikelNr:       	41889
# Studiengruppennummer: 16 041 01
# Projekt:          	Belegaufgabe
# letzte Änderung:	07.07.2017
=====================================================*/

#include <QtDebug>
#include "Book.h"


Book::Book(std::string nr, std::string name, std::string autor,std::string herausgeber, std::string jahr)
	: mName(name), mNr(nr), mAutor(autor), mHerausgeber(herausgeber), mJahr(jahr)
{
}


Book::~Book()
{
}

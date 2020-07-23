/*=====================================================
# Modul:            	Programmierung II SS17
# Uhrheber:          	Jonathan Vincent Cremer
# MatrikelNr:       	41889
# Studiengruppennummer: 16 041 01
# Projekt:          	Belegaufgabe
# letzte Änderung:	07.07.2017
=====================================================*/

#include "Video.h"



Video::Video(std::string nr, std::string name, std::string regisseur, std::string filmverleih, std::string jahr)
	: mName(name), mNr(nr), mRegisseur(regisseur), mFilmverleih(filmverleih), mJahr(jahr)
{
}


Video::~Video()
{
}

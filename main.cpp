/*=====================================================
# Modul:            	Programmierung II SS17
# Uhrheber:          	Jonathan Vincent Cremer
# MatrikelNr:       	41889
# Studiengruppennummer: 16 041 01
# Projekt:          	Belegaufgabe
# letzte Änderung:	07.07.2017
=====================================================*/

#include "mainwindow.h"
#include <QApplication>

#include "Medium.h"
#include "Person.h"
#include "Book.h"
#include "Video.h"
#include "CD.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.run();
    return a.exec();
}

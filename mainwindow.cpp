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
#include <QtDebug>
#include <QString>
#include <QStringList>
#include <QDirModel>
#include <QLabel>

#include <iostream>

#include "Medium.h"
#include "Person.h"
#include "Book.h"
#include "Video.h"
#include "CD.h"

#include <list>
#include <cstring>
#include <cstdlib>
#include <fstream>

#include <string>
#include <cctype>
#include <time.h>
#include <ctime>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

MainWindow::~MainWindow()
{
	
}

//Prototypen
bool istZulaessigerString(std::string str);
bool istGebdat(std::string str);
bool istZulaessigeNummer(std::string str);
bool NummerExistiertSchon(std::string str, std::list<Person> *group);
bool MediumExistiertSchon(std::string str, std::list<std::list<Medium*> > *Bestand, int typ);
void getDatum(char* ret, int extra);

//Wurzelitem zu Bibbliothek-Tabelle hinzufügen
QTreeWidgetItem* MainWindow::BibAddRoot(std::string titel, std::string autor,
	std::string herausgeber, std::string erscheinungsjahr, int exemplare)
{
	QTreeWidgetItem *item = new QTreeWidgetItem(ui.BibTree);

	item->setText(0, QString::fromStdString(titel));
	item->setText(1, QString::fromStdString(autor));
	item->setText(2, QString::fromStdString(herausgeber));
	item->setText(3, QString::fromStdString(erscheinungsjahr));
	item->setText(4, QString::number(exemplare));

	ui.treeWidget->addTopLevelItem(item);
	return item;
}

//Wurzelitem zu Kunden-Tabelle hinzufügen
QTreeWidgetItem* MainWindow::addRoot(std::string nr, std::string vorname, std::string name,
	char geschl, std::string ort, std::string GebDat)
{
	QTreeWidgetItem *item = new QTreeWidgetItem(ui.treeWidget);
	item->setText(0, QString::fromStdString(nr));
	item->setText(1, QString::fromStdString(vorname));
	item->setText(2, QString::fromStdString(name));
	item->setText(3, QChar::fromLatin1(geschl));
	item->setText(4, QString::fromStdString(ort));
	item->setText(5, QString::fromStdString(GebDat));

	ui.treeWidget->addTopLevelItem(item);
	return item;
}

//Untergeordnetes Item zu Items in Kunden-Tabelle hinzufügen
void MainWindow::addChild(QTreeWidgetItem *parent, std::string name, std::string Description, std::string leihDat, std::string fristDat, int typ)
{
	QTreeWidgetItem *item = new QTreeWidgetItem();
	item->setText(0, QString::fromStdString(name));
	item->setText(1, QString::fromStdString(Description));
	item->setText(2, QString::fromStdString(leihDat));
	item->setText(3, QString::fromStdString(fristDat));
	parent->addChild(item);

//Typ 1 bedeutet, dass es sich um eine Überschrift handeln soll
	if (typ == 1)
	{
		for (int i = 0; i < 5; i++)
		{
			QFont font;
			font.setBold(true);
			item->setFont(i, font);
		}
	}
		
}

//Untergeordnetes Item zu Items in Kunden-Tabelle hinzufügen
void MainWindow::BibAddChild(QTreeWidgetItem *parent, std::string nr, std::string name,
	std::string eigner, std::string leihDat, std::string fristDat, int leihbar)
{
	QTreeWidgetItem *item = new QTreeWidgetItem();
	item->setText(0, QString::fromStdString(nr));
	item->setText(1, QString::fromStdString(name));
	item->setText(2, QString::fromStdString(eigner));
	item->setText(3, QString::fromStdString(leihDat));
	item->setText(4, QString::fromStdString(fristDat));
//Schrifttyp für Überschriften
	QFont font;
	font.setBold(true);
	
	for (int i = 0; i < 6; i++)
	{
		if (leihbar == 1)
			item->setForeground(i, Qt::darkGreen);
		else if (leihbar == 0)
			item->setForeground(i, Qt::red);
		//Andernfalls überschrift:
		else
			item->setFont(i, font);
	}
	parent->addChild(item);
}

//Hilfsfunktionen um den Namen von Personen vergleichen und diese als Funktionspointer an Sortierfunktion übergeben zu können
bool compFirst(const Person &a, const Person &b) { return a.getName() < b.getName(); }
//Hilfsfunktionen um den Titel von Artikeln vergleichen und diese als Funktionspointer an Sortierfunktion übergeben zu können
bool compArtikel(std::list<Medium*> & a, std::list<Medium*> & b) { return a.front()->getName() < b.front()->getName(); }

//Personen aus Kunden.txt lesen und in übergebene Liste einfügen
void lesePersonen(std::list<Person> *group)
{
    std::ifstream fd("Kunden.txt");
	char vBuf[128];

	if (fd.is_open())
	{
		while (fd.getline(vBuf, 128))
		{

			char *nr, *vorname, *nam, *geschl, *ort, *gebdat, *ptr0 = NULL;

			//////////strtok_r für Linux und strtok_s für windows
            nr = strtok_r(vBuf, ";", &ptr0);
            vorname = strtok_r(NULL, ";", &ptr0);
            nam = strtok_r(NULL, ";", &ptr0);
            geschl = strtok_r(NULL, ";", &ptr0);
            ort = strtok_r(NULL, ";", &ptr0);
            gebdat = strtok_r(NULL, ";", &ptr0);

            /*nr = strtok_s(vBuf, ";", &ptr0);
			vorname = strtok_s(NULL, ";", &ptr0);
			nam = strtok_s(NULL, ";", &ptr0);
			geschl = strtok_s(NULL, ";", &ptr0);
			ort = strtok_s(NULL, ";", &ptr0);
            gebdat = strtok_s(NULL, ";", &ptr0);*/

			(*group).push_back({ nr, vorname, nam, geschl[0], ort, gebdat });

		}
	}
	fd.close();
}

//Veränderte Personenliste und Medieliste zurück in Dateien schreiben
void speichern(std::list<std::list<Medium*> >* Bestand, std::list<Person> *personen)
{
    std::ofstream fd("Kunden.txt");

//i dient dazu beim ersten Schleifendurchlauf kein 'endl' zu setzen
	bool i = true;
//Kundenliste in Kunden.txt schreiben
	for (std::list<Person>::iterator it = (*personen).begin(); it != (*personen).end(); ++it)
	{
		if (!i)
			fd << std::endl << it->getNr() << ";" << it->getVorname() << ";" << it->getName() << ";" <<
			it->getGeschlecht() << ";" << it->getWohnort() << ";" << it->getGebDat() << ";";
		else
		{
			fd << it->getNr() << ";" << it->getVorname() << ";" << it->getName() << ";" << it->getGeschlecht() <<
				";" << it->getWohnort() << ";" << it->getGebDat() << ";";
			i = false;
		}
	}
	fd.close();
    fd.open("Bestand.txt");
//i dient dazu beim ersten Schleifendurchlauf kein 'endl' zu setzen
	i = true;
//Bestandsliste in Bestand.txt schreiben
	for (std::list<std::list<Medium*> >::iterator mit = Bestand->begin(); mit != Bestand->end(); ++mit)
	{
		std::list<Medium*>::iterator it = mit->begin();
		for (; it != mit->end(); ++it)
		{
			if (!i)
				fd << std::endl << (*it)->getNr() << ";" << (*it)->getName() << ";" <<
				(*it)->getKuenstler() << ";" << (*it)->getHerausgeber() << ";" <<
				((*it)->getJahr()) << ";" << ((*it)->getTyp()) << ";" << ((*it)->getEigner()) << ";" << (*it)->getAusleihDat() << ";" << (*it)->getFristDat() << ";";
			else
			{
				fd << (*it)->getNr() << ";" << (*it)->getName() << ";" << (*it)->getKuenstler() << ";" << (*it)->getHerausgeber() << ";" <<
					(*it)->getJahr() << ";" << (*it)->getTyp() << ";" << (*it)->getEigner() << ";" << (*it)->getAusleihDat() << ";" << (*it)->getFristDat() << ";";
				i = false;
			}
		}
	}
	fd.close();
}

//Medien aus Bestand.txt lesen und in übergebene Liste einfügen
void leseMedienBestand(std::list<std::list<Medium*> > *Bestand,
	std::list<Person> *personen)
{
	// 1 : CD, 2 : Video , 3 : Buch

    std::ifstream fd("Bestand.txt");
	char vBuf[128];
	std::string buf;

	if (fd.is_open())
	{
		while (fd.getline(vBuf, 128))
		{

			char *nr, *nam, *autor, *herausgeber, *jahr, *typ, *eigner, *leihDat, *fristDat, *ptr0 = NULL;

            nr = strtok_r(vBuf, ";", &ptr0);
            nam = strtok_r(NULL, ";", &ptr0);
            autor = strtok_r(NULL, ";", &ptr0);
            herausgeber = strtok_r(NULL, ";", &ptr0);
            jahr = strtok_r(NULL, ";", &ptr0);
            typ = strtok_r(NULL, ";", &ptr0);
            eigner = strtok_r(NULL, ";", &ptr0);

            leihDat = strtok_r(NULL, ";", &ptr0);
            fristDat = strtok_r(NULL, ";", &ptr0);

			std::string strnam = nam;

		//Für den Fall, dass Bestand noch leer ist
			if (Bestand->empty() || strnam.compare(Bestand->back().back()->getName())) //not equal
			{
				std::list<Medium*> item;
				Bestand->push_back(item);
			}
		//Medientyp herausfinden und entsprechendes Objekt erstellen und in Liste anhängen
			if (atoi(typ) == 1) //CD
			{
				CD* tmp = new CD(nr, nam, autor, herausgeber, jahr);
				Bestand->back().push_back(tmp);
			}
			else if (atoi(typ) == 2) //Video
			{
				Video* tmp = new Video(nr, nam, autor, herausgeber, jahr);
				Bestand->back().push_back(tmp);
			}
			else if (atoi(typ) == 3) //Buch
			{
				Book* tmp = new Book(nr, nam, autor, herausgeber, jahr);
				Bestand->back().push_back(tmp);
			}

			if (!strstr(eigner, "00000"))
			{
				for (std::list<Person>::iterator it = (*personen).begin(); it != (*personen).end(); ++it)
				{
					if ((std::string(eigner).compare(it->getNr()) == 0))
					{
						it->leiheAus(Bestand->back().back());
					}

				}
			}

			Bestand->back().back()->setEigner(eigner);
			Bestand->back().back()->setLeihDat(leihDat);
			Bestand->back().back()->setFristDat(fristDat);
		}
	}

	fd.close();
}

//Medium-Objekt, dass durch den Namen oder die Nummer identifiziert wird aus Bestand-Liste holen (Objekt wird zurückgegeben)
Medium* holeMedium(std::string identifier, std::list<std::list<Medium*> > *Bestand, int typ)
{
//Parameter typ gibt an ob mit Mediennummer "0" oder Name "1" verglichen werden soll
    for (std::list<std::list<Medium*> >::iterator it = Bestand->begin(); it != Bestand->end(); ++it)
    {
        std::list<Medium*>::iterator mit = it->begin();

        for (; mit != it->end(); mit++)
        {
			if (typ == 1)
			{
				if (!(*mit)->getName().compare(identifier))
					return (*mit);
			}
			else
			{
				if (!(*mit)->getNr().compare(identifier))
					return (*mit);
			}
        }
    }
    return NULL;
}

//Person-Objekt, dass durch die Nummer identifiziert wird aus Kunden-Liste holen (Objekt wird zurückgegeben)
Person* MainWindow::holePerson(std::string nummer)
{
		for (std::list<Person>::iterator it = group.begin(); it != group.end(); ++it)
		{
			if (!it->getNr().compare(nummer))
				return &(*it); 
				//Syntax^(& und *) notwendig, damit der Compiler den Rückgabewert akzeptiert
		}	
	//falls keine Person mit übergebener Nummer gefunden wurde
		return NULL;
}

//Funktion, die nach Programmstart (nach dem Konstruktor) ausgeführt wird
void MainWindow::run()
{
//Bestands-Liste und Kunden-Liste aus Dateien holen
	lesePersonen(&group);
	leseMedienBestand(&Bestand, &group);
//Checkboxen für Video/ Buch/ CD Anzeige zu Beginn den Wert true zuweisen
	mBuch = mVideo = mCD = true;

//Tabellen (treeWidgets) aufbauen
	aktualisiereTabellen(mBuch, mVideo, mCD);
}

//Ausgeführte Funktion, wenn "Speichern und Beenden" Button betätigt wird
void MainWindow::on_mCloseBtn_clicked()
{
//Bestand sortieren, damit gleiche Titel in der Datei hintereinander stehen
//->notwendig um verschachtelte Listen korrekt aufzubauen
	Bestand.sort(compArtikel);
//Speichern und Schließen
	speichern(&Bestand, &group);
	close();
}

//Tabellen (Kunden und Bestand) aktualisieren
void MainWindow::aktualisiereTabellen(bool buch, bool video, bool cd)
{
//zuerst alte Daten löschen

//mComboBox leeren
	ui.mComboBox->clear();

	while (int nb = ui.treeWidget->topLevelItemCount())
	{
		delete ui.treeWidget->takeTopLevelItem(nb - 1);
	}
	while (int nb = ui.BibTree->topLevelItemCount())
	{
		delete ui.BibTree->takeTopLevelItem(nb - 1);
	}
	
////neu füllen
	
//Überschriften
    ui.BibTree->setColumnCount(5);
    QStringList headerLabels;
    headerLabels.push_back(tr("Titel"));
    headerLabels.push_back(tr("Autor/ Kuenstler"));
    headerLabels.push_back(tr("Verlag/ Herausgeber"));
    headerLabels.push_back(tr("Erscheinungsjahr"));
    headerLabels.push_back(tr("Exemplare"));
    ui.BibTree->setHeaderLabels(headerLabels);
    
    ui.treeWidget->setColumnCount(6);
    QStringList headerLabels2;
    headerLabels2.push_back(tr("Kundennummer"));
    headerLabels2.push_back(tr("Vorname"));
    headerLabels2.push_back(tr("Nachname"));
    headerLabels2.push_back(tr("Geschlecht"));
    headerLabels2.push_back(tr("Wohnort"));
    headerLabels2.push_back(tr("Geburtsdatum"));
    ui.treeWidget->setHeaderLabels(headerLabels2);

	for (std::list<Person>::iterator it = group.begin(); it != group.end(); ++it)
	{
	//ComboBox mit Kunden füllen
		ui.mComboBox->addItem(QString::fromStdString(it->getNr() + " - " + it->getName()));

//Kundentabelle befüllen
		QTreeWidgetItem* parent = new QTreeWidgetItem();

		parent = addRoot(it->getNr(), it->getVorname(), it->getName(), it->getGeschlecht(), it->getWohnort(), it->getGebDat());


		if (!it->getLeihBestand().empty())
		{
			addChild(parent, "Mediennummer", "Titel", "Ausleihdatum", "Abgabefrist",1);

			std::list<Medium*> leihbestand = it->getLeihBestand();

			for (std::list<Medium*>::iterator mit = leihbestand.begin(); mit != leihbestand.end(); mit++)
			{
				addChild(parent, (*mit)->getNr(), (*mit)->getName(), (*mit)->getAusleihDat(), (*mit)->getFristDat(),0);
			}
		}
	}

//Bibliothek befüllen

///Typkennziffern
//CD	: 1
//Video	: 2
//Buch	: 3
	for (std::list<std::list<Medium*> >::iterator it = Bestand.begin(); it != Bestand.end(); ++it)
	{
	// Medienarten für die kein Häckchen gesetzt wurde nicht anzeigen
		if (it->front()->getTyp() == 1 && !cd) //CDs
			continue;
		if (it->front()->getTyp() == 2 && !video) //CDs
			continue;
		if (it->front()->getTyp() == 3 && !buch) //CDs
			continue;
		
		QTreeWidgetItem* parent = new QTreeWidgetItem();

		parent = BibAddRoot(it->front()->getName(), it->front()->getKuenstler(),
			it->front()->getHerausgeber(), it->front()->getJahr(), it->size());

		BibAddChild(parent, "Nummer", "Titel", "Eigner",
			"Auleihdatum","Abgabefrist", 2);

		std::list<Medium*>::iterator mit = it->begin();

		for (; mit != it->end(); ++mit)
		{
			if ((*mit)->getEigner().compare("00000"))
			{
				std::string eigner;
				
				//Eignername wird hier durch holeperson(<nummer>) herausgefunden
				BibAddChild(parent, (*mit)->getNr(), (*mit)->getName(), holePerson((*mit)->getEigner())->getName(), 
					(*mit)->getAusleihDat(), (*mit)->getFristDat(), 0);
			}
			else
				BibAddChild(parent, (*mit)->getNr(), (*mit)->getName(), "Auf Lager",
					"", "", 1);
		}
	}
	

	
}

//Kunde aus Datenbank bei Button-Betätigung löschen
void MainWindow::on_mDeletePersonBtn_clicked()
{

	QModelIndexList indexes = ui.treeWidget->selectionModel()->selectedIndexes();
	if (indexes.size() > 0) {
		QModelIndex selectedIndex = indexes.at(0); //erste Spalte
		QVariant data = ui.treeWidget->model()->data(selectedIndex);
		QString text = data.toString();
	//der QString text enthält die Kundennummer in der ausgewählten Zeile
		if (Person* tmpPerson = holePerson(text.toStdString()))
		{
		//entferne alle Auleihen aus der Leihliste des Kunden und aktualisiere die Verfügbarkeit der Medien (Leihdatum etc.) mit der Funktion leihRueck()
			tmpPerson->leiheRueck();
			
		//Person aus Liste entfernen
			for (std::list<Person>::iterator it = group.begin(); it != group.end();)
			{
				if (&(*tmpPerson) == &(*it))
				{
					it = group.erase(it);
					break;
				}
				else
					++it;
			}

			aktualisiereTabellen(mBuch, mVideo,mCD);
		}
		else
			ui.statusBar->showMessage("Kein Kunde ausgewaehlt", 800);
	}

}

//Kunde hinzufügen
void MainWindow::on_mKundeHinzuBtn_clicked()
{
	std::string nr, vorname, nachname, ort, gebdat;
	char geschl;

	nr = (ui.NummerEdt->text()).toStdString();
	if (!istZulaessigerString(vorname = (ui.VornameEdt->text()).toStdString()))
	{
		ui.VornameEdt->clear();
		ui.statusBar->showMessage("Kein zulaessiger Vorname", 800);
		return;
	}
	else if (!istZulaessigerString(nachname = (ui.NachnameEdt->text()).toStdString()))
	{
		ui.NachnameEdt->clear();
		ui.statusBar->showMessage("Kein zulaessiger Nachname", 800);
		return;
	}
	//5 als zweiter Parameter, da Nummer fünfstellig sein muss
	else if (!istZulaessigeNummer(nr) || nr.length() != 5
		|| NummerExistiertSchon(nr, &group))
	{
		ui.NummerEdt->clear();
		ui.statusBar->showMessage("Keine neue oder fuenfstellige Nummer", 800);
		return;
	}
	else if (!istZulaessigerString(ort = (ui.OrtEdt->text()).toStdString()))
	{
		ui.OrtEdt->clear();
		ui.statusBar->showMessage("Kein zulaessiger Ort", 800);
		return;
	}
	else if (!istGebdat(gebdat = (ui.GebdatEdt->text()).toStdString()))
	{
		ui.GebdatEdt->clear();
		ui.statusBar->showMessage("Kein zulaessiges Geburtdatum", 800);
		return;
	}
	if (ui.mRadio->isChecked())
		geschl = 'm';
	else if (ui.wRadio->isChecked())
		geschl = 'w';
	else
	{
		ui.statusBar->showMessage("Kein Geschlecht ausgewaehlt", 800);
		return;
	}
	
	ui.statusBar->showMessage("Kunde wurde hinzugefuegt", 800);
	group.push_back({ nr, vorname, nachname, geschl, ort, gebdat });
	aktualisiereTabellen(mBuch, mVideo, mCD);		
}

//"Leihe Beenden" Button
void MainWindow::on_mBtnLeiheBeenden_clicked()
{
	QModelIndexList indexes = ui.treeWidget->selectionModel()->selectedIndexes();
	if (indexes.size() > 0) {
		QModelIndex selectedIndex = indexes.at(0); //Artikelnummer
		QVariant data = ui.treeWidget->model()->data(selectedIndex);
		QString text = data.toString();

		if (Medium* tmp = holeMedium(text.toStdString(), &Bestand,0))
		{
			if (Person *tmpPerson = holePerson(tmp->getEigner()))
			{
				tmpPerson->leiheRueck(tmp);
			}
			aktualisiereTabellen(mBuch, mVideo, mCD);
		}
		else
			ui.statusBar->showMessage("Kein Medium ausgewaehlt", 800);
	}
	
}

//Neues Medium hinzufügen zum Bestand
void MainWindow::on_mNeuesMediumBtn_clicked()
{
	std::string nr, titel, herausgeber, autor;
	int jahr;
	
    std::string erscheinungsjahr = ui.JahrEdt->text().toStdString();
	jahr = ui.JahrEdt->text().toInt();
	nr = (ui.MedienNrEdt->text()).toStdString();

//Eingaben überprüfen
	if (!istZulaessigerString(titel = (ui.TitelEdt->text()).toStdString()))
	{
		ui.TitelEdt->clear();
		ui.statusBar->showMessage("Kein zulaessiger Titel", 800);
		return;
	}
	else if (MediumExistiertSchon(titel, &Bestand, 1))
	{
		ui.TitelEdt->clear();
		ui.statusBar->showMessage("Titel existiert schon, bitte neues Exemplar an anderer Stelle hinzufuegen", 800);
		return;
	}
	else if (!istZulaessigerString(autor = (ui.AutorEdt->text()).toStdString()))
	{
		ui.AutorEdt->clear();
		ui.statusBar->showMessage("Kein zulaessiger Autorname", 800);
		return;
	}
	else if (!istZulaessigerString(herausgeber = (ui.VerlagEdt->text()).toStdString()))
	{
		ui.VerlagEdt->clear();
		ui.statusBar->showMessage("Kein zulaessiger Herausgeber", 800);
		return;
	}
	//4 als zweiter Parameter, da Nummer fünfstellig sein muss
	else if (!istZulaessigeNummer(nr) || nr.length() != 4
		|| MediumExistiertSchon(nr, &Bestand, 0))
	{
		ui.MedienNrEdt->clear();
		ui.statusBar->showMessage("Keine neue oder vierstellige Nummer", 800);
		return;
	}

	else if (!(jahr > 1000 && jahr < 2100))
	{
		ui.JahrEdt->clear();
		ui.statusBar->showMessage("Das Angegebene Erscheinungsjahr muss zwischen 1000 und 2100 liegen", 800);
		return;
	}

//neue Liste anhängen
	std::list<Medium*> item;
	Bestand.push_back(item);
//Checkbox (Video, CD oder Buch)
//Item in verschachtelte Liste einhängen

	if (ui.vRadio->isChecked())
	{
		Video* tmp = new Video(nr, titel, autor, herausgeber, erscheinungsjahr);
		Bestand.back().push_back(tmp);
	}
	else if (ui.bRadio->isChecked())
	{
		Book* tmp = new Book(nr, titel, autor, herausgeber, erscheinungsjahr);
		Bestand.back().push_back(tmp);
	}
	else if (ui.cRadio->isChecked())
	{
		CD* tmp = new CD(nr, titel, autor, herausgeber, erscheinungsjahr);
		Bestand.back().push_back(tmp);
	}
	else
	{
		ui.statusBar->showMessage("Keine Medienart ausgewaehlt", 800);
		return;
	}

//Als nicht ausgeliehen kennzeichnen
	Bestand.back().back()->setEigner("00000");
	Bestand.back().back()->setLeihDat("00.00.0000");
	Bestand.back().back()->setFristDat("00.00.0000");

//Eingabefelder leeren
	ui.AutorEdt->clear();
	ui.JahrEdt->clear();
	ui.TitelEdt->clear();
	ui.MedienNrEdt->clear();
	ui.VerlagEdt->clear();

	aktualisiereTabellen(mBuch, mVideo, mCD);

}

//Exemplar von schon bestehendem Medium hinzufügen
void MainWindow::on_mAltHinzuBtn_clicked()
{
	QModelIndexList indexes = ui.BibTree->selectionModel()->selectedIndexes();
	if (indexes.size() > 0) {
		QModelIndex selectedIndex = indexes.at(0); //Artikelnummer
		QVariant data = ui.treeWidget->model()->data(selectedIndex);
		QString text = data.toString();
		
		std::string nr, titel, herausgeber, autor, jahr;

	//Nummer aus Eingabe lesen
		nr = (ui.altNrEdt->text()).toStdString();
	//4 als zweiter Parameter, da Nummer fünfstellig sein muss
		if (!istZulaessigeNummer(nr) ||nr.length() != 4
			|| MediumExistiertSchon(nr, &Bestand, 0))
		{
			ui.MedienNrEdt->clear();
			ui.statusBar->showMessage("Keine neue oder vierstellige Nummer", 800);
			return;
		}

	//Medium in die richtige Liste einhängen:
		for (std::list<std::list<Medium*> >::iterator it = Bestand.begin(); it != Bestand.end(); ++it)
		{
			std::list<Medium*>::iterator mit = it->begin();

			for (; mit != it->end(); mit++)
			{
				if ((*mit)->getName() == text.toStdString())
				{
					if ((*mit)->getTyp() == 2)
					{
						Video* tmp = new Video(nr, (*mit)->getName(), (*mit)->getKuenstler(), (*mit)->getHerausgeber(), (*mit)->getJahr());
						it->push_back(tmp);

					//Leihdaten setzen
						it->back()->setEigner("00000");
						it->back()->setLeihDat("00.00.0000");
						it->back()->setFristDat("00.00.0000");

						goto weiter;
					}
					else if ((*mit)->getTyp() == 3)
					{
						Book* tmp = new Book(nr, (*mit)->getName(), (*mit)->getKuenstler(), (*mit)->getHerausgeber(), (*mit)->getJahr());
						it->push_back(tmp);

					//Leihdaten setzen
						it->back()->setEigner("00000");
						it->back()->setLeihDat("00.00.0000");
						it->back()->setFristDat("00.00.0000");

						goto weiter;
					}
					else if ((*mit)->getTyp() == 1)
					{
						CD* tmp = new CD(nr, (*mit)->getName(), (*mit)->getKuenstler(), (*mit)->getHerausgeber(), (*mit)->getJahr());
						it->push_back(tmp);

					//Leihdaten setzen
						it->back()->setEigner("00000");
						it->back()->setLeihDat("00.00.0000");
						it->back()->setFristDat("00.00.0000");

						goto weiter;
					}
				}
			}
		}
		ui.statusBar->showMessage("Bitte Medium-Prototyp makieren (nicht spezifizierte Zeile)", 800);
		return;
	
		//Sprung aus den zwei Schleifen mit goto zu "weiter" um Rechenzeit zu verkürzen		
	weiter:


		ui.statusBar->showMessage("Weiteres Exemplar hinzugefuegt", 800);

	//Eingabefelder leeren
		ui.AutorEdt->clear();
		ui.JahrEdt->clear();
		ui.TitelEdt->clear();
		ui.MedienNrEdt->clear();
		ui.VerlagEdt->clear();

		aktualisiereTabellen(mBuch, mVideo, mCD);

	}
}

//Leihe-Button
void MainWindow::on_mLeihBtn_clicked()
{
	std::string nummer;
	Person *pTmp;

	if (ui.comboRadio->isChecked())
	{
	//Text von ausgewähltem Item aus Combobox holen um neuen Eigner zu ermitteln
		nummer = ui.mComboBox->currentText().toStdString();
	//Abschneiden nach 5 Zeichen um ausschließlich die Kundennummer zu erhalten
		nummer = nummer.substr(0, 5);
		ui.MedienNrEdt->clear();
	}
	else
	{
		nummer = (ui.manuNummerEdt->text()).toStdString();
		if (!(pTmp = holePerson(nummer)))
		{
			ui.statusBar->showMessage("Kunde mit angegebener Kundennummer existiert nicht", 800);
			return;
		}

	}
	if (!(pTmp = holePerson(nummer)))
	{
		ui.statusBar->showMessage("Problem beim Leihvorgang", 800);
		return;
	};

	//ausgewähltes Medium holen
	QModelIndexList indexes = ui.BibTree->selectionModel()->selectedIndexes();
	if (indexes.size() <= 0)
		return;

	QModelIndex selectedIndex = indexes.at(0); //Artikelnummer
	QVariant data = ui.treeWidget->model()->data(selectedIndex);
	QString text = data.toString();

	Medium *mTmp;
	if (!(mTmp = holeMedium(text.toStdString(), &Bestand, 0)))
	{
		ui.statusBar->showMessage("Leihe konnte nicht vollzogen werden - Bitte ein Exemplar auswaehlen", 800);
		return;
	}
	
	if (mTmp->getEigner() != "00000")
	{
		ui.statusBar->showMessage("Ausgewaehltes Medium ist schon verliehen", 800);
		return;
	}

//Aktuelles Datum ermitteln
	char tmpDat[11];
	getDatum(tmpDat, 0);
	std::string leihdatum(tmpDat);
//Abgabedatum ermitteln ( + 30 Tage voreinstellung )
	getDatum(tmpDat, 30);
	std::string Abgabedatum(tmpDat);

	

//Neue Daten in Medium-Objekt eintragen (Membervariablen aktualisieren)
	mTmp->setEigner(nummer);
	mTmp->setLeihDat(leihdatum);
	mTmp->setFristDat(Abgabedatum);
//Medium in Leihliste des gewählten Kunden eintragen
	pTmp->leiheAus(mTmp);
	
	aktualisiereTabellen(mBuch, mVideo, mCD);
}

void MainWindow::on_mDeleteExempBtn_clicked()
{
	QModelIndexList indexes = ui.BibTree->selectionModel()->selectedIndexes();
	if (indexes.size() <= 0)
		return;

	QModelIndex selectedIndex = indexes.at(0); //Artikelnummer
	QVariant data = ui.treeWidget->model()->data(selectedIndex);
	QString nummer = data.toString();

	Medium* mTmp;

//Medium aus Liste holen
	if (!(mTmp = holeMedium(nummer.toStdString(), &Bestand, 0)))
	{
		ui.statusBar->showMessage("Bitte waehlen sie ein Exemplar aus um es zu entfernen", 800);
		return;
	}

//Falls ausgeliehen: Ausleihe beenden
	if (mTmp->getEigner() != "00000")
	{
		Person* pTmp = holePerson(mTmp->getEigner());
		pTmp->leiheRueck(mTmp);
	}

//Aus Liste löschen
	for (std::list<std::list<Medium*> >::iterator it = Bestand.begin(); it != Bestand.end(); ++it)
	{
		std::list<Medium*>::iterator mit = it->begin();

		for (; mit != it->end(); ++mit)
		{
			
			if (!((*mit)->getNr().compare(nummer.toStdString())))
			{
				mit = it->erase(mit);
			//leere Listen entfernen
				if (it->empty())
					it = Bestand.erase(it);
				goto weiter;
			}
		}
	}
	weiter:
	aktualisiereTabellen(mBuch, mVideo, mCD);
}

void MainWindow::on_mDeleteProtoBtn_clicked()
{
	QModelIndexList indexes = ui.BibTree->selectionModel()->selectedIndexes();
	if (indexes.size() <= 0)
		return;

	QModelIndex selectedIndex = indexes.at(0); //Artikelnummer
	QVariant data = ui.treeWidget->model()->data(selectedIndex);
	QString titel = data.toString();

	Medium* mTmp;
	Person* pTmp;

	//Medium aus Liste holen
	if (!(mTmp = holeMedium(titel.toStdString(), &Bestand, 1)))
	{
		ui.statusBar->showMessage("Bitte waehlen sie einen Prototyp aus um es zu entfernen", 800);
		return;
	}

	//Aus Liste löschen
	for (std::list<std::list<Medium*> >::iterator it = Bestand.begin(); it != Bestand.end(); ++it)
	{
		std::list<Medium*>::iterator mit = it->begin();

		if (!(it->back()->getName().compare(titel.toStdString())))
		{
			std::list<Medium*>::iterator mit = it->begin();

			for (; mit != it->end();)
			{
				if ((*mit)->getEigner() != "00000")
				{
					pTmp = holePerson((*mit)->getEigner());
					pTmp->leiheRueck((*mit));
				}
				mit = it->erase(mit);
			}
			it = Bestand.erase(it);
			break;
		}
	}
	aktualisiereTabellen(mBuch, mVideo, mCD);
}

//3 Funktionen, die auf Häckchensetzung der Auswahlcheckboxen für Bestandsanzeige reagieren
void MainWindow::on_BuchCheckbox_stateChanged()
{
	if (ui.BuchCheckbox->isChecked())
		mBuch = true;
	else
		mBuch = false;

	aktualisiereTabellen(mBuch, mVideo, mCD);
}
void MainWindow::on_VideoCheckbox_stateChanged()
{
	if (ui.VideoCheckbox->isChecked())
		mVideo = true;
	else
		mVideo = false;

	aktualisiereTabellen(mBuch, mVideo, mCD);
}
void MainWindow::on_CDCheckbox_stateChanged()
{
	if (ui.CDCheckbox->isChecked())
		mCD = true;
	else
		mCD = false;

	aktualisiereTabellen(mBuch, mVideo, mCD);
}

//prüft, ob Medium schon im Bestand existiert anhand der übergebenen Nummer oder des Namens
bool MediumExistiertSchon(std::string str, std::list<std::list<Medium*> > *Bestand, int typ)
{
//typ gibt an ob der Name "1" oder die Nummer "0" verglichen werden sollen
	for (std::list<std::list<Medium*> >::iterator it = Bestand->begin(); it != Bestand->end(); ++it)
	{
		std::list<Medium*>::iterator mit = it->begin();

		for (; mit != it->end(); mit++)
		{
			if(typ)
            {
				if (!(*mit)->getName().compare(str))
					return true;
            }
            else
            {
				if (!(*mit)->getNr().compare(str))
					return true;
            }
		}
	}
	return false;
}

//Aktuelles Datum ermitteln und in ret schreiben
void getDatum(char* ret, int extra)
{
	time_t jetzt;
	struct tm jetztLokal;

//Zu aktuellem Zeitpunkt Sekunden eines Tages * Extratage hinzuaddieren
	jetzt = time(NULL) + 60 * 60 * 24 * extra;

	jetztLokal = *localtime(&jetzt);

	char dat[11];

	sprintf(dat, "%02d.%02d.%4d", jetztLokal.tm_mday,
		jetztLokal.tm_mon + 1,
		jetztLokal.tm_year + 1900);
	strcpy(ret, dat);
}

//Funktion die prüft, ob übergebener String Kriterien für Namen erfüllt
bool istZulaessigerString(std::string str) 
{
	if (str[0] < 0 || !isupper(str[0]))
		return false;
	for (unsigned int i = 1; i < str.length(); i++)
	{
		if (!(str[0] == '-' || isspace(str[0]) || isalnum(str[0])))
			return false;
	}
	return true;
}

//Funktion die prüft, ob übergebener String die Form XX.XX.XXXX erfüllt
bool istGebdat(std::string str)
{
	std::string year, month, day;

	if (str.length() > 10)
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (str[i] < 0)
			return false;
		if (i == 2 || i == 5)
		{
			if (str[i] != '.')
				return false;
		}
		else
			if (!isdigit(str[i]))
				return false;
	}

	return true;
}

//Prüfen, ob übergebener String der übergebenen länge entspricht und prüfen ob String aus Ziffern besteht
bool istZulaessigeNummer(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] < 0)
			return false;
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

//Prüfen, ob übergebene Nummer schon im Medienbestand vorkommt
bool NummerExistiertSchon(std::string str, std::list<Person> *group)
{
	for (std::list<Person>::iterator it = group->begin(); it != group->end(); ++it)
	{
		if (!str.compare(it->getNr()))
			return true;
	}
	return false;
}

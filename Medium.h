#ifndef MEDIUM_H
#define MEDIUM_H

#include <QtDebug>

#include <iostream>
#include <string>




class Medium
{
public:

    virtual void setEigner(std::string eigner) { qDebug()<<QString::fromStdString(eigner)<<":Eigner konnte nicht gesetzt werden"; }
    virtual void setLeihDat(std::string leihDat) { qDebug() <<  QString::fromStdString(leihDat) << ":Konnte nicht ausgeliehen werden"; }
    virtual void setFristDat(std::string fristDat) { qDebug()<<QString::fromStdString(fristDat)<<":konnte kein Fristdatum eintragen"; }
	
    virtual std::string const getName() { return "Kein Name vorhanden"; }
    virtual std::string const getNr() { return "Keine Nr vorhanden"; }
    virtual std::string const getKuenstler() { return "Kein Kuenstler vorhanden"; }
    virtual std::string const getHerausgeber() { return "Kein Herausgeber vorhanden"; }
    virtual std::string const getJahr() { return "Kein Erscheinungsjahr vorhanden"; }
    virtual int getTyp() { return 0; }

    virtual std::string const getEigner() { return "Kein Eigner vorhanden"; }
    virtual std::string const getAusleihDat() { return "noch nicht verliehen"; }
    virtual std::string const getFristDat() { return "noch nicht verliehen"; }

private:
    std::string mName;
};

#endif

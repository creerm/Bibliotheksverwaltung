#ifndef BOOK_H
#define BOOK_H

#include "Medium.h"
class Book :
	public Medium
{
public:
    Book(std::string nr, std::string autor, std::string name, std::string herausgeber, std::string jahr);
	~Book();


    void setEigner(std::string eigner) { mEigner = eigner; }
    void setLeihDat(std::string leihDat) { mLeihDat = leihDat; }
    void setFristDat(std::string fristDat) { mFristDat = fristDat; }

    std::string const getName() { return mName; }
    std::string const getNr() { return mNr; }
    std::string const getKuenstler() { return mAutor; }
    std::string const getHerausgeber() { return mHerausgeber; }
    std::string const getJahr() { return mJahr; }
    int getTyp() { return 3; }

    std::string const getEigner() { return mEigner; }
    std::string const getAusleihDat() { return mLeihDat; }
    std::string const getFristDat() { return mFristDat; }
private:
    std::string mName;
    std::string mNr;
    std::string mAutor;
    std::string mHerausgeber;
    std::string mJahr;

    std::string mEigner;
    std::string mLeihDat;
    std::string mFristDat;
};

#endif

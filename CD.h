#ifndef CD_H
#define CD_H

#include "Medium.h"
class CD :
	public Medium
{
public:
    CD(std::string nr, std::string name, std::string Kuenstler, std::string label, std::string jahr);
	~CD();

    void setEigner(std::string eigner) { mEigner = eigner; }
    void setLeihDat(std::string leihDat) { mLeihDat = leihDat; }
    void setFristDat(std::string fristDat) { mFristDat = fristDat; }

    std::string const getName() { return mName; }
    std::string const getNr() { return mNr; }
    std::string const getKuenstler() { return mKuenstler; }
    std::string const getHerausgeber() { return mLabel; }
    std::string const getJahr() { return mJahr; }
    int getTyp() { return 1; }

    std::string const getEigner() { return mEigner; }
    std::string const getAusleihDat() { return mLeihDat; }
    std::string const getFristDat() { return mFristDat; }
private:
    std::string mName;
    std::string mNr;
    std::string mKuenstler;
    std::string mLabel;
    std::string mJahr;

    std::string mEigner;
    std::string mLeihDat;
    std::string mFristDat;
};

#endif

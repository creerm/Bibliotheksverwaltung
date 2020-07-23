#ifndef VIDEO_H
#define VIDEO_H

#include "Medium.h"

class Video :
	public Medium
{
public:
    Video(std::string nr, std::string name, std::string regisseur, std::string filmverleih, std::string jahr);
	~Video();

    void setEigner(std::string eigner) { mEigner = eigner; }
    void setLeihDat(std::string leihDat) { mLeihDat = leihDat; }
    void setFristDat(std::string fristDat) { mFristDat = fristDat; }

    std::string const getName() { return mName; }
    std::string const getNr() { return mNr; }
    std::string const getKuenstler() { return mRegisseur; }
    std::string const getHerausgeber() { return mFilmverleih; }
    std::string const getJahr() { return mJahr; }
    int getTyp() { return 2; }

    std::string const getEigner() { return mEigner; }
    std::string const getAusleihDat() { return mLeihDat; }
    std::string const getFristDat() { return mFristDat; }
private:
    std::string mName;
    std::string mNr;
    std::string mRegisseur;
    std::string mFilmverleih;
    std::string mJahr;

    std::string mEigner;
    std::string mLeihDat;
    std::string mFristDat;
};

#endif

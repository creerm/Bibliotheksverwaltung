#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTreeWidgetItem>

#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QLabel>

#include "Person.h"
#include "Medium.h"
#include "Person.h"
#include "Book.h"
#include "Video.h"
#include "CD.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //MainWindow(QWidget *parent = Q_NULLPTR);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void run();

private slots:
    void on_mBtnLeiheBeenden_clicked();
    void on_mCloseBtn_clicked();
    void on_mDeletePersonBtn_clicked();
    void on_mKundeHinzuBtn_clicked();
    void on_mNeuesMediumBtn_clicked();
    void on_mAltHinzuBtn_clicked();
    void on_mLeihBtn_clicked();
    void on_mDeleteExempBtn_clicked();
    void on_mDeleteProtoBtn_clicked();

    void on_BuchCheckbox_stateChanged();
    void on_VideoCheckbox_stateChanged();
    void on_CDCheckbox_stateChanged();

private:
    Ui::MainWindowClass ui;
    std::list<Person> group;
    std::list<std::list<Medium*> > Bestand;

    bool mBuch, mVideo, mCD;

    QTreeWidgetItem*  addRoot(std::string nr, std::string vorname, std::string name, char geschl, std::string ort, std::string GebDat);
    void addChild(QTreeWidgetItem *parent, std::string name, std::string Description, std::string leihDat, std::string fristDat, int typ);
    QTreeWidgetItem* BibAddRoot(std::string titel, std::string autor, std::string herausgeber, std::string erscheinungsjahr, int exemplare);
    void BibAddChild(QTreeWidgetItem *parent, std::string nr, std::string name, std::string eigner, std::string leihDat, std::string fristDat, int leihbar);

    Person* holePerson(std::string nummer);
    void aktualisiereTabellen(bool buch, bool video, bool cd);
};

#endif

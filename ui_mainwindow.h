/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabBib;
    QWidget *tab;
    QTreeWidget *treeWidget;
    QPushButton *mBtnLeiheBeenden;
    QPushButton *mDeletePersonBtn;
    QPushButton *mKundeHinzuBtn;
    QLineEdit *VornameEdt;
    QLineEdit *NachnameEdt;
    QLineEdit *NummerEdt;
    QGroupBox *mRadioBox;
    QRadioButton *wRadio;
    QRadioButton *mRadio;
    QLineEdit *OrtEdt;
    QLineEdit *GebdatEdt;
    QWidget *tab_2;
    QTreeWidget *BibTree;
    QLineEdit *TitelEdt;
    QLineEdit *VerlagEdt;
    QLineEdit *MedienNrEdt;
    QLineEdit *AutorEdt;
    QLineEdit *JahrEdt;
    QGroupBox *groupBox;
    QRadioButton *cRadio;
    QRadioButton *vRadio;
    QRadioButton *bRadio;
    QLabel *label_2;
    QPushButton *mNeuesMediumBtn;
    QPushButton *mAltHinzuBtn;
    QLineEdit *altNrEdt;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QRadioButton *comboRadio;
    QRadioButton *manuellRadio;
    QPushButton *mLeihBtn;
    QLineEdit *manuNummerEdt;
    QComboBox *mComboBox;
    QLabel *label_4;
    QCheckBox *BuchCheckbox;
    QCheckBox *VideoCheckbox;
    QCheckBox *CDCheckbox;
    QPushButton *mDeleteExempBtn;
    QPushButton *mDeleteProtoBtn;
    QPushButton *mCloseBtn;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(989, 605);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabBib = new QTabWidget(centralWidget);
        tabBib->setObjectName(QString::fromUtf8("tabBib"));
        tabBib->setEnabled(true);
        tabBib->setIconSize(QSize(20, 0));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        treeWidget = new QTreeWidget(tab);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(5, QString::fromUtf8("6"));
        __qtreewidgetitem->setText(4, QString::fromUtf8("5"));
        __qtreewidgetitem->setText(3, QString::fromUtf8("4"));
        __qtreewidgetitem->setText(2, QString::fromUtf8("3"));
        __qtreewidgetitem->setText(1, QString::fromUtf8("2"));
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(0, 20, 571, 321));
        treeWidget->setIconSize(QSize(20, 0));
        treeWidget->setSortingEnabled(true);
        treeWidget->setColumnCount(6);
        treeWidget->header()->setDefaultSectionSize(90);
        treeWidget->header()->setMinimumSectionSize(40);
        treeWidget->header()->setProperty("showSortIndicator", QVariant(true));
        mBtnLeiheBeenden = new QPushButton(tab);
        mBtnLeiheBeenden->setObjectName(QString::fromUtf8("mBtnLeiheBeenden"));
        mBtnLeiheBeenden->setGeometry(QRect(420, 370, 111, 25));
        mDeletePersonBtn = new QPushButton(tab);
        mDeletePersonBtn->setObjectName(QString::fromUtf8("mDeletePersonBtn"));
        mDeletePersonBtn->setGeometry(QRect(10, 370, 341, 23));
        mKundeHinzuBtn = new QPushButton(tab);
        mKundeHinzuBtn->setObjectName(QString::fromUtf8("mKundeHinzuBtn"));
        mKundeHinzuBtn->setGeometry(QRect(600, 150, 191, 23));
        VornameEdt = new QLineEdit(tab);
        VornameEdt->setObjectName(QString::fromUtf8("VornameEdt"));
        VornameEdt->setGeometry(QRect(602, 30, 121, 20));
        NachnameEdt = new QLineEdit(tab);
        NachnameEdt->setObjectName(QString::fromUtf8("NachnameEdt"));
        NachnameEdt->setGeometry(QRect(740, 30, 113, 20));
        NummerEdt = new QLineEdit(tab);
        NummerEdt->setObjectName(QString::fromUtf8("NummerEdt"));
        NummerEdt->setGeometry(QRect(602, 60, 121, 20));
        mRadioBox = new QGroupBox(tab);
        mRadioBox->setObjectName(QString::fromUtf8("mRadioBox"));
        mRadioBox->setGeometry(QRect(740, 60, 120, 80));
        wRadio = new QRadioButton(mRadioBox);
        wRadio->setObjectName(QString::fromUtf8("wRadio"));
        wRadio->setGeometry(QRect(10, 40, 82, 17));
        mRadio = new QRadioButton(mRadioBox);
        mRadio->setObjectName(QString::fromUtf8("mRadio"));
        mRadio->setGeometry(QRect(10, 20, 82, 17));
        OrtEdt = new QLineEdit(tab);
        OrtEdt->setObjectName(QString::fromUtf8("OrtEdt"));
        OrtEdt->setGeometry(QRect(602, 90, 121, 20));
        GebdatEdt = new QLineEdit(tab);
        GebdatEdt->setObjectName(QString::fromUtf8("GebdatEdt"));
        GebdatEdt->setGeometry(QRect(602, 120, 121, 20));
        tabBib->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        BibTree = new QTreeWidget(tab_2);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(4, QString::fromUtf8("5"));
        __qtreewidgetitem1->setText(3, QString::fromUtf8("4"));
        __qtreewidgetitem1->setText(2, QString::fromUtf8("3"));
        __qtreewidgetitem1->setText(1, QString::fromUtf8("2"));
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        BibTree->setHeaderItem(__qtreewidgetitem1);
        BibTree->setObjectName(QString::fromUtf8("BibTree"));
        BibTree->setGeometry(QRect(0, 40, 611, 192));
        BibTree->setSortingEnabled(true);
        BibTree->setColumnCount(5);
        BibTree->header()->setDefaultSectionSize(125);
        BibTree->header()->setMinimumSectionSize(28);
        BibTree->header()->setProperty("showSortIndicator", QVariant(true));
        TitelEdt = new QLineEdit(tab_2);
        TitelEdt->setObjectName(QString::fromUtf8("TitelEdt"));
        TitelEdt->setGeometry(QRect(640, 50, 113, 20));
        VerlagEdt = new QLineEdit(tab_2);
        VerlagEdt->setObjectName(QString::fromUtf8("VerlagEdt"));
        VerlagEdt->setGeometry(QRect(640, 80, 113, 20));
        MedienNrEdt = new QLineEdit(tab_2);
        MedienNrEdt->setObjectName(QString::fromUtf8("MedienNrEdt"));
        MedienNrEdt->setGeometry(QRect(640, 110, 113, 20));
        AutorEdt = new QLineEdit(tab_2);
        AutorEdt->setObjectName(QString::fromUtf8("AutorEdt"));
        AutorEdt->setGeometry(QRect(760, 50, 113, 20));
        JahrEdt = new QLineEdit(tab_2);
        JahrEdt->setObjectName(QString::fromUtf8("JahrEdt"));
        JahrEdt->setGeometry(QRect(640, 140, 113, 20));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(760, 80, 120, 80));
        cRadio = new QRadioButton(groupBox);
        cRadio->setObjectName(QString::fromUtf8("cRadio"));
        cRadio->setGeometry(QRect(10, 20, 82, 17));
        vRadio = new QRadioButton(groupBox);
        vRadio->setObjectName(QString::fromUtf8("vRadio"));
        vRadio->setGeometry(QRect(10, 40, 82, 17));
        bRadio = new QRadioButton(groupBox);
        bRadio->setObjectName(QString::fromUtf8("bRadio"));
        bRadio->setGeometry(QRect(10, 60, 82, 17));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(620, 20, 161, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        mNeuesMediumBtn = new QPushButton(tab_2);
        mNeuesMediumBtn->setObjectName(QString::fromUtf8("mNeuesMediumBtn"));
        mNeuesMediumBtn->setGeometry(QRect(634, 170, 251, 23));
        mAltHinzuBtn = new QPushButton(tab_2);
        mAltHinzuBtn->setObjectName(QString::fromUtf8("mAltHinzuBtn"));
        mAltHinzuBtn->setGeometry(QRect(610, 270, 291, 23));
        altNrEdt = new QLineEdit(tab_2);
        altNrEdt->setObjectName(QString::fromUtf8("altNrEdt"));
        altNrEdt->setGeometry(QRect(630, 240, 151, 20));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 270, 201, 16));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 300, 331, 41));
        comboRadio = new QRadioButton(groupBox_2);
        comboRadio->setObjectName(QString::fromUtf8("comboRadio"));
        comboRadio->setEnabled(true);
        comboRadio->setGeometry(QRect(10, 20, 171, 17));
        comboRadio->setCheckable(true);
        comboRadio->setChecked(true);
        comboRadio->setAutoExclusive(true);
        manuellRadio = new QRadioButton(groupBox_2);
        manuellRadio->setObjectName(QString::fromUtf8("manuellRadio"));
        manuellRadio->setGeometry(QRect(210, 20, 111, 17));
        mLeihBtn = new QPushButton(tab_2);
        mLeihBtn->setObjectName(QString::fromUtf8("mLeihBtn"));
        mLeihBtn->setGeometry(QRect(230, 270, 121, 23));
        manuNummerEdt = new QLineEdit(tab_2);
        manuNummerEdt->setObjectName(QString::fromUtf8("manuNummerEdt"));
        manuNummerEdt->setGeometry(QRect(240, 350, 113, 21));
        mComboBox = new QComboBox(tab_2);
        mComboBox->setObjectName(QString::fromUtf8("mComboBox"));
        mComboBox->setGeometry(QRect(30, 350, 191, 22));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(620, 210, 311, 16));
        label_4->setFont(font);
        BuchCheckbox = new QCheckBox(tab_2);
        BuchCheckbox->setObjectName(QString::fromUtf8("BuchCheckbox"));
        BuchCheckbox->setGeometry(QRect(10, 10, 70, 17));
        BuchCheckbox->setChecked(true);
        VideoCheckbox = new QCheckBox(tab_2);
        VideoCheckbox->setObjectName(QString::fromUtf8("VideoCheckbox"));
        VideoCheckbox->setGeometry(QRect(80, 10, 70, 17));
        VideoCheckbox->setChecked(true);
        CDCheckbox = new QCheckBox(tab_2);
        CDCheckbox->setObjectName(QString::fromUtf8("CDCheckbox"));
        CDCheckbox->setGeometry(QRect(150, 10, 70, 17));
        CDCheckbox->setChecked(true);
        mDeleteExempBtn = new QPushButton(tab_2);
        mDeleteExempBtn->setObjectName(QString::fromUtf8("mDeleteExempBtn"));
        mDeleteExempBtn->setGeometry(QRect(0, 240, 111, 23));
        mDeleteProtoBtn = new QPushButton(tab_2);
        mDeleteProtoBtn->setObjectName(QString::fromUtf8("mDeleteProtoBtn"));
        mDeleteProtoBtn->setGeometry(QRect(130, 240, 311, 23));
        tabBib->addTab(tab_2, QString());

        verticalLayout->addWidget(tabBib);

        mCloseBtn = new QPushButton(centralWidget);
        mCloseBtn->setObjectName(QString::fromUtf8("mCloseBtn"));

        verticalLayout->addWidget(mCloseBtn);

        MainWindowClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        tabBib->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "Bibliothek", 0, QApplication::UnicodeUTF8));
        mBtnLeiheBeenden->setText(QApplication::translate("MainWindowClass", "Zur\303\274ckgeben", 0, QApplication::UnicodeUTF8));
        mDeletePersonBtn->setText(QApplication::translate("MainWindowClass", "Kunden entfernen und dessen Ausleihen beenden", 0, QApplication::UnicodeUTF8));
        mKundeHinzuBtn->setText(QApplication::translate("MainWindowClass", "Neuen Kunden hinzuf\303\274gen", 0, QApplication::UnicodeUTF8));
        VornameEdt->setPlaceholderText(QApplication::translate("MainWindowClass", "Vorname", 0, QApplication::UnicodeUTF8));
        NachnameEdt->setText(QString());
        NachnameEdt->setPlaceholderText(QApplication::translate("MainWindowClass", "Nachname", 0, QApplication::UnicodeUTF8));
        NummerEdt->setPlaceholderText(QApplication::translate("MainWindowClass", "Nummer (5-stellig)", 0, QApplication::UnicodeUTF8));
        mRadioBox->setTitle(QApplication::translate("MainWindowClass", "Geschlecht", 0, QApplication::UnicodeUTF8));
        wRadio->setText(QApplication::translate("MainWindowClass", "weib&lich", 0, QApplication::UnicodeUTF8));
        mRadio->setText(QApplication::translate("MainWindowClass", "mae&nnlich", 0, QApplication::UnicodeUTF8));
        OrtEdt->setText(QString());
        OrtEdt->setPlaceholderText(QApplication::translate("MainWindowClass", "Wohnort", 0, QApplication::UnicodeUTF8));
        GebdatEdt->setPlaceholderText(QApplication::translate("MainWindowClass", "DD.MM.YYYY (Geburtsdatum ", 0, QApplication::UnicodeUTF8));
        tabBib->setTabText(tabBib->indexOf(tab), QApplication::translate("MainWindowClass", "Kunden", 0, QApplication::UnicodeUTF8));
        TitelEdt->setPlaceholderText(QApplication::translate("MainWindowClass", "Titel", 0, QApplication::UnicodeUTF8));
        VerlagEdt->setPlaceholderText(QApplication::translate("MainWindowClass", "Herausgeber", 0, QApplication::UnicodeUTF8));
        MedienNrEdt->setPlaceholderText(QApplication::translate("MainWindowClass", "Nummer (vierstellig)", 0, QApplication::UnicodeUTF8));
        AutorEdt->setPlaceholderText(QApplication::translate("MainWindowClass", "Autor/ Kuenstler", 0, QApplication::UnicodeUTF8));
        JahrEdt->setPlaceholderText(QApplication::translate("MainWindowClass", "Erscheinungsjahr", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindowClass", "Medienart", 0, QApplication::UnicodeUTF8));
        cRadio->setText(QApplication::translate("MainWindowClass", "CD", 0, QApplication::UnicodeUTF8));
        vRadio->setText(QApplication::translate("MainWindowClass", "&Video", 0, QApplication::UnicodeUTF8));
        bRadio->setText(QApplication::translate("MainWindowClass", "B&uch", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindowClass", "Neues Medium hinzufuegen", 0, QApplication::UnicodeUTF8));
        mNeuesMediumBtn->setText(QApplication::translate("MainWindowClass", "Hinzuf\303\274gen", 0, QApplication::UnicodeUTF8));
        mAltHinzuBtn->setText(QApplication::translate("MainWindowClass", "Weiteres Exemplar von makiertem Medium hinzuf\303\274gen", 0, QApplication::UnicodeUTF8));
        altNrEdt->setPlaceholderText(QApplication::translate("MainWindowClass", "Nummer (vierstellig)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindowClass", "Makiertes Exemplar ausleihen an", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindowClass", "GroupBox", 0, QApplication::UnicodeUTF8));
        comboRadio->setText(QApplication::translate("MainWindowClass", "&Kunde aus Liste ausw\303\244hlen", 0, QApplication::UnicodeUTF8));
        manuellRadio->setText(QApplication::translate("MainWindowClass", "ma&nuelle Eingabe", 0, QApplication::UnicodeUTF8));
        mLeihBtn->setText(QApplication::translate("MainWindowClass", "Verleihen", 0, QApplication::UnicodeUTF8));
        manuNummerEdt->setPlaceholderText(QApplication::translate("MainWindowClass", "Kundennummer", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindowClass", "Neues Exemplar zu bestehendem Medium hinzuf\303\274gen", 0, QApplication::UnicodeUTF8));
        BuchCheckbox->setText(QApplication::translate("MainWindowClass", "B\303\274cher", 0, QApplication::UnicodeUTF8));
        VideoCheckbox->setText(QApplication::translate("MainWindowClass", "Videos", 0, QApplication::UnicodeUTF8));
        CDCheckbox->setText(QApplication::translate("MainWindowClass", "CDs", 0, QApplication::UnicodeUTF8));
        mDeleteExempBtn->setText(QApplication::translate("MainWindowClass", "Exemplar l\303\266schen", 0, QApplication::UnicodeUTF8));
        mDeleteProtoBtn->setText(QApplication::translate("MainWindowClass", "Alle Exemplare von ausgew\303\244hltem Prototyp l\303\266schen l\303\266schen", 0, QApplication::UnicodeUTF8));
        tabBib->setTabText(tabBib->indexOf(tab_2), QApplication::translate("MainWindowClass", "Bestand", 0, QApplication::UnicodeUTF8));
        mCloseBtn->setText(QApplication::translate("MainWindowClass", "Speichern und beenden", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

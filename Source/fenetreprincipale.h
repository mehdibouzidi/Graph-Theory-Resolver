#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QMainWindow>
#include <vector>
#include "sommet.h"
#include <QtGui>
#include <QtCore>
#include <QProgressBar>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QTableView>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMessageBox>
#include <vector>
#include <string>
#include <QSpinBox>
#include <iostream>


#include "detecteurdesommet.h"
namespace Ui {
class FenetrePrincipale;
}

class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    explicit FenetrePrincipale(QWidget *parent = 0);
    ~FenetrePrincipale();

  /*~~~~~~~~~~~~~ Méthodes ~~~~~~~~~~~~~*/


private:
    Ui::FenetrePrincipale *ui;
    QGroupBox *grapheBox,*modificateur,*tableau;
    QPushButton *parcourrirBtn,*executerBtn;
    QLineEdit *parcourrirEdit;
    QTableView *table;
    QString fichier;
    QFile *matriceTxt;
    QStandardItemModel *tab;
    DetecteurDeSommet *graphe;
    QSpinBox            *tailleGraphe;
    QLabel              *tailleGrapheLbl;
    QProgressBar        *pourcentage;
    bool parc;
private slots:
    void sourisCliquee();
    void parcourrir();
    void executer();
    void aProp();
    void changementTab(int i);
    void bipartie();
    void gloutonC();
    void gloutonMCP();
    void gloutonMCPReel();
    void nouveauG();
    void coloration5();
    void reinitialiserLesCouleurs();
    void redessinerAretes();
    void redessinerGraphe();
    void recuitSimule();
    void ordreSimplicial();
    void ordreQLNC2();

};

#endif // FENETREPRINCIPALE_H

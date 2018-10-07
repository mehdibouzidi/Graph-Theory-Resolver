#ifndef DETECTEURDESOMMET_H
#define DETECTEURDESOMMET_H

#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QEvent>
#include <QDialog>
#include <QProgressBar>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <map>
#include "sommet.h"
class DetecteurDeSommet : public QWidget
{
    Q_OBJECT
public:
 explicit DetecteurDeSommet(QWidget *parent,std::vector<std::vector<int> > mat);

     /*~~~~~~~~~~~~~ Méthodes ~~~~~~~~~~~~~*/
    void mousePressEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *e);
    int aleaInt();
    int aleatoire(int b);
    double aleatoireD();
    bool existX(int x);
    bool existY(int y);
    bool bipartie();
    int gloutonC();
    std::vector<int> gloutonMCP();
    std::vector<int> gloutonMCPREEL();
    std::vector<int> gloutonMCPSystematique();
    std::vector<int> gloutonMCPAleatoire(int sommet);
    void reinitCol();
    std::vector<int> recuitSimule();
    bool siClique(std::vector<int> const& vect);
    bool siAppartient(std::vector<int> const& vect,int i);

    void suppPremElt(std::vector<int> &vect);
    void suppElt(std::vector<int> &vect,int i);
    void suppEltVal(std::vector<int> &vect,int val);
    /************** 5 Coloration ***********/
   bool voisinnageInduit(Sommet* s,std::vector<std::vector<int> > const& mat);
   void suupSommet(Sommet* s,std::vector<std::vector<int> > & mat);
   std::vector<int> eliminationPv5();

   /***************** Reconnaissance ******************/
   std::vector<int> ordreEliminiationSimplicial();
   std::vector<int> ordreEliminiationQLNC2();
   void redessinerAretes();
   void redessinerGraphe();
private:
    int x,y,nbClick;
    QPoint *pt1,*pt2;
    bool B,simplicial,cliquee;
    std::vector<std::vector<int> > matriceAdjacence;
    std::vector<Sommet*>  ensembleSommets;
    std::vector<int> ord;
    std::map<QString,int>  couleurs;

signals:
    void sourisCliquee();
    void sourisPartie();

private slots:
    void sourisCliqueee();


};

#endif // DETECTEURDESOMMET_H

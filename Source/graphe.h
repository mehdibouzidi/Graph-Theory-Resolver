#ifndef GRAPHE_H
#define GRAPHE_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include "sommet.h"

class Graphe : public QMainWindow
{
    Q_OBJECT
public:
    explicit Graphe(QWidget *parent = 0);
    Sommet sommet;
    int x,y;
    QLabel *labb;
    /******* Setters *******/


     /******* Guetters *******/

    /******* Méthodes *******/
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void leaveEvent(QEvent *);

signals:
    void Mouse_Pressed();
    void Mouse_Pos();
    void Mouse_Left();
public slots:
    void SourisPositionActuelle();
    void SourisClickee();
    //void SourisPartie();

private:
Sommet sommets[];
};

#endif // GRAPHE_H

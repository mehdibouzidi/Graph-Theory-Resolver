#include "graphe.h"

Graphe::Graphe(QWidget *parent) : QMainWindow(parent)
{
    QWidget *fenetreCentrale=new QWidget;
    fenetreCentrale->setFixedSize(1200,720);

    //QHBoxLayout *layoutPrincipal=new QHBoxLayout;
    //layoutPrincipal->addWidget(lab);

    Sommet *som=new Sommet(this,33,50,200);
    //layoutPrincipal->addWidget(som);
    //fenetreCentrale->setLayout(layoutPrincipal);
   connect(this,SIGNAL(Mouse_Pos()),this,SLOT(SourisPositionActuelle()));
    connect(this,SIGNAL(Mouse_Pressed()),this,SLOT(SourisClickee()));
   // connect(this,SIGNAL(Mouse_Left()),this,SLOT(SourisPartie());
    labb=new QLabel(this); labb->setText(QString("QQ"));
    setCentralWidget(fenetreCentrale);
}

void Graphe::SourisPositionActuelle()
{
    labb->setText(QString("X%1").arg(x));
}

void Graphe::SourisClickee()
{
    Sommet *som=new Sommet (this,1,x,y);
}

/*void Graphe::SourisPartie()
{

}*/


void Graphe::mouseMoveEvent(QMouseEvent *ev)
{
    x=ev->x();
    y=ev->y();
    emit Mouse_Pos();
}

void Graphe::mousePressEvent(QMouseEvent *ev)
{
    x=ev->x();
    y=ev->y();
    emit Mouse_Pressed();
}

void Graphe::leaveEvent(QEvent *)
{
    emit Mouse_Left();
}

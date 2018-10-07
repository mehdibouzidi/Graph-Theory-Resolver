#ifndef SOMMET_H
#define SOMMET_H

#include<QtGui>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QPaintEvent>
#include <QtCore>
#include <QVBoxLayout>
#include <vector>
class Sommet : public QWidget
{
Q_OBJECT
public:
    Sommet();
    Sommet(QWidget *parent);
    Sommet(QWidget *parent,int nomm,int xx,int yy,int deg, std::vector<int> voisin);
    /*Sommet(const Sommet &sommetACopier);
    Sommet &operator=(Sommet const& sommetACopier);*/

    ~Sommet();
    /******* Setters *******/
    void setNom(int n);
    void setX(int xx);
    void setY(int yy);
    void setB(bool b);
    void setDegre(int deg);
    void setCouleur(QString coul);

    /******* Guetters *******/
    int getNom()const;
    int getX()const;
    int getY()const;
    bool getB()const;
    int getDegre()const;
    std::vector<int> getVoisins()const;
    int getVoisin(int i)const;
    QString getCouleur()const;

    QPainter *painter;

    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *ev);

signals:
void sommetClicke();

private:
    int nom;
    int x,y;
    QLabel *no;
    bool B;
    int degre;
    std::vector<int> voisins;
    QString couleur;
private slots:
    void clicke();



};

#endif // SOMMET_H

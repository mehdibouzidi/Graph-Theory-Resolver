#include "sommet.h"
/****************************************** Constructeurs ***********************************/
Sommet::Sommet()
{
    nom=1; x=0; y=0;
    no=new QLabel(this);
    no->setText("X1");
    if(nom/10==0){no->setGeometry(8,8,22,8);}
    else if(nom/10>=1 && nom/10<10){no->setGeometry(6,8,22,8);}
    else if(nom/10>=10 && nom/10<100){no->setGeometry(3,8,22,8);}
    else if(nom/10>=100 && nom/10<1000){no->setGeometry(2,8,22,8);}
    no->setFont(QFont("calibri",7));
    setCursor(Qt::PointingHandCursor);
    setGeometry(0,0,25,25);
    degre=0;
    B=false;
    QString whatIsThis("Nom: ");
    whatIsThis=whatIsThis+QString::number(nom)+"\nDegré: "+QString::number(degre)+"\nVoisins: ";
    for(int i=0;i<voisins.size();i++)
    {
        whatIsThis=whatIsThis+"X"+QString::number(voisins[i]);
        if(i!=voisins.size()-1){whatIsThis=whatIsThis+", ";}
    }

    setToolTip(whatIsThis);
connect(this,SIGNAL(sommetClicke()),this,SLOT(clicke()));
couleur="S1.png";
}

Sommet::Sommet(QWidget *parent)
{
    setParent(parent);
    nom=1; x=0; y=0;
    no=new QLabel(this);
    no->setText("X1");
    if(nom/10==0){no->setGeometry(8,8,22,8);}
    else if(nom/10>=1 && nom/10<10){no->setGeometry(6,8,22,8);}
    else if(nom/10>=10 && nom/10<100){no->setGeometry(3,8,22,8);}
    else if(nom/10>=100 && nom/10<1000){no->setGeometry(2,8,22,8);}
    no->setFont(QFont("calibri",7));
    setCursor(Qt::PointingHandCursor);
    setGeometry(0,0,25,25);
    degre=0;
    B=false;
    QString whatIsThis("Nom: ");
    whatIsThis=whatIsThis+QString::number(nom)+"\nDegré: "+QString::number(degre)+"\nVoisins: ";
    for(int i=0;i<voisins.size();i++)
    {
        whatIsThis=whatIsThis+"X"+QString::number(voisins[i]);
        if(i!=voisins.size()-1){whatIsThis=whatIsThis+", ";}
    }

    setToolTip(whatIsThis);
connect(this,SIGNAL(sommetClicke()),this,SLOT(clicke()));
couleur="S1.png";
}


Sommet::Sommet(QWidget *parent, int nomm, int xx, int yy, int deg, std::vector<int> voisin)
{
    setParent(parent);
    nom=nomm; x=xx; y=yy;
    no=new QLabel(this);
    no->setText(QString("%1").arg(nom));
    if(nom/10==0){no->setGeometry(8,8,22,8);}
    else if(nom/10>=1 && nom/10<10){no->setGeometry(6,8,22,8);}
    else if(nom/10>=10 && nom/10<100){no->setGeometry(3,8,22,8);}
    else if(nom/10>=100 && nom/10<1000){no->setGeometry(2,8,22,8);}
    no->setFont(QFont("calibri",7));
    setCursor(Qt::PointingHandCursor);
    setGeometry(xx,yy,25,25);
    degre=deg;
    voisins=voisin;
    B=false;
    QString whatIsThis("Nom: ");
    whatIsThis=whatIsThis+QString::number(nom)+"\nDegré: "+QString::number(degre)+"\nVoisins: ";
    for(int i=0;i<voisins.size();i++)
    {
        whatIsThis=whatIsThis+"X"+QString::number(voisins[i]);
        if(i!=voisins.size()-1){whatIsThis=whatIsThis+", ";}
    }

    setToolTip(whatIsThis);
connect(this,SIGNAL(sommetClicke()),this,SLOT(clicke()));
couleur="S1.png";
}
/*
Sommet::Sommet(const Sommet &sommetACopier) : nom(sommetACopier.nom), x(sommetACopier.x), y(sommetACopier.y),
    degre(sommetACopier.degre), voisins(sommetACopier.voisins), couleur(sommetACopier.couleur),no(0)
{
    no = new QLabel(*(sommetACopier.no));
}

Sommet &Sommet::operator=(const Sommet &sommetACopier)
{
    if(this != &sommetACopier)
    //On vérifie que l'objet n'est pas le même que celui reçu en argument
    {
    nom = sommetACopier.nom;
    x = sommetACopier.x; y = sommetACopier.y;
    degre = sommetACopier.degre;
    voisins = sommetACopier.voisins;
    couleur = sommetACopier.couleur;

    delete no;
    no = new QLabel(*(sommetACopier.no));
    }
    return *this; //On renvoie l'objet lui-même

}
*/
Sommet::~Sommet()
{
  //  delete no;
}

/****************************************** Setters ***********************************/

void Sommet::setNom(int n){ nom=n; no->setText(QString("X%1").arg(n));}

void Sommet::setX(int xx){x=xx; setGeometry(xx,y,50,10); }

void Sommet::setY(int yy){y=yy; setGeometry(x,yy,50,10); }

void Sommet::setB(bool b){B=b;}

void Sommet::setDegre(int deg){degre=deg;}

void Sommet::setCouleur(QString coul)
{
    couleur=coul;
    setHidden(true);
    setHidden(false);
}



/*********************************** Guetters ***********************************/

int Sommet::getNom() const{return nom;}

int Sommet::getX() const{return x;}

int Sommet::getY() const{return y;}

bool Sommet::getB() const{return B;}

int Sommet::getDegre() const{return degre;}

std::vector<int> Sommet::getVoisins() const
{
    return voisins;
}

int Sommet::getVoisin(int i) const
{
    return voisins[i];
}

QString Sommet::getCouleur() const
{
    return couleur;
}



void Sommet::paintEvent(QPaintEvent *e)
{
    painter=new QPainter(this);
    QPoint point(0,0);
    if(!B){painter->drawPixmap(point,QPixmap(couleur));}
    else{painter->drawPixmap(point,QPixmap("S2.png"));}
}

void Sommet::mousePressEvent(QMouseEvent *ev)
{
    emit sommetClicke();
}

void Sommet::clicke()
{   if(B){B=false;
    }else{B=true;}
    setHidden(true);
    setHidden(false);
}

#include "detecteurdesommet.h"

using namespace std;


DetecteurDeSommet::DetecteurDeSommet(QWidget * parent,std::vector<std::vector<int> > mat) : QWidget(parent)
{

    x=0;y=0; nbClick=0; B=false; simplicial=false; cliquee =false;
    connect(this,SIGNAL(sourisCliquee()),this,SLOT(sourisCliqueee()));

    matriceAdjacence=mat;
    std::vector<int> lesX;
    std::vector<int> lesY;
    std::vector<int> lesDegres;
    std::vector<int> voisins,init;
    std::vector<std::vector<int> > lesVoisins;
    for(int i=0;i<mat.size();i++)
    {
        //+20 +20
        bool exi=true;
        while(exi)
        {
            x=aleaInt();
            exi=existX(x);
        }
        exi=true;
        while(exi)
        {
            y=aleaInt();
            exi=existY(y);
        }
        lesX.push_back(x);
        lesY.push_back(y);

    }

    int deg;
    for(int i=0;i<mat.size();i++)
    {   deg=0;
        for(int j=0;j<mat[0].size();j++)
        {
            if(mat[i][j]==1)
            {
                deg++; voisins.push_back(j+1);
            }
        }
        lesDegres.push_back(deg); lesVoisins.push_back(voisins);
        voisins=init;
    }
    for(int i=0;i<mat.size();i++)
    {
        Sommet *sommet=new Sommet(this,i+1,lesX[i],lesY[i],lesDegres[i],lesVoisins[i]);
        ensembleSommets.push_back(sommet);
    }

    /******************* Initialisation de la map **********************************/
     QString nomC("S");
             for(int i=3;i<114;i++)
     {
           nomC+=QString::number(i);
           nomC+=".png";
           couleurs[nomC]=i;
           nomC="S";
     }
             qsrand(0);

}




void DetecteurDeSommet::mousePressEvent(QMouseEvent *ev)
{
    emit sourisCliquee();
    this->y=ev->y();
    this->x=ev->x();
}

void DetecteurDeSommet::paintEvent(QPaintEvent *e)
{   
    QPainter *painter=new QPainter(this);
    if(!simplicial)
    {
    for(int i=0;i<matriceAdjacence.size();i++)
    {
        for(int j=i;j<matriceAdjacence[0].size();j++)
        {
            if(matriceAdjacence[i][j]==1)
            {
                painter->drawLine(ensembleSommets[i]->getX()+12,ensembleSommets[i]->getY()+20,ensembleSommets[j]->getX()+12,ensembleSommets[j]->getY()+20);
            }
        }
    }
    }
    else
    {
        for(int i=0;i<matriceAdjacence.size();i++)
        {
            if(siAppartient(ord,i+1))
            {
            for(int j=i;j<matriceAdjacence.size();j++)
            {

                if(matriceAdjacence[i][j]==1 && siAppartient(ord,j+1))
                {
                    painter->drawLine(ensembleSommets[i]->getX()+12,ensembleSommets[i]->getY()+20,ensembleSommets[j]->getX()+12,ensembleSommets[j]->getY()+20);
                }
            }
            }
        }

    }

    if(cliquee)
    {
        QPen stilo;

        for(int i=0;i<ord.size();i++)
        {
            for(int j=0;j<ord.size() && ord[i]!=ord[j];j++)
            {
                stilo.setColor(Qt::red); stilo.setWidth(2);painter->setPen(stilo);

                    painter->drawLine(ensembleSommets[ord[i]]->getX()+12,ensembleSommets[ord[i]]->getY()+20,ensembleSommets[ord[j]]->getX()+12,ensembleSommets[ord[j]]->getY()+20);

            }
        }
    }
}

int DetecteurDeSommet::aleaInt()
{
    return qrand() % 780;
}

int DetecteurDeSommet::aleatoire( int b)
{
    //qsrand(0);
    return (qrand()% b);
}

double DetecteurDeSommet::aleatoireD()
{
    return ((double)(qrand()%100) /(double) 100);
}

bool DetecteurDeSommet::existX(int x)
{
    bool k=false;
        if(!ensembleSommets.empty()){

            for(int i=0;i<ensembleSommets.size()&& !k;i++)
            {
                if(ensembleSommets[i]->getX()==x){k=true;}
            }
        }

return k;}

bool DetecteurDeSommet::existY(int y)
{
    bool k=false;
        if(!ensembleSommets.empty()){

            for(int i=0;i<ensembleSommets.size()&& !k;i++)
            {
                if(ensembleSommets[i]->getY()==y){k=true;}
            }
        }

        return k;
}

bool DetecteurDeSommet::bipartie()
{
    if(!ensembleSommets.empty()){ // Si le graphe n'est pas vide
        if(ensembleSommets.size()==1)
            { // Si on a un seul sommet
              ensembleSommets[0]->setCouleur("S3.png");
              return true;
            }
        else
            { // si on a plus d'un sommet
                    bool B(true);
                    bool K(true);
                    vector <Sommet*> s,ss,erasee;
                    Sommet* v;
                    int w;
                    vector <int> inter;

                    s=ensembleSommets;
                    s[0]->setCouleur("S3.png"); // Le premir sommet prend la première couleur
                    QString couleurContraire="S4.png";

                    bool nonCol(false);
                    //bool col(false);

                    while(!s.empty() && B /*&& !col*/)
                    {
                        K=true;

                        for(int i=0;i<s.size() && K ;i++) // Choix du sommet "v" colorié
                        {
                            if(s[i]->getCouleur()!="S1.png"){v=s[i]; K=false;}
                        }


                        if(v->getDegre()!=0){ // Si le sommet possède des voisins
                            inter=v->getVoisins();
                            if(v->getCouleur()=="S3.png"){couleurContraire="S4.png";}else{ couleurContraire="S3.png";}

                        for(int i=0;i<inter.size() && B;i++)
                        {
                            w=inter[i]; // on choisit un sommet du voisinnage

                            for(int j=0;j<s.size() && B;j++)
                            {
                                if(w==s[j]->getNom() ) // On regarde s'il est dans "s"
                                {
                                    if(s[j]->getCouleur()=="S1.png") // s'il est non colorié
                                    {
                                        s[j]->setCouleur(couleurContraire); // on le colorie
                                    }else{
                                    if(s[j]->getCouleur()==v->getCouleur()){B=false;} // le graphe n'est pas bipartie
                                    }

                                }

                            }
                        }
                            }/*else{ // sinon Si le sommet n'a pas de voisin

                            if(v->getCouleur()=="S1.png"){v->setCouleur("S3.png"); }
                        }*/


                      /******** Suppression du sommet "v" de l'ensemble des sommets ****/
                        for(int i=0;i<s.size();i++)
                        {
                            if(s[i]->getNom()!=v->getNom()){ss.push_back(s[i]);}
                        }

                        s=ss;
                        ss=erasee;
                        /***************************************************************/
                            nonCol=false;
                           // col=true;
                            for(int i=0;i<s.size();i++)
                            {
                            if(s[i]->getCouleur()!="S1.png"){nonCol=true;}
                            //if(s[i]->getCouleur()=="S1.png"){col=false;}

                            }
                            if(!nonCol){s[0]->setCouleur("S3.png");} // si tous les sommets restants ne sont pas coloriés
                             K=true;

                    }// Fin Boucle while

                  /********** Affectation des résultats Ok *************/
                    if(!B){
                        for(int i=0;i<ensembleSommets.size();i++)
                        {
                            ensembleSommets[i]->setCouleur("S1.png");
                        }
                            }
                    return B;
        }
    }else{return true;} // si le graphe est vide alors vrai
}


int DetecteurDeSommet::gloutonC()
{

    int min(INFINITY);
    vector<int> couleursVoisin,init;

    for(int i=0;i<ensembleSommets.size();i++)
    {

        if(ensembleSommets[i]->getDegre()!=0)
        { // Si le sommet possède des voisins

        for(int j=0; j<ensembleSommets[i]->getDegre(); j++)
        {
            if(ensembleSommets[ensembleSommets[i]->getVoisin(j)-1]->getCouleur()!="S1.png")
            {
            couleursVoisin.push_back(couleurs[ensembleSommets[ensembleSommets[i]->getVoisin(j)-1]->getCouleur()]);
            }
        }
            sort(couleursVoisin.begin(),couleursVoisin.end());// On trie par ordre croissant les couleurs des voisins
        }
        else{min=3;}//Si le Sommet est isolé


        if(!couleursVoisin.empty()){//Si le sommet a des voisins déjà coloriés

            /*-------- Suppression des valeurs redondantes ---------*/

            for(int l=0;l<couleursVoisin.size();l++)
            {
                for(int m=l+1;m<couleursVoisin.size();m++)
                {
                    if(couleursVoisin[m]==couleursVoisin[l])
                    {
                        suppElt(couleursVoisin,m);
                        m--;
                    }
                }
            }

            /*-----------------------------------------------------------------*/
        if(couleursVoisin[0]>3 && min!=3){min=3;}/*Si le premier voisin est colorié avec une couleur plus grande
                                                   que la plus petite couleurs existante alors le sommet est colorié
                                                   avec celle-ci*/
        else if(couleursVoisin[0]==3) /*Si le premier voisin est colorié avec la plus petite couleurs existante alors
                                        on trie le tableau des couleurs*/
        {
            int cp(3);
            while(min == 2147483647 && !couleursVoisin.empty())
            {
                    if(cp==couleursVoisin[0])
                    {
                        suppPremElt(couleursVoisin);
                        cp++;
                    }else
                    {
                        min=cp;
                    }

            }

            if(couleursVoisin.empty()){min = cp;}
        }

    }else{min = 3;}// Si tous les voisins du sommet courant ne sont pas coloriés

        QString couleur("S");
        couleur+=QString::number(min)+".png";

        ensembleSommets[i]->setCouleur(couleur);

        min=INFINITY;
        couleursVoisin=init;
    }

    /*** Retourner le nombre de couleurs utilisées ***/
    couleursVoisin=init;
    for(int i=0;i<ensembleSommets.size();i++)
    {
        couleursVoisin.push_back(couleurs[ensembleSommets[i]->getCouleur()]);
    }
    sort(couleursVoisin.begin(),couleursVoisin.end());
    return couleursVoisin[couleursVoisin.size()-1]-2;
}

std::vector<int> DetecteurDeSommet::gloutonMCP()
{
    /************ Recherche de "Sj0" *************/
    int maxim(-1),indiceSommet;

    for(int i=0;i<ensembleSommets.size();i++)
    {
        if(maxim<ensembleSommets[i]->getDegre())
        {
            maxim=ensembleSommets[i]->getDegre();
            indiceSommet=i;
        }
    }
    /***********************************************/

    vector<int> cliqueMax,init,inter,ensTravail(ensembleSommets[indiceSommet]->getVoisins());//les voisins sont en indice+1

    cliqueMax.push_back(indiceSommet);
    maxim=-1;
    int compteur(0);
    ensembleSommets[indiceSommet]->setCouleur("S2.png");
    while(!ensTravail.empty())
    {

        /************ Recherche d'un sommet ayant un degré max dans le voisinnage de "Sj" *********/
        for(int i=0;i<ensTravail.size();i++)
        {
            for(int j=0;j<ensTravail.size();j++)
            {
                compteur+=matriceAdjacence[ensTravail[i]-1][ensTravail[j]-1];
            }

            if(maxim<compteur)
            {
                maxim=compteur;
                indiceSommet=ensTravail[i]-1;
            }
        }

        maxim=-1;compteur=0;
        cliqueMax.push_back(indiceSommet);
        ensembleSommets[indiceSommet]->setCouleur("S2.png");

        /************ Construction du voisinnage du sommet Sj *********/
        for(int i=0;i<ensTravail.size();i++)
        {
            if(matriceAdjacence[indiceSommet][ensTravail[i]-1]==1)
            {
                inter.push_back(ensTravail[i]);
            }
        }
            ensTravail=inter;
            inter=init;

    }

    return cliqueMax;}

std::vector<int> DetecteurDeSommet::gloutonMCPREEL()
{
    /************ Recherche de "Sj0" *************/
    int maxim(-1),indiceSommet;

    for(int i=0;i<ensembleSommets.size();i++)
    {
        if(maxim<ensembleSommets[i]->getDegre())
        {
            maxim=ensembleSommets[i]->getDegre();
            indiceSommet=i;
        }
    }
    /***********************************************/

    vector<int> cliqueMax,init,inter,ensTravail(ensembleSommets[indiceSommet]->getVoisins());//les voisins sont en indice+1
    cliquee=true; simplicial=false;
    cliqueMax.push_back(indiceSommet); ord=cliqueMax; repaint();
    maxim=-1;
    int compteur(0);
    ensembleSommets[indiceSommet]->setCouleur("S2.png");
    while(!ensTravail.empty())
    {

        /************ Recherche d'un sommet ayant un degré max dans le voisinnage de "Sj" *********/
        for(int i=0;i<ensTravail.size();i++)
        {
            for(int j=0;j<ensTravail.size();j++)
            {
                compteur+=matriceAdjacence[ensTravail[i]-1][ensTravail[j]-1];
            }

            if(maxim<compteur)
            {
                maxim=compteur;
                indiceSommet=ensTravail[i]-1;
            }
        }

        maxim=-1;compteur=0;
        cliqueMax.push_back(indiceSommet); ord=cliqueMax; repaint();
        ensembleSommets[indiceSommet]->setCouleur("S2.png");

        /************ Construction du voisinnage du sommet Sj *********/
        for(int i=0;i<ensTravail.size();i++)
        {
            if(matriceAdjacence[indiceSommet][ensTravail[i]-1]==1)
            {
                inter.push_back(ensTravail[i]);
            }
        }
            ensTravail=inter;
            inter=init;

    }

    return cliqueMax;

}

std::vector<int> DetecteurDeSommet::gloutonMCPSystematique()
{

    /************ Recherche de "Sj0" *************/
    int maxim(-1),indiceSommet;
    vector<int> BKS;
    /***********************************************/
for(int k=0;k<ensembleSommets.size();k++)
{
    vector<int> cliqueMax,init,inter,ensTravail(ensembleSommets[k]->getVoisins());//les voisins sont en indice+1

    cliqueMax.push_back(k);
    maxim=-1;
    int compteur(0);

    while(!ensTravail.empty())
    {

        /************ Recherche d'un sommet ayant un degré max dans le voisinnage de "Sj" *********/
        for(int i=0;i<ensTravail.size();i++)
        {
            for(int j=0;j<ensTravail.size();j++)
            {
                compteur+=matriceAdjacence[ensTravail[i]-1][ensTravail[j]-1];
            }

            if(maxim<compteur)
            {
                maxim=compteur;
                indiceSommet=ensTravail[i]-1;
            }
        }

        maxim=-1;compteur=0;
        cliqueMax.push_back(indiceSommet);


        /************ Construction du voisinnage du sommet Sj *********/
        for(int i=0;i<ensTravail.size();i++)
        {
            if(matriceAdjacence[indiceSommet][ensTravail[i]-1]==1)
            {
                inter.push_back(ensTravail[i]);
            }
        }
            ensTravail=inter;
            inter=init;

    }
    if(BKS.size()<=cliqueMax.size()) BKS=cliqueMax;
 }
    return BKS;
}

std::vector<int> DetecteurDeSommet::gloutonMCPAleatoire(int sommet)
{

    vector<int> cliqueMax,init,inter,ensTravail(ensembleSommets[sommet]->getVoisins());

    cliqueMax.push_back(sommet);

    int maxim(-1),indiceSommet;
    int compteur(0);

    while(!ensTravail.empty())
    {

        /************ Recherche d'un sommet ayant un degré max dans le voisinnage de "Sj" *********/
        for(int i=0;i<ensTravail.size();i++)
        {
            for(int j=0;j<ensTravail.size();j++)
            {
                compteur+=matriceAdjacence[ensTravail[i]-1][ensTravail[j]-1];
            }
            if(maxim<compteur)
            {
                maxim=compteur;
                indiceSommet=ensTravail[i]-1;
            }
        }

        maxim=-1;compteur=0;
        cliqueMax.push_back(indiceSommet);

          //  cerr<<"5\n";
        /************ Construction du voisinnage du sommet Sj *********/
        for(int i=0;i<ensTravail.size();i++)
        {
            if(matriceAdjacence[indiceSommet][ensTravail[i]-1]==1)
            {
                inter.push_back(ensTravail[i]);
            }
        }
            ensTravail=inter;
            inter=init;

    }


    return cliqueMax;
}

void DetecteurDeSommet::reinitCol()
{
    if(!ensembleSommets.empty())
    {
    for(int i=0;i<ensembleSommets.size();i++)
    {
        ensembleSommets[i]->setCouleur("S1.png");
    }
    }
}

std::vector<int> DetecteurDeSommet::recuitSimule()
{
    //les indices donnés par gloutonMCP & gloutonMCP sont en "-1"(i) non pas (i+1)
    vector<int> e,ePrime,BKS;
    e=gloutonMCPSystematique();
    BKS=e;
    double x;
    double T(BKS.size()),alpha,alphaP,seuil;
    int k;
    int netta(BKS.size());

    if((BKS.size()/100)>=1){netta*=5;T*=100;alpha=0.8;alphaP=0.9;}
    else if((BKS.size()/10)>=1){netta*=10;T*=500;alpha=0.90;alphaP=0.93;}
    else{netta*=15;T*=300;alpha=0.94;alphaP=0.97;}
    if((T/10000)>=1){seuil=1000;}
    else if((T/1000)>=1){seuil=100;}
    else {seuil=10;}

    while(seuil<T)
    {

        for(int i=0;i<netta && seuil<T;i++) // On cherche le min local
        {
            if(aleatoire(2)==0)
            {
                k=aleatoire(e.size()/2);
                k+=e.size()/2;
            }
            else
            {
                k=aleatoire(e.size()/2);
                if(k==0) k++;
            }





            ePrime=gloutonMCPAleatoire(e[k]);


            if(e.size()<ePrime.size())
            {
                e=ePrime;
                if(BKS.size()<=ePrime.size())
                {
                    BKS=ePrime;
                    T*=alphaP;

                }
            }
            else
            {
                x=aleatoireD();


                if(x<exp(-((double)(e.size()-ePrime.size())/T)))
                {
                    e=ePrime;
                }
            }

        }



        T*=alpha;

    }

    reinitCol();



    for(int i=0;i<BKS.size();i++)
        {
            ensembleSommets[BKS[i]]->setCouleur("S2.png");

        }

    return BKS;
}

bool DetecteurDeSommet::siClique(const std::vector<int> &vect)
{
    if(vect.empty()) return true;
    else
    {
    for(int i=0;i<vect.size();i++)
    {
        for(int j=0;j<vect.size() && vect[j]!=vect[i];j++)
        {
            if(matriceAdjacence[vect[i]-1][vect[j]-1]==0) return false;
        }
    }
    return true;
    }
    }

bool DetecteurDeSommet::siAppartient(std::vector<int> const &vect, int i)
{
    for(int j=0;j<vect.size();j++) {if(i==vect[j])return true;}
return false;}

/*-----------------------------------------------------------------------------------------*/

void DetecteurDeSommet::suppPremElt(std::vector<int> &vect)
{
    vector<int> inter;
    for(int i=1;i<vect.size();i++)
    {
        inter.push_back(vect[i]);
    }
    vect=inter;
}

void DetecteurDeSommet::suppElt(std::vector<int> &vect, int i)
{
    vector<int> inter;
    for(int j=0;j<vect.size();j++)
    {
        if(j!=i)
        {
            inter.push_back(vect[j]);
        }
    }
    vect=inter;
}

void DetecteurDeSommet::suppEltVal(std::vector<int> &vect, int val)
{
    vector<int> inter;
    for(int j=0;j<vect.size();j++)
    {
        if(vect[j]!=val)
        {
            inter.push_back(vect[j]);
        }
    }
    vect=inter;

}

/************** 5 Coloration ***********/


bool DetecteurDeSommet::voisinnageInduit(Sommet* s,std::vector<std::vector<int> > const& mat)
{

    vector<vector<int> > adja;
    vector<int> vect,init;
        bool sommetPv5(true);
        int cp(0);
       vector<int> sommets;
       sommets=s->getVoisins();
       sommets.push_back(s->getNom());

    for(int i=0;i<sommets.size() && sommetPv5  ;i++)
    {
        if(mat[sommets[i]-1][0]!=-1)
        {
        for(int j=0;j<sommets.size()  ;j++)
        { if(mat[sommets[j]-1][0]!=-1)
            {
            if(mat[sommets[i]-1][sommets[j]-1] == 1)
            {
                vect.push_back(1); cp++;
            }
            else
            {
                vect.push_back(0);
            }

            }
        }
        adja.push_back(vect);
        vect=init;
            if(cp>5)
            {
                sommetPv5=false;
            }else
            {
            cp=0;
            }
          }
    }
    return sommetPv5;
}


void DetecteurDeSommet::suupSommet(Sommet *s,  std::vector<std::vector<int> > &mat)
{
    for(int i=0;i<mat.size();i++)
    {
        mat[i][s->getNom()-1]=-1;
        mat[s->getNom()-1][i]=-1;
    }
}


std::vector<int> DetecteurDeSommet::eliminationPv5()
{
    std::vector<std::vector<int> > mat=matriceAdjacence;
    vector<int> ordre;

    int cpt(0);
    while(ordre.size()<mat.size())
    {
        if(voisinnageInduit(ensembleSommets[cpt],mat))
        {
            ordre.push_back(ensembleSommets[cpt]->getNom());
            suupSommet(ensembleSommets[cpt],mat);
            cerr<<ensembleSommets[cpt]->getNom()<<" ";
        }



        cpt++;
        if(cpt==mat.size()){cpt=0;}
    }

    return ordre;}

vector<int> DetecteurDeSommet::ordreEliminiationSimplicial()
{
    bool nonSimpl(false);
    simplicial=true;
    vector<int> espaceTravail,ordre,voisinsCourants,voisins,init;
    for(int i=0;i<ensembleSommets.size();i++) espaceTravail.push_back(i+1);

    int k(0),cpt(0),taille(espaceTravail.size());


    while(!espaceTravail.empty() && !nonSimpl)
    {
        voisins=ensembleSommets[espaceTravail[k]-1]->getVoisins();
        //cerr<<"\nElement = "<<espaceTravail[k]<<" Voisins : \n";
        for(int i=0;i<voisins.size();i++)
        {
           if(siAppartient(espaceTravail,voisins[i])) {voisinsCourants.push_back(voisins[i]);/*cerr<<voisins[i]<<" ";*/}

        }
            if(siClique(voisinsCourants))
            {/*cerr<<"Clique\n";*/ordre.push_back(espaceTravail[k]); ensembleSommets[espaceTravail[k]-1]->setHidden(true); suppEltVal(espaceTravail,espaceTravail[k]); ord=espaceTravail; repaint();k--;}
            voisinsCourants=init;

       k++;
        if(k==espaceTravail.size()) k=0;
        if(taille==espaceTravail.size()){cpt++;}else{cpt=0; taille=espaceTravail.size();}
        if(cpt==taille && taille!=0){nonSimpl=true;}
    }

//cerr<<"\n";
if(nonSimpl){ordre=init;}

return ordre;}

std::vector<int> DetecteurDeSommet::ordreEliminiationQLNC2()
{
    bool nonQLNC2(false);
    simplicial=true;
    vector<int> espaceTravail,ordre,voisinsCourants,voisins,init;
    for(int i=0;i<ensembleSommets.size();i++) espaceTravail.push_back(i+1);

    int k(0),cpt(0),taille(espaceTravail.size());

    while(!espaceTravail.empty() && !nonQLNC2)
    {

        voisins=ensembleSommets[espaceTravail[k]-1]->getVoisins();

        for(int i=0;i<voisins.size();i++)
        {
           if(siAppartient(espaceTravail,voisins[i])) {voisinsCourants.push_back(voisins[i]);/*cerr<<voisins[i]<<" ";*/}

        }

            vector<int> vect(voisinsCourants.size(),1);

            vector<vector<int> > matInter;
            for(int i=0;i<voisinsCourants.size();i++) matInter.push_back(vect);

        sort(voisinsCourants.begin(),voisinsCourants.end());
          for(int i=0;i<voisinsCourants.size();i++) {matInter[i][i]=0;}

        for(int i=0;i<voisinsCourants.size();i++)
        {
            for(int j=0;j<voisinsCourants.size() ;j++)
            {
                    if(matriceAdjacence[voisinsCourants[i]-1][voisinsCourants[j]-1]==1){matInter[i][j]=0;}
            }
        }


        DetecteurDeSommet *g=new DetecteurDeSommet(0,matInter);
        g->setHidden(true);

            if(g->bipartie())
            {ordre.push_back(espaceTravail[k]); ensembleSommets[espaceTravail[k]-1]->setHidden(true); suppEltVal(espaceTravail,espaceTravail[k]); ord=espaceTravail; repaint();k--;}
            voisinsCourants=init;

       k++;
        if(k==espaceTravail.size()) k=0;
        if(taille==espaceTravail.size()){cpt++;}else{cpt=0;taille=espaceTravail.size();}
        if(cpt==taille && taille!=0){nonQLNC2=true;}
    }

    if(nonQLNC2){ordre=init;}

    return ordre;
}

void DetecteurDeSommet::redessinerAretes()
{
    simplicial=false;
    cliquee=false;
    repaint();
}

void DetecteurDeSommet::redessinerGraphe()
{
    redessinerAretes();
    for(int i=0;i<ensembleSommets.size();i++) ensembleSommets[i]->setHidden(false);
}




void DetecteurDeSommet::sourisCliqueee()
{
    nbClick++;
   /* std::vector<int> voisins;
    voisins.push_back(1);voisins.push_back(55);
    if(nbClick%2==0){
    Sommet *sosmmet=new Sommet(this,nbClick/2,x,y,3,voisins);
    sosmmet->setHidden(false);
    if(B){pt2->setX(x);pt2->setY(y);B=false;}else{pt1->setX(x);pt1->setY(y);B=true;}
    }
*/
}

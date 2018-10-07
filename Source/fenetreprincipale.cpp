#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"

using namespace std;

FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetrePrincipale)
{    ui->setupUi(this);

     /*~~~~~~~~~~~~~ Boutons ~~~~~~~~~~~~~*/
    executerBtn=new QPushButton("Dessiner");
    executerBtn->setFixedSize(100,40);
    executerBtn->setIcon(QIcon("exec.png"));

    parcourrirBtn=new QPushButton("Parcourrir");
    parcourrirBtn->setFixedSize(100,40);
    parcourrirBtn->setIcon(QIcon("recherche.png"));
    /*~~~~~~~~~~~~~ Editeurs de text ~~~~~~~~~~~~~*/
     parcourrirEdit=new QLineEdit;
     parcourrirEdit->setText(QString(""));
     parcourrirEdit->setReadOnly(true);
     parcourrirEdit->setFixedSize(500,30);

     tailleGraphe = new QSpinBox;
     tailleGraphe->setMinimum(1);
     tailleGraphe->setMaximum(10000);
    /*~~~~~~~~~~~~~ Tableaux ~~~~~~~~~~~~~*/
     table=new QTableView;
     table->setFixedHeight(450);
     tab=new QStandardItemModel;
      tab->setRowCount(1);
      tab->setColumnCount(1);
      table->setModel(tab);
    /*~~~~~~~~~~~~~ Les Groupes de Boites ~~~~~~~~~~~~~*/
       grapheBox=new QGroupBox;   modificateur=new QGroupBox;   tableau=new QGroupBox;
       grapheBox->setTitle("Graphe"); modificateur->setTitle("Modificateur"); tableau->setTitle("Matrice d'adjacence");
       grapheBox->setFixedSize(800,800); modificateur->setFixedHeight(250);

    /*~~~~~~~~~~~~~ Textes ~~~~~~~~~~~~~*/
     tailleGrapheLbl=new QLabel("La taille du graphe est ");

       /*~~~~~~~~~~~~~ Progression ~~~~~~~~~~~~~*/
      pourcentage  =   new QProgressBar;
      pourcentage->setFixedSize(350,20);
      pourcentage->setValue(0);
    /*~~~~~~~~~~~~~ Layouts ~~~~~~~~~~~~~*/
     QGridLayout *layoutGeneral=new QGridLayout;
     QGridLayout *layParcou=new QGridLayout;
     QGridLayout *layAdja=new QGridLayout;
     QHBoxLayout *layoutMan= new QHBoxLayout;
     QVBoxLayout *layModif = new QVBoxLayout;

      /*layModif->addWidget(pourcentage,0,Qt::AlignCenter);*/
      modificateur->setLayout(layModif);
    layAdja->addWidget(table,0,0,1,10);
    layParcou->addWidget(parcourrirEdit,0,0);
    layParcou->addWidget(parcourrirBtn,0,1); layParcou->addWidget(executerBtn,0,2); //executerBtn->setHidden(true);
     layoutMan->addWidget(tailleGrapheLbl);
     layoutMan->addWidget(tailleGraphe);
    layAdja->addLayout(layoutMan,1,0,1,10,Qt::AlignCenter);
    layAdja->addLayout(layParcou,2,0,1,10,Qt::AlignCenter);
    tableau->setLayout(layAdja);

    layoutGeneral->addWidget(grapheBox,0,0,2,1);
    layoutGeneral->addWidget(modificateur,0,1,1,1);
    layoutGeneral->addWidget(tableau,1,1,1,1);
     ui->centralwidget->setLayout(layoutGeneral);

        /*~~~~~~~~~~~~~ Connexions ~~~~~~~~~~~~~*/
    connect(parcourrirBtn,SIGNAL(clicked()),this,SLOT(parcourrir()));
    connect(executerBtn,SIGNAL(clicked()),this,SLOT(executer()));
    connect(ui->actionBipartie,SIGNAL(triggered()),this,SLOT(bipartie()));
    connect(ui->actionApropos,SIGNAL(triggered()),this,SLOT(aProp()));
    connect(ui->actionGloutonC,SIGNAL(triggered()),this,SLOT(gloutonC()));
    connect(ui->actionQuitter,SIGNAL(triggered()),qApp,SLOT(quit()));
    connect(ui->actionR_initialiser_les_couleurs_2,SIGNAL(triggered()),this,SLOT(reinitialiserLesCouleurs()));
    connect(ui->actionGloutonMCP,SIGNAL(triggered()),this,SLOT(gloutonMCP()));
    connect(ui->actionR_cuit_Simul,SIGNAL(triggered()),this,SLOT(recuitSimule()));
    connect(tailleGraphe,SIGNAL(valueChanged(int)),this,SLOT(changementTab(int)));
    connect(ui->actionGlouton_Temps_R_el,SIGNAL(triggered()),this,SLOT(gloutonMCPReel()));
    connect(ui->actionNouveau,SIGNAL(triggered()),this,SLOT(nouveauG()));
    connect(ui->actionRedessiner_les_ar_tes,SIGNAL(triggered()),this,SLOT(redessinerAretes()));
    connect(ui->action5_Coloration,SIGNAL(triggered()),this,SLOT(coloration5()));
     connect(ui->actionRedessiner_le_graphe,SIGNAL(triggered()),this,SLOT(redessinerGraphe()));
    connect(ui->actionOrdre_D_limination_Simplicial,SIGNAL(triggered()),this,SLOT(ordreSimplicial()));
    connect(ui->actionQLNC2,SIGNAL(triggered()),this,SLOT(ordreQLNC2()));
     ui->action5_Coloration->setEnabled(false);
 ui->actionQuitter->setIcon(QIcon("quitter.png"));
 ui->actionNouveau->setIcon(QIcon("nouveau.png"));
 ui->actionNouveau->setEnabled(false);
 ui->menuColoration->setEnabled(false);
 ui->menuClique_Max->setEnabled(false);

  setWindowIcon(QIcon("Graphe.png"));

parc=false;
 setGeometry((int)(QApplication::desktop()->width() - 1480) / 2, (int)(QApplication::desktop()->height() - 720 - 50) / 2, 1480, 720);
}

FenetrePrincipale::~FenetrePrincipale()
{
    delete ui;
    /*delete grapheBox; delete modificateur; delete tableau;
    delete parcourrirBtn; delete executerBtn;
    delete parcourrirEdit;
    delete table;
    delete matriceTxt;
    delete tab;
    delete graphe;
    delete tailleGraphe;
    delete tailleGrapheLbl;*/
}

void FenetrePrincipale::sourisCliquee()
{

}

void FenetrePrincipale::parcourrir()
{

  // parcourrirBtn->setEnabled(false);


    fichier=QFileDialog::getOpenFileName(this, "Ouvrir un graphe",QString(),"Text (*.txt)");
    parcourrirEdit->setText(fichier);
    parc=true;
}

void FenetrePrincipale::executer()
{

    if(tab->item(0,0)==0 && !parc)
    {
        QMessageBox::warning(this,"Graphe Inexistant","Veuillez introduir un Bunchmark ou bien la matrice d'adjacence SVP");
    }else
    {
/**************************************************************/
    ui->actionNouveau->setEnabled(true);
    parcourrirBtn->setEnabled(false);
    executerBtn->setEnabled(false);
    ui->menuColoration->setEnabled(true);
    ui->actionGloutonC->setEnabled(true);
    ui->menuClique_Max->setEnabled(true);
/**************************************************************/
    std::vector<int> vect,init;
    std::vector<std::vector<int> > matrice;
    if(!parc)
    {
        for(int i=0;i<tab->rowCount();i++)
        {
            for(int j=0;j<tab->columnCount();j++)
            {
                vect.push_back(tab->item(i,j)->text().toInt());
            }
            matrice.push_back(vect);
            vect=init;
        }
        graphe=new DetecteurDeSommet(grapheBox,matrice);
        graphe->setHidden(false);
    }
    else
    {
         int j=tailleGraphe->value();
            QString ligne;
         std::vector<int> vectt(j,0);
         std::vector<std::vector<int> > matri;
         for(int u=0;u<j;u++)
         {
             matri.push_back(vectt);
         }

                  int indL,indC,cpt;
                  QString mot("");

                  matriceTxt=new QFile(fichier);
                  if (!matriceTxt->open(QIODevice::ReadOnly | QIODevice::Text))
                         return;
                  while (!matriceTxt->atEnd()) {
                           ligne = matriceTxt->readLine();
                            cpt=0;
                          for(int i=0;i<ligne.size();i++)
                          {

                              while(ligne[i] != ' ' && i<ligne.size() )
                              {
                                 mot.push_back(ligne[i]);
                                 i++;
                              }

                              if(mot != "")
                              {
                                  cpt++;
                                  if(cpt==1){indL=mot.toInt()-1;}
                                  else if(cpt==2){indC=mot.toInt()-1; matri[indL][indC]=1;matri[indC][indL]=1; }
                                  mot="";
                              }


                          }
                  }

                 for(int z=0;z<matri.size();z++)
                  {
                      for(int y=0;y<matri.size();y++)
                      {
                          tab->setItem(z,y,new QStandardItem(QString::number(matri[z][y])));

                      }

                  }

                  graphe=new DetecteurDeSommet(grapheBox,matri);
                  graphe->setHidden(false);
}
}

}


void FenetrePrincipale::aProp()
{
    QString inf("<br>Cette application a été créer par l'étudiant <strong>Mehdi BOUZiDi</strong>, en master R.O <br>");
    inf+="<br>Option : <strong>METHODES ET MODELES POUR L'INGENIERIE ET LA RECHERCHE </strong>.<br> ";
    inf+="<br>Date : <strong> 05/10/2015</strong> <br>";

    QWidget *infos = new QWidget;
infos->setWindowTitle("À propos");
infos->setWindowIcon(QIcon("info2.png"));
infos->setFixedSize(500,300);
 QLabel *auteur = new QLabel(inf);
 QVBoxLayout *layoutInfo =new QVBoxLayout;
 layoutInfo->addWidget(auteur);
 infos->setLayout(layoutInfo);
 infos->setHidden(false);
}

void FenetrePrincipale::changementTab(int i)
{
    tab->setRowCount(i);
    tab->setColumnCount(i);
}

void FenetrePrincipale::bipartie()
{
ui->actionBipartie->setEnabled(false);
QWidget *bip = new QWidget;
bip->setFixedSize(500,200);
bip->setHidden(false);
QString inf("");
if(graphe->bipartie())
{
    inf+="Ce graphe est <strong>Bipartie</strong>";
}
else
{
inf+="Ce graphe n'est pas <strong>Bipartie</strong>";
}

QLabel *bipartieLbl = new QLabel(inf);
QVBoxLayout *layoutBip =new QVBoxLayout;
layoutBip->addWidget(bipartieLbl,0,Qt::AlignCenter);
bip->setLayout(layoutBip);
ui->actionBiparti->setEnabled(false);
}

void FenetrePrincipale::gloutonC()
{
    QWidget *glout = new QWidget;
    glout->setFixedSize(500,200);
    glout->setHidden(false);
    QString inf("Ce graphe est colorié avec<strong> ");
    int g=graphe->gloutonC();
    inf+=QString::number(g);
    if(g==1){inf+=" </strong>couleur";}else{inf+=" </strong>couleurs";}
    QLabel *gloutLbl = new QLabel(inf);
    QVBoxLayout *layoutGlout =new QVBoxLayout;
    layoutGlout->addWidget(gloutLbl,0,Qt::AlignCenter);
    glout->setLayout(layoutGlout);
    ui->actionGloutonC->setEnabled(false);
}

void FenetrePrincipale::gloutonMCP()
{


    QWidget *glout = new QWidget;
    glout->setFixedSize(500,200);
    glout->setHidden(false);
    QString inf("Cette clique est de taille : <strong> ");

    inf+=QString::number(graphe->gloutonMCP().size());
    inf+=" </strong>";
    QLabel *gloutLbl = new QLabel(inf);
    QVBoxLayout *layoutGlout =new QVBoxLayout;
    layoutGlout->addWidget(gloutLbl,0,Qt::AlignCenter);
    glout->setLayout(layoutGlout);
    ui->actionGloutonMCP->setEnabled(false);
}

void FenetrePrincipale::gloutonMCPReel()
{
    graphe->gloutonMCPREEL();
}

void FenetrePrincipale::nouveauG()
{
    if(parcourrirEdit->text()=="" && parc){parcourrirBtn->setEnabled(true);}
    else
    {
   graphe->setVisible(false);
    graphe->setHidden(true);
    tailleGraphe->setValue(1);
    tab->setRowCount(0);
    tab->setColumnCount(0);
    tab->setRowCount(1);
    tab->setColumnCount(1);
    parcourrirEdit->setText("");
    parc=false;
ui->actionNouveau->setEnabled(false);
ui->menuColoration->setEnabled(false);
ui->actionBiparti->setEnabled(true);
ui->actionGloutonC->setEnabled(false);
ui->actionGloutonMCP->setEnabled(true);
ui->menuClique_Max->setEnabled(false);
parcourrirBtn->setEnabled(true);
executerBtn->setEnabled(true);
    }
}

void FenetrePrincipale::coloration5()
{
    vector <int> k=graphe->eliminationPv5();
   /* for(int i=0;i<k.size();i++)
    {
        cerr<<k[i]<<"   ";
    }
    cerr<<"\n";*/
}

void FenetrePrincipale::reinitialiserLesCouleurs()
{
    graphe->reinitCol();
    ui->actionBipartie->setEnabled(true);
    ui->actionGloutonC->setEnabled(true);
    ui->actionGloutonMCP->setEnabled(true);
}

void FenetrePrincipale::redessinerAretes()
{
    graphe->redessinerAretes();
}

void FenetrePrincipale::redessinerGraphe()
{
    graphe->redessinerGraphe();
}

void FenetrePrincipale::recuitSimule()
{
    QWidget *glout = new QWidget;
    glout->setFixedSize(500,200);
    glout->setHidden(false);
    QString inf("Cette clique est de taille : <strong> ");

    inf+=QString::number(graphe->recuitSimule().size());
    inf+=" </strong>";
    QLabel *gloutLbl = new QLabel(inf);
    QVBoxLayout *layoutGlout =new QVBoxLayout;
    layoutGlout->addWidget(gloutLbl,0,Qt::AlignCenter);
    glout->setLayout(layoutGlout);
     ui->actionGloutonMCP->setEnabled(false);


}

void FenetrePrincipale::ordreSimplicial()
{
    vector<int>vect(graphe->ordreEliminiationSimplicial());
    QWidget *glout = new QWidget;
    glout->setFixedSize(500,200);
    glout->setHidden(false);
    QString inf("L'odre est : <strong> ");

    for(int i=0;i<vect.size();i++)
    {inf+=QString::number(vect[i])+" / "; if(i%10==0) inf+="\n";}

    inf+=" </strong>";
    if(vect.size()==0){inf="Ce graphe n'est pas triangulé"; graphe->redessinerAretes();}
    QLabel *gloutLbl = new QLabel(inf);
    QVBoxLayout *layoutGlout =new QVBoxLayout;
    layoutGlout->addWidget(gloutLbl,0,Qt::AlignCenter);
    glout->setLayout(layoutGlout);
    ui->actionGloutonMCP->setEnabled(false);
}

void FenetrePrincipale::ordreQLNC2()
{
    vector<int>vect(graphe->ordreEliminiationQLNC2());
    QWidget *glout = new QWidget;
    glout->setFixedSize(500,200);
    glout->setHidden(false);
    QString inf("L'odre est : <strong> ");

    for(int i=0;i<vect.size();i++)
    {inf+=QString::number(vect[i])+" / "; if(i%10==0) inf+="\n";}

    inf+=" </strong>";
    if(vect.size()==0){inf="Ce graphe n'est pas QLNC2"; graphe->redessinerAretes();}
    QLabel *gloutLbl = new QLabel(inf);
    QVBoxLayout *layoutGlout =new QVBoxLayout;
    layoutGlout->addWidget(gloutLbl,0,Qt::AlignCenter);
    glout->setLayout(layoutGlout);
    ui->actionGloutonMCP->setEnabled(false);
}








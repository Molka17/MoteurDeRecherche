#include "moteur.h"
#include "nettoyeur.h"
#include "lecteur.h"
#include "analyseur.h"
#include "index.h"
#include "ordonnaceur.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;

void Moteur::indexer(string fichier, Index * x , vector<string> texte,Analyseur *a)
{



    //const char * ch = fichier.c_str();

    //vector<string> v =l->lire(ch);
    //n=new Nettoyeur_minis;
    //vector <string> v1=n->Nettoyer(v);
    vector<Statistique> vs = a->analyser(texte,fichier);
    for (int i=0 ; i<vs.size();i++)
    {
        x->setStatestique(vs[i]);
    }
cout<<"set stat succsess"<<endl;
}

void Moteur::reindexer(string fichier,Index * x ,Lecteur * l,Nettoyeur * n,Analyseur *a)   //mise a joure
{

    const char * ch = fichier.c_str();

    vector<string> v =l->lire(ch);
    //n=new Nettoyeur_minis;
    vector <string> v1=n->Nettoyer(v);
    vector<Statistique> vs = a->analyser(v1,fichier);
     //string filename("index.txt");

    for (int i=0 ; i<vs.size();i++)
    {
            x->setStatestique(vs[i]);  //on a changer seuleument la stricture de donnée
    }
}

vector<string> Moteur ::rechercher(vector <string> requete , Ordonnanceur *o,Index * x)
{
  //  Index *x;
    vector<string> v1 =o->Ordonnoncer(requete,x);
   //cout<<"3abit les fichers fel recherche"<<endl;
    return v1 ;
}

/*void Moteur::supprimer(string fichier, Index * I)   //supprimer un fichier de l'index
{

    vector<Statistique> res;
    res=I->getStatistiques();
    for(int i=0;i<res.size();i++)
    {
        if(res[i].getFich()==fichier)
           res.erase(res.begin(), res.begin() + i);   //
    }

}*/
void Moteur ::sauvgarder(Index * x)
{
vector <Statistique> vs = x->getStatistiques();
ofstream fichier("test.txt", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

        if(fichier)
        {
            for (int i=0 ; i<vs.size(); i++)
            {

                fichier << vs[i].getMot() <<"\t" <<vs[i].getFich()<< "\t"<< vs[i].getValeur() <<endl;
                //fichier<<"haja";

            }
                fichier.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;

//cout<<"naaby fel index"<<endl;
}
/*void Moteur::indexerDossier(string chemin , Index * x,Lecteur * l,Nettoyeur * n,Analyseur *a)
{

const char * ch = chemin.c_str();

    vector<string> vs =l->lire(ch);


    for (int i=0 ; i<vs.size();i++)
    {
        indexer(vs[i],x,l,n,a);
    }
}*/

void Moteur ::supprimer(string fich , Index * x)  //supprime un fichie de l'indexe
{
  vector<Statistique> vect =x->getStatistiques();  // obtient tout les statistiques
  x->getStatistiques().clear();
   // restaurer(x);  // on supprime l'ancienne fichier
ofstream fichier("test.txt", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

 for(int i=0;i<vect.size();i++)
  {
      if(vect[i].getFich()!=fich)
      {
           //res.push_back(vect[i]);
           x->setStatestique(vect[i]); // tant que le fich n'existe pas on retourne les statistiques
           fichier << vect[i].getMot() <<"\t" <<vect[i].getFich()<< "\t"<< vect[i].getValeur() <<endl;
      }
  }
fichier.close();

//sauvgarder(x);
}




void Moteur ::restaurer(Index * i)
{
    i->getStatistiques().clear();
    ofstream fichier("test.txt", ios::out | ios::trunc);
    remove("test.txt");
    delete i;  // ouverture en écriture avec effacement du fichier ouvert

}

void Moteur::AfficherIndex() //methode qui affiche l'index
{
    ifstream fichierIndex("test.txt");
    if(!fichierIndex.is_open())
    {
       cout<<"erreur 4"<<endl;
    }
    else
    {
       string ligne;
       while(getline(fichierIndex,ligne))
       {
           cout<<ligne<<endl;
       }
     }
}
 vector<string> Moteur::choix(int nbr , string ordre , vector<string>  texte)
        {
            vector <string> resultat;

            if(nbr==1)
            {   int num = ordre[0]-'0';
                if(num==1)
                {
                    Nettoyeur* n =new Nettoyeur_minis;
                    int num = ordre[0]-'0';
                    //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                    resultat= n->Nettoyer(texte);
                }
                if(num==2)
                {
                    Nettoyeur* n =new Nettoyeur_ponc;
                    int num = ordre[0]-'0';
                    //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                    resultat= n->Nettoyer(texte);
                }
                if(num==3)
                {
                    Nettoyeur* n =new Nettoyeur_mot_vide;
                    int num = ordre[0]-'0';
                    //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                    resultat= n->Nettoyer(texte);
                }
                if(num==4)
                {
                    Nettoyeur* n =new NettoyeurPlural;
                    int num = ordre[0]-'0';
                    //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                    resultat= n->Nettoyer(texte);
                }


            }
            else if (nbr==2)
            {
                int num= ordre[0] - '0';
                int num2 = ordre[1] - '0';
                if(num==1)
                {
                    Nettoyeur* n =new Nettoyeur_minis;
                    int num = ordre[0]-'0';
                    //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                    vector<string> resultat1= n->Nettoyer(texte);
                                        if(num2==1)
                                    {
                                        Nettoyeur* n =new Nettoyeur_minis;
                                        int num = ordre[0]-'0';
                                        //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                                        resultat= n->Nettoyer(resultat1);
                                    }
                                    if(num2==2)
                                    {
                                        Nettoyeur* n =new Nettoyeur_ponc;

                                        //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                                        resultat= n->Nettoyer(resultat1);
                                    }
                                    if(num2==3)
                                    {
                                        Nettoyeur* n =new Nettoyeur_mot_vide;

                                        //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                                        resultat= n->Nettoyer(resultat1);
                                    }
                                    if(num2==4)
                                    {
                                        Nettoyeur* n =new NettoyeurPlural;

                                        //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                                        resultat= n->Nettoyer(resultat1);
                                    }
                                    }
                if(num==2)
                {
                    Nettoyeur* n =new Nettoyeur_ponc;
                    int num = ordre[1]-'0';
                    //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                    resultat= n->Nettoyer(texte);
                    vector<string> resultat1= n->Nettoyer(texte);
                                        if(num2==1)
                                    {
                                        Nettoyeur* n =new Nettoyeur_minis;

                                        //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                                        resultat= n->Nettoyer(resultat1);
                                    }
                                    if(num2==2)
                                    {
                                        Nettoyeur* n =new Nettoyeur_ponc;
                                       // int num = ordre[0]-'0';
                                        //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                                        resultat= n->Nettoyer(resultat1);
                                    }
                                    if(num2==3)
                                    {
                                        Nettoyeur* n =new Nettoyeur_mot_vide;
                                        //int num = ordre[0]-'0';
                                        //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                                        resultat= n->Nettoyer(resultat1);
                                    }
                                    if(num2==4)
                                    {
                                        Nettoyeur* n =new NettoyeurPlural;
                                        //int num = ordre[0]-'0';
                                        //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                                        resultat= n->Nettoyer(resultat1);
                                    }
                }
                if(num==3)
                {
                    Nettoyeur* n =new Nettoyeur_mot_vide;
                    int num2 = ordre[1]-'0';
                    //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                    resultat= n->Nettoyer(texte);
                    vector<string> resultat1= n->Nettoyer(texte);
                                        if(num2==1)
                                    {
                                        Nettoyeur* n =new Nettoyeur_minis;
                                       // int num = ordre[0]-'0';
                                        //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                                        resultat= n->Nettoyer(resultat1);
                                    }
                                    if(num==2)
                                    {
                                        Nettoyeur* n =new Nettoyeur_ponc;
                                       // int num2 = ordre[0]-'0';
                                        //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                                        resultat= n->Nettoyer(resultat1);
                                    }
                                    if(num==3)
                                    {
                                        Nettoyeur* n =new Nettoyeur_mot_vide;
                                        //int num2 = ordre[0]-'0';
                                        //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                                        resultat= n->Nettoyer(resultat1);
                                    }
                                    if(num==4)
                                    {
                                        Nettoyeur* n =new NettoyeurPlural;
                                      //  int num2 = ordre[0]-'0';
                                        //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                                        resultat= n->Nettoyer(resultat1);
                                    }
                }
                if(num2==4)
                {
                    Nettoyeur* n =new NettoyeurPlural;
                    int num = ordre[0]-'0';
                    //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                    resultat= n->Nettoyer(texte);
                    vector<string> resultat1= n->Nettoyer(texte);
                                        if(num2==1)
                                    {
                                        Nettoyeur* n =new Nettoyeur_minis;
                                        int num2 = ordre[0]-'0';
                                        //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                                        resultat= n->Nettoyer(resultat1);
                                    }
                                    if(num==2)
                                    {
                                        Nettoyeur* n =new Nettoyeur_ponc;
                                        int num2 = ordre[0]-'0';
                                        //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                                        resultat= n->Nettoyer(resultat1);
                                    }
                                    if(num==3)
                                    {
                                        Nettoyeur* n =new Nettoyeur_mot_vide;
                                        int num2 = ordre[0]-'0';
                                        //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                                        resultat= n->Nettoyer(resultat1);
                                    }
                                    if(num==4)
                                    {
                                        Nettoyeur* n =new NettoyeurPlural;
                                        int num2 = ordre[0]-'0';
                                        //cout<<num<<"hany ena numerooooooooooooooooooooooooooo";
                                        resultat= n->Nettoyer(resultat1);
                                    }
                }


            }
            else if (nbr==3)
            {
                int num= ordre[0] - '0';
                int num1 = ordre[1] - '0';
                int num2= ordre[2] - '0';
                if(num == 1 && num1 ==2 and num2 == 3)
                {
                    Nettoyeur* n1 =new Nettoyeur_minis;
                    Nettoyeur* n2 =new Nettoyeur_ponc;
                    Nettoyeur* n3 =new Nettoyeur_mot_vide;
                    vector<string> s= n1->Nettoyer(texte);
                    vector<string> s1= n2->Nettoyer(s);
                    resultat= n3->Nettoyer(s1);

                }

            }
            else if(nbr==4)
            {
                int num1= ordre[0] - '0';
                int num2 = ordre[1] - '0';
                int num3= ordre[2] - '0';
                int num4 = ordre[3] - '0';
                if(num1 == 1 && num2 ==2 and num3 == 3 && num4==4)
                {
                    Nettoyeur* n1 =new Nettoyeur_minis;
                    Nettoyeur* n2 =new Nettoyeur_ponc;
                    Nettoyeur* n3 =new Nettoyeur_mot_vide;
                    Nettoyeur* n4 =new NettoyeurPlural;
                    vector<string> s= n1->Nettoyer(texte);
                    vector<string> s1= n2->Nettoyer(s);
                    vector<string> s2= n3->Nettoyer(s1);
                    resultat= n4->Nettoyer(s2);

                }

                //resultat=tab[nul4]->Nettoyer(tab[num3]->Nettoyer(tab[nul2]->Nettoyer(tab[num1]->Nettoyer(texte))));
            }
             return resultat;

        }

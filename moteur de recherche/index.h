#ifndef INDEX_H_INCLUDED
#define INDEX_H_INCLUDED
#define INDEXEUR_H
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <stdio.h>
#include "analyseur.h"
#include <unordered_map>
using namespace std;

/*class Statistique{

int valeur ;
string mot;
string Fich;
public:
    Statistique(int  , string  , string  );
    Statistique();
    void setValeur(int a);
    string getFich();
    void setFich(string nom);
    int getValeur();
    void setMot(string ch);
    string getMot();
    friend ostream & operator<<(ostream &, Statistique &);

};
*/
class Index
{friend Statistique;
    public:

    // map<string,map<string,int>> Stat;  // <<mot,<fich,occ>>  stat
     //vector<statistique> stat;
     //map<string,map<string,int>> dic;  // output résultat

        Index();
        virtual ~Index();
        virtual vector<Statistique> getStatistiques()=0;  // tout les les stat
        virtual  vector<Statistique> getStatistique(string &)=0;// les stat d'un mot
        virtual void setStatestique(Statistique &)=0;  // objet de statistique
        vector<string> splitRequete(string);
};

      /*  void setMap();
         void setvect();*/



class IndexVect : public Index  // inpuut vector<statistique>
{
   protected:
         vector<Statistique> stat;// pour enregistrer fiha les statistiques
 public:

        //void setvect();

        IndexVect();
        ~IndexVect();
        vector<Statistique> getStatistiques();  // tout les  stat
         vector<Statistique> getStatistique(string &);// les stat d'un mot
        void setStatestique(Statistique &);  //ta3tiha  fichier, objet de statistique -> tenregistri statistique jdida fi l vec de stat


};
class IndexMap : public Index
{


        // void setMap();
     protected:
         map<string,map<string,int>> Stat;  // output résultat t enregistri les resultat fi dictt
     public:
    IndexMap();
    ~IndexMap();
        vector<Statistique> getStatistiques();  // tout les les stat
        vector<Statistique> getStatistique(string &);// les stat d'un mot
        void setStatestique(Statistique &);  // fichier, objet de statistique tenregistrihom fi map

};

class IndexunordredMap : public Index
{

    protected:
         //void setMap();
       unordered_map<string,unordered_map<string,int>> Stat;  // output résultat t enregistri les resultat fi dictt
    public:
    IndexunordredMap(){};
    ~IndexunordredMap(){};
        vector<Statistique> getStatistiques();  // tout les les stat
        vector<Statistique> getStatistique(string &);// les stat d'un mot
        void setStatestique(Statistique &);  // fichier, objet de statistique tenregistrihom fi map

};


#endif // INDEX_H_INCLUDED

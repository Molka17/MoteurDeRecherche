#ifndef ORDONNACEUR_H_INCLUDED
#define ORDONNACEUR_H_INCLUDED
#include "index.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <map>
#include <iterator>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <dirent.h>
#include "analyseur.h"

using namespace std;

/*class Score
{
public:
   // vector<statistique>* vect; // un pointeure
    string nom_fich;
    vector<Statistique> vect;
     Score();
   virtual ~Score();
    void setVect( vector<Statistique>);
    void setFich(string);
    float getScore(); // get score d'un fich
   virtual float setScore(string)=0; // set scors d'un fich

};
class Score_fich: public Score  //  le fich le plus répeter aura le score le plus elevee
{
    public:
    Score_fich();
    ~Score_fich();
     float setScore(string);

};
class Score_occ : public Score // le fich qui contient le plus d'occurance des mots aura le score le plus elevee
{
    public:
    Score_occ();
    ~Score_occ();
     float setScore(string);
};*/

class fichocc
{
    private:
    string fich;
    int occ;

    public:
       fichocc(string f ,int o){fich=f;
       occ=o;};
       ~fichocc(){};
       int getocc(){return occ;};
       string getfich(){return fich;};
       void setocc(int o){occ=o;};
       void setfich(string f){fich=f;};


};


/*class Ordonnanceur
{
    friend fichocc;
    public:
       // vector<string>  mots; // inpout
        public:
        Ordonnanceur(); // constructeure
        virtual ~Ordonnanceur(); // destricteure
        //vector<statistique> Res;  // un vect de stat triée  => resultat
        //map<string,map<string,int>> score;  // dict mot--> score dans un fich
        //map<string,int> ResF;
        virtual vector<string>  Ordonnoncer (vector<string>,Index *)=0;  //ordonnoncer un mot
      //  vector<string> split(const string& s);
       // vector<string> splitRequete(string);
      static bool compare_statistique(Statistique&, Statistique &);
      static bool compar_occfich(fichocc &  ,fichocc &);
       vector<string>  Elimineocc(vector<string>);

      // static bool comparerscore(Statistique&,Statistique&);

};

*/
class Ordonnanceur
{
    friend fichocc;
    public:
       // vector<string>  mots; // inpout
        public:
        Ordonnanceur(); // constructeure
        virtual ~Ordonnanceur(); // destricteure
        //vector<statistique> Res;  // un vect de stat triée  => resultat
        //map<string,map<string,int>> score;  // dict mot--> score dans un fich
        //map<string,int> ResF;
        virtual vector<string>  Ordonnoncer (vector<string>,Index *)=0;  //ordonnoncer un mot
      //  vector<string> split(const string& s);
       // vector<string> splitRequete(string);
      static bool compare_statistique(Statistique&, Statistique &);
        void tier_vect(vector<Statistique>);  //******************** zedtha jdida
      int occ_fich(vector<Statistique> , string);// *****************zedtha jdida
      float score_fich(vector<Statistique>,string);// score d'un fichier prond en considération la position du mot et son occurance **** zedtha jdida
      static bool compar_occfich(fichocc &  ,fichocc &);
       vector<string>  Elimineocc(vector<string>);

      // static bool comparerscore(Statistique&,Statistique&);

};


class Ordonnceur_fich : public Ordonnanceur  //  class ya3ti priorit lil fich li m3awedd akthar marrat
{

public:

     Ordonnceur_fich(){};
    ~Ordonnceur_fich(){};
   vector<string> Ordonnoncer(vector<string>,Index *);


};


class Ordonnanceur_Occurance : public Ordonnanceur   // class ya3ti prioritée li fich li 3ando nbre d'occurance akthar
{
public:
    Ordonnanceur_Occurance(){};
    ~Ordonnanceur_Occurance();
    vector<string>  Ordonnoncer (vector<string>,Index *);
};




#endif // ORDONNACEUR_H_INCLUDED

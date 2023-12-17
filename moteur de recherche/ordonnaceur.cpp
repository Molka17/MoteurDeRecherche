#include <iostream>
#include <vector>
#include <algorithm>
#include "analyseur.h"
#include "ordonnaceur.h"
#include "index.h"

using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>


Ordonnanceur::Ordonnanceur()
{

}

Ordonnanceur::~Ordonnanceur()
{
   // delete ;
}



     vector<string> Ordonnanceur:: Elimineocc(vector<string> vect)
     {
        vector<string> res;
        int i=0;
        res.push_back(vect[i]);
        while(i!=vect.size()-1)
        {
          int p=i;
            if(vect[i]!=vect[i+1])
            {
                res.push_back(vect[i+1]);
            }
            i++;

        }
        return res;
     }





bool Ordonnanceur:: compare_statistique(Statistique &a, Statistique &b)
    {
        return (a.getValeur() > b.getValeur());
    }

     int Ordonnanceur:: occ_fich(vector<Statistique> vect  , string fich)
     {
         int occ=0;
         for(int i=0;i<vect.size();i++)
         {
             if(vect[i].getFich()==fich)
                occ++;
         }
         return occ;
     }

float Ordonnanceur ::score_fich(vector<Statistique> vect ,string fich)
{
    float score=0;
    for(int i=0;i<vect.size();i++)
    {
        if(vect[i].getFich()==fich)
        {
            score+=occ_fich(vect,fich)-(i/float(vect.size()));
        }
    }
    return score;
}


void Ordonnanceur:: tier_vect(vector<Statistique> vect)
{
    bool stop;
    int  j = 0;
    Statistique tmp;
    do
   {
    stop = true;
 //parcours le vect. de la fin vers le debut, au jeme passage les j premiers elements sont tries

for( int i = vect.size()-1; i > j; --i )
{
if(  score_fich( vect ,vect[i].getFich())<score_fich( vect ,vect[i-1].getFich()) ) //l element le plus petit remonte vers le debut
{
tmp = vect[i];
vect[i] = vect[i-1];
vect[i-1] = tmp;
stop = false;
}
}
j++;
}
while(!stop);//si pas de changement à un passage -> tab trie
}

vector<string> Ordonnanceur_Occurance::  Ordonnoncer (vector<string> text,Index *I)
{

    vector<string> result_fich;
    vector<Statistique> res; // un vecteure de copie
    vector<Statistique> resultat; // resultat un vecteure triée contient les stat de tt les mot du vect text
    for(int i=0;i<text.size();i++)
    {
         res=I->getStatistique(text[i]);
       // sort(res.begin(), res.end(), Ordonnanceur::compare_statistique); // trie d'aprés occurance
       /* for(int j=0;j<res.size();j++)
        {
            resultat.push_back(res[j]);
        }*/
         for(int j=0;j<res.size();j++)
          {
              resultat.push_back(res[j]);
          }
          res.clear();
    }

          tier_vect(resultat);


          for(int j=0;j<resultat.size();j++)
          {
              result_fich.push_back(resultat[j].getFich());
          }

          vector<string> a =Ordonnanceur::Elimineocc(result_fich);
          return  a;

}





Ordonnanceur_Occurance::~Ordonnanceur_Occurance(){

   }


 bool Ordonnanceur::compar_occfich(fichocc &a ,fichocc &b)
 {

     return (a.getocc()> b.getocc());
 }



vector<string> Ordonnceur_fich::Ordonnoncer(vector<string> text,Index *I)
{
    vector<string> result_fich;
    vector<Statistique> res; // un vecteure de copie
     vector<fichocc> resultat; // resultat un vecteure triée contient les stat de tt les mot du vect text
    for(int i=0;i<text.size();i++)
    {
         res = I->getStatistique(text[i]);   // res chaque foi tetcrassa
         for(int j=0;j<res.size();j++)
         {

             fichocc fich(res[j].getFich(),res[j].getValeur());

             resultat.push_back(fich);
         }


    }

      sort(resultat.begin(), resultat.end(), Ordonnanceur::compar_occfich);

     for(int k=0;k<resultat.size();k++)
     {
         result_fich.push_back(resultat[k].getfich());
     }

     vector<string> a= Ordonnanceur::Elimineocc(result_fich);


 return a;

}


#include "index.h"
#include<map>
#include "analyseur.h"
#include <bits/stdc++.h>
using namespace std;



Index::Index()
{
    //ctor
}

Index::~Index()
{
    //dtor
}


/*void IndexVect::setvect()
            {

                 Statistique s1(5,"ii","f1");
                 Statistique s2(88,"f4","jj");
                 Statistique s3(10,"f7","kk");
                 stat.push_back(s1);
                 stat.push_back(s2);
                 stat.push_back(s3);

            }*/

 vector<Statistique> IndexVect:: getStatistiques()
{
       vector<Statistique> res;
        for(int i=0;i<stat.size();i++)
        {
            res.push_back(stat[i]);
        }
       //return stat;
       /*for(int i=0;i<stat.size();i++)
       {
           cout<<stat[i];*/

           cout<<"getstat success!!!"<<endl;
      // }
       return res;
}

 vector<Statistique>  IndexVect::getStatistique(string &mot)
{
   vector<Statistique> res;
   for(int i=0;i<stat.size();i++)
   {
       if(stat[i].getMot()==mot)  // si le mot  existe dans le vect de stat
         res.push_back(stat[i]);


   }

    return res;

}



/*void IndexMap:: setMap()
{
Stat["aa"]["f1"]=1;
Stat["dd"]["f2"]=2;
Stat["ee"]["f3"]=3;
Stat["bb"]["f1"]=1;
Stat["cc"]["f2"]=4;
cout<<"le map est ajoutee"<<endl;

}*/





IndexVect::IndexVect()
{
    //ctor
}

IndexVect::~IndexVect()
{
    //dtor
}

void IndexVect::setStatestique(Statistique & s)
{

    stat.push_back(s);


}



IndexMap::IndexMap()
{
    // construct
}
    IndexMap:: ~IndexMap()
    {
        // distruct
    }

    // dic dictionn statique


     vector<Statistique> IndexMap:: getStatistiques()
     {
       // return &Stat;  // copier les resultat dans un ecteure
        vector<Statistique> res;
       //map<string,map<string,double>> :: iterator it;
        //map<string,double> :: iterator it1;

        for(auto it=Stat.begin();it!=Stat.end();it++)
        {
            auto it1=it->second.begin();
            for(it1=it->second.begin();it1!=it->second.end();it1++)
            {
                string mot=it->first;  // mot
               auto it2=it1->first;
               string fich =it2; // fichier
               double occ=Stat[mot][fich];  // occurance du mot
               Statistique s(occ,mot,fich);
               res.push_back(s);
            }
        }

      return res;
     }


      vector<Statistique> IndexMap::getStatistique(string & mot)
      {
       vector<Statistique> res;
   // map<string,map<string,double>> :: iterator it;
   auto  it=(Stat.find(mot));

        if(it!=Stat.end())  // le mot existe
        {
            auto it1=it->second.begin();
            for(it1=it->second.begin();it1!=it->second.end();it1++)
            {
                Statistique s(it1->second,mot,it1->first);
               /* s.setMot(mot);
                s.setValeur(it1->second);
                s.setFich(it1->first);*/
                res.push_back(s);
            }
        }

       return res;
      }


   void IndexMap:: setStatestique(Statistique & s) // input dictionnaire <mot<fich,occ>>
   {
     map<string,double> :: iterator it1;
    auto it=Stat.begin();
    it = Stat.find(s.getMot());
    if(it==Stat.end()) // le mot n'exist pas
      {
         Stat[s.getMot()][s.getFich()]=s.getValeur();
      }
   else
    {
        // le mot existe dans Stat donc on va verifier le fich
        auto it1=it->second.begin();  // parcour du dectionnaire correspond au mot s.mot
        it->second.find(s.getFich());
        if(it1== it->second.end()) // le fich n'existe pas , on ajoute le fich au statistiques
        {
            Stat[s.getMot()][s.getFich()]=s.getValeur();
        }
        else
        {
            Stat[s.getMot()][s.getFich()]=s.getValeur();
        }
    }
   }

//*********  developpement de la sous classe unordred map ***************

     vector<Statistique> IndexunordredMap:: getStatistiques()
     {
       // return &Stat;  // copier les resultat dans un ecteure

        vector<Statistique> res;
     //  unordered_map<string,unordered_map<string,double>> :: iterator it;
      //  unordered_map<string,double> :: iterator it1;

        for(auto it=Stat.begin();it!=Stat.end();it++)
        {
            auto it1=it->second.begin();
            for(it1=it->second.begin();it1!=it->second.end();it1++)
            {
                string mot=it->first;  // mot
               auto it2=it1->first;
               string fich =it2; // fichier
               double occ=Stat[mot][fich];  // occurance du mot
               Statistique s(occ,mot,fich);
               res.push_back(s);
            }
        }

      return res;
     }



vector<Statistique> IndexunordredMap::getStatistique(string & mot)
      {
       vector<Statistique> res;
   // unordered_map<string,unordered_map<string,double>> :: iterator it;
auto     it=(Stat.find(mot));

        if(it!=Stat.end())  // le mot existe
        {
            auto it1=it->second.begin();
            for(it1=it->second.begin();it1!=it->second.end();it1++)
            {
                Statistique s;
                s.setMot(mot);
                s. setValeur(it1->second);
                s.setFich(it1->first);
                res.push_back(s);
            }
        }

       return res;
}



   void IndexunordredMap:: setStatestique(Statistique & s) // input dictionnaire <mot<fich,occ>>
   {

     unordered_map<string,double> :: iterator it1;
    auto it=Stat.begin();
    it = Stat.find(s.getMot());
    if(it==Stat.end()) // le mot n'exist pas

      {
         Stat[s.getMot()][s.getFich()]=s.getValeur();

      }

   else
    {
        // le mot existe dans Stat donc on va verifier le fich
        auto it1=it->second.begin();  // parcour du dectionnaire correspond au mot s.mot
        it->second.find(s.getFich());
        if(it1== it->second.end()) // le fich n'existe pas , on ajoute le fich au statistiques
        {
            Stat[s.getMot()][s.getFich()]=s.getValeur();
        }

    }


   }

vector<string> Index::splitRequete(string req)//methode qui decoupe une chaine en mots et les met dans un vecteur
{
    string  T;
 vector<string> v;
    //getline(cin, S);

    stringstream X(req);

    while (getline(X, T, ' '))
    {
        v.push_back(T);
    }
    return v;

}

/*void IndexVect::indexer(string chemin)//prend les stats que retourne l'analyseur et les met dans un fichier index.txt
{
    ofstream fichierIndex("index.txt",ios::app);
    int taille=stat.size();
    for(int i=0; i<taille;i++)
        {
            //cout<<stat[i];
            fichierIndex << stat[i].getMot() <<'\t'<<chemin<<'\t'<< stat[i].getOcc() <<endl;
        }
}*/

#include "analyseur.h"
#include<vector>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
#include <vector>
#include <list>
#include <map>
#include <set>

AnalyseurVecteur::AnalyseurVecteur(){


}
ostream & operator<<(ostream & flux, Statistique s)
{
        flux<<s.getFich()<<"--"<<s.getMot()<<"--"<<s.getValeur()<<endl;
        return flux;
}
/*vector<Statistique> AnalyseurVecteur::analyser(vector<string> texte)
{
    //voila je suis la voila hey hey
    vector<Statistique> v;
    Statistique s(1,texte[0]);
    v.push_back(s);  // met "voila" dans v

    for(int i=1 ; i<texte.size(); i++)
    {   for (int j=0 ; j<i ; j++)
        {
               if(texte[j]!=texte[i])
               {


                        Statistique s1(1,texte[i]); // si le mot n'existe pas auparavant

                        v.push_back(s1);
               }
               else
               {

                    // ken l9ateha tzid tlawej aal position mte3ha fel s w tzidd el ocuurence +1

                    for(int k=0 ; i<v.size();k++)
                    {
                        if (texte[j]==v[k].getMot())
                        {
                            v[k].setValeur(v[k].getValeur()+1);
                        }
                    }
               }
        }
    }
    return v;
*/

vector<Statistique>  AnalyseurVecteur::analyser(vector<string> & texte , string fichier){
    vector <Statistique> v;
    vector <string> s;     // vecteur fih les mots sans redandence
    s.push_back(texte[0]);
    int j=1;
    while(j< texte.size())
    {
        int x=count(s.begin(),s.end(),texte[j]);
        if (x>0)
            j++;
        else
            s.push_back(texte[j]);
    }
    /*for (int i=0 ; i< s.size(); i++)
    {cout<<s[i]<<"***";}*/

   for (int i=0 ; i< s.size(); i++)
    {
        /*v[i].setMot(texte[i]);
        v[i].setValeur(count(texte.begin(), texte.end(), texte[i]));*/
        string ch=s[i];
        double x=count(texte.begin(), texte.end(), s[i]);
       // cout<<ch<<"----";
       // cout<<x<<"  ";
        Statistique z(x,ch,fichier);
        v.push_back(z);
    }
return v;
}
vector<Statistique>  AnalyseurMap::analyser(vector<string> & texte ,string fichier ){
    vector<Statistique> v ;
    map<string,int> dic;
    vector <string> s;     // vecteur fih les mots sans redandence
    s.push_back(texte[0]);
    int j=1;
    while(j< texte.size())
    {
        int x=count(s.begin(),s.end(),texte[j]);
        if (x>0)
            j++;
        else
            s.push_back(texte[j]);
    }
map<string,int>::iterator it ;

for (int i=0 ; i< s.size(); i++)
{
    string ch=s[i];
        double x=count(texte.begin(), texte.end(), s[i]);
        dic[ch]=x;
}

for(auto it=dic.begin() ; it!=dic.end() ; ++it)
{
    Statistique s(it->second,it->first,fichier);
    v.push_back(s);
}
return v;
}
    AnalyseurVecteur::~AnalyseurVecteur(){

  }
vector<Statistique> AnalyseurFrequenceUnordred ::analyser(vector<string> & texte , string fichier )
{
    vector<Statistique> vs;
    unordered_map <string , double > m_map;
     vector <string> s;     // vecteur fih les mots sans redandence
    s.push_back(texte[0]);
    int j=1;
    while(j< texte.size())
    {
        int x=count(s.begin(),s.end(),texte[j]);
        if (x>0)
            j++;
        else
            s.push_back(texte[j]);
    }
    unordered_map<string,double>::iterator it ;

    for (int i = 0 ; i<s.size() ; i++)
    {

         string ch=s[i];
         int somme = texte.size();
        double a=count(texte.begin(), texte.end(), s[i]);
        double haja = (double)a/somme;
        double x=haja*100;
         m_map[ch]=x;
        //cout<<texte.size()<<"/////////////";
        //cout<<ch<<"***";
         //cout<<x<<endl;
        m_map[ch]=x;
    }
    for(auto it=m_map.begin() ; it!=m_map.end() ; ++it)
{
    Statistique s(it->second,it->first,fichier);
    vs.push_back(s);
}
    return vs;
}




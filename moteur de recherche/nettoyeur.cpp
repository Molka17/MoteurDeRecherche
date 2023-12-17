#include <iostream>
#include "nettoyeur.h"
#include <cstring>
#include <bits/stdc++.h>
using namespace std;


 Nettoyeur::Nettoyeur(){

}



vector<string>  Nettoyeur_minis::Nettoyer(vector<string> & v){

for (int i=0; i< v.size();i++)
{
    string    s=v[i];

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    v[i]=s;
}
return v;
}



vector<string>  Nettoyeur_ponc::Nettoyer(vector<string> &  v)
{
 vector<string> vect;
    for( int i = 0 ; i < v.size(); i++)
        {
                string s=v[i];
                int j=0;
                while (  j < s.size())
                    {

                        if (s[j]=='0' ||s[j]=='1' ||s[j]=='2' ||s[j]=='3' ||s[j]=='}' ||s[j]=='&' ||s[j]=='{' ||s[j]=='!' || s[j]==',' || s[j]=='.' ||s[j]=='§' ||s[j]=='?' ||s[j]=='!' ||s[j]==';' ||s[j]=='/' ||s[j]=='-' ||s[j]=='_' ||s[j]=='(' ||s[j]==')' ||s[j]=='#' ||s[j]=='*' ||s[j]=='+' ||s[j]=='=' ||s[j]==':' ||s[j]==';' )// supprime les !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~. 1234567890
                    {
                          s.erase (std::remove(s.begin(), s.end(), s[j]), s.end());


                    }
                        else
                        {
                            j++;
                        }

                  }


               // cout<<"hi";
                  vect.push_back(s);
        }


    return vect;
}


vector<string>  Nettoyeur_mot_vide::Nettoyer(vector<string>   & v)
{
    vector<string> mot{"i","the" , "this" , "in" , "on" , "a" , "an" , "by" ,"that" , "so" ,"to" , "of" ,"and" , "there" , "my" , "at" , "you" ,"us" , "if" , "for"};
    for( int i = 0 ; i < v.size(); i++)
    {
        for(auto m : mot )   // m= the , this , on , a
    {
        if(m==v[i])
        {
            v.erase(v.begin()+i);
        }

    }

    }

    return v;
}

vector<string> NettoyeurPlural::Nettoyer(vector<string>& v)
{
    vector<string> vect ;
    for (int i=0; i<v.size(); i++)
    {
        string s=v[i];
        if (s[s.size()-1]=='s')
        {
            s.erase (std::remove(s.begin(), s.end(), s[s.size()-1]), s.end());
        }
        vect.push_back(s);
    }
    return vect;
}

void Nettoyeur::duree()
    {
        cout<<"ne7seb"<<endl;
        chrono::system_clock::time_point start = chrono::system_clock::now();
        for ( long i = 0; i < 10000000; ++i )
        {
           sqrt( 123.456L );
        }
        chrono::duration<double> sec = chrono::system_clock::now() - start;
        cout << "the execution took " << sec.count() << " seconds\n";
    }


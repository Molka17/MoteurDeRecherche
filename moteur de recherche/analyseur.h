#ifndef ANALYSEUR_H_INCLUDED
#define ANALYSEUR_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;


class Statistique{

double valeur ;
string mot;
string Fich;
public:
    Statistique(){};
    Statistique(double va , string m , string f ){
    valeur=va;
    mot=m;
    Fich=f;
    }
    void setValeur(double a){ valeur=a;};
    string getFich(){return Fich;};
    void setFich(string nom){Fich=nom;};
    double getValeur(){return valeur;};
    void setMot(string ch){mot=ch;};
    string getMot(){return mot;};
    friend ostream & operator<<(ostream &, Statistique &);

};

class Analyseur{
public:
    Analyseur(){};
    virtual vector<Statistique>  analyser(vector<string> & , string ) =0;
    virtual ~Analyseur(){};
};
class AnalyseurVecteur :public Analyseur{
public:
    AnalyseurVecteur();
    vector<Statistique>   analyser(vector<string> & , string );
    ~AnalyseurVecteur();
};
class AnalyseurMap : public Analyseur{
public:
    AnalyseurMap(){};
    vector<Statistique> analyser(vector<string> & , string );
    ~AnalyseurMap(){};
};
class AnalyseurFrequenceUnordred :public Analyseur {
public :
    AnalyseurFrequenceUnordred(){};
    vector<Statistique> analyser(vector<string> & , string );
    ~AnalyseurFrequenceUnordred(){};
};


#endif // ANALYSEUR_H_INCLUDED

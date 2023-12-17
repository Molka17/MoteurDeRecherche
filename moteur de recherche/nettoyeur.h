#ifndef NETTOYEUR_H_INCLUDED
#define NETTOYEUR_H_INCLUDED

#include <iostream>
#include <cstring>
#include <ctype.h>
#include<cctype>
#include <algorithm>
#include <vector>
#include <chrono>
using namespace std;
class Nettoyeur{

public :

    Nettoyeur();
    virtual vector<string>  Nettoyer(vector<string> & )=0;
    virtual ~Nettoyeur(){};
    void duree();
};

class Nettoyeur_minis : public Nettoyeur{
public:
    Nettoyeur_minis(){};
    vector<string>  Nettoyer(vector<string> & );
    ~Nettoyeur_minis(){};
};
class Nettoyeur_ponc : public Nettoyeur{

public:
    Nettoyeur_ponc(){};
    vector<string>  Nettoyer(vector<string> & );
    ~Nettoyeur_ponc(){};
};
class Nettoyeur_mot_vide : public Nettoyeur{
public:
    Nettoyeur_mot_vide(){};
    vector<string>  Nettoyer(vector<string>& );
    ~Nettoyeur_mot_vide(){};
};
class NettoyeurPlural : public Nettoyeur{
public:
    NettoyeurPlural(){};
    vector<string>  Nettoyer(vector<string>& );
    ~NettoyeurPlural(){};
};




#endif // NETTOYEUR_H_INCLUDED

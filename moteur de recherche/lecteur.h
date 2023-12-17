#ifndef LECTEUR_H_INCLUDED
#define LECTEUR_H_INCLUDED

#include <filesystem>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <iterator>
#include <sstream>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <vector>

using namespace std;

/*class Lecteur
{

    public:
        string ch;
        Lecteur(string);
        virtual ~Lecteur();
        vector<string> lire();
};

Lecteur::Lecteur(string a)
{
    ch=a;
}

Lecteur::~Lecteur()
{
    //dtor
}
*/
class Lecteur
{
    public:
        Lecteur(){};
        virtual ~Lecteur(){};
        virtual vector<string> lire(const char *)=0;
       // bool verif(const char *);  //appel lire qui convient au type
};
class LecteurDoc : public Lecteur{
public:
LecteurDoc(){};
vector<string> lire(const char *);
~LecteurDoc(){};

};
class LecteurDiractory:public Lecteur{
public :
    LecteurDiractory(){};
    vector <string> lire(const char *) ; // chemin el dossier  trajaa liste des fichiers
    ~LecteurDiractory(){};

};

#endif // LECTEUR_H_INCLUDED

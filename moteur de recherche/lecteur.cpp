#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <iterator>
#include <sstream>
#include <cstring>
#include "lecteur.h"

vector<string> LecteurDoc::lire(const char * ch)
    {
        string cheminFichier(ch);
    vector<string> mots;
    string mot;

    ifstream fichier(cheminFichier);
    if (!fichier.is_open())
    {
        cerr << "impossible d'ouvrir le fichier " << cheminFichier << endl;
        //return EXIT_FAILURE;
    }

    while (fichier >> mot) {
        mots.push_back(mot);
    }
 fichier.close();
    return mots;
    }






vector <string> LecteurDiractory::lire(const char * path) {
    vector <string> files;
   struct dirent *entry;
   DIR *dir = opendir(path);
   while ((entry = readdir(dir)) != NULL) {
  // cout << entry->d_name << endl;
            files.push_back(entry->d_name);
   }
auto elem_to_remove = files.begin() ;
files.erase(elem_to_remove);
auto elem = files.begin() ;
files.erase(elem);

closedir(dir);
   return files;
}


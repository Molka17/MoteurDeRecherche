#ifndef MOTEUR_H_INCLUDED
#define MOTEUR_H_INCLUDED

#include<vector>
#include <iostream>
#include <vector>
#include "ordonnaceur.h"
#include <algorithm>
#include <bits/stdc++.h>
#include "index.h"
#include "lecteur.h"
#include "analyseur.h"
#include "nettoyeur.h"
using namespace std;
class Moteur
{
    protected :


    public:
        //vector<string> requete;
        Moteur(){};
        ~Moteur(){};
        //void indexer(string , Index *,Lecteur * ,Nettoyeur * ,Analyseur *) ; //indexer un fichier
        void indexer(string fichier, Index * x ,vector<string> texte,Analyseur *a);
        vector<string> rechercher(vector<string>, Ordonnanceur * ,Index *);//retourne les listes des fichier baad mtaam recherche lel requete
        void supprimer (string,Index *); //supprime un fichier de l'indexe
        void reindexer(string  , Index *,Lecteur * ,Nettoyeur * ,Analyseur *) ;// tekhou esm el fichier
        void indexerDossier(string , Index *,Lecteur * ,Nettoyeur * ,Analyseur *);
        void restaurer(Index *) ; // supprime l'indexe
        void sauvgarder(Index *);
        void AfficherIndex();
        vector<string> choix(int nbr , string ordre , vector<string>  texte);



};

#endif // MOTEUR_H_INCLUDED

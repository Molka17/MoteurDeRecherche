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
#include <iostream>
#include <vector>
#include "analyseur.h"
#include "moteur.h"
#include "nettoyeur.h"
#include "lecteur.h"
#include "index.h"
#include "ordonnaceur.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>

using namespace std::chrono;
using namespace std;

int main()
{
vector<Nettoyeur *> tab;
Nettoyeur * n1=new Nettoyeur_minis;
Nettoyeur * n2 =new Nettoyeur_ponc;
Nettoyeur * n3=new Nettoyeur_mot_vide;
Nettoyeur * n4=new NettoyeurPlural ;
tab.push_back(n1);
tab.push_back(n2);
tab.push_back(n3);
tab.push_back(n4);
Lecteur * ll=new LecteurDoc() ;
Lecteur * l ;
Nettoyeur * n;
Analyseur *a;
Index *x;
Ordonnanceur * o;
Moteur *M;
    int selection=0;
     do
    {
        cout<<endl;
        cout<<  "   ICHRAK   &   MOLKA  & EMNA "<<endl;
        cout << "  ====================================\n";
        cout << "  1.  Search Engine\n";
        cout << "  2.  index \n";
        cout << "  3.  save \n";
        cout << "  4.  Delete File\n";
        cout<<  "  5.  Print all statictics  \n";
        cout << "  6.  Restore index \n";
        cout << "\n";
        cout << "  7.  Exit \n";
        cout << "  ====================================\n";
        cout << "  Enter your selection: ";
         while(!(cin >> selection))
            {
            cin.clear();
            cin.ignore(999,'\n');
            cout<<"Invalid selection type!\nPlease enter your selection again: ";
            }
        cout << endl;
        system("cls");
        switch (selection)
         {


            case 1:
               {
                     //search
                        string req;
                        int s0=0;
                        cout << "  ====================================\n";
                        cout << "  1.   search with ordonnanceur occ\n";
                        cout << "  2.   search with ord fich\n";
                        cout << endl;
                        cout << "  3.  Exit\n";
                        cout << "  ====================================\n";
                        cout << "  Enter your selection: ";
                        while(!(cin >> s0))
                        {
                            cin.clear();
                            cin.ignore(999,'\n');
                            cout<<"Invalid selection type!\nPlease enter your selection again: ";
                        }
                            cout << endl;
                            switch(s0)
                            {
                               case 1:
                               {
                                   cout<<" Enter here words  to search: ";
                                   o= new Ordonnanceur_Occurance;  //esm classe fille mel ordonnaceur
                                   cin.ignore();
                                   getline(cin,req,'\n');
                                   cout<<endl;
                                   vector<string> v = x->splitRequete(req);
                                     auto start = high_resolution_clock::now(); //debu
                                   vector <string> m=M->rechercher(v,o,x);
                                    auto stop = high_resolution_clock::now(); //fin
                                    auto duration = duration_cast<microseconds>(stop - start);
                                    cout << "Time taken by search: "
                                         << duration.count() << " microseconds" << endl;
                                   //cout<<"recherche fait !!"<<endl;
                                   cout<<m.size()<<"  result found : ";

                                   for(int i=0 ; i<m.size(); i++)
                                   {
                                       cout<<m[i]<<endl;
                                   }
                                   break;
                               }
                               case 2:
                               {
                                   cout<<" Enter here words to search : ";
                                   o= new Ordonnceur_fich ;  //esm classe fille mel ordonnaceur
                                   cin.ignore();
                                   getline(cin,req,'\n');
                                   cout<<endl;

                                   //cout<<"9bam el split"<<endl;
                                    vector<string> v = x->splitRequete( req);
                                    cout<<v.size()<<endl;
                                    cout<<v[0]<<endl;
                                   // v.push_back(req);
                                   // cout<<"9rit el requete" <<endl;
                                    auto start = high_resolution_clock::now(); //debu
                                   vector <string> m1=M->rechercher(v,o,x);
                                   auto stop = high_resolution_clock::now(); //fin
                                    auto duration = duration_cast<microseconds>(stop - start);
                                    cout << "Time taken by search: "
                                         << duration.count() << " microseconds" << endl;
                                   cout<<m1.size()<<"  result found : ";
                                   //cout<<"baad el recherche"<<endl;
                                   for(int i=0 ; i<m1.size(); i++)
                                   {
                                       cout<<m1[i]<<endl;
                                   }
                                   //cout<<"affichit"<<endl;
                                   break;
                                   }


                               default: {//cout <<s << " is not a valid menu item try again.\n";
                               cout<<endl;
                                        }
                            break;
                 }
               }

            case 2 :
                {//indexer
                     int se =0;
                                cout << "  ====================================\n";
                                cout << "  1.  Index file\n";
                                cout << "  2.  Index diractory\n";

                                cout << "\n";
                                cout << "  4.  Exit\n";
                                cout << "  ====================================\n";
                                cout << "  Enter your selection: ";
                                 while(!(cin >> se))
                                {
                                    cin.clear();
                                    cin.ignore(999,'\n');
                                    cout<<"Invalid selection type!\nPlease enter your selection again: ";
                                }
                                cout << endl;
                                system("cls");
                                switch(se)
                                {
                                case 1 :
                                    {
                                         int sel1 =0;
                                cout << "  ====================================\n";
                                cout << "  1.  Index with vector\n";
                                cout << "  2.  Index with map\n";
                                cout << "  3.  Index with unordred map\n";
                                cout << "\n";
                                cout << "  4.  Exit\n";
                                cout << "  ====================================\n";
                                cout << "  Enter your selection: ";
                                while(!(cin >> sel1))
                                {
                                    cin.clear();
                                    cin.ignore(999,'\n');
                                    cout<<"Invalid selection type!\nPlease enter your selection again: ";
                                }
                                cout << endl;
                               system("cls");
                                switch(sel1)
                                {
                                    case 1 :{   // index file with vector
                                        string file;
                                        x=new IndexVect;
                                        cin.ignore();
                                        cout<<" Enter Full File Path (Example: C:\\Users\\user\\OneDrive\\Bureau\\c++\\moteur_recherche\\nouvau\\184.txt ): ";
                                        l=new LecteurDoc;
                                        getline(cin,file,'\n');
                                        int s0=0;

                                        cout << "  ====================================\n";
                                        cout << "  1.Analyze with vector\n";
                                        cout << "  2.Analyze with map\n";
                                        cout << "  3.Analyze with unordred map\n";
                                        cout << "\n";
                                        cout << "  4.  Exit\n";
                                        cout << "  ====================================\n";
                                        cout << "  Enter your selection: ";
                                        while(!(cin >> s0))
                                        {
                                        cin.clear();
                                        cin.ignore(999,'\n');
                                        cout<<"Invalid selection type!\nPlease enter your selection again: ";
                                        }
                                        cout << endl;
                                        system("cls");
                                        switch(s0)
                                        {
                                        case 1 :
                                            {
                                                //analyze with vect
                                                            a=new AnalyseurVecteur;
                                                            system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Clean to lower \n";
                                                            cout << "  2.clean punctuation\n";
                                                            cout << "  3.Nclean stop words \n";
                                                            cout<<  "  4.clean plural      \n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                            cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;

                                                                        const char * ch1 = file.c_str();
                                                                        vector <string> u=ll->lire(ch1);

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;
                                                                        auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);
                                                                        auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;
                                                                       // cout<<"amalt indexer";
                                                                        M->sauvgarder(x);
                                                                        //cout<<"aamlt sauvgrader";



                                                                    break;
                                                                }
                                        case 2 :
                                                                {
                                                                    //analyse with map
                                                                     a=new AnalyseurMap;
                                                            system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Clean to lower \n";
                                                            cout << "  2.clean punctuation\n";
                                                            cout << "  3.Nclean stop words \n";
                                                            cout<<  "  4.clean plural      \n";
                                                            cout << "\n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                            cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;

                                                                        const char * ch1 = file.c_str();
                                                                        vector <string> u=ll->lire(ch1);

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;
                                                                        auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);
                                                                        auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;
                                                                       // cout<<"amalt indexer";
                                                                        M->sauvgarder(x);
                                                                        //cout<<"aamlt sauvgrader"



                                                                break;
                                                                }
                                        case 3:
                                                                {
                                                                    //analyse with unordred map
                                                                     a=new AnalyseurFrequenceUnordred;
                                                            system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Clean to lower \n";
                                                            cout << "  2.clean punctuation\n";
                                                            cout << "  3.Nclean stop words \n";
                                                            cout<<  "  4.clean plural      \n";
                                                            cout << "\n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                            cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;

                                                                        const char * ch1 = file.c_str();
                                                                        vector <string> u=ll->lire(ch1);

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;
                                                                        auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);
                                                                        auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;
                                                                       // cout<<"amalt indexer";
                                                                        M->sauvgarder(x);
                                                                        //cout<<"aamlt sauvgrader"

                                                                    break;
                                                                }
                                        }

                                break;
                                            }

                                    case 2:
                                    {

                                        string file;
                                        x=new IndexMap;
                                        cin.ignore();
                                        cout<<" Enter Full File Path (Example: C:\\Users\\user\\OneDrive\\Bureau\\c++\\moteur_recherche\\nouvau\\184.txt ): ";
                                        l=new LecteurDoc;
                                        getline(cin,file,'\n');
                                        int s0=0;

                                        cout << "  ====================================\n";
                                        cout << "  1.Analyze with vector\n";
                                        cout << "  2.Analyze with map\n";
                                        cout << "  3.Analyze with unordred map\n";
                                        cout << "\n";
                                        cout << "  4.  Exit\n";
                                        cout << "  ====================================\n";
                                        cout << "  Enter your selection: ";
                                        while(!(cin >> s0))
                                        {
                                        cin.clear();
                                        cin.ignore(999,'\n');
                                        cout<<"Invalid selection type!\nPlease enter your selection again: ";
                                        }
                                        cout << endl;
                                        system("cls");
                                        switch(s0)
                                        {
                                        case 1 :
                                            {
                                                //analyze with vect
                                                            a=new AnalyseurVecteur;
                                                            system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Clean to lower \n";
                                                            cout << "  2.clean punctuation\n";
                                                            cout << "  3.Nclean stop words \n";
                                                            cout<<  "  4.clean plural      \n";
                                                            cout << "\n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                            cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;

                                                                        const char * ch1 = file.c_str();
                                                                        vector <string> u=ll->lire(ch1);

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;
                                                                        auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);
                                                                        auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;
                                                                       // cout<<"amalt indexer";
                                                                        M->sauvgarder(x);
                                                                        //cout<<"aamlt sauvgrader"

                                                                    break;
                                                                }
                                        case 2 :
                                                                {
                                                                    //analyse with map
                                                                     a=new AnalyseurMap;
                                                            system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Clean to lower \n";
                                                            cout << "  2.clean punctuation\n";
                                                            cout << "  3.Nclean stop words \n";
                                                            cout<<  "  4.clean plural      \n";
                                                            cout << "\n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                            cout << "  Enter your selection: ";
                                                            cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;

                                                                        const char * ch1 = file.c_str();
                                                                        vector <string> u=ll->lire(ch1);
                                                                        cout<<"amalt lire"<<endl;

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                        cout<<"texte netoyee bel choix"<<endl;
                                                                        auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);
                                                                        auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;
                                                                        cout<<"amalt indexer";
                                                                        M->sauvgarder(x);
                                                                        cout<<"aamlt sauvgrader";

                                                                break;
                                                                }
                                        case 3:
                                                                {
                                                                    //analyse with unordred map
                                                                     a=new AnalyseurFrequenceUnordred;
                                                            system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Nettoyer miniscule \n";
                                                            cout << "  2.Nettoyer ponctuation\n";
                                                            cout << "  3.Nettoyer mots vides \n";
                                                            cout<<  "  4.Nettoyer plural      \n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                            cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;

                                                                        const char * ch1 = file.c_str();
                                                                        vector <string> u=ll->lire(ch1);

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;
                                                                        auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);
                                                                         auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;
                                                                       // cout<<"amalt indexer";
                                                                        M->sauvgarder(x);
                                                                        //cout<<"aamlt sauvgrader"

                                                                    break;
                                                                }
                                        }

                                break;
                                }
                                case 3:
                                        {   // index file with unordred-map
                                        string file;
                                        x=new IndexunordredMap;
                                        cin.ignore();
                                        cout<<" Enter Full File Path (Example: C:\\Users\\user\\OneDrive\\Bureau\\c++\\moteur_recherche\\nouvau\\184.txt ): ";
                                        l=new LecteurDoc;
                                        getline(cin,file,'\n');
                                        int s0=0;

                                        cout << "  ====================================\n";
                                        cout << "  1.Analyze with vector\n";
                                        cout << "  2.Analyze with map\n";
                                        cout << "  3.Analyze with unordred map\n";
                                        cout << "\n";
                                        cout << "  4.  Exit\n";
                                        cout << "  ====================================\n";
                                        cout << "  Enter your selection: ";
                                        while(!(cin >> s0))
                                        {
                                        cin.clear();
                                        cin.ignore(999,'\n');
                                        cout<<"Invalid selection type!\nPlease enter your selection again: ";
                                        }
                                        cout << endl;
                                        system("cls");
                                        switch(s0)
                                        {
                                        case 1 :
                                            {
                                                //analyse with vect
                                                            a=new AnalyseurVecteur;
                                                            system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Nettoyer miniscule \n";
                                                            cout << "  2.Nettoyer ponctuation\n";
                                                            cout << "  3.Nettoyer mots vides \n";
                                                            cout<<  "  4.Nettoyer plural      \n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                            cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;

                                                                        const char * ch1 = file.c_str();
                                                                        vector <string> u=ll->lire(ch1);

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;
                                                                        auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);
                                                                         auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;
                                                                       // cout<<"amalt indexer";
                                                                        M->sauvgarder(x);
                                                                        //cout<<"aamlt sauvgrader"


                                                break;
                                            }
                                        case 2 :
                                            {
                                                //anlyze map
                                                  a=new AnalyseurMap;
                                                  system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Nettoyer miniscule \n";
                                                            cout << "  2.Nettoyer ponctuation\n";
                                                            cout << "  3.Nettoyer mots vides \n";
                                                            cout<<  "  4.Nettoyer plural      \n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";

                                                           cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;

                                                                        const char * ch1 = file.c_str();
                                                                        vector <string> u=ll->lire(ch1);

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;
                                                                        auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);
                                                                         auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;
                                                                       // cout<<"amalt indexer";
                                                                        M->sauvgarder(x);
                                                                        //cout<<"aamlt sauvgrader"


                                            break;
                                            }
                                        case 3:
                                            {
                                                //analyse with unordred map
                                                  a=new AnalyseurFrequenceUnordred;
                                                  system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Nettoyer miniscule \n";
                                                            cout << "  2.Nettoyer ponctuation\n";
                                                            cout << "  3.Nettoyer mots vides \n";
                                                            cout<<  "  4.Nettoyer plural      \n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                            cout << "  Enter your selection: ";
                                                            cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;

                                                                        const char * ch1 = file.c_str();
                                                                        vector <string> u=ll->lire(ch1);

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;
                                                                        auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);
                                                                         auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;
                                                                       // cout<<"amalt indexer";
                                                                        M->sauvgarder(x);
                                                                        //cout<<"aamlt sauvgrader"

                                                break;
                                            }
                                        }

                                        break;
                                        }

                                    cout<<endl;
                                }

                                        break;
                                    }
                                                            case 2:
                                                                { //index diractory
                                                                     int sel1 =0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.  Index with vector\n";
                                                            cout << "  2.  Index with map\n";
                                                            cout << "  3.  Index with unordred map\n";
                                                            cout << "\n";
                                                            cout << "  4.  Exit\n";
                                                            cout << "  ====================================\n";
                                                            cout << "  Enter your selection: ";
                                                            while(!(cin >> sel1))
                                                            {
                                                                cin.clear();
                                                                cin.ignore(999,'\n');
                                                                cout<<"Invalid selection type!\nPlease enter your selection again: ";
                                                            }
                                                            cout << endl;
                                                           system("cls");
                                switch(sel1)
                                {
                                    case 1 :{   // index diractory with vector
                                        string esmdossier;
                                        x=new IndexVect;
                                        cin.ignore();
                                        cout<<" Enter Full Diractory Name (Example: C:\\Users\\user\\OneDrive\\Bureau\\c++\\moteur_recherche\\nouvau ): ";
                                        l=new LecteurDiractory;
                                        ll=new LecteurDoc;
                                        getline(cin,esmdossier,'\n');
                                        const char * ch = esmdossier.c_str();
                                        int s0=0;
                                        vector <string> s = l->lire(ch);
                                        vector <string > s1;
                                        for (int i=0 ; i<s.size();i++)
                                        {
                                            string ch1= esmdossier+"\\"+s[i];
                                            s1.push_back(ch1);
                                        }

                                        cout << "  ====================================\n";
                                        cout << "  1.Analyze with vector\n";
                                        cout << "  2.Analyze with map\n";
                                        cout << "  3.Analyze with unordred map\n";
                                        cout << "\n";
                                        cout << "  4.  Exit\n";
                                        cout << "  ====================================\n";
                                        cout << "  Enter your selection: ";
                                        while(!(cin >> s0))
                                        {
                                        cin.clear();
                                        cin.ignore(999,'\n');
                                        cout<<"Invalid selection type!\nPlease enter your selection again: ";
                                        }
                                        cout << endl;
                                        system("cls");
                                        switch(s0)
                                        {
                                        case 1 :
                                            {
                                                //analyze with vect
                                                            a=new AnalyseurVecteur;
                                                            system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Nettoyer miniscule \n";
                                                            cout << "  2.Nettoyer ponctuation\n";
                                                            cout << "  3.Nettoyer mots vides \n";
                                                            cout<<  "  4.Nettoyer plural      \n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                            cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;
                                                             auto start = high_resolution_clock::now(); //debu



                                                                    for (int i =0 ; i<s1.size(); i++)
                                                                    {

                                                                        const char * ch1 = s1[i].c_str();
                                                                        vector <string> u=ll->lire(ch1);

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;
                                                                       // auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);

                                                                       // cout<<"amalt indexer";
                                                                     //   M->sauvgarder(x);
                                                                        //cout<<"aamlt sauvgrader";
                                                                    }
                                                                     auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;


                                                                    break;
                                                                }
                                        case 2 :
                                                                {
                                                                    //analyse with map
                                                                     a=new AnalyseurMap;
                                                            system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Nettoyer miniscule \n";
                                                            cout << "  2.Nettoyer ponctuation\n";
                                                            cout << "  3.Nettoyer mots vides \n";
                                                            cout<<  "  4.Nettoyer plural      \n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                            cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;

                                                                        auto start = high_resolution_clock::now(); //debu


                                                                    for (int i =0 ; i<s1.size(); i++)
                                                                    {

                                                                        const char * ch1 = s1[i].c_str();
                                                                        vector <string> u=ll->lire(ch1);

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;

                                                                        M->indexer(ch1,x,p,a);
                                                                         auto stop = high_resolution_clock::now(); //fin

                                                                       // cout<<"amalt indexer";
                                                                        M->sauvgarder(x);
                                                                        //cout<<"aamlt sauvgrader";
                                                                    }
                                                                      auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;


                                                                break;
                                                                }
                                        case 3:
                                                                {
                                                                    //analyse with unordred map
                                                                     a=new AnalyseurFrequenceUnordred;
                                                            system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Nettoyer miniscule \n";
                                                            cout << "  2.Nettoyer ponctuation\n";
                                                            cout << "  3.Nettoyer mots vides \n";
                                                            cout<<  "  4.Nettoyer plural      \n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                            cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;
                                                            auto start = high_resolution_clock::now(); //debu



                                                                    for (int i =0 ; i<s1.size(); i++)
                                                                    {

                                                                        const char * ch1 = s1[i].c_str();
                                                                        vector <string> u=ll->lire(ch1);

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;
                                                                      //  auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);
                                                                         //auto stop = high_resolution_clock::now(); //fin

                                                                       // cout<<"amalt indexer";
                                                                        M->sauvgarder(x);
                                                                        //cout<<"aamlt sauvgrader";
                                                                    }
                                                                     auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;


                                                                    break;
                                                                }
                                        }

                                break;
                                            }

                                    case 2:
                                    { //index diractory with map

                                         string esmdossier;
                                        x=new IndexMap;
                                        cin.ignore();
                                        cout<<" Enter Full Diractory Name (Example: C:\\Users\\user\\OneDrive\\Bureau\\c++\\moteur_recherche\\nouvau ): ";
                                        l=new LecteurDiractory;
                                        ll=new LecteurDoc;
                                        getline(cin,esmdossier,'\n');
                                        const char * ch = esmdossier.c_str();
                                        //int s0=0;
                                        vector <string> s = l->lire(ch);
                                        vector <string > s1;
                                        for (int i=0 ; i<s.size();i++)
                                        {
                                            string ch= esmdossier+"\\"+s[i];
                                            s1.push_back(ch);
                                        }
                                        int s0=0;

                                        cout << "  ====================================\n";
                                        cout << "  1.Analyze with vector\n";
                                        cout << "  2.Analyze with map\n";
                                        cout << "  3.Analyze with unordred map\n";
                                        cout << "\n";
                                        cout << "  4.  Exit\n";
                                        cout << "  ====================================\n";
                                        cout << "  Enter your selection: ";
                                        while(!(cin >> s0))
                                        {
                                        cin.clear();
                                        cin.ignore(999,'\n');
                                        cout<<"Invalid selection type!\nPlease enter your selection again: ";
                                        }
                                        cout << endl;
                                        system("cls");
                                        switch(s0)
                                        {
                                        case 1 :
                                            {
                                                //analyze with vect
                                                            a=new AnalyseurVecteur;
                                                            system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Nettoyer miniscule \n";
                                                            cout << "  2.Nettoyer ponctuation\n";
                                                            cout << "  3.Nettoyer mots vides \n";
                                                            cout<<  "  4.Nettoyer plural      \n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                            cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;
                                                            auto start = high_resolution_clock::now(); //debu



                                                                    for (int i =0 ; i<s1.size(); i++)
                                                                    {

                                                                        const char * ch1 = s1[i].c_str();
                                                                        vector <string> u=ll->lire(ch1);
                                                                       // cout<<"amlt lire"<<u[0]<<endl;
                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;
                                                                        //auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);
                                                                       //  auto stop = high_resolution_clock::now(); //fin
                                                                       // auto duration = duration_cast<microseconds>(stop - start);
                                                                       // cout << "Time taken by index: "
                                                                           //  << duration.count() << " microseconds" << endl;
                                                                      //  cout<<"amalt indexer";
                                                                       // M->sauvgarder(x);
                                                                       // cout<<"aamlt sauvgrader";
                                                                    }
                                                                     auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;

                                                                    break;
                                                                }
                                        case 2 :
                                                                {
                                                                    //analyse with map
                                                                     a=new AnalyseurMap;
                                                            system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Clean to lower  \n";
                                                            cout << "  2.Clean punctuation\n";
                                                            cout << "  3.Clean words \n";
                                                            cout<<  "  4.Clean plural      \n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                           cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;

                                                                             auto start = high_resolution_clock::now(); //debu

                                                                    for (int i =0 ; i<s1.size(); i++)
                                                                    {

                                                                        const char * ch1 = s1[i].c_str();
                                                                        vector <string> u=ll->lire(ch1);

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;
                                                                       // auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);
                                                                       //  auto stop = high_resolution_clock::now(); //fin
                                                                       // auto duration = duration_cast<microseconds>(stop - start);
                                                                       // cout << "Time taken by index: "
                                                                       //      << duration.count() << " microseconds" << endl;
                                                                       // cout<<"amalt indexer";
                                                                        M->sauvgarder(x);
                                                                        //cout<<"aamlt sauvgrader";
                                                                    }
                                                                     auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;


                                                                break;
                                                                }
                                        case 3:
                                                                {
                                                                    //analyse with unordred map
                                                                     a=new AnalyseurFrequenceUnordred;
                                                            system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Nettoyer miniscule \n";
                                                            cout << "  2.Nettoyer ponctuation\n";
                                                            cout << "  3.Nettoyer mots vides \n";
                                                            cout<<  "  4.Nettoyer plural      \n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                           cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;

                                                                             auto start = high_resolution_clock::now(); //debu

                                                                    for (int i =0 ; i<s1.size(); i++)
                                                                    {

                                                                        const char * ch1 = s1[i].c_str();
                                                                        vector <string> u=ll->lire(ch1);

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;
                                                                       // auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);
                                                                       //  auto stop = high_resolution_clock::now(); //fin
                                                                       // auto duration = duration_cast<microseconds>(stop - start);
                                                                       // cout << "Time taken by index: "
                                                                        //     << duration.count() << " microseconds" << endl;
                                                                       // cout<<"amalt indexer";
                                                                        M->sauvgarder(x);
                                                                        //cout<<"aamlt sauvgrader";
                                                                    }
                                                                    auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;

                                                                    break;
                                                                }
                                        }

                                break;
                                }
                                case 3:
                                        {   // index file with unordred-map
                                            string esmdossier;
                                        x=new IndexunordredMap;
                                        cin.ignore();
                                        cout<<" Enter Full Diractory Name (Example: C:\\Users\\user\\OneDrive\\Bureau\\c++\\moteur_recherche\\nouvau ): ";
                                        l=new LecteurDiractory;
                                        ll=new LecteurDoc;
                                        getline(cin,esmdossier,'\n');
                                        const char * ch = esmdossier.c_str();
                                        //int s0=0;
                                        vector <string> s = l->lire(ch);
                                        vector <string > s1;
                                        for (int i=0 ; i<s.size();i++)
                                        {
                                            string ch= esmdossier+"\\"+s[i];
                                            s1.push_back(ch);
                                        }
                                        int s0=0;

                                        cout << "  ====================================\n";
                                        cout << "  1.Analyze with vector\n";
                                        cout << "  2.Analyze with map\n";
                                        cout << "  3.Analyze with unordred map\n";
                                        cout << "\n";
                                        cout << "  4.  Exit\n";
                                        cout << "  ====================================\n";
                                        cout << "  Enter your selection: ";
                                        while(!(cin >> s0))
                                        {
                                        cin.clear();
                                        cin.ignore(999,'\n');
                                        cout<<"Invalid selection type!\nPlease enter your selection again: ";
                                        }
                                        cout << endl;
                                        system("cls");
                                        switch(s0)
                                        {
                                        case 1 :
                                            {
                                                //analyse with vect
                                                a=new AnalyseurVecteur;
                                                  system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Nettoyer miniscule \n";
                                                            cout << "  2.Nettoyer ponctuation\n";
                                                            cout << "  3.Nettoyer mots vides \n";
                                                            cout<<  "  4.Nettoyer plural      \n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                            cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;

                                                                    auto start = high_resolution_clock::now(); //debu

                                                                    for (int i =0 ; i<s1.size(); i++)
                                                                    {

                                                                        const char * ch1 = s1[i].c_str();
                                                                        vector <string> u=ll->lire(ch1);

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;
                                                                      //  auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);
                                                                      //   auto stop = high_resolution_clock::now(); //fin
                                                                      //  auto duration = duration_cast<microseconds>(stop - start);
                                                                       // cout << "Time taken by index: "
                                                                       //      << duration.count() << " microseconds" << endl;
                                                                       // cout<<"amalt indexer";
                                                                       // M->sauvgarder(x);
                                                                        //cout<<"aamlt sauvgrader";
                                                                    }
                                                                     auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;


                                                break;
                                            }
                                        case 2 :
                                            {
                                                //anlyze map
                                                  a=new AnalyseurMap;
                                                  system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Nettoyer miniscule \n";
                                                            cout << "  2.Nettoyer ponctuation\n";
                                                            cout << "  3.Nettoyer mots vides \n";
                                                            cout<<  "  4.Nettoyer plural      \n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                           cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;

                                                                     auto start = high_resolution_clock::now(); //debu

                                                                    for (int i =0 ; i<s1.size(); i++)
                                                                    {

                                                                        const char * ch1 = s1[i].c_str();
                                                                        vector <string> u=ll->lire(ch1);

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;
                                                                      //  auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);
                                                                       //  auto stop = high_resolution_clock::now(); //fin
                                                                       // auto duration = duration_cast<microseconds>(stop - start);

                                                                        M->sauvgarder(x);
                                                                        //cout<<"aamlt sauvgrader";
                                                                    }
                                                                     auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;




                                            break;
                                            }
                                        case 3:
                                            {
                                                //analyse with unordred map
                                                  a=new AnalyseurFrequenceUnordred;
                                                  system("cls");
                                                            int sel0=0;
                                                            cout << "  ====================================\n";
                                                            cout << "  1.Nettoyer miniscule \n";
                                                            cout << "  2.Nettoyer ponctuation\n";
                                                            cout << "  3.Nettoyer mots vides \n";
                                                            cout<<  "  4.Nettoyer plural      \n";
                                                            cout << "\n";
                                                            cout << "  5.  Exit\n";
                                                            cout << "  ====================================\n";
                                                           cout << "  Entrer nombre de nettoyers: ";
                                                            int nbr ;
                                                            cin>> nbr;
                                                            string ordre ;
                                                            cout << "  Enter leur ordre : exemple  123 ";
                                                            cin>> ordre ;

                                                                     auto start = high_resolution_clock::now(); //debu

                                                                    for (int i =0 ; i<s1.size(); i++)
                                                                    {

                                                                        const char * ch1 = s1[i].c_str();
                                                                        vector <string> u=ll->lire(ch1);

                                                                        vector <string> p=M->choix(nbr,ordre,u);
                                                                       // cout<<"texte netoyee bel choix"<<endl;
                                                                       // auto start = high_resolution_clock::now(); //debu
                                                                        M->indexer(ch1,x,p,a);
                                                                         //auto stop = high_resolution_clock::now(); //fin
                                                                        //auto duration = duration_cast<microseconds>(stop - start);
                                                                        //cout << "Time taken by index: "
                                                                         //    << duration.count() << " microseconds" << endl;
                                                                       // cout<<"amalt indexer";
                                                                        M->sauvgarder(x);
                                                                        //cout<<"aamlt sauvgrader";
                                                                    }
                                                                    auto stop = high_resolution_clock::now(); //fin
                                                                        auto duration = duration_cast<microseconds>(stop - start);
                                                                        cout << "Time taken by index: "
                                                                             << duration.count() << " microseconds" << endl;


                                                break;
                                            }
                                        }

                                        break;
                                        }

                                    cout<<endl;
                                }

                                        break;

                                                                }
                                } //nsaker el switch

                                break;

                        } // nsaker el case 2mtaa el main

            case 3 :
                {
                    system("cls");
                    M->sauvgarder(x);
                    break;
                }
            case 4 :
                {
                    system("cls");
                    string fich;
                    cout<<"the file path that you want to delete from index is : "<<endl;
                    cin>>fich;
                    M->supprimer(fich,x);
                    break;
                }
            case 5 :
                {
                    system("cls");
                    M->AfficherIndex();
                    break;
                }
            case 6:
                {
                    system("cls");
                    M->restaurer(x);
                    break;
                }
            case 7:
                {
                    system("cls");
                    cout<<"Good bye!! see you next time !!"<<endl;

                    break;
                }

            default: //cout <<selection << " is not a valid menu item try again.\n";

                cout << endl;
        }
        }while (selection != 8 );


/*
Moteur * M;
Lecteur * l=new LecteurDiractory  ;
Lecteur * ll=new LecteurDoc  ;
Nettoyeur * n=new Nettoyeur_minis;
Analyseur *a =new AnalyseurMap;
Index *x=new IndexMap;
//Index *x=new IndexVect;
vector <string> v = l->lire("C:\\Users\\user\\OneDrive\\Bureau\\c++\\moteur_recherche\\nouvau");

//cout<<v.size();
for (int i =0 ; i<v.size(); i++)
{
    string ch="C:\\Users\\user\\OneDrive\\Bureau\\c++\\moteur_recherche\\nouvau\\"+v[i];
    const char * ch1 = ch.c_str();
    ll->lire(ch1);
    M->indexer(ch1,x,ll,n,a);
    M->sauvgarder(x);
}
M->supprimer("molka.txt",x);
M->sauvgarder(x);*/
   /* const char * ch = fichier.c_str();
string ch = l->verif("C:\\Users\\user\\OneDrive\\Bureau\\c++\\moteur_recherche\\nouvau");
cout<<ch;

cout<<v.size();
for (int i =0 ; i<v.size(); i++)
{
    cout<<v[i]<<endl;
}
M->indexer("molka.txt",x,l,n,a);
    vector <string> v2 = l->lire("C:\\Users\\user\\OneDrive\\Bureau\\c++\\moteur_recherche\\nouvau\\184.txt");
    //cout<<"hetha size"<<v2.size()<<"---";
    //n=new Nettoyeur_minis;
   // vector <string> v1=n->Nettoyer(v);
    vector <string> v3=n->Nettoyer(v2);
   // vector<Statistique> vs = a->analyser(v1,"molka.txt");
    vector<Statistique> vs1 = a->analyser(v3,"184.txt");
    for (int i=0 ; i<vs.size();i++)
{

    cout<<vs[i].getMot();
    cout<<"---";
    cout<<vs[i].getValeur()<<endl;
    cout<<"---";
    cout<<vs[i].getFich()<<endl;
}
M->sauvgarder(x);

    for (int i=0 ; i<vs1.size();i++)
    {

        x->setStatestique(vs1[i]);
    }
    vector <Statistique> res = x->getStatistiques();
    cout<<"affiche index"<<endl;
    for (int i=0 ; i<vs1.size();i++)
    {

        x->setStatestique(vs1[i]);
    }
    vector <Statistique> res1 = x->getStatistiques();
   // cout<<res.size()<<endl;
    //cout<<res1.size()<<endl;
for (int i=0 ; i<res.size();i++)
{

    cout<<res[i].getMot();
    cout<<"---";
    cout<<res[i].getValeur()<<endl;
    cout<<"---";
    cout<<res[i].getFich()<<endl;
}
cout<<"*************************************"<<endl;
for (int i=0 ; i<res1.size();i++)
{

    cout<<res1[i].getMot();
    cout<<"---";
    cout<<res1[i].getValeur()<<endl;
    cout<<"---";
    cout<<res1[i].getFich()<<endl;
}
M->sauvgarder(x);
vector <string > vect = l->lire("index.txt");
cout<<"9bal el supprimer ------------------------"<<endl;
M->supprimer("molka.txt",x);
vector<Statistique> a7= x->getStatistiques();
cout<<"taille de texte : "<<v2.size()<< "---------------------------------------"<<endl;
for (int i=0 ; i<a7.size();i++)
{

    cout<<a7[i].getMot();
    cout<<"---";
    cout<<a7[i].getValeur()<<endl;
    cout<<"---";
    cout<<a7[i].getFich()<<endl;
}
Ordonnanceur * o  =new Ordonnanceur_Occurance;
cout<<"test ord"<<endl;
vector <string> ichrak = {"or" };
vector <string> vectfich = o->Ordonnoncer(ichrak , x);
cout<<"++++++++++++++++++++++++++++++++++++++++***********************************************"<<endl;
cout<<vectfich.size();
cout<<"fichier 1 :"<<endl;
for (int i=0 ; i<vectfich.size();i++)
{
cout<<vectfich[i]<<endl;
}
M->restaurer(x);

cout<<"**********************";
vector <Statistique> s = x->getStatistiques();
//cout<<"**********************";
cout<<s.size();
for (int i=0 ; i<s.size();i++)
{

    cout<<s[i].getMot();
    cout<<"---";
    cout<<s[i].getValeur()<<endl;
    cout<<"---";
    cout<<s[i].getFich()<<endl;
}



for (int i=0 ; i<v.size();i++)
{
    cout<< v.size();
    cout<<v[i]<<endl;

}
*/
  return 0;
}


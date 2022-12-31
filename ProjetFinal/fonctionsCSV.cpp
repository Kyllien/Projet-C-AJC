
#include "fonctionsCSV.h"



int CSVPROtoDB(string filename)
{

//    cout<<"OPENING FILE : "<<filename<<endl;
    // Ouvrir fichier csv.
    ifstream file(filename);
    // Vérifier bonne ouverture du fichier
    if (!file.is_open()) {
        cerr << "Error: Failed to open file." << endl;
    }


    // lire ligne par ligne
    string line;

    int id;
    string nom,prenom,rue,complement,ville, entreprise, email, dtnaissance;
    char genre;
    int cp;

    // lire et ignorer la 1ère ligne:
    getline(file, line);

    // itérer sur les lignes suivantes pour récupérer les contacts
    while (getline(file, line))
    {


        // split chaque ligne avec un délimiteur  ;
        stringstream ss(line);
        string field;

        //ID Nom Prenom Sexe Entreprise rue Complement cp Ville mail dtNaissance
        //0  1   2      3    4          5   6          7  8     9     10

        // entête CSV Pro:
        //﻿Identifiant;Nom;Prénom;Sexe;Entreprise;Libellé;Complément;Code Postal;Ville;Mail de Contact
        int i(0);
        while (getline(ss, field, ';'))
        {

            //cout<<field<<"|";
            switch(i)
            {
                case(0): id=stoi(field); break;
                case(1): nom=field; break;
                case(2): prenom=field; break;
                case(3): genre=field.at(0); break;
                case(4): entreprise=field; break;
                case(5): rue=field; break;
                case(6): complement=field;break;
                case(7): cp=stoi(field); break;
                case(8): ville=field;break;
                case(9): email=field;break;
            }
            i++;
        }
        //cout<<endl<<endl;

        ContactPro ctmp(id,nom,prenom,genre,entreprise,rue,complement,cp,ville,email);

//        cout<<ctmp<<endl<<endl;

        // ajouter le contact à la BDD
        addContact(&ctmp);

    }


    // Close the file
    file.close();

    int result = remove(&filename[0]);
    if (result != 0) {
        cout<<"an error occured during file deletion"<<endl;
    }

    return 0;
}


int CSVPRIVEtoDB(string filename)
{

//    cout<<"OPENING FILE : "<<filename<<endl;
    // Ouvrir fichier csv.
    ifstream file(filename);
    // Vérifier bonne ouverture du fichier
    if (!file.is_open()) {
        cerr << "Error: Failed to open file." << endl;
    }


    // lire ligne par ligne
    string line;

    int id;
    string nom,prenom,rue,complement,ville, entreprise, email, dtnaissance;
    char genre;
    int cp;

    // lire et ignorer la 1ère ligne:
    getline(file, line);

    // itérer sur les lignes suivantes pour récupérer les contacts
    while (getline(file, line))
    {


        // split chaque ligne avec un délimiteur  ;
        stringstream ss(line);
        string field;

        //ID Nom Prenom Sexe Entreprise rue Complement cp Ville mail dtNaissance
        //0  1   2      3    4          5   6          7  8     9     10

        // entête CSV Private
        //﻿Identifiant;Nom;Prénom;Sexe;Libellé;Complément;Code Postal;Ville;Date de Naissance
        int i(0);
        while (getline(ss, field, ';'))
        {

            //cout<<field<<"|";
            switch(i)
            {
                case(0): id=stoi(field); break;
                case(1): nom=field; break;
                case(2): prenom=field; break;
                case(3): genre=field.at(0); break;
                case(4): rue=field; break;
                case(5): complement=field;break;
                case(6): cp=stoi(field); break;
                case(7): ville=field;break;
                case(8): dtnaissance=field;break;
            }
            i++;
        }
        //cout<<endl<<endl;

        ContactPrive ctmp(id,nom,prenom,genre,rue,complement,cp,ville,dtnaissance);

//        cout<<ctmp<<endl<<endl;

        // ajouter le contact à la BDD
        addContact(&ctmp);

    }


    // Close the file
    file.close();

    int result = remove(&filename[0]);
    if (result != 0) {
        cout<<"an error occured during file deletion"<<endl;
    }

    return 0;
}

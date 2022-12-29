#ifndef Contact_H
#define Contact_H

#include<iostream>
#include <sstream>
#include<stdlib.h>
#include<string>
using namespace std;



class Contact
{
    public:
        Contact(int,string,string,char);
        virtual ~Contact();

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        string Getnom() { return nom; }
        void Setnom(string val) { nom = val; }
        string Getprenom() { return prenom; }
        void Setprenom(string val) { prenom = val; }
        char Getgenre() { return genre; }
        void Setgenre(char val) { genre = val; }

        virtual string infos() =0;

    protected:

    private:
        int id;
        string nom;
        string prenom;
        char genre;
};

ostream& operator<<(ostream& sortie, Contact& p);

#endif // Contact_H

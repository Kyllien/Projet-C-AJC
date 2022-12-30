#ifndef Contact_H
#define Contact_H

#include<iostream>
#include <sstream>
#include<stdlib.h>

using namespace std;



class Contact
{
    public:
        Contact(int,string,string,char,string , string, int, string);
        virtual ~Contact();

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        char* Getnom() {return &(this->nom[0]);}
        void Setnom(string val) { nom = val; }
        char* Getprenom() { return &(prenom[0]); }
        void Setprenom(string val) { prenom = val; }
        char* Getgenre() ;
        void Setgenre(char val) { genre = val; }
        char* Getrue() { return &rue[0]; }
        void Setrue(string val) { rue = val; }
        char* Getcomplement() { return &complement[0]; }
        void Setcomplement(string val) { complement = val; }
        int Getcp() { return cp; }
        void Setcp(int val) { cp = val; }
        char* Getville() { return &ville[0]; }
        void Setville(string val) { ville= val; }


        virtual string infos() =0;

    protected:

    private:
        int id;
        string nom;
        string prenom;
        char genre;
        string rue;
        string complement;
        int cp;
        string ville;
};

ostream& operator<<(ostream& sortie, Contact& p);

#endif // Contact_H

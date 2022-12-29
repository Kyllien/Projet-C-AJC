#ifndef Contact_H
#define Contact_H

#include<iostream>
#include <sstream>
#include<stdlib.h>

using namespace std;



class Contact
{
    public:
        Contact(int,char*,char*,char, char* , char*, int, char*);
        virtual ~Contact();

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        char* Getnom() { return nom; }
        void Setnom(char* val) { nom = val; }
        char* Getprenom() { return prenom; }
        void Setprenom(char* val) { prenom = val; }
        char* Getgenre() ;
        void Setgenre(char val) { genre = val; }
        char* Getrue() { return rue; }
        void Setrue(char* val) { rue = val; }
        char* Getcomplement() { return complement; }
        void Setcomplement(char* val) { complement = val; }
        int Getcp() { return cp; }
        void Setcp(int val) { cp = val; }
        char* Getville() { return ville; }
        void Setville(char* val) { ville= val; }


        virtual string infos() =0;

    protected:

    private:
        int id;
        char*  nom;
        char* prenom;
        char genre;
        char* rue;
        char* complement;
        int cp;
        char* ville;
};

ostream& operator<<(ostream& sortie, Contact& p);

#endif // Contact_H

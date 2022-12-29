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
        Contact(int,string,string,char, string , string, int, string);
        virtual ~Contact();

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        string Getnom() { return nom; }
        void Setnom(string val) { nom = val; }
        string Getprenom() { return prenom; }
        void Setprenom(string val) { prenom = val; }
        char Getgenre() { return genre; }
        void Setgenre(char val) { genre = val; }
        string Getrue() { return rue; }
        void Setrue(string val) { rue = val; }
        string Getcomplement() { return complement; }
        void Setcomplement(string val) { complement = val; }
        int Getcp() { return cp; }
        void Setcp(int val) { cp = val; }
        string Getville() { return ville; }
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

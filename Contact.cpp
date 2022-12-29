#include "Contact.h"

Contact::Contact(int id,string nom, string prenom,char genre)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->genre=genre;
}

Contact::~Contact()
{
    cout<<"suppression contact "<<this->nom<<endl;
    //dtor
}



ostream& operator<<(ostream& sortie, Contact& p)
{

    sortie << p.infos() ;
    return sortie;
}


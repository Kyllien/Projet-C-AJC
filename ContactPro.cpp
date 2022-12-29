#include "ContactPro.h"


ContactPro::ContactPro(int id, string nom, string prenom, char genre, string entreprise, string adresse, string email )
    :Contact(id,nom,prenom,genre)
{
    this->nomEntreprise=entreprise;
    this->adresseEntreprise=adresse;
    this->email=email;
}

ContactPro::~ContactPro()
{
    //dtor
}

string ContactPro::infos()
{

    ostringstream oss;
    oss  << endl << "Id " << this->Getid();
    oss  << endl << "Nom " << this->Getnom();
    oss  << endl << "Prenom " << this->Getprenom();
    oss  << endl << "genre " << this->Getgenre();
    oss << endl << "entreprise "<<this->GetnomEntreprise();
    oss << endl << "adresse "<<this->GetadresseEntreprise();
    oss << endl << "email "<<this->Getemail();
    return oss.str();
}

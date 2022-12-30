#include "ContactPrive.h"


ContactPrive::ContactPrive(int id, string nom, string prenom, char genre, string adresse, string date )
    :Contact(id,nom,prenom,genre)
{
    this->adresse=adresse;
    this->dateNaissance=date;
}

ContactPrive::~ContactPrive()
{
    //dtor
}

string ContactPrive::infos()
{

    ostringstream oss;
    oss  << endl << "Id " << this->Getid();
    oss  << endl << "Nom " << this->Getnom();
    oss  << endl << "Prenom " << this->Getprenom();
    oss  << endl << "genre " << this->Getgenre();
    oss << endl << "adresse "<<this->Getadresse();
    oss << endl << "date de naissance "<<this->GetdateNaissance();
    return oss.str();
}

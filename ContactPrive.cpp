#include "ContactPrive.h"


ContactPrive::ContactPrive(int id, string nom, string prenom, char genre, string rue, string complement, int cp, string ville, string date )
    :Contact(id,nom,prenom,genre,rue,complement,cp,ville)
{

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
    oss << endl << "adresse perso "<<this->Getrue()<<" "<<this->Getcomplement()<<" "<<this->Getcp()<<" "<<this->Getville();
    oss << endl << "date de naissance "<<this->GetdateNaissance();
    return oss.str();
}

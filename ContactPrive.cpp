#include "ContactPrive.h"


ContactPrive::ContactPrive(int id, char* nom, char* prenom, char genre, char* rue, char* complement, int cp, char* ville, char* date )
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

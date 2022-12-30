#include "ContactPro.h"


ContactPro::ContactPro(int id,string nom,string prenom, char genre,string entreprise, string rue,string complement, int cp, string ville, string email )
    :Contact(id,nom,prenom,genre,rue,complement,cp,ville)
{
    this->nomEntreprise=entreprise;
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
    oss << endl << "adresse entreprise "<<this->Getrue()<<" "<<this->Getcomplement()<<" "<<this->Getcp()<<" "<<this->Getville();
    oss << endl << "email "<<this->Getemail();
    return oss.str();
}

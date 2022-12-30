#ifndef ContactPRO_H
#define ContactPRO_H

#include "Contact.h"


class ContactPro : public Contact
{
    public:
        ContactPro(int, string, string, char, string, string, string );
        virtual ~ContactPro();
        string GetnomEntreprise() { return nomEntreprise; }
        void SetnomEntreprise(string val) { nomEntreprise= val; }
        string GetadresseEntreprise() { return adresseEntreprise; }
        void SetadresseEntreprise(string val) { adresseEntreprise = val; }
        string Getemail() { return email; }
        void Setemail(string val) { email = val; }
        string infos() override;

    protected:

    private:
        string nomEntreprise;
        string adresseEntreprise;
        string email;
};

#endif // ContactPRO_H

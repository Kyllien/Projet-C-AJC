#ifndef ContactPRO_H
#define ContactPRO_H

#include "Contact.h"


class ContactPro : public Contact
{
    public:
        ContactPro(int, string,string, char,string,string , string, int,string,string );
        virtual ~ContactPro();

        char* GetnomEntreprise() { return &nomEntreprise[0]; }
        void SetnomEntreprise(string val) { nomEntreprise= val; }
        char* Getemail() { return &email[0]; }
        void Setemail(string val) { email = val; }
        string infos() override;

    protected:

    private:
        string nomEntreprise;
        string email;
};

#endif // ContactPRO_H

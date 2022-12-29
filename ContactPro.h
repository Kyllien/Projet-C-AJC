#ifndef ContactPRO_H
#define ContactPRO_H

#include "Contact.h"


class ContactPro : public Contact
{
    public:
        ContactPro(int, char*, char*, char, char*, char* , char*, int, char*, char* );
        virtual ~ContactPro();

        char* GetnomEntreprise() { return nomEntreprise; }
        void SetnomEntreprise(char* val) { nomEntreprise= val; }
        char* Getemail() { return email; }
        void Setemail(char* val) { email = val; }
        string infos() override;

    protected:

    private:
        char* nomEntreprise;
        char* email;
};

#endif // ContactPRO_H

#ifndef ContactPRIVE_H
#define ContactPRIVE_H

#include "Contact.h"


class ContactPrive : public Contact
{
    public:
        ContactPrive(int,string,string,char,string , string, int, string,string);
        virtual ~ContactPrive();

        string GetdateNaissance() { return dateNaissance; }
        void SetdateNaissance(string val) { dateNaissance = val; }

        string infos() override;

    protected:

    private:

        string dateNaissance;
};

#endif // ContactPRIVE_H

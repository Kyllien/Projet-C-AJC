#ifndef ContactPRIVE_H
#define ContactPRIVE_H

#include "Contact.h"


class ContactPrive : public Contact
{
    public:
        ContactPrive(int,string,string,char,string ,string, int,string,string);
        virtual ~ContactPrive();

        char* GetdateNaissance() { return &dateNaissance[0]; }
        void SetdateNaissance(char* val) { dateNaissance = val; }

        string infos() override;

    protected:

    private:

        string dateNaissance;
};

#endif // ContactPRIVE_H

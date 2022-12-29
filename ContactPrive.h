#ifndef ContactPRIVE_H
#define ContactPRIVE_H

#include "Contact.h"


class ContactPrive : public Contact
{
    public:
        ContactPrive(int,char*,char*,char,char* , char*, int, char*,char*);
        virtual ~ContactPrive();

        char* GetdateNaissance() { return dateNaissance; }
        void SetdateNaissance(char* val) { dateNaissance = val; }

        string infos() override;

    protected:

    private:

        char* dateNaissance;
};

#endif // ContactPRIVE_H

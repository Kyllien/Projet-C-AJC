#ifndef MONEXCEPTION_H
#define MONEXCEPTION_H

#include <iostream>
#include <stdexcept>

using namespace std;



class MonException: public exception
{
    public:

        MonException(string cause)
        {
            this->cause = cause;
        }
        MonException(int errCode)
        {
            this->codeErr = errCode;
            if (codeErr == 1)
            {
                this->cause ="Argument invalide";
            }
            else
            {
                this->cause ="Autre cause";
            }

        }
        virtual ~MonException() {cout<<"destruction cause : "<<this->cause;}


        const char* what() const noexcept //noexcept : cette methode ne peut pas throw !
        {

            return cause.c_str(); //conversion type string vers type const char*
        }


    protected:


    private:
        string cause;
        int codeErr;
};

#endif // MONEXCEPTION_H

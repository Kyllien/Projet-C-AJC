#include "Contact.h"
#include "ContactPro.h"
#include "ContactPrive.h"

int main()
{

    ContactPro pro1(1,"Wallace","Marcel",'M',"Renault","Guyancourt",
                    "marcel.wallace@renault.com");

    cout<<pro1;

    ContactPrive prive1(2,"willis","bruce",'M',"Los Angeles","17/10/59");

    cout<<"hello world"<<endl;


    return 0;
}

#include "Contact.h"
#include "ContactPro.h"
#include "ContactPrive.h"

#include "fonctionsDB.h"







int main()
{


    // création instances de contacts:
    ContactPro* pro1 = new ContactPro(1,"Wallace","Marcel",'M',"Renault","rue du quai","",78888,"Guyancourt",
                    "marcel.wallace@renault.com");

    cout<<*pro1<<endl;

    ContactPrive prive1(2,"willis","bruce",'M',"hollywood Bvrd","",55544,"Los Angeles"
                    ,"1959-10-17");


    cout<<prive1<<endl;


    // Ajouter les contacts à la BDD:
    addContact(pro1);
    addContact(&prive1);


    delete pro1;
    return 0;
}



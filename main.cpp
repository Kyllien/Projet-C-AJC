#include "Contact.h"
#include "ContactPro.h"
#include "ContactPrive.h"
#include "sqlite3.h"
#include <string>

void addContact(Contact*);
sqlite3* ouvertureDB();
void fermetureDB(sqlite3*);

int main()
{


    ContactPro* pro1 = new ContactPro(1,"Wallace","Marcel",'M',"Renault","rue du quai","",78888,"Guyancourt",
                    "marcel.wallace@renault.com");

    cout<<*pro1<<endl;

    ContactPrive prive1(2,"willis","bruce",'M',"hollywood Bvrd","",555444,"Los Angeles"
                    ,"17/10/59");


    cout<<prive1<<endl;

    addContact(pro1);

    addContact(&prive1);


    delete pro1;
    return 0;
}


void addContact(Contact* monContact)
{

    sqlite3 *db = ouvertureDB();

    sqlite3_stmt *stmt=NULL;

    //ID Nom Prenom Sexe Entreprise rue Complement cp Ville mail dtNaissance
    char *requete = "insert into contacts values (NULL,?,?,?,?,?,?,?,?,?,?)";



    // Spécialisation requête suivant type de contact Pro ou Privé
    ContactPro* contact=dynamic_cast<ContactPro*>(monContact);

    if (sqlite3_prepare_v2(db,requete,200, &stmt,NULL)== SQLITE_OK)
    {

        if (contact!= nullptr) //l'objet casté est bien de type ContactPro
        {
            // création requete pour ajout d'un contact pro;
            cout<<"contact PRO!"<<endl;
        }
        else
        {
            cout<<"contact PRIVE!"<<endl;
            // création requete pour ajout d'un contact privé;
        }

    }
    else
        cout<<"problem w/ sql request"<<endl;



//    sqlite3_bind_text(stmt,1,"MDR 2023",strlen("MDR 20023"),NULL);
//    sqlite3_bind_int(stmt,2,348);

    fermetureDB(db);

}



sqlite3* ouvertureDB()
{
    try
    {
        sqlite3 *db=NULL;        // connection Base
        int rc;             // code retour
        char *errmsg=NULL;       // pointeur vers err


        rc = sqlite3_open("dbContacts.db", &db);

        if (rc != SQLITE_OK) {
            printf("ERREUR Open : %s\n", sqlite3_errmsg(db));
        }
        else
            cout<<"openened DB successfully"<<endl;

        return db;


    }
    catch(...)
    {
    }
}

void fermetureDB(sqlite3* db)
{

    try
    {
        int rc;
        rc = sqlite3_close(db);
        if (rc != SQLITE_OK) {
            printf("ERREUR Open : %s\n", sqlite3_errmsg(db));

        }
    }
    catch(...)
    {
    }

}

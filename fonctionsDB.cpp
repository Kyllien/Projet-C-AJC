#include "fonctionsDB.h"


void addContact(Contact* monContact)
{

    sqlite3 *db = ouvertureDB();
    int rc;
    sqlite3_stmt *stmt=NULL;



    //ID Nom Prenom Sexe Entreprise rue Complement cp Ville mail dtNaissance
    //0  1   2      3    4          5   6          7  8     9     10
    string req = "insert into CONTACTS (IdContact,Nom,Prenom,Sexe,Entreprise,rue,Complement,cp,Ville,mail,dtNaissance) \
                        values (NULL, ?,?,?,?,?,?,?,?,?,?);";

    char* requete = &req[0];

    // preparer la requete
    rc = sqlite3_prepare_v2(db,requete,500, &stmt,NULL);
    if (rc != SQLITE_OK)
        fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));


    // valoriser les champs connus (niveau Contact)
    sqlite3_bind_text(stmt,1,monContact->Getnom(),strlen(monContact->Getnom()),NULL);
    sqlite3_bind_text(stmt,2,monContact->Getprenom(),strlen(monContact->Getprenom()),NULL);
    sqlite3_bind_text(stmt,3,monContact->Getgenre(),1,NULL);
    sqlite3_bind_text(stmt,5,monContact->Getrue(),strlen(monContact->Getrue()),NULL);
    sqlite3_bind_text(stmt,6,monContact->Getcomplement(),strlen(monContact->Getcomplement()),NULL);
    sqlite3_bind_int(stmt,7,monContact->Getcp());
    sqlite3_bind_text(stmt,8,monContact->Getville(),strlen(monContact->Getville()),NULL);



    // Spécialisation requête suivant type de contact Pro ou Privé
    ContactPro* cpro=dynamic_cast<ContactPro*>(monContact);

    if (cpro) //l'objet casté est bien de type ContactPro
    {
        // création requete pour ajout d'un contact pro;
        cout<<"contact PRO!"<<endl;
        // ajout d'email et nom entreprise
        sqlite3_bind_text(stmt,4,cpro->GetnomEntreprise(),strlen(cpro->GetnomEntreprise()),NULL);
        sqlite3_bind_text(stmt,9,cpro->Getemail(),strlen(cpro->Getemail()),NULL);
        sqlite3_bind_null(stmt,10);
    }

    else
    {
        ContactPrive* cprive=dynamic_cast<ContactPrive*>(monContact);
        if (cprive)
        {
            // création requete pour ajout d'un contact privé;
            cout<<"contact PRIVE!"<<endl;
            // ajout de date de naissance
            sqlite3_bind_text(stmt,10,cprive->GetdateNaissance(),strlen(cprive->GetdateNaissance()),NULL);
            sqlite3_bind_null(stmt,4);
            sqlite3_bind_null(stmt,9);
        }
    }




    rc = sqlite3_step(stmt);
    printf("rc:%d",rc);

    try
    {
        rc = sqlite3_finalize(stmt);
        if (rc != SQLITE_OK) {
            throw MonException(sqlite3_errmsg(db));
        }

    }
    catch(const MonException& ex)
    {
        cout<<endl<< "MonException :" << ex.what() <<endl;
    }


    fermetureDB(db);

}



sqlite3* ouvertureDB()
{
    try
    {
        sqlite3 *db=NULL;        // connection Base
        int rc;             // code retour
//        char *errmsg=NULL;       // pointeur vers err


        rc = sqlite3_open(DB, &db);

        if (rc != SQLITE_OK) {
            throw MonException(sqlite3_errmsg(db));
            //throw MonException(2);
        }
        else
            cout<<"openened DB successfully"<<endl;

        return db;


    }
    catch(const MonException& ex)
    {
        cout<<endl<< "MonException :" << ex.what() <<endl;
        return nullptr;
    }

}

void fermetureDB(sqlite3* db)
{

    try
    {
        int rc;
        rc = sqlite3_close(db);
        if (rc != SQLITE_OK) {
            throw MonException(sqlite3_errmsg(db));

        }
        else
        {
            cout<<"fermeture DB OK."<<endl;
        }
    }

    catch(const MonException& ex)
    {
        cout<<endl<< "MonException :" << ex.what() <<endl;
    }
}

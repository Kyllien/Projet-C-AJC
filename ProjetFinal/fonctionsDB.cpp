#include "fonctionsDB.h"


using namespace std;



// Fonction qui permet la lecture de la bdd et l'afficher en fonction de la requete
void get_table(const char *sql)
{
    sqlite3 *db = ouvertureDB();

    // Récupérer la table
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc)
    {
        cerr << "Erreur lors de la préparation de la requête : " << sqlite3_errmsg(db) << endl;
    }

    // Parcourir les lignes de la table
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);

        // Récupérer les valeurs de chaque colonne de la ligne courante
        const unsigned char *nom = sqlite3_column_text(stmt, 1);
        string s_nom(nom, nom + strlen((const char *)nom));

        const unsigned char *prenom = sqlite3_column_text(stmt, 2);
        string s_prenom(prenom, prenom + strlen((const char *)prenom));

        char *sexe = (char *)sqlite3_column_text(stmt, 3);

        const unsigned char *entreprise = sqlite3_column_text(stmt, 4);

        const unsigned char *libelle = sqlite3_column_text(stmt, 5);
        string s_libelle(libelle, libelle + strlen((const char *)libelle));

        const unsigned char *complement = sqlite3_column_text(stmt, 6);
        string s_complement;
        if (complement != NULL)
        {
            string str_complement(complement, complement + strlen((const char *)complement));
            s_complement = str_complement;
        }
        else
        {
            s_complement = "";
        }

        int codeP = sqlite3_column_int(stmt, 7);

        const unsigned char *ville = sqlite3_column_text(stmt, 8);
        string s_ville(ville, ville + strlen((const char *)ville));

        const unsigned char *mail = sqlite3_column_text(stmt, 9);

        const unsigned char *date = sqlite3_column_text(stmt, 10);

        // Gestion si c'est un compte pro ou prive pour ensuite créer un objet contact

        if (entreprise != NULL)
        {
            string s_mail(mail, mail + strlen((const char *)mail));
            string s_entreprise(entreprise, entreprise + strlen((const char *)entreprise));

            ContactPro* contac = new ContactPro(id,s_nom,s_prenom,sexe[0],s_entreprise,s_libelle,s_complement,codeP,s_ville,
                        s_mail);

            cout << *contac << endl;

        }
        else
        {
            string s_date(date, date + strlen((const char *)date));
            ContactPrive contac1(id,s_nom,s_prenom,sexe[0],s_libelle,s_complement,codeP,s_ville,s_date);
            cout << contac1 << endl;

        }
    }
    sqlite3_finalize(stmt);
}


// Fonction qui permet de supprimer un élement de la bdd

void supprimerElement(int id)
{
    sqlite3 *db = ouvertureDB();
    int rc;
    sqlite3_stmt *stmt;


    // Prépare la requête de suppression
    string sql = "DELETE FROM contacts WHERE IdContact=?";
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    if (rc)
    {
        cerr << "Erreur lors de la préparation de la requête : " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
    }

    // Lie la valeur de l'ID à la requête
    rc = sqlite3_bind_int(stmt, 1, id);
    if (rc)
    {
        cerr << "Erreur lors du liage de la valeur de l'ID : " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
    }

    // Exécute la requête
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        cerr << "Erreur lors de l'exécution de la requête : " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

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
        //cout<<"contact PRO!"<<endl;
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
            //cout<<"contact PRIVE!"<<endl;
            // ajout de date de naissance
            sqlite3_bind_text(stmt,10,cprive->GetdateNaissance(),strlen(cprive->GetdateNaissance()),NULL);
            sqlite3_bind_null(stmt,4);
            sqlite3_bind_null(stmt,9);
        }
    }




    rc = sqlite3_step(stmt);
//    printf("rc:%d",rc);

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

    }

    catch(const MonException& ex)
    {
        cout<<endl<< "MonException :" << ex.what() <<endl;
    }
}

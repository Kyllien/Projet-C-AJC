#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <climits>


#include "Contact.h"
#include "ContactPro.h"
#include "ContactPrive.h"
#include "fonctionsDB.h"
#include "fonctionsInterface.h"
#include "fonctionsCSV.h"

#include <cstdio>
#include <chrono>
#include <thread>

#define CSVPRO "./donnee/newprofs.csv"
#define CSVPRIVE "./donnee/newprivates.csv"



using namespace std;




int main()
{
    // Thread pour surveillance et traitement des fichiers contact CSV:

    // interval pour check des fichiers csv.
    chrono::seconds interval(5);
    chrono::seconds interval2(1);

    // chemins à surveiller
//    filesystem::path filePro(CSVPRO);
//    filesystem::path filePrive(CSVPRIVE);

    // Thread pour vérif et traitement des CSV
    thread fileCheckingThread([&] {
        while (true)
        {



            // si fichier existe : import + suppression
            FILE* filePro = fopen(CSVPRO, "r");
            if (filePro)
            {

                CSVPROtoDB(CSVPRO);
                cout<<"imported 'newprofs.csv'"<<endl;
            }


            // si fichier existe : import + suppression
            FILE* filePrive = fopen(CSVPRIVE, "r");
            if (filePrive)
            {

                CSVPRIVEtoDB(CSVPRIVE);
                cout<<"imported 'newprivates.csv'"<<endl;

            }

            // sleep pendant interval
            this_thread::sleep_for(interval);
        }
    });


    /******************** THREAD PRINCIPAL *******************/

    // Declaration Variables
    bool quit = false;
    bool quit1;
    bool quit2;
    bool quit3;
    bool quitComplement;
    int choice1;
    int choice2;
    int choice3;
    int choicePro;
    int choiceComp;
    string nom;
    string ville;
    string prenom;
    char sexe;
    string entreprise;
    string libelle;
    string complement = "";
    int codeP;
    string mail;
    tm date;
    string str_date;
    stringstream ss;
    bool bool_date;
    bool bool_sexe;
    int idSup;

    // MENU
    while (!quit)
    {
        cout << "\nPour ajouter des contacts a partir de fichiers .csv, les ajouter dans le dossier /donnee" << endl;
        cout << "\n1. Lister les contacts" << endl;
        cout << "2. Rechercher a partir de certains criteres (nom ou ville)" << endl;
        cout << "3. Ajouter un contact" << endl;
        cout << "4. Supprimer un contact" << endl;
        cout << "5. Quitter" << endl;

        int choice;
        cout << "Choisissez une option (1|2|3|4|5) : ";
        fflush(stdin);
        cin >> choice;

        switch (choice)
        {
            // Liste les contacts
            case 1:
                do
                {
                    cout << "\n1. Afficher tous les contacts" << endl;
                    cout << "2. Afficher les contacts pro " << endl;
                    cout << "3. Afficher les contacts prive " << endl;

                    cout << "Choisissez une option (1|2|3) : ";
                    cin >> choice1;
                    quit1 = false;
                    if (choice1 == 1)
                    {
                        const char *sql = "SELECT * FROM contacts";
                        get_table(sql);

                        quit1 = true;
                    }
                    else if (choice1 == 2)
                    {
                        const char *sql = "SELECT * FROM contacts WHERE entreprise not null";
                        get_table(sql);
                        quit1 = true;
                    }
                    else if (choice1 == 3)
                    {
                        const char *sql = "SELECT * FROM contacts WHERE entreprise is null";
                        get_table(sql);
                        quit1 = true;
                    }

                }while(!quit1);

                break;

            // Recherche à partir de critères
            case 2:
                do
                {
                    quit2 = false;
                    cout << "\n1. Rechercher par nom" << endl;
                    cout << "2. Rechercher par ville" << endl;


                    cout << "Choisissez une option (1|2) : ";
                    cin.clear(); // réinitialise les indicateurs d'erreur de cin
                    cin.ignore(INT_MAX, '\n'); // ignore la ligne entrée
                    cin >> choice2;

                    // Recherche par le nom
                    if (choice2 == 1)
                    {
                        cout << "Quel est le nom que vous souhaiter rechercher ?\n" ;
                        cin >> nom;
                        nom = to_upper(nom);
                        const char *msg = "SELECT * FROM contacts WHERE nom='";
                        const char *sql = strdup((msg + nom + "'").c_str());
                        get_table(sql);
                        quit2 = true;
                    }
                    // Recherche par la ville
                    else if (choice2 == 2)
                    {
                        cout << "Quelle est la ville que vous souhaiter rechercher ?\n" ;
                        cin >> ville;
                        ville = to_upper(ville);
                        const char *msg = "SELECT * FROM contacts WHERE ville='";
                        const char *sql = strdup((msg + ville + "'").c_str());
                        get_table(sql);
                        quit2 = true;
                    }
                    // Exceptions
                    else
                    {
                        cout << "L'option choisie n'est pas la bonne" << endl;
                    }

                }while(!quit2);
                break;

            case 3:
                cout << "Entrez un nom : ";
                cin >> nom;
                nom = to_upper(nom);

                cout << "Entrez un prenom : ";
                cin >> prenom;
                prenom = capitalize(prenom);

                // Gestion exceptions pour le sexe
                do
                {
                    cout << "Entrez le sexe (M/F) : ";
                    cin >> sexe;
                    sexe = toupper(sexe);
                    if (sexe == 'M' | sexe == 'F')
                    {
                        bool_sexe = false;
                    }
                    else
                    {
                        cerr << "Erreur dans le format du sexe\n" << endl;
                        bool_sexe = true;
                    }
                }while(bool_sexe);


                cout << "Entrez le libelle de rue : ";
                cin.clear(); // réinitialise les indicateurs d'erreur de cin
                cin.ignore(INT_MAX, '\n'); // ignore la ligne entrée
                getline(cin,libelle);

                // Gestion exception Complement d'adresse
                do
                {
                    quitComplement = true;
                    cout << "Il y a t il un complement d adresse (1 = Oui / 2 = Non) ? ";
                    cin >> choiceComp;
                    if (choiceComp == 1)
                    {
                        quitComplement = false;
                        cout << "Entrez un complement d adresse : ";
                        cin.clear(); // réinitialise les indicateurs d'erreur de cin
                        cin.ignore(INT_MAX, '\n'); // ignore la ligne entrée
                        getline(cin,complement);
                    }
                    else if (choiceComp == 2)
                    {
                        quitComplement = false;
                    }
                }while(quitComplement);



                // A FAIRE : gestion du bon format pour code postal
                cout << "Entrez un code postal : ";
                cin >> codeP;

                cout << "Entrez une ville : ";
                cin.clear(); // réinitialise les indicateurs d'erreur de cin
                cin.ignore(INT_MAX, '\n'); // ignore la ligne entrée
                getline(cin,ville);
                ville = to_upper(ville);

                // COmpte pro ou privé
                do
                {
                    quit3 = true;
                    cout << "Compte pro ou prive (1/2) ?  ";
                    cin >> choicePro;
                    if (choicePro == 1)
                    {
                        quit3 = false;
                        cout << "Entrez un mail : ";
                        cin >> mail;

                        cout << "Entrez une entreprise : ";
                        cin.clear(); // réinitialise les indicateurs d'erreur de cin
                        cin.ignore(INT_MAX, '\n'); // ignore la ligne entrée
                        getline(cin,entreprise);
                        entreprise = to_upper(entreprise);

                        // création instances de contacts:
                        ContactPro* pro1 = new ContactPro(1,nom,prenom,sexe,entreprise,libelle,complement,codeP,ville,
                        mail);

                        addContact(pro1);
                        delete pro1;

                    }
                    else if (choicePro == 2)
                    {
                        quit3 = false;
                        // Gestion de la date au bon format
                        do
                        {
                            bool_date = true;
                            cout << "Entrez une date de naissance au format dd/mm/yyyy : ";
                            cin >> get_time(&date, "%d/%m/%Y"); // utilisation de get_time pour lire la date au format spécifié
                            if (cin.fail())
                            {
                                cerr << "Erreur dans le format de la date\n" << endl;
                                cin.clear(); // réinitialise les indicateurs d'erreur de cin
                                cin.ignore(INT_MAX, '\n'); // ignore la ligne entrée
                                bool_date = false;
                            }
                        }while(!bool_date);
                        ss << put_time(&date, "%d/%m/%Y");
                        str_date = ss.str();

                        ContactPrive prive1(2,nom,prenom,sexe,libelle,complement,codeP,ville,str_date);

                        addContact(&prive1);

                    }
                }while(quit3);

                break;

            // Suppression d'un contact via son id
            case 4:
                cout << "Quel est l'identifiant du contact que vous voulez supprimer : ";
                cin >> idSup;
                supprimerElement(idSup);
                cout << "Suppression effectué\n" << endl;
                break;

            case 5:
                cout << "Vous quittez l'interface" << endl;
                quit = true;
                break;

            default:
                cout << "Vous avez mal entre l'option choisie" << endl;
                break;
        }
    }


    fileCheckingThread.detach();
    return 0;
}

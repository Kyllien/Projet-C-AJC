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

//fichiers CSV à déposer dans 1 sous-dossier csv
#define CSVPRO "csv/newprofs.csv"
#define CSVPRIVE "csv/newprivates.csv"



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
    bool quit2 = false;
    bool quit3;
    bool quitComplement;
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
        std::cout << "\n1. Lister les contacts" << std::endl;
        std::cout << "2. Rechercher a partir de certains criteres (nom ou ville)" << std::endl;
        std::cout << "3. Ajouter un contact" << std::endl;
        std::cout << "4. Supprimer un contact" << std::endl;
        std::cout << "5. Quitter" << std::endl;

        int choice;
        std::cout << "Choisissez une option (1|2|3|4|5) : ";
        fflush(stdin);
        std::cin >> choice;

        switch (choice)
        {
            // Liste les contacts
            case 1:
                get_table();
                break;

            // Recherche à partir de critères
            case 2:
                while (!quit2)
                {
                    std::cout << "\n1. Rechercher par nom" << std::endl;
                    std::cout << "2. Rechercher par ville" << std::endl;


                    std::cout << "Choisissez une option (1|2) : ";
                    std::cin >> choice2;

                    // Recherche par le nom
                    if (choice2 == 1)
                    {
                        std::cout << "Quel est le nom que vous souhaiter rechercher ?\n" ;
                        std::cin >> nom;
                        nom = to_upper(nom);
                        quit2 = true;
                    }
                    // Recherche par la ville
                    else if (choice2 == 2)
                    {
                        std::cout << "Quelle est la ville que vous souhaiter rechercher ?\n" ;
                        std::cin >> ville;
                        ville = to_upper(ville);
                        quit2 = true;
                    }
                    // Exceptions
                    else
                    {
                        std::cout << "L'option choisie n'est pas la bonne" << std::endl;
                    }

                }
                break;

            case 3:
                std::cout << "Entrez un nom : ";
                std::cin >> nom;
                nom = to_upper(nom);

                std::cout << "Entrez un prenom : ";
                std::cin >> prenom;
                prenom = capitalize(prenom);

                // Gestion exceptions pour le sexe
                do
                {
                    std::cout << "Entrez le sexe (M/F) : ";
                    std::cin >> sexe;
                    sexe = toupper(sexe);
                    if (sexe == 'M' | sexe == 'F')
                    {
                        bool_sexe = false;
                    }
                    else
                    {
                        std::cerr << "Erreur dans le format du sexe\n" << std::endl;
                        bool_sexe = true;
                    }
                }while(bool_sexe);


                std::cout << "Entrez le libelle de rue : ";
                std::cin.clear(); // réinitialise les indicateurs d'erreur de cin
                std::cin.ignore(INT_MAX, '\n'); // ignore la ligne entrée
                std::getline(cin,libelle);


                // Gestion exception Complement d'adresse
                do
                {
                    quitComplement = true;
                    std::cout << "Il y a t il un complement d adresse (1 = Oui / 2 = Non) ? ";
                    std::cin >> choiceComp;
                    if (choiceComp == 1)
                    {
                        quitComplement = false;
                        std::cout << "Entrez un complement d adresse : ";
                        std::cin >> complement;
                    }
                    else if (choiceComp == 2)
                    {
                        quitComplement = false;
                    }
                }while(quitComplement);



                // A FAIRE : gestion du bon format pour code postal
                std::cout << "Entrez un code postal : ";
                std::cin >> codeP;

                std::cout << "Entrez une ville : ";
                std::cin >> ville;
                ville = to_upper(ville);

                // COmpte pro ou privé
                do
                {
                    quit3 = true;
                    std::cout << "Compte pro ou prive (1/2) ?  ";
                    std::cin >> choicePro;
                    if (choicePro == 1)
                    {
                        quit3 = false;
                        std::cout << "Entrez un mail : ";
                        std::cin >> mail;

                        std::cout << "Entrez une entreprise : ";
                        std::cin >> entreprise;
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
                            std::cout << "Entrez une date de naissance au format dd/mm/yyyy : ";
                            std::cin >> std::get_time(&date, "%d/%m/%Y"); // utilisation de get_time pour lire la date au format spécifié
                            if (std::cin.fail())
                            {
                                std::cerr << "Erreur dans le format de la date\n" << std::endl;
                                std::cin.clear(); // réinitialise les indicateurs d'erreur de cin
                                std::cin.ignore(INT_MAX, '\n'); // ignore la ligne entrée
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
                std::cout << "Vous quittez l'interface" << std::endl;
                quit = true;
                break;

            default:
                std::cout << "Vous avez mal entre l'option choisie" << std::endl;
                break;
        }
    }


    fileCheckingThread.detach();
    return 0;
}

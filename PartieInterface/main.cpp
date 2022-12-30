#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <climits>
#include <sqlite3.h>

using namespace std;

// Fonction qui permet de supprimer un élement de la bdd
int supprimerElement(const std::string &nomBaseDeDonnees, int id) {
    sqlite3 *db;
    int rc;
    sqlite3_stmt *stmt;

    // Ouvre la base de données
    rc = sqlite3_open(nomBaseDeDonnees.c_str(), &db);
    if (rc)
    {
        std::cerr << "Erreur lors de l'ouverture de la base de données : " << sqlite3_errmsg(db) << std::endl;
    }

    // Prépare la requête de suppression
    std::string sql = "DELETE FROM contacts WHERE id=?";
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    if (rc)
    {
        std::cerr << "Erreur lors de la préparation de la requête : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
    }

    // Lie la valeur de l'ID à la requête
    rc = sqlite3_bind_int(stmt, 1, id);
    if (rc)
    {
        std::cerr << "Erreur lors du liage de la valeur de l'ID : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
    }

    // Exécute la requête
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        std::cerr << "Erreur lors de l'exécution de la requête : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
    }

    // Finalisez et fermez la requête et la connexion à la base de données
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

// Fonction qui permet de passer en majuscule le premier caractère d'un string
std::string capitalize(const std::string& str) {
    std::string result;
    result.reserve(str.size()); // réserve de l'espace pour éviter les réallocations

    if (!str.empty()) {
        result += toupper(str[0]);
    }
    result += str.substr(1);

    return result;
}


// Fonction qui permet la mise en majuscule de l'ensemble d'un string
std::string to_upper(const std::string& str) {
    std::string result;
    result.reserve(str.size()); // réserve de l'espace pour éviter les réallocations

    for (char c : str) {
        result += toupper(c);
    }

    return result;
}

int main()
{
    // Declaration Variables
    bool quit = false;
    bool quit2 = false;
    bool quit3 = false;
    int choice2;
    string nom;
    string ville;
    string prenom;
    char sexe;
    string entreprise;
    string libelle;
    string complement;
    string codeP;
    string mail;
    tm date;
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

                std::cout << "Entrez une entreprise (inserer NULL si pas d entreprise) : ";
                std::cin >> entreprise;

                std::cout << "Entrez le libelle de rue : ";
                std::cin >> libelle;

                std::cout << "Entrez un complement d adresse (inserer NULL si pas de complement) : ";
                std::cin >> complement;

                // A FAIRE : gestion du bon format pour code postal
                std::cout << "Entrez un code postal : ";
                std::cin >> codeP;

                std::cout << "Entrez une ville : ";
                std::cin >> ville;
                ville = to_upper(ville);

                std::cout << "Entrez un mail (inserer NULL si pas de mail) : ";
                std::cin >> mail;


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



                break;

            // Suppression d'un contact via son id
            case 4:
                std::cout << "Quel est l'identifiant du contact que vous voulez supprimer : ";
                std::cin >> idSup;


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
    return 0;
}

#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <climits>

using namespace std;

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

                std::cout << "Entrez une entreprise : ";
                std::getline(std::cin, entreprise);





                // Gestion de la date au bon format
                do
                {
                    std::cout << "Entrez une date au format dd/mm/yyyy : ";
                    std::cin >> std::get_time(&date, "%d/%m/%Y"); // utilisation de get_time pour lire la date au format spécifié
                    if (std::cin.fail())
                    {
                        std::cerr << "Erreur dans le format de la date\n" << std::endl;
                        std::cin.clear(); // réinitialise les indicateurs d'erreur de cin
                        std::cin.ignore(INT_MAX, '\n'); // ignore la ligne entrée
                        bool_date = true;
                    }
                    else
                    {
                        bool_date = false;
                    }
                }while(bool_date);

                //std::cout << "Date saisie : " << std::put_time(&date, "%d/%m/%Y") << std::endl;



                break;
            case 4:

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

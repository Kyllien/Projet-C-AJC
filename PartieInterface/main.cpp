#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Declaration Variables
    bool quit = false;
    bool quit2 = false;
    int choice2;
    string nom;
    string ville;

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
                        std::cout << "Quel est le nom que vous souhaiter rechercher ?" ;
                        std::cin >> nom;

                        quit2 = true;
                    }
                    // Recherche par la ville
                    else if (choice2 == 2)
                    {
                        std::cout << "Vous avez  entré l'option choisie" << std::endl;
                        quit2 = true;
                    }
                    // Exceptions
                    else
                    {
                        std::cout << "Vous avez mal entre l'option choisie" << std::endl;
                    }

                }


                break;
            case 3:

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

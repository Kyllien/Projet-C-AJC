#include <iostream>

using namespace std;

int main()
{
    bool quit = false;
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
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                std::cout << "Vous quittez l'interface" << std::endl;
                quit=true;
                break;
            default:
                std::cout << "Vous avez mal entré l'option choisie" << std::endl;
                break;
        }
    }
    return 0;
}

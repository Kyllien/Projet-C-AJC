#include "fonctionsInterface.h"

#include <string>



// Fonction qui permet de passer en majuscule le premier caract�re d'un string
string capitalize(const string& str) {
    string result;
    result.reserve(str.size()); // r�serve de l'espace pour �viter les r�allocations

    if (!str.empty()) {
        result += toupper(str[0]);
    }
    result += str.substr(1);

    return result;
}


// Fonction qui permet la mise en majuscule de l'ensemble d'un string
string to_upper(const string& str) {
    string result;
    result.reserve(str.size()); // r�serve de l'espace pour �viter les r�allocations

    for (char c : str) {
        result += toupper(c);
    }

    return result;
}

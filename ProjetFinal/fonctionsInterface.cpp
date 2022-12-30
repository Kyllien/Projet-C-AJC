#include "fonctionsInterface.h"

#include <string>



// Fonction qui permet de passer en majuscule le premier caractère d'un string
string capitalize(const string& str) {
    string result;
    result.reserve(str.size()); // réserve de l'espace pour éviter les réallocations

    if (!str.empty()) {
        result += toupper(str[0]);
    }
    result += str.substr(1);

    return result;
}


// Fonction qui permet la mise en majuscule de l'ensemble d'un string
string to_upper(const string& str) {
    string result;
    result.reserve(str.size()); // réserve de l'espace pour éviter les réallocations

    for (char c : str) {
        result += toupper(c);
    }

    return result;
}

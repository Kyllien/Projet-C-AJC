#ifndef FONCTIONSDB_H_INCLUDED
#define FONCTIONSDB_H_INCLUDED

#include "sql/sqlite3.h"
#include "Contact.h"
#include "ContactPrive.h"
#include "ContactPro.h"
#include "MonException.h"
#include <cstring>


#define DB "donnee/dbContacts.db"

void get_recherche(string, string);
void get_table();
void supprimerElement(int);
void addContact(Contact*);
sqlite3* ouvertureDB();
void fermetureDB(sqlite3*);

#endif // FONCTIONSDB_H_INCLUDED

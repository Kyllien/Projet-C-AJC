#ifndef FONCTIONSDB_H_INCLUDED
#define FONCTIONSDB_H_INCLUDED

#ifdef SQLITE3_H
#include "sqlite3.h"
#else
#include "sql/sqlite3.h"
#endif


#include "Contact.h"
#include "ContactPrive.h"
#include "ContactPro.h"
#include "MonException.h"
#include <cstring>


#define DB "donnee/dbContacts.db"

void get_recherche(string, string);
void get_table(const char *);
void supprimerElement(int);
void addContact(Contact*);
sqlite3* ouvertureDB();
void fermetureDB(sqlite3*);

#endif // FONCTIONSDB_H_INCLUDED

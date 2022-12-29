#ifndef FONCTIONSDB_H_INCLUDED
#define FONCTIONSDB_H_INCLUDED

#include "sqlite3.h"
#include "Contact.h"
#include "ContactPrive.h"
#include "ContactPro.h"
#include "MonException.h"
#include <cstring>


#define DB "dbContacts.db"

void addContact(Contact*);
sqlite3* ouvertureDB();
void fermetureDB(sqlite3*);

#endif // FONCTIONSDB_H_INCLUDED

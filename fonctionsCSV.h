#ifndef FONCTIONSCSV_H_INCLUDED
#define FONCTIONSCSV_H_INCLUDED


#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "Contact.h"
#include "ContactPrive.h"
#include "ContactPro.h"
#include "fonctionsDB.h"


using namespace std;

int CSVPROtoDB(string);
int CSVPRIVEtoDB(string);

#endif // FONCTIONSCSV_H_INCLUDED

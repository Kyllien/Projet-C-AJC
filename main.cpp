#include "Contact.h"
#include "ContactPro.h"
#include "ContactPrive.h"


#include "fonctionsDB.h"
#include "fonctionsCSV.h"

#include <cstdio>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <thread>

#define CSVPRO "./csv/newprofs.csv"
#define CSVPRIVE "./csv/newprivates.csv"

bool terminateProgram = false;

int main()
{




    // interval pour check des fichiers csv.
    chrono::seconds interval(5);
    chrono::seconds interval2(1);

    // chemins à surveiller
    filesystem::path filePro(CSVPRO);
    filesystem::path filePrive(CSVPRIVE);

    // Thread pour vérif et traitement des CSV
    thread fileCheckingThread([&] {
        while (true)
        {



            // si fichier existe : import + suppression
            if (filesystem::exists(filePro))
            {

                CSVPROtoDB(filePro);
                cout<<"imported 'newprofs.csv'"<<endl;
                int result = remove(CSVPRO);
                if (result != 0) {
                    cout<<"an error occured during file deletion"<<endl;
                    return 1;
                }
            }


            // si fichier existe : import + suppression
            if (filesystem::exists(filePrive))
            {

                CSVPRIVEtoDB(filePrive);
                cout<<"imported 'newprivates.csv'"<<endl;
                int result = remove(CSVPRIVE);
                if (result != 0) {
                    cout<<"an error occured during file deletion"<<endl;
                    return 1;
                }
            }

            // sortir si l'utilisateur a demandé à quitter le programme.
            if (terminateProgram)
            {
                break;
            }

            // sleep pendant interval
            this_thread::sleep_for(interval);
        }
    });

    // Thread pour l'interface utilisateur
    thread userInterfaceThread([&] {
        cout<<"doing something"<<endl
        ;
        int i=0;
        while(1)
        {
            i++;
            cout<<"."<<endl;
            this_thread::sleep_for(interval2);
            if (i==4)
            {
                terminateProgram=true;
                break;
            }
        }
    });




    // Wait for the file checking thread to finish
    fileCheckingThread.join();
    userInterfaceThread.join();
    return 0;






    /*
    // création instances de contacts:
    ContactPro* pro1 = new ContactPro(1,"Wallace","Marcel",'M',"Renault","rue du quai","",78888,"Guyancourt",
                    "marcel.wallace@renault.com");

    cout<<*pro1<<endl;

    ContactPrive prive1(2,"willis","bruce",'M',"hollywood Bvrd","",55544,"Los Angeles"
                    ,"1959-10-17");


    cout<<prive1<<endl;
    */

    // Ajouter les contacts à la BDD:
//    addContact(pro1);
//    addContact(&prive1);



        //CSVPROtoDB("./csv/newprofs.csv");
        //CSVPRIVEtoDB("./csv/newprivates.csv");

//    delete pro1;

}



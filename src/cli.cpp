/****************************************************************************************
// CLI (Source File)
//
// Created:     10 July 2023
// Atualização: 10 July 2023
// Compiler:    gcc/g++
//
// Description: The CLI class provides an interface to manage you Contact information.
//
****************************************************************************************/

#include <iostream>
#include <limits>

#include "cli.h"

// ---------------------------------------------------------------------------------

void CLI::callCLI()
{
    while (1)
    {
        std::cout << "1) Display all contacts\n";
        std::cout << "2) Add new contact\n";
        std::cout << "3) Search telephone No.\n";
        std::cout << "4) Search person name\n";
        std::cout << "5) Update telephone No.\n";
        std::cout << "6) Delete a contact\n";
        std::cout << "7) Exit\n";
        std::cout << "Choose your choice: ";
        int choice;
        if (!(std::cin >> choice))
        {
            std::cout << "\nWARNING: Invalid input. Please enter a valid integer (1 to 7).\n\n";
            std::cin.clear(); // Clear the error state
            // Discard the remaining invalid input line
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // Restart the loop
        }
        switch (choice)
        {
        case 1:
            // this->display();
            break;
        case 2:
            // this->add_new_record();
            break;
        case 3:
            // this->searchByPhone();
            break;
        case 4:
            // this->searchByName();
            break;
        case 5:
            // this->modify();
            break;
        case 6:
            // rec.deleterec();
            break;
        case 7:
            std::cout << "Goodbye, see you later!\n\n";
            exit(1);
        default:
            std::cout << "\nWARNING: You enter an invalid option... Please, send 1 to 7!\n"
                      << "\n";
        }
    }
}

// ---------------------------------------------------------------------------------

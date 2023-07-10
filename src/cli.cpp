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
#include "contact.h"

Contact contact_manager; // Global object.

// ---------------------------------------------------------------------------------

void CLI::show_cli()
{
    while (1)
    {
        std::cout << "1) Display all contacts\n";
        std::cout << "2) Add new contact\n";
        std::cout << "3) Search telephone No.\n";
        std::cout << "4) Search person name\n";
        std::cout << "5) Update contact name or telephone No.\n";
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
            contact_manager.display_contacts();
            break;
        case 2:
            contact_manager.add_contact();
            break;
        case 3:
            contact_manager.search_by_phone();
            break;
        case 4:
            contact_manager.search_by_name();
            break;
        case 5:
            this->update_contact_menu();
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

bool CLI::update_contact_menu()
{
    while (1)
    {
        std::cout << "If you wish to modify your name enter one (1) ";
        std::cout << "\nIf you wish to modify your phone number enter two (2) ";
        std::cout << "\nIf you wish to back to the menu enter three (3) ";
        std::cout << "\nEnter your option: ";
        int choice;
        if (!(std::cin >> choice))
        {
            std::cout << "\nWARNING: Invalid input. Please enter a valid integer (1 to 3).\n\n";
            std::cin.clear(); // Clear the error state
            // Discard the remaining invalid input line
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // Restart the loop
        }
        switch (choice)
        {
        case 1:
            contact_manager.update_name();
            break;
        case 2:
            break;
        case 3:
            this->show_cli();
            break;
        default:
            std::cout << "\nWARNING: You enter an invalid option... Please, send 1 to 3!\n"
                      << "\n";
        }
    }
}

// ---------------------------------------------------------------------------------

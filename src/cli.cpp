/****************************************************************************************
// CLI (Source File)
//
// Created:     10 July 2023
// Atualização: 11 July 2023
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
        std::cout << "\n********************************** ( Contact Management System (C++) ) **********************************\n";
        std::cout << "*\t\t\t\t\t\t\t\t\t\t\t\t\t*\n";
        std::cout << "*" << "\t\t1.Display all contacts";
        std::cout << "\t\t\t2.Add new contact\t\t\t\t*\n*\t\t\t\t\t\t\t\t\t\t\t\t\t*\n";
        std::cout << "*" << "\t\t3.Search telephone No.";
        std::cout << "\t\t\t4.Search person name\t\t\t\t*\n*\t\t\t\t\t\t\t\t\t\t\t\t\t*\n";
        std::cout << "*" << "\t\t5.Update contact";
        std::cout << "\t\t\t6.Delete contact\t\t\t\t*\n*\t\t\t\t\t\t\t\t\t\t\t\t\t*\n";
        std::cout << "*" << "\t\t\t\t\t     7.Exit\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t\t\t\t\t\t*\n";
        std::cout << "*********************************************************************************************************\n\n";
        std::cout << "Please, enter an option (1 to 7): ";
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
            this->delete_contact_menu();
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

void CLI::update_contact_menu()
{
    while (1)
    {
        std::cout << "If you wish to modify your contact name enter one (1) ";
        std::cout << "\nIf you wish to modify your phone number enter two (2) ";
        std::cout << "\nIf you wish to back to the main menu enter three (3) ";
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
            contact_manager.update_phone_number_by_name();
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

void CLI::delete_contact_menu()
{
    while (1)
    {
        std::cout << "If you wish to delete a contact by name enter one (1) ";
        std::cout << "\nIf you wish to delete a contact by phone number enter two (2) ";
        std::cout << "\nIf you wish to back to the main menu enter three (3) ";
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
            contact_manager.delete_contact_by_name();
            break;
        case 2:
            contact_manager.delete_contact_by_phone();
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

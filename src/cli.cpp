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

// Bold (negrito).
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"

// Underlined.
#define RED_UNDERLINED "\033[4;31m"
#define GREEN_UNDERLINED "\033[4;32m"
#define YELLOW_UNDERLINED "\033[4;33m"
#define BLUE_UNDERLINED "\033[4;34m"

#define RESET "\033[0m" // Used to reset to normal.

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
        std::cout << CYAN "\n********************************** ( Contact Management System (C++) ) **********************************\n";
        std::cout << "*\t\t\t\t\t\t\t\t\t\t\t\t\t*\n";
        std::cout << "*" << GREEN_UNDERLINED "\t\t1. Display all contacts";
        std::cout << "\t\t\t2. Add new contact" << RESET << CYAN "\t\t\t\t*\n";
        std::cout << "*\t\t\t\t\t\t\t\t\t\t\t\t\t*\n";
        std::cout << "*" << YELLOW_UNDERLINED << "\t\t3. Search telephone No.";
        std::cout << "\t\t\t4. Search person name" << RESET << CYAN << "\t\t\t\t*\n";
        std::cout << "*\t\t\t\t\t\t\t\t\t\t\t\t\t*\n";
        std::cout << "*" << BLUE_UNDERLINED << "\t\t5. Update contact";
        std::cout << "\t\t\t6. Delete contact" << RESET << CYAN "\t\t\t\t*\n";
        std::cout << "*\t\t\t\t\t\t\t\t\t\t\t\t\t*\n";
        std::cout << "*\t\t\t\t\t     " << RED_UNDERLINED << "7. Exit" << RESET << CYAN "\t\t\t\t\t\t\t*\n";
        std::cout << "*\t\t\t\t\t\t\t\t\t\t\t\t\t*\n";
        std::cout << "*********************************************************************************************************\n\n"
                  << RESET;
        std::cout << "Please, enter an option (1 to 7): ";
        int choice;
        if (!(std::cin >> choice))
        {
            std::cout << RED "\nWARNING: Invalid input. Please enter a valid integer (1 to 7).\n\n"
                      << RESET;
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
            std::cout << MAGENTA "Goodbye, see you later!\n\n"
                      << RESET;
            exit(1);
        default:
            std::cout << RED "\nWARNING: You enter an invalid option... Please, send 1 to 7!\n\n"
                      << RESET;
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
            std::cout << RED "\nWARNING: Invalid input. Please enter a valid integer (1 to 7).\n\n"
                      << RESET;
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
            std::cout << RED "\nWARNING: You enter an invalid option... Please, send 1 to 7!\n\n"
                      << RESET;
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
            std::cout << RED "\nWARNING: Invalid input. Please enter a valid integer (1 to 7).\n\n"
                      << RESET;
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
            std::cout << RED "\nWARNING: You enter an invalid option... Please, send 1 to 7!\n\n"
                      << RESET;
        }
    }
}

// ---------------------------------------------------------------------------------

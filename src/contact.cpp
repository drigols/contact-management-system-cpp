/**********************************************************************************
// CLI (Source File)
//
// Created:     10 July 2023
// Atualização: 10 July 2023
// Compiler:    gcc/g++
//
// Description: The Contact class provides methods to manage your contacts.
//
**********************************************************************************/

#include <iostream>
#include <fstream>

#include "contact.h"

// Global variable.
std::string file_name = "../data/contacts.txt";

// ---------------------------------------------------------------------------------

void Contact::display_contacts()
{
    std::ifstream file(file_name); // ifstream object.
    std::string current_line;      // Store the current file line.

    if (file.is_open())
    {
        std::cout << "\nContact list:\n";

        while (std::getline(file, current_line))
        {
            std::string current_name;                       // Store the name of the current line.
            std::string current_phone_number;               // Store the phone of the current line.
            std::size_t comma_pos = current_line.find(','); // Get comma (vírgula posittion).

            // Check if the comma (vírgula) was find() in the current line.
            if (comma_pos != std::string::npos)
            {
                current_name = current_line.substr(0, comma_pos);
                current_phone_number = current_line.substr(comma_pos + 1);
                std::cout << "Username: " << current_name << ", Phone numer: " << current_phone_number << "\n";
            }
        }
        file.close();
        std::cout << "\n";
    }
    else
    {
        std::cout << "Error opening the file: " << file_name << "\n\n";
    }
}

// ---------------------------------------------------------------------------------

void Contact::add_contact()
{
    std::string userName, phoneNumber;

    std::cout << "Enter your username: ";
    std::getline(std::cin >> std::ws, userName);

    std::cout << "Enter your Phone number: ";
    std::getline(std::cin >> std::ws, phoneNumber);

    // ofstream object.
    std::ofstream outputFile(file_name, std::ios::app);

    if (outputFile.is_open())
    {
        outputFile << userName << "," << phoneNumber << "\n";
        outputFile.close();
        std::cout << "Contact added successfully!"
                  << "\n\n";
    }
    else
    {
        std::cout << "Failed to open the file."
                  << "\n\n";
    }
}

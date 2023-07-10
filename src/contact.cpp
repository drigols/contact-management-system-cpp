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

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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

// ---------------------------------------------------------------------------------

bool Contact::search_by_phone()
{
    std::ifstream file(file_name);

    if (!file)
    {
        std::cout << "Error opening the file."
                  << "\n";
        return false;
    }

    std::string searched_number;
    std::cout << "Enter the phone number to search: ";
    std::cin.ignore(); // Clear input buffer
    std::getline(std::cin, searched_number);
    std::string temp_searched_number = searched_number;

    // Remove special characters and white spaces.
    temp_searched_number.erase(
        std::remove_if(
            temp_searched_number.begin(),
            temp_searched_number.end(),
            [](unsigned char c)
            { return !std::isalnum(c) || c == ' '; }),
        temp_searched_number.end());

    std::string line;                        // To store the current line from the file (records.txt).
    std::vector<std::string> matching_lines; // Vector to store matching lines.

    // Reads the current line from the file (records.txt) using getline() function.
    while (std::getline(file, line))
    {
        std::stringstream current_line(line); // Get the current line.
        std::string current_name;             // Store the name of the current line.
        std::string current_phone_number;     // Store the phone of the current line.

        /**
         * - Extract the name from the current line (ss).
         * - Save in the "name" variable.
         * - Uses delimiter ",". That's, stop when find ",".
         */
        std::getline(current_line, current_name, ',');

        /**
         * Saves the rest (resto) of the text (phone number) in the variable "phone_number".
         * That's, all after ",".
         */
        std::getline(current_line, current_phone_number);

        // Remove special characters and white spaces.
        current_phone_number.erase(
            std::remove_if(
                current_phone_number.begin(),
                current_phone_number.end(),
                [](unsigned char c)
                { return !std::isalnum(c) || c == ' '; }),
            current_phone_number.end());

        // Transform (converts) the passed number and the current phone number to lowercase.
        std::transform(temp_searched_number.begin(), temp_searched_number.end(), temp_searched_number.begin(), ::tolower);
        std::transform(current_phone_number.begin(), current_phone_number.end(), current_phone_number.begin(), ::tolower);

        // Check if the searched number is equal to the current phone number.
        if (temp_searched_number == current_phone_number)
        {
            // If it matches, add the current line to the Vector.
            matching_lines.push_back(line);
        }
    }

    file.close();

    if (matching_lines.empty())
    {
        std::cout << "\nNo contacts found for the provided phone number: '" << searched_number << "'\n\n";
        return true;
    }

    std::cout << "\nContacts found for the phone number '" << searched_number << "':"
              << "\n";

    for (const std::string &match : matching_lines)
    {
        std::cout << match << "\n";
    }

    std::cout << "\n";
    return true;
}

// ---------------------------------------------------------------------------------

bool Contact::search_by_name()
{
    std::ifstream file(file_name);

    if (!file)
    {
        std::cout << "Error opening the file."
                  << "\n";
        return false;
    }

    std::string searched_name;
    std::cout << "Enter the name to search: ";
    std::cin.ignore(); // Clear input buffer
    std::getline(std::cin, searched_name);
    std::string temp_searched_name = searched_name;

    // Remove special characters and white spaces.
    temp_searched_name.erase(
        std::remove_if(
            temp_searched_name.begin(),
            temp_searched_name.end(),
            [](unsigned char c)
            { return !std::isalnum(c) || c == ' '; }),
        temp_searched_name.end());
    // Transform (converts) the passed name to lowercase.
    std::transform(temp_searched_name.begin(), temp_searched_name.end(), temp_searched_name.begin(), ::tolower);

    std::string current_line;                // To store the current line from the file (records.txt).
    std::vector<std::string> matching_lines; // Vector to store matching lines.

    // Reads the current line from the file (records.txt) using getline() function.
    while (std::getline(file, current_line))
    {
        std::string current_name;                       // Store the name of the current line.
        std::string current_phone_number;               // Store the phone of the current line.
        std::size_t comma_pos = current_line.find(','); // Get comma (vírgula posittion).

        // Check if the comma (vírgula) was find() in the current line.
        if (comma_pos != std::string::npos)
        {
            /**
             * [Extract the current name from the line]
             * Creates a substring from position zero to comma (vírgula) position.
             */
            current_name = current_line.substr(0, comma_pos);

            /**
             * [Extract the current phone number to the line]
             * Creates a substring from comma (vírgula) until the end of the line.
             */
            current_phone_number = current_line.substr(comma_pos + 1);

            // Remove special characters and white spaces.
            current_name.erase(
                std::remove_if(
                    current_name.begin(),
                    current_name.end(),
                    [](unsigned char c)
                    { return !std::isalnum(c) || c == ' '; }),
                current_name.end());
            // Transform (converts) the passed number and the current phone number to lowercase.
            std::transform(current_name.begin(), current_name.end(), current_name.begin(), ::tolower);

            if (current_name.find(temp_searched_name) != std::string::npos)
            {
                matching_lines.push_back(current_line);
            }
        }
    }

    file.close();

    if (matching_lines.empty())
    {
        std::cout << "\nNo contacts found for the provided name: '" << searched_name << "'\n\n";
        return true;
    }

    std::cout << "\nContacts found for the name '" << searched_name << "':"
              << "\n";

    for (const std::string &match : matching_lines)
    {
        std::cout << match << "\n";
    }

    std::cout << "\n";
    return true;
}

// ---------------------------------------------------------------------------------

bool Contact::update_name()
{
    std::fstream file(file_name);

    if (!file)
    {
        std::cout << "Error opening the file."
                  << "\n";
        return false;
    }

    std::string searched_name;
    std::cout << "Enter the complete name to search and modify: ";
    std::cin.ignore(); // Clear input buffer
    std::getline(std::cin, searched_name);
    std::string temp_searched_name = searched_name;

    // Remove special characters and white spaces.
    temp_searched_name.erase(
        std::remove_if(
            temp_searched_name.begin(),
            temp_searched_name.end(),
            [](unsigned char c)
            { return !std::isalnum(c) || c == ' '; }),
        temp_searched_name.end());
    // Transform (converts) the passed name to lowercase.
    std::transform(temp_searched_name.begin(), temp_searched_name.end(), temp_searched_name.begin(), ::tolower);

    std::vector<std::string> lines;
    std::string current_line;
    bool found = false;

    while (std::getline(file, current_line))
    {
        std::string current_name;                       // Store the name of the current line.
        std::string current_phone_number;               // Store the phone of the current line.
        std::size_t comma_pos = current_line.find(','); // Get comma (vírgula posittion).

        // Check if the comma (vírgula) was find() in the current line.
        if (comma_pos != std::string::npos)
        {
            /**
             * [Extract the current name from the line]
             * Creates a substring from position zero to comma (vírgula) position.
             */
            current_name = current_line.substr(0, comma_pos);

            /**
             * [Extract the current phone number to the line]
             * Creates a substring from comma (vírgula) until the end of the line.
             */
            current_phone_number = current_line.substr(comma_pos + 1);

            // Remove special characters and white spaces.
            current_name.erase(
                std::remove_if(
                    current_name.begin(),
                    current_name.end(),
                    [](unsigned char c)
                    { return !std::isalnum(c) || c == ' '; }),
                current_name.end());
            // Transform (converts) the passed number and the current phone number to lowercase.
            std::transform(current_name.begin(), current_name.end(), current_name.begin(), ::tolower);

            if (current_name == temp_searched_name)
            {
                found = true;
                std::string new_name;
                std::cout << "Enter the new name: ";
                std::getline(std::cin, new_name);
                current_line = new_name + "," + current_phone_number; // Change the name.
            }
        }
        lines.push_back(current_line);
    }

    file.close();

    if (!found)
    {
        std::cout << "No contact found for the provided name: '" << searched_name << "'\n\n";
        return true;
    }

    // Reopen the file in write mode and update the contents.
    std::ofstream outfile(file_name);

    // Check if the file open.
    if (!outfile)
    {
        std::cout << "Error opening the file for writing."
                  << "\n";
        return false;
    }

    for (const std::string &updated_line : lines)
    {
        outfile << updated_line << "\n";
    }

    outfile.close();
    std::cout << "Name updated successfully."
              << "\n\n";

    return true;
}

// ---------------------------------------------------------------------------------

bool Contact::update_phone_number_by_name()
{
    std::fstream file(file_name);

    if (!file)
    {
        std::cout << "Error opening the file."
                  << "\n";
        return false;
    }

    std::string searched_name;
    std::cout << "Enter the complete name to search and modify the phone number: ";
    std::cin.ignore(); // Clear input buffer
    std::getline(std::cin, searched_name);
    std::string temp_searched_name = searched_name;

    // Remove special characters and white spaces.
    temp_searched_name.erase(
        std::remove_if(
            temp_searched_name.begin(),
            temp_searched_name.end(),
            [](unsigned char c)
            { return !std::isalnum(c) || c == ' '; }),
        temp_searched_name.end());
    // Transform (converts) the passed name to lowercase.
    std::transform(temp_searched_name.begin(), temp_searched_name.end(), temp_searched_name.begin(), ::tolower);

    std::vector<std::string> lines;
    std::string current_line;
    bool found = false;

    while (std::getline(file, current_line))
    {
        std::string current_name;                       // Store the name of the current line.
        std::string current_phone_number;               // Store the phone of the current line.
        std::size_t comma_pos = current_line.find(','); // Get comma (vírgula posittion).

        // Check if the comma (vírgula) was find() in the current line.
        if (comma_pos != std::string::npos)
        {
            /**
             * [Extract the current name from the line]
             * Creates a substring from position zero to comma (vírgula) position.
             */
            current_name = current_line.substr(0, comma_pos);

            /**
             * [Store the real name of the current line]
             * This is because the "current_name" will be modify to compare with
             * "searched_name" and we need a original name to put in the file
             */
            std::string original_current_name = current_name;

            /**
             * [Extract the current phone number to the line]
             * Creates a substring from comma (vírgula) until the end of the line.
             */
            current_phone_number = current_line.substr(comma_pos + 1);

            // Remove special characters and white spaces.
            current_name.erase(
                std::remove_if(
                    current_name.begin(),
                    current_name.end(),
                    [](unsigned char c)
                    { return !std::isalnum(c) || c == ' '; }),
                current_name.end());
            // Transform (converts) the passed number and the current phone number to lowercase.
            std::transform(current_name.begin(), current_name.end(), current_name.begin(), ::tolower);

            if (current_name == temp_searched_name)
            {
                found = true;
                std::string new_phone_number;
                std::cout << "Enter the new phone number: ";
                std::getline(std::cin, new_phone_number);
                current_line = original_current_name + "," + new_phone_number;
            }
        }
        lines.push_back(current_line);
    }

    file.close();

    if (!found)
    {
        std::cout << "No contact found for the provided name: '" << searched_name << "'\n\n";
        return true;
    }

    // Reopen the file in write mode and update the contents.
    std::ofstream outfile(file_name);

    // Check if the file open.
    if (!outfile)
    {
        std::cout << "Error opening the file for writing."
                  << "\n\n";
        return false;
    }

    for (const std::string &updated_line : lines)
    {
        outfile << updated_line << "\n";
    }

    outfile.close();

    std::cout << "Phone number updated successfully."
              << "\n\n";

    return true;
}

// ---------------------------------------------------------------------------------

bool Contact::delete_contact_by_name()
{
    std::fstream file(file_name);

    if (!file)
    {
        std::cout << "Error opening the file."
                  << "\n";
        return false;
    }

    std::string searched_name;
    std::cout << "Enter the complete name to search and delete: ";
    std::cin.ignore(); // Clear input buffer
    std::getline(std::cin, searched_name);
    std::string temp_searched_name = searched_name;

    // Remove special characters and white spaces.
    temp_searched_name.erase(
        std::remove_if(
            temp_searched_name.begin(),
            temp_searched_name.end(),
            [](unsigned char c)
            { return !std::isalnum(c) || c == ' '; }),
        temp_searched_name.end());
    // Transform (converts) the passed name to lowercase.
    std::transform(temp_searched_name.begin(), temp_searched_name.end(), temp_searched_name.begin(), ::tolower);

    std::vector<std::string> lines;
    std::string current_line;
    bool found = false;

    while (std::getline(file, current_line))
    {
        std::string current_name;                       // Store the name of the current line.
        std::string current_phone_number;               // Store the phone of the current line.
        std::size_t comma_pos = current_line.find(','); // Get comma (vírgula posittion).

        // Check if the comma (vírgula) was find() in the current line.
        if (comma_pos != std::string::npos)
        {
            /**
             * [Extract the current name from the line]
             * Creates a substring from position zero to comma (vírgula) position.
             */
            current_name = current_line.substr(0, comma_pos);

            /**
             * [Extract the current phone number to the line]
             * Creates a substring from comma (vírgula) until the end of the line.
             */
            current_phone_number = current_line.substr(comma_pos + 1);

            // Remove special characters and white spaces.
            current_name.erase(
                std::remove_if(
                    current_name.begin(),
                    current_name.end(),
                    [](unsigned char c)
                    { return !std::isalnum(c) || c == ' '; }),
                current_name.end());
            // Transform (converts) the passed number and the current phone number to lowercase.
            std::transform(current_name.begin(), current_name.end(), current_name.begin(), ::tolower);

            if (current_name == temp_searched_name)
            {
                found = true;
            }
            else
            {
                // If the line does not match with searched name save it in the Vector.
                lines.push_back(current_line);
            }
        }
    }

    file.close();

    // If the passed name does not match, then stop the method (return false).
    if (!found)
    {
        std::cout << "No contacts found for the provided name: '" << searched_name << "'\n\n";
        return true;
    }

    // Reopen the file in write mode and update the contents
    std::ofstream outfile(file_name);

    // Check if the file open.
    if (!outfile)
    {
        std::cout << "Error opening the file for writing." << "\n\n";
        return false;
    }

    // Overwrite the contact list without the contact to be deleted.
    for (const std::string &line : lines)
    {
        outfile << line << "\n";
    }

    outfile.close();

    std::cout << "Contact deleted successfully." << "\n\n";

    return true;
}

// ---------------------------------------------------------------------------------

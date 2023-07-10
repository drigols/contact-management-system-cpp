/**********************************************************************************
// CLI (Header File)
//
// Created:     10 July 2023
// Atualização: 10 July 2023
// Compiler:    gcc/g++
//
// Description: The Contact class provides methods to manage your contacts.
//
**********************************************************************************/

#ifndef CONTACT_H_

#include <string>

class Contact
{
public:
    // Useful methods.
    void display_contacts();

    // Add methods.
    void add_contact();

    // Search functions.
    bool search_by_phone();
    bool search_by_name();
};

#endif // CONTACT_H_

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

    // [C]reate methods.
    void add_contact();

    // [R]ead functions.
    bool search_by_phone();
    bool search_by_name();

    // [U]pdate functions.
    bool update_name();
    bool modifyPhoneNumberByName();
};

#endif // CONTACT_H_

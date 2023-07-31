/**********************************************************************************
// CLI (Header File)
//
// Created:     10 July 2023
// Updated:     31 July 2023
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
    // [C]reate methods.
    void add_contact();

    // [R]ead methods.
    bool search_by_phone();
    bool search_by_name();

    // [U]pdate methods.
    bool update_name();
    bool update_phone_number_by_name();

    // [D]elete methods.
    bool delete_contact_by_name();
    bool delete_contact_by_phone();

    // Useful methods.
    void display_contacts();
};

#endif // CONTACT_H_

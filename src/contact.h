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
private:
    // Encapsulation.
    std::string userName, phoneNumber;

public:
    // Setters.
    void setName(std::string userName);
    void setPhone(std::string phoneNumber);

    // Getters
    std::string getName();
    std::string getPhone();
};

#endif // CONTACT_H_

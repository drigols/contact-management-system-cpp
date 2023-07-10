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

#include "contact.h"

// ---------------------------------------------------------------------------------

void Contact::setName(std::string userName)
{
    this->userName = userName;
}

// ---------------------------------------------------------------------------------

std::string Contact::getName()
{
    return this->userName;
}

// ---------------------------------------------------------------------------------

void Contact::setPhone(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

// ---------------------------------------------------------------------------------

std::string Contact::getPhone()
{
    return this->phoneNumber;
}

// ---------------------------------------------------------------------------------

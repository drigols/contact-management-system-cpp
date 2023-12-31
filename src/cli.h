/****************************************************************************************
// CLI (Header File)
//
// Created:     10 July 2023
// Updated:     31 July 2023
// Compiler:    gcc/g++
//
// Description: The CLI class provides an interface to manage you Contact information.
//
****************************************************************************************/

#ifndef CLI_H_
#define CLI_H_

#include <string>

class CLI
{
public:
    void show_cli();
    void update_contact_menu();
    void delete_contact_menu();
};

#endif // CLI_H_

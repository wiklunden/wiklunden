/* 
	Milton Wiklund
	01/12-2022
	Datateknik GR (A), Introduktion till programmering
	Projekt: En kontaktbok
*/

// Funktion som kallar programmets meny (gränssnitt).

#include "interface.h"

void Interface()
{
	std::cout << "\n";
	std::cout << "----------------------------------------------\n";
	std::cout << "|                 PHONE BOOK                 |\n";
	std::cout << "----------------------------------------------\n";
	std::cout << "\n\tWhat would you like to do?\n";
	std::cout << "\n\t1) Add new contact.\n";
	std::cout << "\t2) Find contact by name.\n";
	std::cout << "\t3) Show all contacts.\n";
	std::cout << "\t4) Remove a contact.\n";
	std::cout << "\t5) Remove all contacts.\n";
	std::cout << "\t6) Exit.\n";
	std::cout << "> ";
	
	return;
}
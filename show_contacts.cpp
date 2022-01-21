/* 
	Milton Wiklund
	01/12-2022
	Datateknik GR (A), Introduktion till programmering
	Projekt: En kontaktbok
*/

// Funktion som skriver ut alla kontakter från kontaktboken.

#include "show_contacts.h"

void ShowContacts(const std::string CONTACTBOOK)
{
	std::ifstream contactBook;
	contactBook.open(CONTACTBOOK);

	if(contactBook.fail())
	{
		std::cout << "Failed to open file.\n";
		std::cout << "\n[Press Enter to continue]\n";
		return;
	}
	else
	{
		// Söker igenom hela kontaktboken och hämtar dess storlek.
		std::ifstream fileSize(CONTACTBOOK);
		fileSize.seekg(0, std::ios::end);
		int sizeOfFile = fileSize.tellg();
		
		// Skriver ut alla kontakter såvida kontaktboken inte är tom.
		if(sizeOfFile != 0)
		{
			std::cout << "\n|All contacts|\n\n";

			std::string output;

			while(getline(contactBook, output))
			{
				std::cout << output << "\n";
			}
			std::cout << "\n[Press Enter to continue]\n";
		}
		else
		{
			std::cout << "\nContact book is empty.\n";
			std::cout << "\n[Press Enter to continue]\n";
		}
		contactBook.close();
		std::cin.get();
	}
	return;
}
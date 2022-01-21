/* 
	Milton Wiklund
	01/12-2022
	Datateknik GR (A), Introduktion till programmering
	Projekt: En kontaktbok
*/

// Funktion som rensar kontaktbok.

#include "clear_contact_list.h"

void ClearContactList(const std::string CONTACTBOOK)
{
	std::ofstream contactBook;

	if(contactBook.fail())
	{
		std::cout << "Failed to open file.\n";
		std::cout << "\n[Press Enter to continue]\n";
		return;
	}
	else
	{
		std::cout << "\nRemove all contacts? (1/0): ";

		int choice;
		std::cin >> choice;
		
		if(choice == 1)
		{
			contactBook.open(CONTACTBOOK, std::ios::trunc);
			contactBook.close();
			std::cout << "\nAll contacts have been removed.\n";
			std::cout << "\n[Press Enter to continue]\n";
			std::cin.get();
		}
		else if(choice == 0)
		{
			std::cout << "\nContacts were not removed.\n";
			std::cout << "\n[Press Enter to continue]\n";
			std::cin.get();
		}
		contactBook.close();
		std::cin.get();
	}
	return;
}
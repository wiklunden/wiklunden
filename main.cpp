/* 
	Milton Wiklund
	01/12-2022
	Datateknik GR (A), Introduktion till programmering
	Projekt: En kontaktbok
*/

// En kontaktbok med ett flertal val av kommandon.

#include "interface.h"
#include "add_contact.h"
#include "find_contact.h"
#include "show_contacts.h"
#include "remove_contact.h"
#include "clear_contact_list.h"

int main()
{
	// Kallar på programmets meny och ber om ett val.
	Interface();

	const std::string CONTACTBOOK = "contacts.txt";
	const int ROWAMOUNT = 6;
	int choice;

	while(true)
	{
		while(true)
		{
			if(std::cin >> choice)
			{
				// Hoppar ur while-loopen och går vidare till switch:en omm 'choice' är ett heltal mellan 1 och 6.
				if(choice > 0 && choice <= 6)
					break;
			}		
			std::cout << "\nIncorrect input.\n";
			std::cout << "\nEnter a number between 1 and 6: ";
			std::cin.clear(); // Rensar error-tillståndet.
			std::cin.ignore(10000, '\n'); // Rensar bufferten.
		}

		std::cin.ignore(10000, '\n');

		switch(choice)
		{
			case 1:
				AddContact(CONTACTBOOK);
				break;

			case 2:
				FindContact(CONTACTBOOK, ROWAMOUNT);
				break;
				
			case 3:
				ShowContacts(CONTACTBOOK);
				break;
				
			case 4:
				RemoveContact(CONTACTBOOK, ROWAMOUNT);
				break;
				
			case 5:
				ClearContactList(CONTACTBOOK);
				break;
			
			case 6:
				std::cout << "\nExiting...\n\n";
				return 0;
			
			default:
				break;
		}
		Interface();
	}

	return 0;
}
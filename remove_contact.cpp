/* 
	Milton Wiklund
	01/12-2022
	Datateknik GR (A), Introduktion till programmering
	Projekt: En kontaktbok
*/

// Funktion som tar bort efterfrågad kontakt från kontaktboken.

#include "remove_contact.h"

void RemoveContact(const std::string CONTACTBOOK, const int ROWAMOUNT)
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
		std::cout << "\n|Remove a contact|\n";
		std::cout << "\nSearch for the name of contact to remove: ";

		std::string findByName, name;
		getline(std::cin, findByName);

		std::vector<std::string> searchVec;
		std::vector<std::string> lowercaseVec; // Hämtar samma information som 'searchVec' och gör allt till gemener.

		while(getline(contactBook, name))
		{
			searchVec.push_back(name);
			lowercaseVec.push_back(name);
		}
		
		transform(findByName.begin(), findByName.end(), findByName.begin(), ::tolower);
		
		bool contactIsFound = false;
		bool contactIsRemoved = false;
		
		// Söker igenom hela vektorn.
		for(int i = 0; i < searchVec.size(); i += ROWAMOUNT)
		{
			transform(lowercaseVec[i].begin(), lowercaseVec[i].end(), lowercaseVec[i].begin(), ::tolower);

			// Letar efter efterfrågat namn.
			if((lowercaseVec[i].find(findByName) != std::string::npos) && (findByName.length() != 0))
			{
				contactIsFound = true;

				std::cout << "\nContact found!\n\n";

				// Matar ut hela kontaktens delar
				for(int l = 0; l < 5; l++)
					std::cout << searchVec[i+l] << "\n";

				std::cout << "\nWould you like to delete " << searchVec[i] << "? (1/0): ";

				int choice;
				std::cin >> choice;
				std::cin.ignore(10000, '\n');

				if(choice == 1)
				{
					contactIsRemoved = true;
					
					// Tar bort alla rader med det hittade namnets kontaktinformation.
					for(int j = 0; j < ROWAMOUNT; j++)
					{
						searchVec.erase(searchVec.begin() + i);
						lowercaseVec.erase(lowercaseVec.begin() + i);
					}

					std::cout << "\nContact successfully removed.\n";
					std::cout << "\n[Press Enter to continue]\n";
					std::cin.get();
					i -= ROWAMOUNT;
				}
				else if(choice != 1)
				{
					std::cout << "\nContact was not removed.\n";
					std::cout << "\n[Press Enter to continue]\n";
					std::cin.get();
				}
			}
		}

		// Skrivs ut omm programmet ej hittar efterfrågad kontakt.
		if(!contactIsFound)
		{
			std::cout << "\nNo contact found.\n";
			std::cout << "\n[Press Enter to continue]\n";
			std::cin.get();
		}
		// Skriver över kontaktbok omm minst en kontakt har blivit borttagen.
		if(contactIsRemoved)
		{
			std::ofstream contactBookOutput;

			contactBookOutput.open(CONTACTBOOK);

			// Skriver över kontaktbok med all kvarstående information.
			for(auto i: searchVec)
				contactBookOutput << i << "\n";

			contactBookOutput.close();
		}
		contactBook.close();
	}
	return;
}
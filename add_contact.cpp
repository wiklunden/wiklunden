/* 
	Milton Wiklund
	01/12-2022
	Datateknik GR (A), Introduktion till programmering
	Projekt: En kontaktbok
*/

// Funktion som lägger till ny kontakt i kontaktboken.

#include "add_contact.h"

// Konstruktion för kontakt.
struct Contact
{
	std::string name;
	std::string address;
	std::string email;
	std::string phone;
	std::string birthday;
	std::string gender;
};

void AddContact(const std::string CONTACTBOOK)
{
	std::ofstream contactBook;
	contactBook.open(CONTACTBOOK, std::ios::app);

	// Felmeddelande ifall filen ej kunde öppnas.
	if(contactBook.fail())
	{
		std::cout << "Failed to open file.\n";
		std::cout << "\n[Press Enter to continue]\n";
	}
	else
	{
		Contact contact;
		std::cout << "\n|Add a new contact|\n";

		std::cout << "\nName: ";
		getline(std::cin, contact.name);

		std::string nameRemoveSpace;

		// Kollar om namnet är alfabetiskt.
		nameRemoveSpace = contact.name;
		// Tar bort mellanslag för att underlätta sökning efter bokstäver.
		nameRemoveSpace.erase(remove(nameRemoveSpace.begin(), nameRemoveSpace.end(), ' '), nameRemoveSpace.end());

		int resetCounter = -1;

		for(int i = 0; i < nameRemoveSpace.length(); i++)
		{
			if(isalpha(nameRemoveSpace[i]) || nameRemoveSpace[i] == '-') // Tillåter bokstäver och bindestreck.
				continue;
			
			else
			{
				std::cout << "\nIncorrect input.\n";

				std::cout << "\nName: ";
				getline(std::cin, contact.name);

				nameRemoveSpace = contact.name;
				nameRemoveSpace.erase(remove(nameRemoveSpace.begin(), nameRemoveSpace.end(), ' '), nameRemoveSpace.end());

				i = resetCounter;
			}
		}

		std::cout << "Address: ";
		getline(std::cin, contact.address);

		std::cout << "Email: ";
		getline(std::cin, contact.email);

		std::cout << "Phone number: ";
		getline(std::cin, contact.phone);

		// Kollar om telefonnumret är numeriskt.
		for(int i = 0; i < contact.phone.length(); i++)
		{
			if(!isalpha(contact.phone[i]))
				continue;
			
			else
			{
				std::cout << "\nIncorrect input.\n";

				std::cout << "\nPhone number: ";
				getline(std::cin, contact.phone);

				i = resetCounter;
			}
		}

		std::cout << "Birthday (YY/MM/DD): ";
		getline(std::cin, contact.birthday);
		
		// Kollar om könet är alfabetiskt.
		std::cout << "Gender: ";
		getline(std::cin, contact.gender);

		for(int i = 0; i < contact.gender.length(); i++)
		{
			if(isalpha(contact.gender[i]))
				continue;
			
			else
			{
				std::cout << "\nIncorrect input.\n";

				std::cout << "\nGender: ";
				getline(std::cin, contact.gender);
				
				i = resetCounter;
			}
		}

		contactBook << contact.name << "\n";
		contactBook << contact.address << "\n";
		contactBook << contact.email << "\n";
		contactBook << contact.phone << "\n";
		contactBook << contact.birthday << "\n";
		contactBook << contact.gender << "\n";

		std::cout << "\nNew contact added!\n";
		std::cout << "\n[Press Enter to continue]\n";

		contactBook.close();
		std::cin.get();
	}
	return;
}
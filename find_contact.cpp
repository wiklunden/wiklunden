/* 
	Milton Wiklund
	01/12-2022
	Datateknik GR (A), Introduktion till programmering
	Projekt: En kontaktbok
*/

// Funktion som hittar efterfrågad kontakt.

#include "find_contact.h"

struct Contact
{
	std::string name;
	std::string address;
	std::string email;
	std::string phone;
	std::string birthday;
	std::string gender;
};

void FindContact(const std::string CONTACTBOOK, const int ROWAMOUNT)
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
		std::cout << "\n|Find contact by name|\n";

		std::string findByName;

		std::cout << "\nSearch for name: ";
		getline(std::cin, findByName);
		std::cout << "\n";

		transform(findByName.begin(), findByName.end(), findByName.begin(), ::tolower);

		Contact contact;
		std::vector<Contact> findContact; // Vektor som lagrar hela struct:en 'contact'.

		// Hämtar varenda rad från textfil.
		while(getline(contactBook, contact.name))
		{
			getline(contactBook, contact.address);
			getline(contactBook, contact.email);
			getline(contactBook, contact.phone);
			getline(contactBook, contact.birthday);
			getline(contactBook, contact.gender);

			findContact.push_back(contact);
		}

		std::string row;
		std::vector<int> contactPos;

		for(int i = 0; i < findContact.size(); i++)
		{
			for(int j = 0; j < ROWAMOUNT; j++)
			{
				switch (j)
				{
					case 0:
						row = findContact[i].name;
						break;

					case 1:
						row = findContact[i].address;
						break;

					case 2:
						row = findContact[i].email;
						break;

					case 3:
						row = findContact[i].phone;
						break;

					case 4:
						row = findContact[i].birthday;
						break;

					case 5:
						row = findContact[i].gender;
						break;
				}

				transform(row.begin(), row.end(), row.begin(), ::tolower);

				if(row.find(findByName) != std::string::npos)
				{
					// Kollar om namnets index redan är lagrat i 'contactPos'.
					if(find(contactPos.begin(), contactPos.end(), i) == contactPos.end())
						contactPos.push_back(i);
				}
			}
		}
		if(contactPos.size() == 0)
		{
			std::cout << "Contact not found.\n";
			std::cout << "\n[Press Enter to continue]\n";
			std::cin.get();
		}
		else
		{
			for(int i = 0; i < contactPos.size(); i++)
			{
				std::cout << "\nContact found!\n\n";
				std::cout << "Name: " << findContact[contactPos[i]].name << "\n";
				std::cout << "Address: " << findContact[contactPos[i]].address << "\n";
				std::cout << "Email: " << findContact[contactPos[i]].email << "\n";
				std::cout << "Phone: " << findContact[contactPos[i]].phone << "\n";
				std::cout << "Birthday: " << findContact[contactPos[i]].birthday << "\n";
				std::cout << "Gender: " << findContact[contactPos[i]].gender << "\n";
				std::cout << "\n[Press Enter to continue]\n";
				std::cin.get();
			}
		}
		contactBook.close();
	}
	return;
}
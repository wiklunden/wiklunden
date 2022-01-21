program: main.cpp interface.cpp add_contact.cpp find_contact.cpp show_contacts.cpp remove_contact.cpp clear_contact_list.cpp interface.h add_contact.h find_contact.h show_contacts.h remove_contact.h clear_contact_list.h
	g++ -o program main.cpp interface.cpp add_contact.cpp find_contact.cpp show_contacts.cpp remove_contact.cpp clear_contact_list.cpp

run: program
	./program

clean:
	rm program
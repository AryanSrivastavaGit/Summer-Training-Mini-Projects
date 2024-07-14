// Project PhoneBook in C++

#include "bits/stdc++.h"

using namespace std;

struct Contact
{
    string name;
    string phoneNumber;
};

int main(void)
{

    vector<Contact> phonebook; // vector for store the user name and contact number
    int choice;
    do
    {
        cout << "-------------------------------------------------------\n";
        cout << "Press 1 for Add Contact\n";
        cout << "Press 2 for Display All Contacts\n";
        cout << "Press 3 for Search  Contact\n";
        cout << "Press 4 for Edit Contact\n";
        cout << "Press 5 for Delete Contact\n";
        cout << "Press 6 for Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Contact newContact;
            cout << "Enter name: ";
            cin >> newContact.name;
            cout << "Enter phone number: ";
            cin >> newContact.phoneNumber;
            phonebook.push_back(newContact);
            cout << "Contact added successfully!\n\n\n\n";
            break;
        }
        case 2:
        {
            cout << "-------------------------------------------------------\n";
            cout << "Contacts:\n";
            for (const auto &contact : phonebook)
            {
                cout << "Name: " << contact.name << ", Phone Number: " << contact.phoneNumber << "\n";
            }
            break;
        }
        case 3:
        {
            cout << "Enter The Contact Name You Looking for\n";
            string searchQuery;
            cin >> searchQuery;

            bool found = false;
            for (const auto &contact : phonebook)
            {
                if (contact.name == searchQuery)
                {
                    cout << "-------------------------------------------------------\n";
                    cout << "Contact found!\n";
                    cout << "Name: " << contact.name << ", Phone Number: " << contact.phoneNumber << "\n";
                    found = true;
                }
            }

            // if contact is not exist
            if (!found)
            {
                cout << "Contact not found.\n";
            }

            break;
        }
        case 4:
        {
            cout << "Enter The Name of the contact to edit: ";
            string editQuery;
            cin >> editQuery;

            bool edited = false;
            for (auto &contact : phonebook)
            {
                if (contact.name == editQuery)
                {
                    cout << "Enter the new name: ";
                    cin >> contact.name;
                    cout << "Enter the new phone number: ";
                    cin >> contact.phoneNumber;
                    edited = true;
                    cout << "-------------------------------------------------------\n";
                    cout << "Contact Edited Successfully!\n";
                    break;
                }
            }

            // if contact is not exist
            if (!edited)
            {
                std::cout << "Contact Not Found.\n";
            }

            break;
        }
        case 5:
        {
            cout << "Enter The Name of the Contact to Delete: ";
            string deleteQuery;
            cin >> deleteQuery;

            bool deleted = false;
            for (auto it = phonebook.begin(); it != phonebook.end(); ++it)
            {
                if (it->name == deleteQuery)
                {
                    phonebook.erase(it);
                    deleted = true;
                    cout << "-------------------------------------------------------\n";
                    cout << "Contact Deleted Successfully!\n";
                    break;
                }
            }

            // if contact is not exist
            if (!deleted)
            {
                cout << "Contact Not Found.\n";
            }

            break;
        }

        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

    } while (choice != 6);

    return 0;
}



#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

// Contact class definition
class Contact {
private:
	string name;
	string phoneNumber;

public:
	Contact(string n, string p) : name(n), phoneNumber(p) {}

	string getName() const {
		return name;
	}

	string getPhoneNumber() const {
		return phoneNumber;
	}

	void displayContact() const {
		cout << "Name: " << name << ", Phone: " << phoneNumber << endl;
	}
};

// Function declarations
void addContact(vector<Contact>& contacts);
void viewContacts(const vector<Contact>& contacts);
void deleteContact(vector<Contact>& contacts);
void showMenu();

int main() {
	vector<Contact> contacts;
	int choice;

	while (true) {
		showMenu();
		cin >> choice;
		cin.ignore(); 

		switch (choice) {
		case 1:
			addContact(contacts);
			break;
		case 2:
			viewContacts(contacts);
			break;
		case 3:
			deleteContact(contacts);
			break;
		case 4:
			cout << "Exiting the program......" << endl;
			return 0;
		default:
			cout << "Invalid Option. Please Try Again." << endl;
		}
	}

	return 0;
}

// Display the menu options
void showMenu() {
	cout << "\n ''Contact Management System''" << endl;
	cout << "Type 1 to Add Contact." << endl;
	cout << "Type 2 to View Contacts." << endl;
	cout << "Type 3 to Delete Contact." << endl;
	cout << "Type 4 to Exit." << endl;
	cout << "Please Enter your Choice: ";
}

// Add a new contact
void addContact(vector<Contact>& contacts) {
	string name, phoneNumber;

	cout << "Please Enter the Contact Name: ";
	getline(cin, name);
	cout << "Please Enter the Contact Phone Number: ";
	getline(cin, phoneNumber);

	contacts.push_back(Contact(name, phoneNumber));
	cout << "Contact Added Successfully!" << endl;
}

// View all contacts
void viewContacts(const vector<Contact>& contacts) {
	if (contacts.empty()) {
		cout << "No Contacts Available." << endl;
		return;
	}

	cout << "\nList of Contacts:" << endl;
	for (size_t i = 0; i < contacts.size(); ++i) {
		cout << i + 1 << ". ";
		contacts[i].displayContact();
	}
}

// Delete a contact by name
void deleteContact(vector<Contact>& contacts) {
	if (contacts.empty()) {
		cout << "No Contacts to Delete." << endl;
		return;
	}

	string nameToDelete;
	cout << "Please Enter the Name of the Contact to Delete: ";
	getline(cin, nameToDelete);

	// Find the contact by name
	auto it = find_if(contacts.begin(), contacts.end(),
		[&nameToDelete](const Contact& c) { return c.getName() == nameToDelete; });

	if (it != contacts.end()) {
		contacts.erase(it);
		cout << "Contact '" << nameToDelete << "' Deleted Successfully!" << endl;
	}
	else {
		cout << "Contact not Found." << endl;
	}
}

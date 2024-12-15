/*
AIM:
club member‘s information using singly linked list. 
Store student PRN and Name. 
Write functions to: 
a) Add and delete the members as well as president or even secretary. 
b) Compute total number of members of club 
c) Display members
d) Two linked lists exists for two divisions. 
   Concatenate two lists

INPUT: 
    1. Student PRN and Name

OUTPUT:
    1. Display Members list for SE-A and SE-B divisions
	2. Add Member to SE-A and SE-B divisions
	3. Delete Member from SE-A and SE-B divisions
	4. Concatenate two lists

AUTHOR: Dr. Sunil Rathod
DATE: 03.09.2024
*/
#include <iostream>
#include <string>

using namespace std;

// Node structure for the singly linked list
struct Node {
    int prn;
    string name;
    Node* next;

    Node(int prn, string name) : prn(prn), name(name), next(nullptr) {}
};

class Club {
private:
    Node* head;

public:
    Club() : head(nullptr) {}

    // Add member at the end
    void addMember(int prn, string name) {
        Node* newNode = new Node(prn, name);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Delete member by PRN
    void deleteMember(int prn) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        if (head->prn == prn) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Member with PRN " << prn << " deleted.\n";
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->prn != prn) {
            temp = temp->next;
        }

        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Member with PRN " << prn << " deleted.\n";
        } else {
            cout << "Member with PRN " << prn << " not found.\n";
        }
    }

    // Compute total members
    int countMembers() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Display members
    void displayMembers() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Address\t\tPRN\tName\n";
        while (temp) {
            cout << temp << "\t" << temp->prn << "\t" << temp->name << "\n";
            temp = temp->next;
        }
    }

    // Concatenate another list
    void concatenate(Club& other) {
        if (!head) {
            head = other.head;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = other.head;
    }
};

int main() {
    Club seA, seB;
    int choice, prn;
    string name;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Member to SE-A\n";
        cout << "2. Add Member to SE-B\n";
        cout << "3. Delete Member from SE-A\n";
        cout << "4. Delete Member from SE-B\n";
        cout << "5. Display Members of SE-A\n";
        cout << "6. Display Members of SE-B\n";
        cout << "7. Concatenate SE-A and SE-B\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter PRN and Name for SE-A: ";
                cin >> prn;
                cin.ignore();
                getline(cin, name);
                seA.addMember(prn, name);
                break;

            case 2:
                cout << "Enter PRN and Name for SE-B: ";
                cin >> prn;
                cin.ignore();
                getline(cin, name);
                seB.addMember(prn, name);
                break;

            case 3:
                cout << "Enter PRN to delete from SE-A: ";
                cin >> prn;
                seA.deleteMember(prn);
                break;

            case 4:
                cout << "Enter PRN to delete from SE-B: ";
                cin >> prn;
                seB.deleteMember(prn);
                break;

            case 5:
                cout << "Members of SE-A:\n";
                seA.displayMembers();
                break;

            case 6:
                cout << "Members of SE-B:\n";
                seB.displayMembers();
                break;

            case 7:
                cout << "Concatenating SE-A and SE-B...\n";
                seA.concatenate(seB);
                cout << "Concatenated List:\n";
                seA.displayMembers();
                break;

            case 8:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}

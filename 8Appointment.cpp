/*
AIM:
Write C++ program for storing appointment schedule for day.
Appointments are booked randomly using linked list.
Set start and end time and min and max duration for visit slot.
Write functions for:
a) Display free slots 
b) Book appointment 
c) Cancel appointment (check validity, time bounds, availability etc.) 
d) Sort list based on time
e) Sort list based on time using pointer manipulation

INPUT: 
    1. Name of visitor
	2. hourOfDay, start and end time 
	3. min and max duration for visit slot

OUTPUT:
	a) Display free slots 
	b) Book appointment 
	c) Cancel appointment (check validity, time bounds, availability etc.) 
	d) Sort list based on time
	e) Sort list based on time using pointer manipulation
	
*/
#include <iostream>
#include <string>
using namespace std;

// Node structure for linked list
struct Node {
    string visitorName;
    int hourOfDay;
    int startTime;
    int endTime;
    Node* next;

    Node(string name, int hour, int start, int end) : visitorName(name), hourOfDay(hour), startTime(start), endTime(end), next(nullptr) {}
};

class AppointmentScheduler {
private:
    Node* head;

public:
    AppointmentScheduler() : head(nullptr) {}

    // Add free slot
    void addFreeSlot(int hourOfDay, int startTime, int endTime) {
        Node* newNode = new Node("Free Slot", hourOfDay, startTime, endTime);
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

    // Display free slots
    void displayFreeSlots() {
        if (!head) {
            cout << "No free slots available.\n";
            return;
        }

        Node* temp = head;
        cout << "Free Slots:\n";
        while (temp) {
            if (temp->visitorName == "Free Slot") {
                cout << "Hour: " << temp->hourOfDay << " | Start: " << temp->startTime << " | End: " << temp->endTime << "\n";
            }
            temp = temp->next;
        }
    }

    // Book an appointment
    void bookAppointment(string name, int hourOfDay, int startTime, int duration) {
        Node* temp = head;
        while (temp) {
            if (temp->visitorName == "Free Slot" && temp->hourOfDay == hourOfDay && temp->startTime <= startTime && temp->endTime >= startTime + duration) {
                temp->visitorName = name;
                temp->endTime = startTime + duration;
                cout << "Appointment booked for " << name << ".\n";
                return;
            }
            temp = temp->next;
        }
        cout << "No suitable slot found for booking.\n";
    }

    // Cancel an appointment
    void cancelAppointment(string name) {
        Node* temp = head;
        while (temp) {
            if (temp->visitorName == name) {
                temp->visitorName = "Free Slot";
                cout << "Appointment for " << name << " has been cancelled.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "No appointment found for " << name << ".\n";
    }

    // Sort list based on time
    void sortByTime() {
        if (!head || !head->next) return;

        for (Node* i = head; i->next; i = i->next) {
            for (Node* j = head; j->next; j = j->next) {
                if (j->hourOfDay > j->next->hourOfDay || (j->hourOfDay == j->next->hourOfDay && j->startTime > j->next->startTime)) {
                    swap(j->hourOfDay, j->next->hourOfDay);
                    swap(j->startTime, j->next->startTime);
                    swap(j->endTime, j->next->endTime);
                    swap(j->visitorName, j->next->visitorName);
                }
            }
        }
        cout << "Slots sorted by time.\n";
    }

    // Sort by pointer manipulation (Bubble Sort)
    void sortByPointer() {
        if (!head || !head->next) return;

        bool swapped;
        do {
            swapped = false;
            Node** current = &head;

            while ((*current)->next) {
                Node* a = *current;
                Node* b = a->next;

                if (a->hourOfDay > b->hourOfDay || (a->hourOfDay == b->hourOfDay && a->startTime > b->startTime)) {
                    a->next = b->next;
                    b->next = a;
                    *current = b;
                    swapped = true;
                }
                current = &(*current)->next;
            }
        } while (swapped);

        cout << "Slots sorted by time using pointer manipulation.\n";
    }
};

int main() {
    AppointmentScheduler scheduler;
    int choice, hourOfDay, startTime, endTime, duration;
    string visitorName;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Free Slot\n";
        cout << "2. Display Free Slots\n";
        cout << "3. Book Appointment\n";
        cout << "4. Cancel Appointment\n";
        cout << "5. Sort Slots by Time\n";
        cout << "6. Sort Slots by Pointer Manipulation\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter hour of the day (0-23): ";
                cin >> hourOfDay;
                cout << "Enter start time: ";
                cin >> startTime;
                cout << "Enter end time: ";
                cin >> endTime;
                scheduler.addFreeSlot(hourOfDay, startTime, endTime);
                break;

            case 2:
                scheduler.displayFreeSlots();
                break;

            case 3:
                cout << "Enter visitor name: ";
                cin.ignore();
                getline(cin, visitorName);
                cout << "Enter hour of the day (0-23): ";
                cin >> hourOfDay;
                cout << "Enter start time: ";
                cin >> startTime;
                cout << "Enter duration: ";
                cin >> duration;
                scheduler.bookAppointment(visitorName, hourOfDay, startTime, duration);
                break;

            case 4:
                cout << "Enter visitor name to cancel: ";
                cin.ignore();
                getline(cin, visitorName);
                scheduler.cancelAppointment(visitorName);
                break;

            case 5:
                scheduler.sortByTime();
                break;

            case 6:
                scheduler.sortByPointer();
                break;

            case 7:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}

#include <iostream>
#include <limits>
#include <string>

using namespace std;

-
struct Period {
    string subject;
    string teacher;
}


Period timetable[5][4];
string days[5] = {"mon", "tues", "wed", "thurs", "Fri"};

void displayMenu();
void setTimetable();
void viewTimetable();
int getValidatedInput(int min, int max);


int main() {
    int choice;

    do {
        displayMenu();
        cout << "enter your choice: ";
        choice = getValidatedInput(1, 3);

        switch (choice) {
            case 1:
                setTimetable();
                break;
            case 2:
                viewTimetable();
                break;
            case 3:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}


void displayMenu() {
    cout << "\n--- SCHOOL TIMETABLE MANAGEMENT ---\n";
    cout << "1. Set Timetable\n";
    cout << "2. View Timetable\n";
    cout << "3. Exit\n";
}

int getValidatedInput(int min, int max) {
    int input;
    while (!(cin >> input) || input < min || input > max) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a number between " << min << " and " << max << ": ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    return input;
}


void setTimetable() {
    int day, period;
    string subject, teacher;

    cout << "\nSelect Day:\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << days[i] << endl;
    }

    cout << "Enter day number (1-5): ";
    day = getValidatedInput(1, 5);

    cout << "Enter period number (1-4): ";
    period = getValidatedInput(1, 4);

    cin.ignore(); 
    cout << "Enter subject name: ";
    getline(cin, subject);

    cout << "Enter teacher name (optional): ";
    getline(cin, teacher);

    timetable[day - 1][period - 1] = {subject, teacher};
    cout << "Timetable updated successfully!\n";
}


void viewTimetable() {
    cout << "\n--- SCHOOL TIMETABLE ---\n";

    for (int i = 0; i < 5; i++) {
        cout << days[i] << ":\n";
        for (int j = 0; j < 4; j++) {
            if (timetable[i][j].subject.empty())
                cout << "  Period " << j + 1 << ": Free\n";
            else
                cout << "  Period " << j + 1 << ": " << timetable[i][j].subject
                     << " (" << timetable[i][j].teacher << ")\n";
        }
    }
}




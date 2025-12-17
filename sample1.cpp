#include <iostream>
#include <limits> //we use this if we put wrong input we need to put a proper code for it


using namespace std;


string timetable[5][4];   
string days[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};


void displayMenu();
void timetableModule();

int main() {
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";

        while (!(cin >> choice)) {
            cout << "Invalid input. Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limitr for wrong input like a formula for it
        }

        switch (choice) {
            case 1:
                timetableModule();
                break;
            case 2:
                cout << "\nExiting program. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice.\n";
        }

    } while (choice != 2);

    return 0;
}

// Display Main Menu
void displayMenu() {
    
    cout << " SCHOOL TIMETABLE SYSTEM\n";
    
    cout << "1. Timetable Module\n";
    cout << "2. Exit";
    cout << "------------------------------\n";
}


void timetableModule() {
    int choice;

    do {
        cout << "\n--- Timetable Module ---\n";
        cout << "1. Set Timetable\n";
        cout << "2. View Timetable\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter choice: ";

        while (!(cin >> choice)) {
            cout << "Invalid input. Enter number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (choice == 1) {
            int day, period;
            string subject;

            cout << "\nSelect Day:\n";
            for (int i = 0; i < 5; i++) {
                cout << i + 1 << ". " << days[i] << endl;
            }

            cout << "Enter day number (1-5): ";
            cin >> day;

            cout << "Enter period number (1-4): ";
            cin >> period;

            cin.ignore();
            cout << "Enter subject name: ";
            getline(cin, subject);

            timetable[day - 1][period - 1] = subject;
            cout << "Timetable updated successfully.\n";
        }

        else if (choice == 2) {
            cout << "\n-------- TIMETABLE --------\n";
            for (int i = 0; i < 5; i++) {
                cout << days[i] << ":\n";
                for (int j = 0; j < 4; j++) {
                    cout << "  Period " << j + 1 << ": ";
                    if (timetable[i][j] == "")
                        cout << "Free\n";
                    else
                        cout << timetable[i][j] << endl;
                }
            }
        }

    } while (choice != 3);
}

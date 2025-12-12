
#include <iostream>
#include <limits> // Required for input cleaning

using namespace std;

// Function Prototypes (Declaring the functions we will use)
void displayMenu();
void studentModule();
void teacherModule();

int main() {
    int choice;

    do {
        // Display the main menu
        displayMenu();
        
        cout << "Enter your choice (1-5): ";
        
        // Input validation loop
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number: ";
            // Clear the error flags on cin
            cin.clear(); 
            // Discard the bad input up to the next newline character
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }

        // Handle the user's choice
        switch (choice) {
            case 1:
                studentModule();
                break;
            case 2:
                teacherModule();
                break;
            case 3:
                cout << "\n--- Attendance Module Selected ---\n";
                // Add Attendance functionality here
                break;
            case 4:
                cout << "\n--- Fees Module Selected ---\n";
                // Add Fees functionality here
                break;
            case 5:
                cout << "\nExiting School Management System. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice. Please select a number between 1 and 5.\n";
                break;
        }

    } while (choice != 5);

    return 0;
}

// Function to display the main menu
void displayMenu() {
    cout << "\n===================================" << endl;
    cout << "  SCHOOL MANAGEMENT SYSTEM - MENU" << endl;
    cout << "===================================" << endl;
    cout << "1. Student Module" << endl;
    cout << "2. Teacher Module" << endl;
    cout << "3. Attendance" << endl;
    cout << "4. Fees" << endl;
    cout << "5. Exit" << endl;
    cout << "-----------------------------------" << endl;
}

// Function for the Student Module
void studentModule() {
    cout << "\n--- Student Module ---\n";
    cout << "  1. Add New Student" << endl;
    cout << "  2. View Student Records" << endl;
    cout << "  3. Update Student Info" << endl;
    cout << "  4. Go Back to Main Menu" << endl;
    
    // Add logic for student module sub-menu here
}

// Function for the Teacher Module
void teacherModule() {
    cout << "\n--- Teacher Module ---\n";
    cout << "  1. Add New Teacher" << endl;
    cout << "  2. View Teacher Records" << endl;
    cout << "  3. Assign Classes/Subjects" << endl;
    cout << "  4. Go Back to Main Menu" << endl;
    
    // Add logic for teacher module sub-menu here
}
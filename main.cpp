/*
Name: Aayam Raj Shakya
Date: 16 Feb 2023
Description: This program is a simple class schedule manager that allows the user
             to add and remove classes. The program uses two vectors to store
             the course codes and names, and provides a menu interface for the user to
             interact with. The user can view their class schedule, add a new class by
             entering its course code and name and remove an existing class by selecting from
             a list. The program performs input validation and provides error messages to the user
             when necessary.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void viewSchedule(vector<string>& codes, vector<string>& names) {
    cout << "Your Class Schedule: " << endl;
    for (int i = 0; i < codes.size(); i++) {
        cout << i + 1 << ". " << codes[i] << " " << names[i] << endl;
        cout << endl;

    }
}

bool addClass(vector<string>& codes, vector<string>& names) {
    string newCode, newName;
    cout << "Enter the course code (exactly 4 characters): ";
    cin >> newCode;
    if (newCode.size() != 4) {
        cout << "Course code must be exactly 4 characters long. Try again." << endl;
        return false;
    }
    cout << "Enter course name: ";
    cin.ignore();
    getline(cin, newName);
    codes.push_back(newCode);
    names.push_back(newName);
    cout << "Course added successfully!" << endl;
    return true;
}

bool removeClass(vector<string>& codes, vector<string>& names) {
    if (codes.empty() || names.empty()) {
        cout << "There are no courses to remove. Try again." << endl;
        return false;
    }
    cout << "Which course would you like to remove?" << endl;
    for (int i = 0; i < codes.size(); i++) {
        cout << i << ": " << codes[i] << " - " << names[i] << endl;
    }
    int choice;
    cin >> choice;
    if (choice < 0 || choice >= codes.size()) {
        cout << "Invalid choice. Try again." << endl;
        return false;
    }
    codes.erase(codes.begin() + choice);
    names.erase(names.begin() + choice);
    cout << "Course removed successfully!" << endl;
    return true;
}

int main() {
    vector<string> courseCodes;
    vector<string> courseNames;
    cout << "Welcome to the class schedule manager." << endl << endl;
    int choice = 0;
    while (choice != 4) {
        cout << "1. View Schedule" << endl;
        cout << "2. Add Class" << endl;
        cout << "3. Remove Class" << endl;
        cout << "4. Exit" << endl;
        cout << endl;
        cout << "Select an option: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1:
                if (courseCodes.empty() || courseNames.empty()) {
                    cout << "You have to add classes first!" << endl;
                } else {
                    viewSchedule(courseCodes, courseNames);
                }
                break;
            case 2:
                addClass(courseCodes, courseNames);
                break;
            case 3:
                removeClass(courseCodes, courseNames);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "That's not a valid menu option. Try again." << endl;
                break;
        }
    }
    return 0;
}





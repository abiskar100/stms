/**
 * @file Menu.cpp
 * @brief Implements the Menu class methods for handling user interactions and managing student records.
 */

#include "menu.h"
#include <iomanip>
#include <iostream>
#include <string>
#include "student.h"
#include "filehandling.h"
#include "inputvalidation.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cstdlib>

using namespace std;

/**
 * @brief Default constructor initializes a Menu object with a default choice value.
 *
 * This constructor sets the `choice` member variable to 0, representing no menu option selected.
 */
Menu::Menu() : choice(0) {}

/**
 * @brief Displays the menu options to the user.
 *
 * This method prints the available menu options to the console, including options for
 * adding a student, viewing records, searching, updating names, removing students, and exiting.
 */
void Menu::displaymenu() {
    cout << endl;
    cout << endl;
    cout << "Menu" << endl;
    cout << "1. Add student" << endl;
    cout << "2. View Record" << endl;
    cout << "3. Search by Roll" << endl;
    cout << "4. Update Name" << endl;
    cout << "5. Remove student" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
}

/**
 * @brief Sets the user's menu choice.
 * @param c The user's menu choice.
 *
 * This method updates the `choice` member variable with the user's selected menu option.
 */
void Menu::getchoice(int c) {
    choice = c;
}

/**
 * @brief Adds a new student to the system.
 *
 * This method prompts the user for the student's name and roll number, validates the input,
 * creates a Student object, and appends the student's information to the file "studentRec.txt".
 * Any invalid input will result in an exception being caught and an error message being displayed.
 */
void Menu::addStudent() {
    try {
        string s_name;
        int s_roll;

        cout << "Enter your full name: " << endl;
        getline(cin, s_name);

        cout << "Enter your roll number: " << endl;
        cin >> s_roll;
        cin.ignore();  // Clear the newline character from the input buffer

        // Validate inputs
        string o_name = checkInput::checkName(s_name);
        int o_roll = checkInput::checkRoll(s_roll);

        // Create a Student object and append to file
        Student s1(o_name, o_roll);
        FileHandling filh("studentRec.txt");
        filh.appendStudent(s1);

        cout << "Successfully written" << endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() << "\n";
    }
}

/**
 * @brief Displays all student records.
 *
 * This method creates a FileHandling object to read and display all student records from the file
 * "studentRec.txt". It prints each record to the console.
 */
void Menu::viewRecord() {
    FileHandling record("studentRec.txt");
    cout << "Student Name: " << setw(22) << "Roll number: " << endl;
    record.readfile();
}

/**
 * @brief Searches for a student record by roll number.
 *
 * This method prompts the user for a roll number, searches the file "studentRec.txt" for
 * a record with the specified roll number, and displays the student's name if found.
 */
void Menu::search() {
    string line;
    string fname;
    string lname;
    int roll, sroll;

    cout << "Enter the roll number to search: " << endl;
    cin >> sroll;
    cin.ignore();  // Clear the newline character from the input buffer

    ifstream file("studentRec.txt");

    if (!file.is_open()) {
        cout << "Unable to open the file" << endl;
        return;
    }

    while (getline(file, line)) {
        stringstream content(line);
        content >> fname >> lname >> roll;

        if (roll == sroll) {
            cout << fname << " " << lname << endl;
            file.close();
            return;
        }
    }
    file.close();
    cout << "Student with roll number " << sroll << " not found." << endl;
}

/**
 * @brief Updates the name of a student in the records.
 *
 * This method allows the user to update a student's name based on their roll number. It reads
 * from the original file "studentRec.txt", updates the relevant record, and writes the changes
 * to a temporary file. The original file is then replaced with the updated file.
 */
void Menu::updateName() {
    string fname, lname, fnew_fname, fnew_lname, file_context;
    int roll, search_roll;

    ifstream original_file("studentRec.txt");
    ofstream temp_file("temp.txt");

    if (!original_file.is_open() || !temp_file.is_open()) {
        cout << "ERROR: Unable to open file." << endl;
        return;
    }

    cout << "Enter the roll number to update the name: " << endl;
    cin >> search_roll;
    cin.ignore();  // Clear the newline character from the input buffer

    cout << "Enter new first name: " << endl;
    cin >> fnew_fname;
    cin.ignore();  // Clear the newline character from the input buffer

    cout << "Enter new last name: " << endl;
    cin >> fnew_lname;
    cin.ignore();  // Clear the newline character from the input buffer

    while (getline(original_file, file_context)) {
        stringstream line(file_context);
        line >> fname >> lname >> roll;

        if (search_roll == roll) {
            temp_file << fnew_fname << " " << fnew_lname << " " << roll << endl;
        } else {
            temp_file << fname << " " << lname << " " << roll << endl;
        }
    }

    original_file.close();
    temp_file.close();

    remove("studentRec.txt");
    rename("temp.txt", "studentRec.txt");

    cout << "Successfully updated" << endl;
}

/**
 * @brief Removes a student record based on the student's name.
 *
 * This method prompts the user for the name of the student to be removed, reads the file
 * "studentRec.txt", and writes all records except the one with the specified name to a new
 * temporary file. The original file is then replaced with the updated file.
 */
void Menu::removeStudent() {
    string stdname;
    cout << "Enter the name of the student to remove: " << endl;
    cin >> stdname;
    cin.ignore();  // Clear the newline character from the input buffer

    ifstream readfile("studentRec.txt");
    vector<string> lines;
    string line;

    if (!readfile.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    while (getline(readfile, line)) {
        if (line.find(stdname) == string::npos) {
            lines.push_back(line);
        }
    }

    readfile.close();

    ofstream writefile("studentRec.txt");

    if (!writefile.is_open()) {
        cout << "ERROR: Unable to open file in write mode." << endl;
        return;
    }

    for (const auto& updatedRecord : lines) {
        writefile << updatedRecord << endl;
    }
    writefile.close();

    cout << "Student removed" << endl;
}

/**
 * @brief Handles the user's menu choice and executes the corresponding operation.
 *
 * This method uses a switch-case structure to determine which operation to perform based on
 * the user's menu choice, including adding a student, viewing records, searching, updating
 * names, removing students, or exiting the application.
 */
void Menu::handlechoice() {
    switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            viewRecord();
            break;
        case 3:
            search();
            break;
        case 4:
            updateName();
            break;
        case 5:
            removeStudent();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
}


/**
 * @file FileHandling.cpp
 * @brief Implements the FileHandling class for managing file operations related to student data.
 */

#include "filehandling.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/**
 * @brief Parameterized constructor initializes a FileHandling object with a specific file name.
 * @param fname The name of the file to be opened for file operations.
 *
 * This constructor sets up an instance of FileHandling and assigns the provided file name
 * to the `filename` member variable. The file is not opened at this point.
 */
FileHandling::FileHandling(const string& fname) {
    filename = fname;
}

/**
 * @brief Destructor closes any open file streams when the object is destroyed.
 *
 * This ensures that all file resources are properly released. If the file streams are open,
 * they are closed to prevent resource leaks.
 */
FileHandling::~FileHandling() {
    if (filestream.is_open()) {
        filestream.close();
    }
    if (fileRstream.is_open()) {
        fileRstream.close();
    }
}

/**
 * @brief Appends a student's record to the file.
 * @param student The Student object whose record is to be appended.
 *
 * This method opens the file in append mode and writes the student's name and roll number
 * to the file. If the file cannot be opened, an error message is printed to the console.
 */
void FileHandling::appendStudent(const Student& student) {
    filestream.open(filename, ios::app);

    if (filestream.is_open()) {
        filestream << student.getName() << " " << student.getRoll() << endl;
        filestream.close();
    } else {
        cout << "ERROR: unable to open the file" << endl;
    }
}

/**
 * @brief Reads student records from the file and prints them to the console.
 *
 * This method opens the file in read mode and prints each line to the console. If the file
 * cannot be opened, an error message is printed. After reading, the file stream is closed.
 */
void FileHandling::readfile() {
    fileRstream.open(filename, ios::in);

    if (fileRstream.is_open()) {
        string line;
        while (getline(fileRstream, line)) {
            cout << line << endl;
        }
        fileRstream.close();
    } else {
        cout << "ERROR: unable to open the file" << endl;
    }
}


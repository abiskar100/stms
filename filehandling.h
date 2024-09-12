/**
 * @file FileHandling.h
 * @brief Defines the FileHandling class for managing file operations related to student data.
 */

#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <fstream>
#include <string>
#include "student.h"

using namespace std;

/**
 * @class FileHandling
 * @brief Handles file operations for storing and retrieving student data.
 *
 * This class provides functionalities to open a file, append student records to it,
 * and read student records from the file. It utilizes standard file streams from
 * the `<fstream>` library to perform these operations.
 */
class FileHandling {
private:
    string filename; /**< The name of the file used for storing or reading student data. */
    ofstream filestream; /**< Output file stream for writing student data to the file. */
    ifstream fileRstream; /**< Input file stream for reading student data from the file. */

public:
    /**
     * @brief Default constructor initializes a FileHandling object with no specific file.
     *
     * This constructor sets up an instance of FileHandling without opening any file.
     */
    FileHandling();

    /**
     * @brief Parameterized constructor initializes a FileHandling object with a specific file name.
     * @param fname The name of the file to be opened for file operations.
     *
     * This constructor sets up an instance of FileHandling and opens the specified file.
     */
    FileHandling(const string& fname);

    /**
     * @brief Destructor closes any open file streams when the object is destroyed.
     *
     * This ensures that all file resources are properly released when the FileHandling
     * object is no longer needed.
     */
    ~FileHandling();

    /**
     * @brief Appends a student's record to the file.
     * @param student The Student object whose record is to be appended.
     *
     * This method writes the data from the provided Student object to the file.
     * The file is opened in append mode to ensure existing data is preserved.
     */
    void appendStudent(const Student& student);

    /**
     * @brief Reads student records from the file and processes them.
     *
     * This method opens the file for reading and retrieves student data.
     * The data is typically processed or displayed as needed.
     */
    void readfile();
};

#endif // FILEHANDLING_H


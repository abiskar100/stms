/**
 * @file Student.cpp
 * @brief Implements the methods of the Student class for managing student data.
 */

#include <string>
#include <stdexcept>
#include "student.h"
#include "inputvalidation.h"
#include <iostream>

/**
 * @brief Default constructor initializes a Student object with default values.
 *
 * This constructor sets the `name` to an empty string and the `roll` to -1, representing
 * that the student has not been fully initialized.
 */
Student::Student() : name(""), roll(-1) {}

/**
 * @brief Parameterized constructor initializes a Student object with given values.
 * @param n The student's name.
 * @param r The student's roll number.
 *
 * This constructor initializes the `name` and `roll` member variables using the provided
 * values by calling the `setName` and `setRoll` methods to ensure proper validation.
 */
Student::Student(std::string n, int r) {
    setName(n);
    setRoll(r);
}

/**
 * @brief Destructor for the Student class.
 *
 * This destructor is used to clean up resources when a Student object is destroyed.
 */
Student::~Student() {}

/**
 * @brief Sets the student's name.
 * @param n The new name to set for the student.
 *
 * This method updates the `name` member variable with the provided value. It does not
 * perform validation as it assumes the input has already been validated.
 */
void Student::setName(std::string n) {
    name = n;
}

/**
 * @brief Sets the student's roll number.
 * @param r The new roll number to set for the student.
 *
 * This method updates the `roll` member variable with the provided value. It does not
 * perform validation as it assumes the input has already been validated.
 */
void Student::setRoll(int r) {
    roll = r;
}

/**
 * @brief Gets the student's name.
 * @return The student's name.
 *
 * This method returns the current value of the `name` member variable.
 */
std::string Student::getName() const {
    return name;
}

/**
 * @brief Gets the student's roll number.
 * @return The student's roll number.
 *
 * This method returns the current value of the `roll` member variable.
 */
int Student::getRoll() const {
    return roll;
}


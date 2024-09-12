/**
 * @file InputValidation.cpp
 * @brief Implements the checkInput class methods for validating student data.
 */

#include "inputvalidation.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @brief Default constructor initializes a checkInput object with default values.
 *
 * This constructor sets the `name` to an empty string and the `roll` to -1.
 * It is primarily used for initialization purposes.
 */
checkInput::checkInput() : name(""), roll(-1) {}

/**
 * @brief Validates and formats the student name.
 * @param n A reference to the student name string to be validated.
 * @return A validated student name.
 * @throw invalid_argument If the provided name is empty.
 *
 * This method checks if the provided student name is empty. If it is, an exception
 * is thrown with a message indicating that the name cannot be empty. If the name is valid,
 * it is returned.
 */
string checkInput::checkName(string& n) {
    string name;
    name = n;

    if (name.empty()) {
        throw invalid_argument("Name cannot be empty. Please provide a valid Name.");
    }

    return name;
}

/**
 * @brief Validates the roll number.
 * @param r The roll number to be validated.
 * @return A valid roll number.
 * @throw invalid_argument If the provided roll number is less than or equal to 0.
 *
 * This method checks if the provided roll number is greater than 0. If it is not,
 * an exception is thrown with a message indicating that the roll number must be greater than 0.
 * If the roll number is valid, it is returned.
 */
int checkInput::checkRoll(int r) {
    int roll;
    roll = r;

    if (roll <= 0) {
        throw invalid_argument("Roll number cannot be less than or equal to 0. Please provide a valid Roll number.");
    }

    return roll;
}


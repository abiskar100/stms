/**
 * @file InputValidation.h
 * @brief Defines the checkInput class for validating user input related to student data.
 */

#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <string>

/**
 * @class checkInput
 * @brief Provides methods for validating student input data such as name and roll number.
 *
 * This class includes static methods to validate the format and correctness of student
 * names and roll numbers. It does not store state information but offers utility methods
 * for input validation.
 */
class checkInput {
private:
    std::string name; /**< The name of the student (not used in static methods). */
    int roll; /**< The roll number of the student (not used in static methods). */

public:
    /**
     * @brief Default constructor initializes a checkInput object with default values.
     *
     * This constructor sets up an instance of checkInput with default values for the
     * `name` and `roll` member variables. This constructor is not used in the context
     * of static validation methods.
     */
    checkInput();

    /**
     * @brief Validates and formats the student name.
     * @param name A reference to the student name string to be validated.
     * @return A validated and formatted student name.
     *
     * This static method takes a student name as input, validates it, and returns a
     * formatted version of the name. It ensures that the name adheres to expected
     * conventions and is free of invalid characters.
     */
    static std::string checkName(std::string& name);

    /**
     * @brief Validates the roll number.
     * @param roll The roll number to be validated.
     * @return A valid roll number if the input is correct; otherwise, returns a default value.
     *
     * This static method checks if the provided roll number is within a valid range and
     * returns the validated roll number. If the roll number is invalid, it returns a
     * default or corrected value.
     */
    static int checkRoll(int roll);
};

#endif // INPUTVALIDATION_H


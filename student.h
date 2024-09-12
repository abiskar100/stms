/**
 * @file Student.h
 * @brief Defines the Student class for representing a student in the system.
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

/**
 * @class Student
 * @brief Represents a student with a name and roll number.
 *
 * This class provides methods to set and get the student's name and roll number.
 */
class Student {
private:
    std::string name; /**< The student's name. */
    int roll; /**< The student's roll number. */

public:
    /**
     * @brief Default constructor initializes a Student object with default values.
     *
     * This constructor sets the `name` to an empty string and the `roll` to 0.
     */
    Student();

    /**
     * @brief Parameterized constructor initializes a Student object with given values.
     * @param n The student's name.
     * @param r The student's roll number.
     *
     * This constructor initializes the `name` and `roll` member variables with the provided values.
     */
    Student(std::string n, int r);

    /**
     * @brief Destructor for the Student class.
     *
     * This destructor is used to clean up resources when a Student object is destroyed.
     */
    ~Student();

    /**
     * @brief Sets the student's name.
     * @param n The new name to set for the student.
     *
     * This method updates the `name` member variable with the provided value.
     */
    void setName(std::string n);

    /**
     * @brief Sets the student's roll number.
     * @param r The new roll number to set for the student.
     *
     * This method updates the `roll` member variable with the provided value.
     */
    void setRoll(int r);

    /**
     * @brief Gets the student's name.
     * @return The student's name.
     *
     * This method returns the current value of the `name` member variable.
     */
    std::string getName() const;

    /**
     * @brief Gets the student's roll number.
     * @return The student's roll number.
     *
     * This method returns the current value of the `roll` member variable.
     */
    int getRoll() const;
};

#endif // STUDENT_H


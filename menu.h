/**
 * @file Menu.h
 * @brief Defines the Menu class for handling user interactions in a student management system.
 */

#ifndef MENU_H
#define MENU_H

/**
 * @class Menu
 * @brief Manages the user interface for interacting with the student management system.
 *
 * This class provides methods for displaying a menu, handling user choices, and performing
 * various operations related to student management, such as adding, searching, updating,
 * removing students, and viewing records.
 */
class Menu {
private:
    int choice; /**< Stores the user's menu choice. */

public:
    /**
     * @brief Default constructor initializes a Menu object with default values.
     *
     * This constructor sets up an instance of Menu, initializing the `choice` member variable
     * to a default value.
     */
    Menu();

    /**
     * @brief Handles the user's menu choice and executes the corresponding operation.
     *
     * This method processes the user's choice and calls the appropriate method to perform
     * the requested operation, such as adding a student or searching for a record.
     */
    void handlechoice();

    /**
     * @brief Sets the user's menu choice.
     * @param c The user's menu choice.
     *
     * This method updates the `choice` member variable with the user's selected menu option.
     */
    void getchoice(int c);

    /**
     * @brief Displays the menu options to the user.
     *
     * This method prints the available menu options to the console, allowing the user to
     * choose an action to perform.
     */
    void displaymenu();

    /**
     * @brief Adds a new student to the system.
     *
     * This method prompts the user for student details and adds a new student to the system.
     */
    void addStudent();

    /**
     * @brief Searches for a student rec


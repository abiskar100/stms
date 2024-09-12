/**
 * @file main.cpp
 * @brief Contains the main function to run the student management system.
 */

#include <iostream>
#include "menu.h"

using namespace std;

/**
 * @brief The entry point of the program.
 *
 * This function creates a `Menu` object and runs a loop to display the menu, accept user input,
 * and handle menu choices. It continuously prompts the user until the program is exited.
 *
 * @return 0 on successful execution.
 */
int main() {
    int choice; /**< Variable to store the user's menu choice. */
    Menu menu; /**< Menu object to handle menu operations. */

    // Infinite loop to keep displaying the menu and handling choices.
    while (true) {
        menu.displaymenu(); // Display the menu options.
        cin >> choice; // Get the user's choice.
        cin.ignore(); // Ignore any remaining characters in the input buffer.

        menu.getchoice(choice); // Set the choice in the Menu object.
        menu.handlechoice(); // Handle the chosen menu option.
    }

    return 0; // Return 0 to indicate successful execution.
}


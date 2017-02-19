#pragma once

#include "stdafx.h"

class UserInterface
{

public:

    static void clearScreen ();							// clears the screen
    static void pressEnter ();							// waits until the user presses the <ENTER> key
    static void displayMainMenu ();						// displays the main menu containing all the options available to the user
	static void displayInvestmentMenu ();				// offers various options for manipulating investments
	static void displayMortgageMenu ();					// offers various options for manipulating mortgages
	static void displayReportMenu ();					// displays report menu options

}; // class UserInterface

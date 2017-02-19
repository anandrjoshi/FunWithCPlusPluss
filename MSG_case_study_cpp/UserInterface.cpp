#include "UserInterface.h"
#include "Investment.h"
#include "Mortgage.h"
#include "EstimateFundsForWeek.h"
#include "OperatingExpenses.h"
#include "AssetManager.h"

#pragma once


  void UserInterface::clearScreen ()
  //
  // clears the screen
  //
  {

	//
	// implementation-dependent code to clear the screen should replace
	// the code given below
	//

	for (int i = 0; i < 40; i++)
		cout << endl;

  }  // clearScreen ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void UserInterface::pressEnter()
  //
  // waits until the user presses the <enter> key
  //
  {

	char ch;  // dummy variable used to induce keyboard input

	fflush (stdin);
	cout << endl;
	ch = getchar ();

  } // pressEnter ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void UserInterface::displayMainMenu ()
  //
  // displays main menu that drives product, offering the user choice
  // of investment data, mortgage data, operating expenses, or reports; the appropriate
  // method is then called, namely displayInvestmentMenu, displayMortgageMenu,
  // updateAnnualOperatingExpenses, or displayReportMenu, respectively.
  // The user may also choose to quit
  //
  {
  
	bool done = false;	// terminates while loop
    int  choice;        // user's choice

    while (!done)
    {

	  clearScreen ();

	  cout << "\t               MAIN MENU\n\n";
	  cout << "\t  MARTHA STOCKTON GREENGAGE FOUNDATION\n\n";
	  cout << "\t            1. Estimate Funds for Week\n";
	  cout << "\t            2. Manage an Investment\n";
	  cout << "\t            3. Manage a Mortgage\n";
	  cout << "\t            4. Update Operating Expenses\n";
	  cout << "\t            5. Produce Reports\n";
	  cout << "\t            6. Quit\n\n";
	  cout << "Enter your choice and press <ENTER>: ";

      cin >> choice;

	  switch (choice)
	  {

        case 1:
			EstimateFundsForWeek::compute();
		  break;

        case 2:
		  displayInvestmentMenu ();
		  break;

	    case 3:
		  displayMortgageMenu ();
		  break;

	    case 4:
		  (new OperatingExpenses)->updateAnnualOperatingExpenses ();
		  break;

	    case 5:
	      displayReportMenu ();
		  break;

        case 6:
          done = true;
		  break;

        default:
		  cout << "\n\nNot a valid choice\n";
          pressEnter();
		  break;

	  }

    }

  }  // displayMainMenu ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void UserInterface::displayInvestmentMenu ()
  //
  // displays investment, offering the user the choice of adding, modifying, 
  // or deleting an investment; the appropriate method is then called.  
  // The user may also choose to return to main menu.
  //
  {

	bool	     done = false;			                  // terminates while loop
    int          choice;				                  // user's choice
    Investment*  investment = new Investment ();	      // investment record

    while (!done)
    {
	
	  clearScreen ();

      cout << "\t               INVESTMENTS\n\n";
	  cout << "\t  MARTHA STOCKTON GREENGAGE FOUNDATION\n\n";
	  cout << "\t            1. Add an investment\n";
      cout << "\t            2. Modify an investment\n";
	  cout << "\t            3. Delete an investment\n";
	  cout << "\t            4. Exit to main menu\n\n";
	  cout << "Enter your choice and press <ENTER>: ";

      cin >> choice;

	  switch (choice)
	  {

	    case 1:
		  clearScreen ();
		  investment->addAsset ();
		  break;

	    case 2:
		  clearScreen ();
		  AssetManager::manageInvestment ();
		  break;

        case 3:
		  clearScreen ();
		  investment->deleteAsset ();
		  break;

        case 4:
  		  done = true;
		  break;

	    default:
		  cout << "\n\nNot a valid choice\n";
          pressEnter();
		  break;

  	  }

    }

  }  // displayInvestmentMenu ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void UserInterface::displayMortgageMenu ()
  //
  // displays mortgage menu, offering the user the choice of adding, modifying, 
  // or deleting a mortgage; the appropriate method is then called. The user 
  // may also choose to return to main menu.
  //
  {
    bool	  done = false;			        // terminates while-loop
    int       choice;	                    // user's choice
    Mortgage*  mortgage = new Mortgage ();	// mortgage record

    while (!done)
    {

	  clearScreen ();

	  cout << "\t                MORTGAGES\n\n";
	  cout << "\t  MARTHA STOCKTON GREENGAGE FOUNDATION\n\n";
	  cout << "\t            1. Add a mortgage\n";
	  cout << "\t            2. Modify a mortgage\n";
	  cout << "\t            3. Delete a mortgage\n";
	  cout << "\t            4. Exit to main menu\n\n";
	  cout << "Enter your choice and press <ENTER>: ";

	  cin >> choice;

      switch (choice)
      {

	    case 1:
	      clearScreen ();
		  mortgage->addAsset ();
		  break;

		case 2:
	      clearScreen ();
		  AssetManager::manageMortgage ();
	      break;

		case 3:
		  clearScreen ();
		  mortgage->deleteAsset ();
		  break;

		case 4:
		  done = true;
		  break;

		default:
		    cout << "\n\nNot a valid choice\n";
            pressEnter();
		    break;

	  }

    }

  }  // displayMortgageMenu ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void UserInterface::displayReportMenu ()
  //
  // displays report menu, offering the user the choice of investment report, 
  // mortgage report, or funds availability report;  the appropriate method is then called.
  // The user may also choose to return to main menu.
  //
  {
    bool	done = false;	      // terminates while loop
    int     choice;               // user's choice

    while (!done)
    {

	  clearScreen ();

	  cout << "\t                 REPORTS\n\n";
	  cout << "\t  MARTHA STOCKTON GREENGAGE FOUNDATION\n\n";
	  cout << "\t            1. List of investments\n";
	  cout << "\t            2. List of mortgages\n";
	  cout << "\t            3. Exit to main menu\n\n";
	  cout << "Enter your choice and press <ENTER>: ";

      cin >> choice;

	  switch (choice)
	  {

		case 1:
		  Investment::printAll ();
		  break;

		case 2:
          Mortgage::printAll ();
		  break;

		case 3:
		  done = true;
		  break;

		default:
		  cout << "\n\nNot a valid choice\n";
          pressEnter();
		  break;

		}

	  }

    }  // displayReportMenu ()



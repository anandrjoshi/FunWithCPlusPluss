#include "AssetManager.h"

  void AssetManager::manageInvestment ()
  //
  // modifies an investment
  //
  {

	char	      option = '0';					    // # of field to be changed
	bool	      done = false;					    // terminates while-loop
	bool	      found = false;			        // tells if investment is found
	string        input;                            // buffer for line of characters
	char	      choice;	                        // user's choice
    Investment*   investment = new Investment ();   // investment to be modified

	while (!found && !done)
	{
   
		cout << "Please enter the number of the investment to be updated (12 digits): ";

        cin >> input;

	    found = investment->find (input);

	    if (!found)
	    {

		  cout << "Investment " << input << " was not found.\n";
		  cout << "Would you like to enter another investment id (y/n)? ";

          cin >> choice;

		  if (choice == 'n')
		    done = true;
	
        }
	}

	if (!found)
	   return;

	while (!done)
	{

	  UserInterface::clearScreen ();

	  cout << "\t           UPDATE INVESTMENTS\n\n";
	  cout << "\t MARTHA STOCKTON GREENGAGE FOUNDATION\n\n";
	  cout << "\t        1. Update investment name\n";
	  cout << "\t        2. Update expected return\n";
	  cout << "\t        3. Exit to investment menu\n\n";
	  cout << "Enter your choice and press <ENTER>: ";

	  cin >> choice;

      switch (choice)
      {

	    case '1':
		  investment->updateInvestmentName();
		  break;

		case '2':
		  investment->updateExpectedReturn();
		  break;

		case '3':
		  done = true;
		  break;

		default:
		  cout << "\n\nNot a valid choice\n\n";
		  UserInterface::pressEnter();
		  break;

	  }

      if (!done)
	  {

         cout << endl << endl;
	     investment->print ();
         cout << endl << endl << "Press <ENTER> to return to previous menu...";
		 UserInterface::pressEnter();

      }

	}

	investment->save ();
 
  }  // manageInvestment ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void AssetManager::manageMortgage ()
  //
  // modifies a mortgage
  //
  {

	char	      option = '0';					    // # of field to be changed
	bool	      done = false;					    // terminates while-loop
	bool	      found = false;			        // tells if investment is found
	string        input;                            // buffer for line of characters
	char	      choice;	                        // user's choice
    Mortgage*	  mortgage = new Mortgage ();	    // mortgage to be modified

	while (!found && !done)
	{
   
		cout << "Please enter the number of the mortgage to be updated (12 digits): ";

        cin >> input;

	    found = mortgage->find (input);

	    if (!found)
	    {

		  cout << "Mortgage " << input << " was not found.\n";
		  cout << "Would you like to enter another investment id (y/n)?";

          cin >> choice;

		  if (choice == 'n')
		    done = true;
	
        }
	}

	if (!found)
	   return;

	while (!done)
	{

	  UserInterface::clearScreen ();

      cout << "\t           UPDATE MORTGAGES\n\n";
	  cout << "\t MARTHA STOCKTON GREENGAGE FOUNDATION\n\n";
	  cout << "\t        1. Update mortgagee name\n";
	  cout << "\t        2. Update price of home\n";
	  cout << "\t        3. Update date mortgage issued\n";
	  cout << "\t        4. Update current weekly income\n";
	  cout << "\t        5. Update property tax\n";
	  cout << "\t        6. Update insurance premium\n";
	  cout << "\t        7. Update mortgage balance\n";
	  cout << "\t        8. Exit to mortgage menu\n\n";
	  cout << "Enter your choice and press <ENTER>: ";

      cin >> choice;

	  switch (choice)
	  {

	     case '1':
		   mortgage->updateMortgageeName();
		   break;

	     case '2':
			mortgage->updatePrice();
			break;

		 case '3':
			mortgage->updateDate();
		    break;

		 case '4':
			mortgage->updateWeeklyIncome();
			break;

		 case '5':
			mortgage->updatePropertyTax();
			break;

		 case '6':
			mortgage->updateInsurancePremium();
			break;

		 case '7':
			mortgage->updateBalance();
			break;

		 case '8':
			done = true;
			break;

         default:
			cout << "\n\nNot a valid choice\n";
			UserInterface::pressEnter();
			break;
		
	  }

      if (!done)
	  {

         cout << endl << endl;
	     mortgage->print ();
         cout << endl << endl << "Press <ENTER> to return to previous menu...";
		 UserInterface::pressEnter();
			
	  }
		   
	}

	mortgage->save ();

  }  // manageMortgage ()

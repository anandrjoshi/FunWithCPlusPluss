#include "Asset.h"

  void Asset::deleteAsset ()
  //
  // deletes an Asset
  //
  {

	string        input;			    // buffer for line of characters
	bool		  done = false;	        // tells when user is done entering information
	bool	      found = false;	    // tells when an investment has been found
	char          choice;               // for storing user's response

	while (!found && !done)
	{

	  cout << "Please enter the number of the asset to be deleted (12 digits): ";

      cin >> input;

	  found = find (input);

	  if (!found)
	  {

		cout << "Asset " << input << " was not found.\n";
        cout << "Would you like to enter another number (y/n)? ";

        cin >> choice;

	    if (choice == 'n')
	      done = true;
	    
	  }

	}

    if (!found)
      return;
  
	performDeletion ();
    cout << "\nThe record has been deleted." << endl << endl;
	cout << "Press <ENTER> to return to previous menu...";
    UserInterface::pressEnter();
    
  }  // deleteAsset ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Asset::addAsset ()
  //
  // adds a new investment/mortgage
  //
  {

	obtainNewData ();
	save ();
	cout << "\nThe following record was inserted:" << endl << endl;
	print ();
	cout << endl << endl << "Press <ENTER> to return to previous menu...";
	UserInterface::pressEnter();

  }  // addAsset ()

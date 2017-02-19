#include "MortgageReport.h"

  void MortgageReport::printReport ()
  //
  // generates the mortgage report
  //
  {

	ifstream inFile;								// stream object used for file input 
	int   i = 0;									// used for screen clearing
    Mortgage* tempMortgage = new Mortgage ();		// temporary mortgage object for reporting

	inFile.open ("mortgage.dat", ios::in);

	if (inFile)
	{

	  while (!inFile.eof ())
	  {
	    //
	    // pause the screen after every four mortgages
	    //
	    if (((i % 4) == 0) && (i != 0))
	    {

    		cout << endl << endl;
	    	cout << "Press <ENTER> to view the next screen...";
			UserInterface::pressEnter ();

	    }

	    //
	    // display a header message after every fourth mortgage
	    //
	    if ((i % 4) == 0)
	    {

			UserInterface::clearScreen ();

     		cout << endl << endl;
	    	cout << "\t       Martha Stockton Greengage Foundation\n";
    		cout << "\t                 MORTGAGE REPORT\n\n";

	    }

        cout << "-----------------------------------------------------------------------------" << endl;

	    tempMortgage->read (inFile);

	    tempMortgage->print ();

	    i++;

	  }

	  inFile.close ();

	}
	else
	  cout << "\nNo mortgages currently exist.\n";

	cout << endl << endl << "Press <ENTER> to return to main menu...";
	UserInterface::pressEnter ();

  }  // printReport ()



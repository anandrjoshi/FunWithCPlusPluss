#include "InvestmentReport.h"

  void InvestmentReport::printReport ()
  //
  // generates the investment report
  //
  {

	ifstream inFile;								// stream object used for file input 
	int   i = 0;									// used for screen clearing
    Investment* tempInvestment = new Investment ();	// temporary investment object for reporting

	inFile.open ("investment.dat");

	if (inFile)
	{

	  while (!inFile.eof ())
	  {
	    //
	    // pause the screen after every four investments
	    //
	    if (((i % 4) == 0) && (i != 0))
	    {

    		cout << endl << endl;
	    	cout << "Press <ENTER> to view the next screen...";
			UserInterface::pressEnter ();

	    }

	    //
	    // display a header message after every fourth investment
	    //
	    if ((i % 4) == 0)
	    {

			UserInterface::clearScreen ();

     		cout << endl << endl;
	    	cout << "\t       Martha Stockton Greengage Foundation\n";
    		cout << "\t                 INVESTMENT REPORT\n\n";

	    }

        cout << "-----------------------------------------------------------------------------\n";

	    tempInvestment->read (inFile);

	    tempInvestment->print ();

	    i++;

	  }

	  inFile.close ();

	}
	else
	  cout << "\nNo investments currently exist.\n";

	cout << endl << endl << "Press <ENTER> to return to main menu...";
	UserInterface::pressEnter ();

  }  // printReport ()


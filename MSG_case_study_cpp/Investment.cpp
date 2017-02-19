#include "Investment.h"

  double Investment::totalWeeklyReturnOnInvestment ()
  //
  // reads records from the investments file and computes totalAnnualReturn 
  // by summing each expectedAnnualReturn on investments and dividing by WEEKS_IN_YEAR
  //
  {

	ifstream inFile;								// stream object used for file input 
	double totalAnnualReturn = 0.0;					// total annual return on investments

	inFile.open ("investment.dat");

	if (inFile)
	{

	  while (!inFile.eof ())
	  {

	      read (inFile);
	      totalAnnualReturn += expectedAnnualReturn;

      }

	  inFile.close ();

	}

	return (totalAnnualReturn / (double) 52.0);

  }  // totalWeeklyReturnOnInvestment ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  bool Investment::find (string findInvestmentID)
  //
  // find locates a given investment record if it exists.
  // Returns true if the investment is located, otherwise false
  //
  {

	ifstream inFile;			// stream object used for file input 
	bool	 found = false;		// result of comparison

	inFile.open ("investment.dat");

	if (inFile)
	{

	  while (!inFile.eof () && !found)
	  {

        read (inFile);

        if (assetNumber.compare (findInvestmentID) == 0)
		  found = true;
      }

	  inFile.close ();

    }

    return found;

  }  // find ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Investment::read (ifstream& fileName)
  //
  // reads an investment record from fileName.
  // Assumes that the existence of fileName has already been established
  //
  {

    fileName >> assetNumber;
	fileName >> investmentName;
    fileName >> expectedAnnualReturn;
	fileName >> expectedAnnualReturnUpdated;

  }  // read ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Investment::write (ofstream& fileName, bool addNL)
  //
  // writes an investment record to fileName
  //
  {

    if(addNL)
	  fileName << endl;

    fileName << assetNumber << endl;
	fileName << investmentName << endl;
	fileName << expectedAnnualReturn << endl;
	fileName << expectedAnnualReturnUpdated;

  }  // write ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Investment::print ()
  //
  // displays the contents of an investment object
  //
  {
      cout << "Investment ID: " << assetNumber;
      cout << "\tInvestment Name: " << investmentName << endl;
      cout << "Expected return: " << expectedAnnualReturn << endl;
      cout << "Date expected return was updated: " << expectedAnnualReturnUpdated << endl;

  }  // print ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Investment::printAll ()
  //
  // displays a list of all investment objects.
  //
  {
	  InvestmentReport::printReport();

  }  // printAll ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Investment::obtainNewData ()
  //
  // Reads a new investment record by calling readData
  //
  {

    readInvestmentData ();

  }  // obtainNewData ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Investment::performDeletion ()
  //
  // performs the actual deletion of an investment record from a file
  //
  {

	ifstream inFile;							// stream object used for file input 
	ofstream tmpFile;							// stream object used for file copying
	Investment* investment = new Investment ();	// record to be checked
    bool multipleWrite = false;

	inFile.open ("investment.dat");

	if (!inFile)
	  return;

	tmpFile.open ("investment.tmp");

    while (!inFile.eof ())
    {

	  investment->read (inFile);

      if (assetNumber.compare (investment->getAssetNumber ()) != 0)
	  {

		  investment->write (tmpFile, multipleWrite);
	      multipleWrite = true;

	  }

	}

	inFile.close ();
	tmpFile.close ();

	remove("investment.dat");

	if(multipleWrite)
	  rename("investment.tmp", "investment.dat");
	else
	  remove("investment.tmp");

  }  // performDeletion ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Investment::save ()
  //
  // saves an individual investment record into a file, ordered by investmentID
  //
  {

	ifstream	 inFile;							// stream object used for file input 
	ofstream	 newFile;							// stream object used for file copying
	Investment*  investment = new Investment ();	// record read, then written
	int			 compareInvestments;				// to find correct place for the new investment
	bool		 found = false;						// terminates while-loop
    bool         multipleWrite = false;

	inFile.open ("investment.dat");
	newFile.open ("investment.tmp");

	if (!inFile)
	  write (newFile, multipleWrite);
	else
	{

	  while (!inFile.eof ())
      {

        investment->read (inFile);

        compareInvestments = assetNumber.compare (investment->getAssetNumber());

	    if ((!found) && (compareInvestments < 0))
	    {

		  write (newFile, multipleWrite);
		  multipleWrite = true;
		  investment->write (newFile, multipleWrite);
		  found = true;

	    }
	    else if (compareInvestments == 0)
	    {

		  write (newFile, multipleWrite);
		  multipleWrite = true;
		  found = true;

	     }
		 else
		 {

		  investment->write (newFile, multipleWrite);
		  multipleWrite = true;

		}
	
	  }  // while

	  if (!found) 
		write (newFile, multipleWrite);

	  inFile.close ();
	  newFile.close ();

	}  // else

	newFile.close ();

	remove("investment.dat");
	rename("investment.tmp", "investment.dat");

  }  // save ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Investment::readInvestmentData ()
  //
  // readData obtains input data for all fields of an investment record.
  //
  {

	bool  valid = false;      		// used to validate length of ID

	while (!valid)
    {

	  cout << "Enter investment number (12 digits): ";
      cin >> assetNumber;
      valid = (assetNumber.length () <= 12);

      if (!valid)
		cout << "\n\nThe investment number must be 12 digits long." << endl;

     }

	 cout << "Enter investment name: ";
     cin  >> investmentName;

     cout << "Enter expected annual return: ";
	 cin  >> expectedAnnualReturn;

     cout << "Enter today's date (mm/dd/yyyy): ";
     cin  >> expectedAnnualReturnUpdated;

  }  // readData ()
 

//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Investment::updateInvestmentName ()
  {

    cout << "\n\nOld investment name: " << investmentName << endl;
    cout << "Enter new investment name: ";
    cin  >> investmentName;

  } // updateInvestmentName ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Investment::updateExpectedReturn ()
  {

    cout << "\n\nOld expected return: " << expectedAnnualReturn << endl;
    cout << "Enter new expected return: ";
    cin  >> expectedAnnualReturn;

    cout << "Enter today's date (mm/dd/yyyy): ";
    cin  >> expectedAnnualReturnUpdated;

  } // updateExpectedReturn ()



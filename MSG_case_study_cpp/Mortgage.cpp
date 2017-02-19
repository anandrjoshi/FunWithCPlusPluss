#include "Mortgage.h"

  int    Mortgage::NUMBER_OF_MORTGAGE_PAYMENTS = 1560;
  double Mortgage::MAXIMUM_PERC_OF_INCOME = (double) 0.28;
  double Mortgage::WEEKS_IN_YEAR = (double) 52.0;
  double Mortgage::INTEREST_RATE = (double) 0.04;

  double Mortgage::totalWeeklyNetPayments ()
  //
  // Computes the net total weekly payments made by the mortgagees, that is,
  // the expected total weekly mortgage amount less the expected total weekly grants
  //
  {

	  ifstream inFile;										// stream object used for file input	 
      double expectedTotalWeeklyMortgages = (double) 0.0;	// expected total weekly mortgages
      double expectedTotalWeeklyGrants = (double) 0.0;		// expected total weekly grants
      double capitalRepayment = (double) 0.0;				// capital repayment
      double interestPayment = (double) 0.0;				// interest payment
      double escrowPayment = (double) 0.0;					// escrow payment
      double tempMortgage = (double) 0.0;					// temporary mortgage payment
      double maximumPermittedMortgagePayment = (double) 0.0; // maximum a family is allowed to pay

      inFile.open ("mortgage.dat");

	  if (inFile)
	  {

	    while (!inFile.eof ())
	    {

           read (inFile);

           capitalRepayment = price / NUMBER_OF_MORTGAGE_PAYMENTS;
           interestPayment = mortgageBalance * INTEREST_RATE / WEEKS_IN_YEAR ;
           escrowPayment = (annualPropertyTax + annualInsurancePremium) / WEEKS_IN_YEAR;
           tempMortgage = capitalRepayment + interestPayment + escrowPayment;
           expectedTotalWeeklyMortgages += tempMortgage;
           maximumPermittedMortgagePayment = currentWeeklyIncome * MAXIMUM_PERC_OF_INCOME;

	       if (tempMortgage > maximumPermittedMortgagePayment)
		      expectedTotalWeeklyGrants += tempMortgage - maximumPermittedMortgagePayment;
	    }

	    inFile.close ();

      }	// if

      return (expectedTotalWeeklyMortgages - expectedTotalWeeklyGrants);

  }  // totalWeeklyNetPayments ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  bool Mortgage::find (string findMortgageID)
  //
  // find locates a given mortgage record if it exists.
  // Returns true if the mortgage is located, otherwise false.
  //
  {

 	ifstream inFile;			// stream object used for file input 
	bool	 found = false;		// result of comparison

	inFile.open ("mortgage.dat");

	if (inFile)
	{

	  while (!inFile.eof () && !found)
	  {

        read (inFile);

        if (assetNumber.compare (findMortgageID) == 0)
		  found = true;
      }

	  inFile.close ();

    }

    return found;

  }  // find ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Mortgage::read (ifstream& fileName)
  //
  // reads a mortgage record from fileName
  // Assumes that the existence of fileName has already been established
  //
  {

	fileName >> assetNumber;
	fileName >> mortgageeName;
    fileName >> price;
	fileName >> dateMortgageIssued;
	fileName >> currentWeeklyIncome;
	fileName >> weeklyIncomeUpdated;
	fileName >> annualPropertyTax;
	fileName >> annualInsurancePremium;
	fileName >> mortgageBalance;

  }  // read ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Mortgage::write (ofstream& fileName, bool addNL)
  //
  // writes a mortgage record to fileName
  //
  {

    if(addNL)
	  fileName << endl;

	fileName << assetNumber << endl;
	fileName << mortgageeName << endl;
    fileName << price << endl;
	fileName << dateMortgageIssued << endl;
	fileName << currentWeeklyIncome << endl;
	fileName << weeklyIncomeUpdated << endl;
	fileName << annualPropertyTax << endl;
	fileName << annualInsurancePremium << endl;
	fileName << mortgageBalance;

  }  // write ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Mortgage::print ()
  //
  // displays the names of the fields of a mortgage and their values.
  //
  {

    cout << "Mortgage ID: " << assetNumber << "\tMortgagee Name: " << mortgageeName << "\tPrice: " << price << endl;
    cout << "Date mortgage issued:       " << dateMortgageIssued << endl;
    cout << "Date weekly income updated: " << weeklyIncomeUpdated << endl;
    cout << "Current weekly income: " << currentWeeklyIncome << endl;
    cout << "Annual property tax:   " << annualPropertyTax << endl;
    cout << "Annual insurance premium: " << annualInsurancePremium << endl;
    cout << "Mortgage balance: " << mortgageBalance << endl;

  }  // print ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Mortgage::printAll ()
  //
  // displays a list of all mortgage objects
  //
  {
  
	 MortgageReport::printReport();

  }  // printAll ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Mortgage::obtainNewData ()
  //
  // obtainNewData reads a new mortgage record by calling readMortgageData
  //
  {

	 readMortgageData ();

  }  // obtainNewData ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Mortgage::performDeletion ()
  //
  // performDeletion performs the actual deletion of a mortgage record from a file
  //
  {

 	ifstream  inFile;							// stream object used for file input 
	ofstream  tmpFile;							// stream object used for file copying
	Mortgage* mortgage = new Mortgage ();		// record to be checked
    bool      multipleWrite = false;

	inFile.open ("mortgage.dat");

	if (!inFile)
	  return;

	tmpFile.open ("mortgage.tmp");

    while (!inFile.eof ())
    {

	  mortgage->read (inFile);

      if (assetNumber.compare (mortgage->getAssetNumber ()) != 0)
	  {

	      mortgage->write (tmpFile, multipleWrite);
	      multipleWrite = true;

	  }

	}

	inFile.close ();
	tmpFile.close ();

	if(multipleWrite)
	  rename("mortgage.tmp", "mortgage.dat");
	else
	  remove("mortgage.tmp");

  }  // performDeletion ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Mortgage::save ()
  //
  // saves an individual mortgage record into a file, ordered by mortgageID
  //
  {
 
	ifstream	 inFile;							// stream object used for file input 
	ofstream	 newFile;							// stream object used for file copying
	Mortgage*	 mortgage = new Mortgage ();		// record read, then written
	int			 compareMortgages;					// to find correct place for the new mortgage
	bool		 found = false;						// terminates while-loop
    bool         multipleWrite = false;

	inFile.open ("mortgage.dat");
	newFile.open ("mortgage.tmp");

	if (!inFile)
	  write (newFile, multipleWrite);
	else
	{

	  while (!inFile.eof ())
      {

        mortgage->read (inFile);

        compareMortgages = assetNumber.compare (mortgage->getAssetNumber());

	    if ((!found) && (compareMortgages < 0))
	    {

		  write (newFile, multipleWrite);
		  multipleWrite = true;
		  mortgage->write (newFile, multipleWrite);
		  found = true;

	    }
	    else if (compareMortgages == 0)
	    {

		  write (newFile, multipleWrite);
		  multipleWrite = true;
		  found = true;

	     }
		 else
		 {

		  mortgage->write (newFile, multipleWrite);
		  multipleWrite = true;

		}
	
	  }  // while

	  if (!found) 
		write (newFile, multipleWrite);

	  inFile.close ();
	  newFile.close ();

	}  // else

	newFile.close ();

	remove("mortgage.dat");
	rename("mortgage.tmp", "mortgage.dat");

  }  // save ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Mortgage::readMortgageData ()
  //
  // readMortgageData asks user to enter information for the fields of a mortgage
  //
  {

	bool  valid = false;      		// used to validate length of ID

	while (!valid)
    {

	  cout << "Enter investment number (12 digits): ";
      cin >> assetNumber;
      valid = (assetNumber.length () <= 12);

      if (!valid)
		cout << "\n\nThe mortgage number must be 12 digits long." << endl;

     }

	cout << "Enter mortgagee name: ";
	cin >> mortgageeName;

	cout << "Enter price of home: ";
	cin >> price;

	cout << "Enter date mortgage was issued (mm/dd/yy): ";
	cin >> dateMortgageIssued;

	cout << "Enter current weekly income: ";
	cin >> currentWeeklyIncome;

    cout << "Enter today's date (mm/dd/yy): ";
    cin >> weeklyIncomeUpdated;

    cout << "Enter annual property tax: ";
	cin >> annualPropertyTax;

	cout << "Enter annual insurance premium: ";
	cin >> annualInsurancePremium;

	cout << "Enter mortgage balance: ";
	cin >> mortgageBalance;

  }  // readMortgageData ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Mortgage::updateMortgageeName ()
  {

    cout << "\n\nOld mortgagee name: " << mortgageeName;
    cout << "Enter new mortgagee name: ";
    cin >> mortgageeName;

  } // updateMortgageeName ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Mortgage::updatePrice ()
  {

    cout << "\n\nOld price: " << price << endl;
    cout << "Enter new price of home: ";
    cin >> price;

  } // updatePrice ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Mortgage::updateDate ()
  {

    cout << "\n\nOld mortgage date: " << dateMortgageIssued << endl;
    cout << "Enter date the mortgage was issued (mm/dd/yy): ";
    cin >> dateMortgageIssued;

  } // updateDate ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Mortgage::updateWeeklyIncome ()
  {

    cout << "\n\nOld weekly income: " << currentWeeklyIncome << endl;
    cout << "Enter current weekly income: ";
    cin >> currentWeeklyIncome;

    cout << "Enter today's date (mm/dd/yy): ";
    cin >> weeklyIncomeUpdated;

  } // updateWeeklyIncome ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Mortgage::updatePropertyTax ()
  {

    cout << "\n\nOld annual property tax: " << annualPropertyTax << endl;
    cout << "Enter new annual property tax: ";
    cin  >> annualPropertyTax;

  } // updatePropertyTax ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Mortgage::updateInsurancePremium ()
  {

    cout << "\n\nOld insurance premium: " << annualInsurancePremium << endl;
    cout << "Enter new annual insurance premium: ";
	cin  >> annualInsurancePremium;

  } // updateInsurancePremium ()


//----------------------------------------------------------------------------------------------------------------------------------------------------


  void Mortgage::updateBalance ()
  {

    cout << "\n\nOld mortgagee balance: " << mortgageBalance << endl;
    cout << "Enter new mortgage balance: ";
    cin  >> mortgageBalance;

  } // updateBalance ()

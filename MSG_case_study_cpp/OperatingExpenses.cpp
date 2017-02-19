#include "OperatingExpenses.h"

  double OperatingExpenses::estimatedAnnualOperatingExpenses;
  double OperatingExpenses::estimatedFundsForWeek; 

  void OperatingExpenses::setAnnualOperatingExpenses (double newAnnualOperatingExpenses)
  //
  // validates new annual operating expenses, writes data to opexp.dat
  // for use in the current execution
  //
  {

	if (newAnnualOperatingExpenses >= 0.0)
	{
		
	  ofstream operatingExpensesFile;                // file containing annual operating expenses

	  operatingExpensesFile.open ("opexp.dat");   
      operatingExpensesFile << newAnnualOperatingExpenses << endl;
	  operatingExpensesFile.close ();

	  estimatedAnnualOperatingExpenses = newAnnualOperatingExpenses;

	}

  }  // setAnnualOperatingExpenses ()


//----------------------------------------------------------------------------------------------------------------------------------------------


  void OperatingExpenses::updateAnnualOperatingExpenses ()
  //
  // obtains the new annual operating expenses from user, validates,
  // and then writes the data to the operating expenses file
  //
  {
    
	double  newAnnualOperatingExpenses;   // value of new annual operating expense

	UserInterface::clearScreen ();

	cout << "\nEnter new annual operating expenses: ";
	cin >> newAnnualOperatingExpenses;

	setAnnualOperatingExpenses (newAnnualOperatingExpenses);

  }  // updateAnnualOperatingExpenses ()


//----------------------------------------------------------------------------------------------------------------------------------------------


  void OperatingExpenses::setEstimatedFundsForWeek(double e)
  //
  //  display report for each change of estimate
  //
  {

    estimatedFundsForWeek = e;
	EstimatedFundsReport::printReport();

  } // setEstimatedFundsForWeek ()


//----------------------------------------------------------------------------------------------------------------------------------------------


  void OperatingExpenses::initializeExpenses ()
  //
  // initializeApplication initializes annual operating expenses from file opexp.dat, if it exists.
  // If file does not exist, annual operating expenses are set to 0.0 by calling setAnnualOperatingExpenses
  //
  {
   
	ifstream  operatingExpensesFile;	// file containing annual operating expenses
	
	operatingExpensesFile.open ("opexp.dat");  

	if (!operatingExpensesFile)
      setAnnualOperatingExpenses (0.0);
	else
      operatingExpensesFile >> estimatedAnnualOperatingExpenses;

    operatingExpensesFile.close ();

  }  // initializeApplication ()


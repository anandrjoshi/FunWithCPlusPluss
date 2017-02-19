#include "EstimatedFundsReport.h"

  void EstimatedFundsReport::printReport ()
  //
  // computes total funds available for purchasing new mortgages in the current week.
  //
  {
 
	cout << endl << endl;
    cout << "Funds available: " << (new OperatingExpenses)->getEstimatedFundsForWeek() << endl << endl;
	cout << "Press <ENTER> to return to main menu...";
	UserInterface::pressEnter();

  }  // printReport ()

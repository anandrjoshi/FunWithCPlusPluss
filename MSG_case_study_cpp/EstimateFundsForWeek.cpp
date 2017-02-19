#include "EstimateFundsForWeek.h"
#include "OperatingExpenses.h"
#include "Investment.h"
#include "Mortgage.h"

  void EstimateFundsForWeek::compute()
  //
  // computes the estimated funds available for week
  //
  {

	double expectedWeeklyInvestmentReturn = 0.0;		// expected weekly investment return
	double expectedTotalWeeklyNetPayments = 0.0;		// expected total mortgage payments less total weekly grants
    double estimatedFunds = 0.0;
	OperatingExpenses* op = new OperatingExpenses();

	Investment*  inv = new Investment ();			// investment record
	Mortgage*    mort = new Mortgage ();			// mortgage record

	expectedWeeklyInvestmentReturn = inv->totalWeeklyReturnOnInvestment ();
	expectedTotalWeeklyNetPayments = mort->totalWeeklyNetPayments ();

    estimatedFunds = (expectedWeeklyInvestmentReturn - (op->getAnnualOperatingExpenses () / 52.0) + expectedTotalWeeklyNetPayments);

    op->setEstimatedFundsForWeek(estimatedFunds);

  }  // compute ()

#pragma once

#include "stdafx.h"
#include "UserInterface.h"
#include "EstimatedFundsReport.h"

class OperatingExpenses
{

public:

  // getter-setter methods for OperatingExpenses
  double getAnnualOperatingExpenses () { return estimatedAnnualOperatingExpenses; }
  double getEstimatedFundsForWeek () { return estimatedFundsForWeek; }
  void setEstimatedFundsForWeek (double e);	

  void setAnnualOperatingExpenses (double newAnnualOperatingExpenses);  // validates new annual operating expenses, writes data to opexp.dat
  void updateAnnualOperatingExpenses ();							    // obtains the new annual operating expenses from user
  void initializeExpenses ();										    // initializes annual operating expenses from file opexp.dat, if it exists

private:

  static double estimatedAnnualOperatingExpenses;   	// annual operating expenses
  static double estimatedFundsForWeek;					// weekly funds available

}; // class OperatingExpenses

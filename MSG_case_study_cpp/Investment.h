#pragma once

#include "stdafx.h"
#include "Asset.h"
#include "InvestmentReport.h"

class Investment : public Asset
{

public:

  // getter-setter methods for Investment
  string getInvestmentName () { return investmentName; }
  void setInvestmentName (string n) { investmentName = n; }
  double getExpectedAnnualReturn () { return expectedAnnualReturn; }
  void setExpectedAnnualReturn (double r) { expectedAnnualReturn = r; }
  string getExpectedAnnualReturnUpdated () { return expectedAnnualReturnUpdated; }
  void setExpectedAnnualReturnUpdated (string d) { expectedAnnualReturnUpdated = d; }

  double totalWeeklyReturnOnInvestment ();
  bool find (string findInvestmentID);			// returns true if investment exists
  void read (ifstream& fileName);				// reads an investment record from fileName
  void write (ofstream& fileName, bool addNL);	// writes an investment record to fileName
  void print ();								// displays the contents of an investment object
  static void printAll ();						// displays a list of all investment objects
  void obtainNewData ();						// reads a new investment record by calling readInvestmentData
  void performDeletion ();						// performs the actual deletion of an investment record from a file
  void save ();									// saves an individual investment record into a file, ordered by investmentID
  void readInvestmentData ();					// obtains input data for all fields of an investment record
  void updateInvestmentName ();                 // obtain new investment name from user
  void updateExpectedReturn ();					// obtain new expected return from user

private:

  string investmentName;        		// investment name
  double expectedAnnualReturn;		  	// expected annual return on investment
  string expectedAnnualReturnUpdated;   // date expected annual return updated

}; // class Investment

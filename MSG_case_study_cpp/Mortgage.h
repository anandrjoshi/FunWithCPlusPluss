#pragma once

#include "stdafx.h"
#include "Asset.h"
#include "MortgageReport.h"

class Mortgage : public Asset
{

public:

  // getter-setter methods for Mortgage
  string getMortgageeName () { return mortgageeName; }
  void  setMortgageeName (string n) { mortgageeName = n; }
  double getPrice () { return price; }
  void  setPrice (double p) { price = p; }
  string  getDateMortgageIssued () { return dateMortgageIssued; }
  void  setDateMortgageIssued (string d) { dateMortgageIssued = d; }
  double getCurrentWeeklyIncome () { return currentWeeklyIncome; }
  void  setCurrentWeeklyIncome (double c) { currentWeeklyIncome = c; }
  string  getWeeklyIncomeUpdated () { return weeklyIncomeUpdated; }
  void  setWeeklyIncomeUpdated (string w) { weeklyIncomeUpdated = w; }
  double getAnnualPropertyTax () { return annualPropertyTax; }
  void setAnnualPropertyTax (double p) { annualPropertyTax = p; }
  double getAnnualInsurancePremium () { return annualInsurancePremium; }
  void setAnnualInsurancePremium (double a) { annualInsurancePremium = a; }
  double getMortgageBalance () { return mortgageBalance; }
  void setMortgageBalance (double m) { mortgageBalance = m; }

  double totalWeeklyNetPayments () ;					// computes the net total weekly payments made by the mortgagees
  bool find (string findMortgageID) ;					// find locates a given mortgage record if it exists
  void read (ifstream& fileName) ;						// reads a mortgage record from fileName
  void write (ofstream& fileName, bool addNL) ;			// writes a mortgage record to specified file
  void print () ;										// displays the names of the fields of a mortgage and their values
  static void printAll () ;								// displays a list of all mortgage objects
  void obtainNewData () ;								// reads a new mortgage record by calling readMortgageData
  void performDeletion () ;								// performs the actual deletion of a mortgage record from a file
  void save () ;										// saves an individual mortgage record into a file, ordered by mortgageID
  void readMortgageData () ;							// asks user to enter information for the fields of a mortgage
  
  // update methods that query a user for field changes to a mortgage object
  void updateMortgageeName () ;							
  void updatePrice () ;
  void updateDate () ;
  void updateWeeklyIncome () ;
  void updatePropertyTax () ;
  void updateInsurancePremium () ;
  void updateBalance () ;

private:

  string mortgageeName;				// names of mortgagees
  double price;						// price paid for mortgaged property
  string dateMortgageIssued;		// date mortgage was issued
  double currentWeeklyIncome;		// weekly income of mortgagees
  string weeklyIncomeUpdated;		// date weekly income updated
  double annualPropertyTax;			// annual property tax
  double annualInsurancePremium;	// annual insurance premium
  double mortgageBalance;			// mortgage balance

  static int NUMBER_OF_MORTGAGE_PAYMENTS;
  static double MAXIMUM_PERC_OF_INCOME;
  static double WEEKS_IN_YEAR;
  static double INTEREST_RATE;
  

}; // class Mortgage

#include "stdafx.h"
#include "UserInterface.h"
#include "OperatingExpenses.h"

  int main(int argc, char* argv[])
  //
  // main method of MSG product
  // initializes application and calls displayMainMenu to solicit user's choice.
  //
  {

    (new OperatingExpenses)->initializeExpenses ();
	UserInterface::displayMainMenu ();

	return 0;

  }  // main ()
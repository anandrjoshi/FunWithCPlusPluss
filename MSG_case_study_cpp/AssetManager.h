#pragma once

#include "stdafx.h"
#include "UserInterface.h"
#include "Investment.h"
#include "Mortgage.h"

class AssetManager
{

public:

  static void manageInvestment ();		// modifies an investment
  static void manageMortgage ();		// modifies a mortgage

}; // class AssetManger

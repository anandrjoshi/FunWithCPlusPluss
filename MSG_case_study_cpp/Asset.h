#pragma once

#include "stdafx.h"
#include "UserInterface.h"

class Asset
{

public:

  // getter-setter methods for Asset
  string getAssetNumber ()       { return assetNumber; }
  void setAssetNumber (string a) { assetNumber = a; }

  // virtual methods
  virtual void read (ifstream& fileName) = 0;
  virtual void print () = 0;
  virtual void save () = 0;
  virtual void write (ofstream& fileName, bool addNL) = 0;
  virtual bool find (string findRecordID) = 0;
  virtual void obtainNewData () = 0;
  virtual void performDeletion () = 0;

  void deleteAsset ();			// deletes an investment/mortgage	
  void addAsset ();				// adds a new investment/mortgage
 
protected:
	
  string assetNumber;  // unique identifying number of an asset

};  // class Asset

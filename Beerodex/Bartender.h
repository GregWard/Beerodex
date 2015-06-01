/// 
/// \class Bartender
///
/// \brief The purpose of this class is to instantiate a new Bartneder object that will act as the view layer between the BeerFridge and the user.
///
/// \date Created on March 30, 2015
///
/// The Bartender class contains the user menu as well as the inpt level validators /gathering details.
///
/// \author Jeremy Anderson and Greg Ward
///


#ifndef BARTENDER_H
#define BARTENDER_H

#include "commonLibs.h"

using namespace std;

class Bartender{

private:
	//no private data members
public:

	//These are the input level validators
	static bool GetFloat(float& newFloat, istream& is = cin);
	static bool GetInt(int& newInt, istream& is = cin);
	static bool GetDetails(string& newName, string& newBrewery, float& newAlcoholContent, string& newType, int& newIBU);

	//The user menu
	void UserMenu(void);
	void GiveMenu(BeerFridge& fridge);
	void ChangeSorting(BeerFridge& TheFridge);
	void SearchForBeer(BeerFridge& TheFridge);



	
};
#endif
/*
* FILE : Main.cpp
* PROJECT : DS-OOP - Bringing it all together...
* PROGRAMMER : Jeremy Anderson & Greg Ward
* FIRST VERSION : 2015 - 03 - 31
* DESCRIPTION : PUT SOME AMAZING STUFF HERE ABOUT OUR PROGRAM
*
*/

#include "commonLibs.h"



using namespace std;

void testGetInt(void);
void testGetFloat(void);
void testBeerConstructor(void);

//initializing our static variable for the sorting predicate located in SortBy.h
int SortBy::sortBy = kName;





//If not in test mode the below 'main' will be run
#ifndef testHarness
int main(void)
{
	try
	{
		Bartender Sean;  //start our program with the bartender for our view layer person
		BeerFridge* Fridge = NULL; //

		Fridge = new BeerFridge(); //create a new BeerFridge

		Sean.GiveMenu(*Fridge);
		
		delete Fridge;
	}
	catch (bad_alloc& error)
	{
		printf("\nThere was an error allocating space for the program start.\n Error is: %s", error.what());
	}

	return 0;
}
#endif





//If in test most the below 'main' will be run
#ifdef testHarness
int main(void)
{
	//In this function call we will be testing five valid (normal) integer inputs followed by five invalid (exception) integer inputs.
	//The test harness will compare the expected result (1 for valid, 0 for invalid) against the actual result (same criteria)
	//and display whether the test was successful
	testGetInt();

	//In this function call we will be testing five valid (normal) float values followed by five invalid (exception) float values.
	//The test harness will compare the expected result (1 for valid, 0 for invalid) against the actual result (same criteria)
	//and display whether the test was successful
	testGetFloat();

	//In this function call we will be testing five valid (normal) Beer constructor data sets followed by five invalid (exception) Beer constructor data sets.
	//The test harness will compare the expected result (1 for valid, 0 for invalid) against the actual result (same criteria)
	//and display whether the test was successful
	testBeerConstructor();
	return 0;
}
#endif





/**
*\brief This function is called to generate a random alphanumeric string
*
* \param int len - how long the string should be
*
* \return string r - the random alphanumeric string
*
*/

string random(int len)
{
	string a = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	string r = "";
	for (int i = 0; i < len; i++)
	{
		r += (a.at(size_t(rand() % 62)));
	}
	return r;
}





/**
*\brief This function is called to generate a random alphabetic string
*
* \param int len - how long the string should be
*
* \return string r - the random alphabetic string
*
*/

string randomType(int len)
{
	string a = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string r = "";
	for (int i = 0; i < len; i++)
	{
		r += (a.at(size_t(rand() % 52)));
	}
	return r;
}
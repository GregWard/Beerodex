/*
* FILE : Bartender.cpp
* PROJECT : DS-OOP - Bringing it all together...
* PROGRAMMER : Jeremy Anderson & Greg Ward
* FIRST VERSION : 2015 - 03 - 31
* DESCRIPTION : This file contains the logic used in the Bartender view layer class.
*
*/



#include "commonLibs.h"




/**
*\brief This method is called to display the main menu to the user and prompt them for input. Input is handled accordingly.
*
* \param BeerFridge& fridge - the BeerFridge the manu is for. The list of data (Beer) that the menu applies to.
*
* \return This method does not return anything.
*
*/

void Bartender::GiveMenu(BeerFridge& fridge)
{
		bool quitProgram = false;
		
		char button = ' ';
		do{
			system("cls");
			UserMenu();
			button = _getch();
			switch (button)
			{
			case (kMenuOptionOne) :
				fridge.AddNewBeer();
				break;
			case (kMenuOptionTwo) :
				SearchForBeer(fridge);
				break;
			case (kMenuOptionThree) :
				fridge.DisplayBeerList();
				break;
			case (kMenuOptionFour) :
				ChangeSorting(fridge);
				break;
			case (kMenuOptionFive) :
				fridge.AddRandomData();
				break;
			case(kMenuOptionSix) :

				printf("\n\nYou are about to empty your entire beer fridge...Are you sure(I mean like\nreally sure) That you want to do this?\n");
				printf("Press 'y' to delete all items or press any key to skip over this.");

				button = _getch();

				if (button == 'y')
				{
					fridge.EmptyFridge();
				}
				break;
			case (kMenuOptionSeven) :
				quitProgram = true;
				break;
			default:
				system("cls");
				break;
			}
		} while (quitProgram == false);
		
}





/**
*\brief This method is called to display the main menu to the user.
*
*
* \return This method does not return anything.
*
*/

void Bartender::UserMenu(void)
{

	printf("Beerodex 1.00.00\n");
	printf("__________________________\n");
	printf("1.\tAdd An Item\n");
	printf("2.\tSearch\\Modify Beerodex\n");
	printf("3.\tDisplay Entire Database\n");
	printf("4.\tChange Sorted\n");
	printf("5.\tTEST ADD RANDOM ITEMS\n");
	printf("6.\tEmpty Fridge\n");
	printf("7.\tExit Program (Database changes will be saved automagically)\n");
}





/**
*\brief This method is called to validate whether or not user input is a float (decimal number) or not.
*
* \param float& newFloat - the value being validated
* \param istream& is - what input stream the value is coming from
*
* \return bool isFloat - a boolean value indicating whether the value is a valid float (true) or not (false)
*
*/

bool Bartender::GetFloat(float& newFloat, istream& is)
{
	regex reg("[-+]?[0-9]*\\.?[0-9]+");
	bool isFloat = false;

	string buffer = "";

	getline(is, buffer);

	if ((regex_match(buffer.begin(), buffer.end(), reg) == true) || buffer.length() == 0)
	{
		isFloat = true;
		sscanf(buffer.c_str(), "%f", &newFloat);
	}
	else
	{
		throw buffer;
	}

	return isFloat;
}






/**
*\brief This method is called to validate whether or not user input is an integer or not.
*
* \param float& newInt - the value being validated
* \param istream& is - what input stream the value is coming from
*
* \return bool isFloat - a boolean value indicating whether the value is a valid integer (true) or not (false)
*
*/

bool Bartender::GetInt(int& newInt, istream& is)
{
	regex reg("-?[[:digit:]]+");

	bool isInt = false;

	string buffer = "";

	getline(is, buffer);

	if ((regex_match(buffer.begin(), buffer.end(), reg) == true) || buffer.length() == 0)
	{
		isInt = true;
		sscanf(buffer.c_str(), "%d", &newInt);
	}
	else
	{
		throw buffer;
	}

	return isInt;
}





/**
*\brief This method is called to prompt the user for the details needed to create and insert a new Beer into the BeerFridge 
*
* \param string& newName			- the value input for the new Beer's name
* \param string& newBrewery			- the value input for the new Beer's brewery
* \param float& newAlcoholContent	- the value input for the new Beer's alcohol content
* \param string& newType			- the value input for the new Beer's type
* \param int& newIBU				- the value input for the new Beer's IBU
*
* \return bool skipEntry - a boolean value indicating whether the input should be skipped (true) due to invalid data or not (false).
*
*/


bool Bartender::GetDetails(string& newName, string& newBrewery, float& newAlcoholContent, string& newType, int& newIBU)
{
	bool keepInputting = true;
	bool skipEntry = false;
	char button = ' ';

	printf("Please Insert the details of your new beer\n");
	printf("______________________________________\n");

	do{
		printf("\nPlease type your new entry name. Name cannot be skipped\nand cannot start with a ' ' character. Press enter to skipp \"Add new Beer\".\n");
		printf("Beer Name: ");
		getline(cin, newName);
		if (newName.length() == 0)
		{
			printf("Press enter again to stop entering new beer.\n");
			if ((button = _getch()) == '\r')
			{
				keepInputting = false;
				skipEntry = true;
			}
		}
		else
		{
			keepInputting = false;
		}
	} while (keepInputting == true);

	if (skipEntry != true)
	{
		keepInputting = true;

		printf("\nBrewery Name: ");
		getline(cin, newBrewery);
		do{
			try{
				printf("\nAlcohol Content (Can only be 0-100): ");
				GetFloat(newAlcoholContent);
				keepInputting = false;
			}
			catch (string& error)
			{
				printf("%s is not valid. Press 'y' to re-enter or any other key to skip entry.\n", error.c_str());
				if ((button = _getch()) != 'y')
				{
					keepInputting = false;
				}
			}
		} while (keepInputting == true);

		keepInputting = true;
		printf("\nBeer Type: ");
		getline(cin, newType);

		do{

			try{
				printf("\nIBU Count (this must be greater than 0): ");
				Bartender::GetInt(newIBU);
				keepInputting = false;
			}
			catch (string& error)
			{
				printf("%s is not a valid number. Press 'y' to re-enter or any other key to skip entry.\n", error.c_str());
				if ((button = _getch()) != 'y')
				{
					keepInputting = false;
				}
			}
		} while (keepInputting == true);
	}

	return skipEntry;
}





/**
*\brief This method is called to prompt the user to select what value they would like to sort their BeerFridge by. It adjusts the value of sortBy and then calls
* the sorting function to sort the BeerFridge byu the desired attribute.
*
* \param BeerFridge& TheFridge - the BeerFridge we are changing sorting preferences for 
*
* \return None
*
*/


void Bartender::ChangeSorting(BeerFridge& TheFridge)
{
	bool doneEntry = false;
	char entry = ' ';

	while (doneEntry != true)
	{
		system("cls");
		printf("Sort By:\n");
		printf("___________________\n");
		printf("1.\tName\n");
		printf("2.\tBrewery\n");
		printf("3.\tType\n");
		printf("4.\tAlcohol Content\n");
		printf("5.\tIBU\n");
		printf("6.\tGo Back\n");

		entry = _getch();

		switch (entry)
		{
		case (kMenuOptionOne) :
			SortBy::sortBy = kName;
			TheFridge.SortFridge();
			doneEntry = true;
			break;
		case (kMenuOptionTwo) :
			SortBy::sortBy = kBrewery;
			TheFridge.SortFridge();
			doneEntry = true;
			break;
		case (kMenuOptionThree) :
			SortBy::sortBy = kType;
			TheFridge.SortFridge();
			doneEntry = true;
			break;
		case (kMenuOptionFour) :
			SortBy::sortBy = kAlcoholContent;
			TheFridge.SortFridge();
			doneEntry = true;
			break;
		case (kMenuOptionFive) :
			SortBy::sortBy = kIBU;
			TheFridge.SortFridge();
			doneEntry = true;
			break;
		case (kMenuOptionSix) :
			doneEntry = true;
			break;
		}

	}
	system("cls");
}





/**
*\brief This method is called to prompt the user which attribute they wish to search by. Once they select an attribute, 
* they are prompted to enter what value they wish to search for. This method calls the SearchFridge method using the given values.
*
* \param BeerFridge& TheFridge - the BeerFridge we are searching
*
* \return None
*
* \see SearchFridge()
*
*/

void Bartender::SearchForBeer(BeerFridge& TheFridge)
{
	bool stopSearch = false;
	char button = ' ';
	float searchAlcoholContent = 0;
	int searchIBU = 0;
	string searchString;

	int searchBy = 0;

	do{
		system("cls");
		printf("Please enter your search criteria. You can modify/delete items after search.\n");
		printf("______________________\n");
		printf("1.\tName\n");
		printf("2.\tBrewery\n");
		printf("3.\tAlcohol Content\n");
		printf("4.\tType\n");
		printf("5.\tIBU\n");
		printf("6.\tBack to Search Menu\n");
		button = _getch();

		printf("______________________________________\n");

		switch (button)
		{
		case (kMenuOptionOne) :
			printf("Enter a name to search by: ");

			getline(cin, searchString);
			searchBy = kName;
			TheFridge.BeerSearch(searchString, searchIBU, searchAlcoholContent, searchBy);
			break;
		case (kMenuOptionTwo) :
			printf("Enter a brewery to search by: ");
			getline(cin, searchString);
			searchBy = kBrewery;
			TheFridge.BeerSearch(searchString, searchIBU, searchAlcoholContent, searchBy);
			break;
		case (kMenuOptionThree) :
			printf("Enter an Alcohol to search by: ");
			GetFloat(searchAlcoholContent);
			searchBy = kAlcoholContent;
			TheFridge.BeerSearch(searchString, searchIBU, searchAlcoholContent, searchBy);
			break;
		case (kMenuOptionFour) :
			printf("Enter an Type to search by: ");
			getline(cin, searchString);
			searchBy = kType;
			TheFridge.BeerSearch(searchString, searchIBU, searchAlcoholContent, searchBy);
			break;
		case (kMenuOptionFive) :
			printf("Enter an IBU to search by: ");
			GetInt(searchIBU);
			searchBy = kIBU;
			TheFridge.BeerSearch(searchString, searchIBU, searchAlcoholContent, searchBy);
			break;
		case (kMenuOptionSix) :
			stopSearch = true;
		default:
			break;
		}
	} while (stopSearch == false);
}
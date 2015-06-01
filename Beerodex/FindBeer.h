/*
* FILE : FindBeer.h
* PROJECT : DS-OOP - Bringing it all together...
* PROGRAMMER : Jeremy Anderson & Greg Ward
* FIRST VERSION : 2015 - 03 - 31
* DESCRIPTION : This file contains the search struct predicate used for the "Find_if" function in the Beerodex program. 
*/


#include "commonLibs.h"

/// 
/// \struct FindBeer
///
/// \brief The purpose of this struct is to be used as the search predicate for the <b>find_if</b> function used to search the BeerFridge
///
/// \date Created on April 04, 2015
///
/// The FindBeer struct contains four variables that may be used in the user search of the database. When find_if calls FindBeer it passes
/// to it the string that is being searched for, the alcohol content or the IBU count. Lastly, and most importantly is the 'search by' which
/// is used to determine which case in the overloaded () will be used.
///
///
///
/// \author Jeremy Anderson and Greg Ward
///





struct FindBeer
{
	string searchString; ///< What is the searched items Name, Brewery or Type?
	int searchKey;  ///< What are they trying to search by? (IBU, Alcohol Content, 
	int IBU;  ///< What is the IBU they are searching for
	float AContent; ///< What is the alcohol content of the beer they wish to find





	/**
	* \brief To instantiate a new FindBeer struct 
	*
	* \details
	*		 This constructor function is called upon when a new Find Beer struct is to be created
	*
	* \param searchString - <b>string</b> - This could contain the name, brewery, or type of beer we wish to search for
	* \param IBU - <b> int </b> - This contains the IBU being searched for 
	* \param AContent - <b> float</b> - This contains the Alcohol Content being searched for
	* \param searchBy - <b> int </b> - This contains the key in which we will search through our overloaded () operator
	*
	* \return <b>Return Value</b><br>
	*			As this is a <i>constructor</i>, nothing is returned.
	*
	*/





	FindBeer::FindBeer(string searchString, int IBU, float AContent, int searchBy)
	{
		this->searchString = searchString;
		this->IBU = IBU;
		this->AContent = AContent;
		this->searchKey = searchBy;
	}





	/**
	* \brief An overloaded () operator for searching
	*
	* \details
	*		 This operator is used to determine what the user wishes to search for and what the 
	*
	* \param theBeer - <b>Beer</b> - This is the Beer that is being compared agains the predefined search parameters
	*
	* \return <b>Return Value</b><br>
	*			isEqual - <b> bool </b> - This bool will determine whether a substring of the search is true or the strings match.
	*
	*/



	bool operator()(const Beer& theBeer) const
	{
		bool isEqual = false;

		switch (searchKey) //depending on the key passed will determine which case is used
		{
			//Search by name
		case (kName) : 
			if ((strstr(theBeer.GetName().c_str(), searchString.c_str())) != NULL || stricmp(theBeer.GetName().c_str(), searchString.c_str()) == 0)
			{
				isEqual = true;
			}
					   break;
			//Search by Brewer
		case (kBrewery) :
			if ((strstr(theBeer.GetBrewery().c_str(), searchString.c_str())) != NULL || (stricmp(theBeer.GetBrewery().c_str(), searchString.c_str())) == 0)
			{
				isEqual = true;
			}
						break;
			//Search by Alcohol Content
		case (kAlcoholContent) :
			if ((theBeer.GetAlcoholContent() == AContent))
			{
				isEqual = true;
			}
					    break;
			//Search by Type
		case (kType) :
			if ((strstr(theBeer.GetType().c_str(), searchString.c_str())) != NULL || stricmp(theBeer.GetType().c_str(), searchString.c_str()) == 0)
			{
				isEqual = true;
			}
					 break;
			//Search by IBU
		case (kIBU) :
			if ((theBeer.GetIBU() == IBU))
			{
				isEqual = true;
			}
					break;
		}
		return isEqual;
	}
};
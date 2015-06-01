/*
* FILE : SortBy.h
* PROJECT : DS-OOP - Bringing it all together...
* PROGRAMMER : Jeremy Anderson & Greg Ward
* FIRST VERSION : 2015 - 03 - 31
* DESCRIPTION : This file contains the sort struct predicate used for the sorting and resorting of items into the "TheBeers" multiset container.
*/




#include "commonLibs.h"




/// 
/// \struct SortBy
///
/// \brief The purpose of this struct is to be used as the sorting predicate for the multiset <b>TheBeers</b>.
///
/// \date Created on April 07, 2015
///
/// The SortBy struct contains a static variable that may be used in determining how the user wishes to sort the list. By default we sort by kName
/// (the variable is initialized just above the main function). But, if the user wishes to re-sort a they access this through the appropriate menu option
/// 
///
///
///
/// \author Jeremy Anderson and Greg Ward
///




struct SortBy{

	static int sortBy; ///< this is a static variable that we use in the "SortBy" struct that is used in our typdefed multiset "The Beers"






	/**
	* \brief An overloaded () operator for sorting
	*
	* \details
	*		 This operator is used to determine what the user wishes to sort by in their list using the static "sortBy" variable
	*
	* \param lhs - <b>Beer</b> - This is the Beer that is being compared against on the left hand side when sorting
	* \param rhs - <b>Beer</b> - This is the Beer that is being compared against on the right hand side when sorting
	*
	* \return <b>Return Value</b><br>
	*			placeHere - <b> bool </b> - This bool will determine whether the item being sorted should be placed at its current iteration or not.
	*
	*/





	bool operator ()(const Beer& lhs, const Beer& rhs)
	{
		bool placeHere = false;

		switch (sortBy)
		{
		case(kName) :
		{
			if ((stricmp(lhs.GetName().c_str(), rhs.GetName().c_str()) < 0))
			{
				placeHere = true;
			}
			break;
		}
		case (kBrewery) :
		{
			if ((stricmp(lhs.GetBrewery().c_str(), rhs.GetBrewery().c_str()) < 0))
			{
				placeHere = true;
			}

			break;
		}
		case (kAlcoholContent) :
		{
			if (lhs.GetAlcoholContent() < rhs.GetAlcoholContent())
			{
				placeHere = true;
			}
			break;
		}
		case (kType) :
		{
			if ((stricmp(lhs.GetType().c_str(), rhs.GetType().c_str()) < 0))
			{
				placeHere = true;
			}

			break;
		}
		case (kIBU) :
		{
			if (lhs.GetIBU() < rhs.GetIBU())
			{
				placeHere = true;
			}
			break;
		}
		default:
			break;
		}
		return placeHere;
	}
};


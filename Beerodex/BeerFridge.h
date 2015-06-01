/// 
/// \class BeerFridge
///
/// \brief The purpose of this class is to instantiate a new BeerFridge object to contain the multiset 
/// of beers, as well as methods to access and change the contents/how they are displayed
///
/// \date Created on March 30, 2015
///
/// The BeerFridge class contains the typdefed Multiset <b>TheBeers</b>
///
/// \author Jeremy Anderson and Greg Ward
///






#ifndef FRIDGE_H
#define FRIDGE_H

#include "commonLibs.h"

using namespace std;





class BeerFridge
{
// ** PRIVATE **
private:
	TheBeers OurBeers;	///<The MultiSet holding our Beers
	
// ** PUBLIC **
public:
	// * CONSTRUCTOR *
	BeerFridge();

	// * DESTRUCTORS *
	~BeerFridge();

	// * ACCESSORS *
	
	TheBeers GetBeerList(void);

	// * OTHER *
	friend void operator >>(istream& is, TheBeers& list);
	bool operator ()(const Beer& lhs, const Beer& rhs);
	bool operator ==(const Beer& rhs);

	//these methods are all used to access the domain layer items
	void DisplayBeerList(void);
	void AddRandomData(void); 
	void SortFridge(void);
	void AddNewBeer();
	
	void BeerSearch(string& searchString, int& searchIBU, float& searchAlcoholContent, int& searchBy);
	void DrinkABeer(int beerPosition);
	void ChangeABeer(int beerPosition);
	void EmptyFridge();
	
	void DumpFridge(); //used in destructor to print all beers to file
	void OpenFridge(); //used to print all beers into our TheBeers OurBeers attribute
};
#endif
/// 
/// \class Beer
///
/// \brief The purpose of this class is to instantiate a new Beer object given a set of parameters. This is the domain layer class.
///
/// \date Created on April 04, 2015
///
/// \author Jeremy Anderson and Greg Ward
///





#ifndef BEER_H
#define BEER_H

#include "commonLibs.h"

using namespace std;





class Beer
{
// ** PRIVATE **
private:
	string brewery;			///<What brewery produces this beer?
	string displayBrewery;  ///<If the brewery is longer thant 15 characters, what will we call it?
	string name;			///<What is the beer called?
	string displayName;     ///<If the name is longer than 15 characters, what will we call it?
	float alcoholContent;	///<What is the alcohol content?
	string type;			///<What type of beer is it?
	string displayType;     ///< If the type is longer than 15 characters, what will we call it?
	int IBU;				///<What is the IBU (International Bitter Units) of the beer?

// ** PUBLIC **
public:
	// * CONSTRUCTORS *
	Beer(string newName, string newBrewery, float newAlcoholContent, string newType, unsigned int newIBU);

	// * DESTRUCTORS *
	~Beer();

	// * ACCESSORS *
	const string GetBrewery() const;
	const string GetName() const;
	const float GetAlcoholContent() const;
	const string GetType() const;
	const int GetIBU()const;
	const string GetDisplayName() const;
	const string GetDisplayType() const;
	const string GetDisplayBrewery() const;
	
	// * MUTATORS *
	void SetName(string newName);
	void SetBrewery(string newBrewery);
	void SetAlcoholContent(float newAlcoholContent);
	void SetType(string newType);
	void SetIBU(int newIBU);
	void SetDisplayName(string& newName);
	void SetDisplayType(string& newType);
	void SetDisplayBrewery(string& newBrewery);

	// * OPERATORS *
	bool Beer::operator ()(const Beer& lhs, const Beer& rhs);
	friend ostream& operator<<(ostream& os, const Beer& thisBeer);
};
#endif
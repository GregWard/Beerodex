/*
* FILE : Beer.cpp
* PROJECT : DS-OOP - Bringing it all together...
* PROGRAMMER : Jeremy Anderson & Greg Ward
* FIRST VERSION : 2015 - 03 - 31
* DESCRIPTION : This file contains the logic used for the domain class Beer.
*/


//WE STILL NEED TO COMMENT THE DESTRUCTOR


#include "commonLibs.h"

#define kMinAlcoholContent 0
#define kMaxAlcoholContent 100
#define kDisplayLength 15
#define kLengthCutOff 12






/**
* \brief To instantiate a new Beer object
*
* \details
*		 This constructor method is called upon when a new Beer object is to be created
*
* \param newName - <b>string</b> - This contains the name that the new beer object will have.
* \param newBrewery - <b>string</b> - This could contain the brewery of the beer we wish instantiate
* \param newType - <b>string</b> - This could contain the type (ale, lager, etc.) of the beer we wish instantiate
* \param newIBU - <b> int </b> - This ccould contain the IBU for the beer we are instantiating
* \param newAlcoholContent - <b> float</b> - This could contain the Alcohol Content for the beer object being instantiated
*
* \return <b>Return Value</b><br>
*			As this is a <i>constructor</i>, nothing is returned.
*
*/





Beer::Beer(string newName, string newBrewery, float newAlcoholContent, string newType, unsigned int newIBU)
{
	//validate newName
	regex reg("([!-~]+[ -~]*)");
	if ((regex_match(newName.begin(), newName.end(), reg) == false))
	{
		throw newName; //if the newName is invalid, throw back the name
	}
	else
	{ //if the new name is valid, set the display name as well
		name = newName;
		if (newName.length() > kDisplayLength)
		{
			newName = newName.substr(0, kLengthCutOff) + "...";
		}
		displayName = newName;
	}

	//validate newBrewery
	reg = "([!-~]+[ -~]*)";
	if (((regex_match(newBrewery.begin(), newBrewery.end(), reg) == true) || (newBrewery.length() == 0)))
	{
		brewery = newBrewery;
		if (newBrewery.length() > kDisplayLength)
		{
			newBrewery = newBrewery.substr(0,kLengthCutOff) + "...";
		}
		displayBrewery = newBrewery;
	}
	else
	{
		throw newBrewery; //throw the brewery so we can let the user know that the brewery was problematic
		
	}

	//validate newAlcoholContent
	if ((newAlcoholContent < kMinAlcoholContent) || (newAlcoholContent > kMaxAlcoholContent))
	{
		//throw an exception
		throw newAlcoholContent; //throwback the alcohol content letting the user know it can only be between 0-100
	}
	else{
		alcoholContent = newAlcoholContent;
	}

	//validate newType
	reg = ("[a-zA-Z]+( [a-zA-Z]+)*");
	if (((regex_match(newType.begin(), newType.end(), reg) == true) || (newType.length() == 0)))
	{
		//if it is valid, we will set the beer type and the "display string"
		type = newType;
		if (newType.length() > kDisplayLength)
		{
			newType = newType.substr(0,kLengthCutOff) + "...";
		}
		displayType = newType;
		
	}
	else
	{
		throw newType;
	}

	//validate IBU
	if (newIBU < 0)
	{
		//throw the IBU up the call stack if it's wrong
		throw newIBU;
	}
	else
	{
		IBU = newIBU;
	}
}

/**
* \brief To destroy a Beer object
*
* \details
*		 This destructor method is called upon to destroy a Beer object when it loses scope.
*
* \return <b>Return Value</b><br>
*			As this is a <i>destructor</i>, nothing is returned.
*
*/

Beer::~Beer()
{
	//printf("Why is the Beer gone?.."); //the  sorting function creates and delets beer at random to sort itself...it's 
}

// * MUTATORS *





/**
* \brief To change the brewery field
*
* \details
*		 This method is called upon when the user wishes the modify the brewery attribute
*
* \param newBrewery - <b>string</b> - This contains the new brewery we wish to change the beer to
*
* \return <b>Return Value</b><br>
*			There is no return from this method.
*
*/




void Beer::SetBrewery(string newBrewery)
{
	regex reg("([!-~]+[ -~]*)");
	if ((regex_match(newBrewery.begin(), newBrewery.end(), reg) == false))
	{
		throw newBrewery;
	}
	else
	{
		brewery = newBrewery;
		SetDisplayBrewery(newBrewery);
	}
}





/**
* \brief To change the name field
*
* \details
*		 This method is called upon when the user wishes the modify the name attribute
*
* \param newName - <b>string</b> - This contains the new name of the beer we wish change
*
* \return <b>Return Value</b><br>
*			There is no return from this method.
*
*/





void Beer::SetName(string newName)
{
	regex reg("([!-~]+[ -~]*)");
	if ((regex_match(newName.begin(), newName.end(), reg) == false))
	{
		throw newName;
	}
	else
	{
		name = newName;
		SetDisplayName(newName);
	}
}






/**
* \brief To change the Alcohol Content field
*
* \details
*		 This method is called upon when the user wishes the modify the AlcoholContent attribute
*
* \param newAlcoholContent - <b>float</b> - This contains the new AlcoholContent of the beer we wish change
*
* \return <b>Return Value</b><br>
*			There is no return from this method.
*
*/






void Beer::SetAlcoholContent(float newAlcoholContent)
{
	if ((newAlcoholContent < kMinAlcoholContent) || (newAlcoholContent > kMaxAlcoholContent)){
		throw newAlcoholContent;
	}
	else{
		alcoholContent = newAlcoholContent;
	}
}






/**
* \brief To change the Type field
*
* \details
*		 This method is called upon when the user wishes the modify the Type attribute
*
* \param newType - <b>string</b> - This contains the new Type of the beer we wish change
*
* \return <b>Return Value</b><br>
*			There is no return from this method.
*
*/





void Beer::SetType(string newType)
{
	regex reg("\\w+");
	if ((regex_match(newType.begin(), newType.end(), reg) == false))
	{
		throw newType;
	}
	else{
		type = newType;
		SetDisplayType(newType);
	}
}
	




/**
* \brief To change the IBU field
*
* \details
*		 This method is called upon when the user wishes the modify the IBU attribute
*
* \param newIBU - <b>int</b> - This contains the new IBU of the beer we wish change
*
* \return <b>Return Value</b><br>
*			There is no return from this method.
*
*/




void Beer::SetIBU(int newIBU)
{
	if (newIBU < 0){
		throw newIBU;
	}
	else{
		IBU = newIBU;
	}
}






/**
* \brief To change the Displayed Name field
*
* \details
*		 This method is called upon when the name attribute is changed
*
* \param newName - <b>string</b> - This contains the new name of the beer we wish change
*
* \return <b>Return Value</b><br>
*			There is no return from this method.
*
*/




void Beer::SetDisplayName(string& newName)
{
	if (newName == name && newName.length() > kDisplayLength)
	{
		displayName = newName.substr(0, kLengthCutOff) + "...";
	}
}





/**
* \brief To change the Displayed Type field
*
* \details
*		 This method is called upon when the type attribute is changed
*
* \param newType - <b>string</b> - This contains the new type of the beer we wish change
*
* \return <b>Return Value</b><br>
*			There is no return from this method.
*
*/




void Beer::SetDisplayType(string& newType)
{
	if (newType == type && newType.length() > kDisplayLength)
	{
		displayType = newType.substr(0, kLengthCutOff) + "...";
	}
}





/**
* \brief To change the Displayed Brewery field
*
* \details
*		 This method is called upon when the brewery attribute is changed
*
* \param newBrewery - <b>string</b> - This contains the new brewery of the beer we wish change
*
* \return <b>Return Value</b><br>
*			There is no return from this method.
*
*/





void Beer::SetDisplayBrewery(string& newBrewery)
{
	if (newBrewery == brewery && newBrewery.length() > kDisplayLength)
	{
		displayBrewery = newBrewery.substr(0, kLengthCutOff) + "...";
	}
}






/**
* \brief To get the brewery attribute of the beer object
*
* \details
*		 This method returns the brewery attribute.
*
* \return <b>Return Value</b><br>
*			Brewery - <b>string</b> - This contains the brewery of the beer object.
*/





const string Beer::GetBrewery() const
{
	return brewery;
}




/**
* \brief To get the name attribute of the beer object
*
* \details
*		 This method returns the name attribute.
*
* \return <b>Return Value</b><br>
*			name - <b>string</b> - This contains the name of the beer object.
*/





const string Beer::GetName() const
{
	return name;
}





/**
* \brief To get the Alcohol Content attribute of the beer object
*
* \details
*		 This method returns the Alcohol Content attribute.
*
* \return <b>Return Value</b><br>
*			alcoholContent - <b>float</b> - This contains the Alcohol Content of the beer object.
*/





const float Beer::GetAlcoholContent() const
{
	return alcoholContent;
}





/**
* \brief To get the type attribute of the beer object
*
* \details
*		 This method returns the type attribute.
*
* \return <b>Return Value</b><br>
*			type - <b>string</b> - This contains the type of the beer object.
*/





const string Beer::GetType() const
{
	return type;
}





/**
* \brief To get the IBU attribute of the beer object
*
* \details
*		 This method returns the IBU attribute.
*
* \return <b>Return Value</b><br>
*			IBU - <b>int</b> - This contains the IBU of the beer object.
*/





const int Beer::GetIBU()const
{
	return IBU;
}





/**
* \brief To get the displayName attribute of the beer object
*
* \details
*		 This method returns the displayName attribute.
*
* \return <b>Return Value</b><br>
*			displayName - <b>string</b> - This contains the displayName of the beer object.
*/





const string Beer::GetDisplayName() const
{
	return displayName;
}





/**
* \brief To get the displayType attribute of the beer object
*
* \details
*		 This method returns the displayType attribute.
*
* \return <b>Return Value</b><br>
*			displayType - <b>string</b> - This contains the displayType of the beer object.
*/





const string Beer::GetDisplayType() const
{
	return displayType;
}





/**
* \brief To get the displayBrewery attribute of the beer object
*
* \details
*		 This method returns the displayBrewery attribute.
*
* \return <b>Return Value</b><br>
*			displayBrewery - <b>string</b> - This contains the displayBrewery of the beer object.
*/





const string Beer::GetDisplayBrewery() const
{
	return displayBrewery;
}





/**
* \brief This is the overloaded << operator for the beer class
*
* \details
*		 This method is used to direct the different attributes to the output stream indicated. This is primarily used to write the different beers to a file.
*
* \return <b>Return Value</b><br>
*			os - <b> << operator </b> - This contains the displayType of the beer object.
*/





ostream& operator<<(ostream& os, const Beer& thisBeer)
{
	os << thisBeer.name << "\n";
	os << thisBeer.brewery << "\n";
	os << thisBeer.alcoholContent << "\n";
	os << thisBeer.type << "\n";
	os << thisBeer.IBU << "\n";

	return os;
}
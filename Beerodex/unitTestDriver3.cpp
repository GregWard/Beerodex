/*
* FILE : unitTestDriver3.cpp
* PROJECT : DS-OOP - Bringing it all together...
* PROGRAMMER : Jeremy Anderson & Greg Ward
* FIRST VERSION : 2015 - 03 - 31
* DESCRIPTION : This file contains the logic used by the third test harness. The harness tests the effectiveness of our Beer() constructor
*				by passing in five valid and five invalid data sets and interpreting the results when the constructor is called.
*/





#include "commonlibs.h"






/**
*\brief This function is called to test the Beer class' constructor  by passing it a bunch of values and interpreting the results.
* THe test results are displayed on the screen.
*
* \return None
*
*/

void testBeerConstructor(void)
{
	string testType[2] = { "Normal", "Exception" };

	struct DataFields
	{
		string testName;
		string testBrewery;
		float testAlcohol;
		string testType;
		int testIBU;
	};

	DataFields testData[kNumberOfBeers] =
	{
		//Valid Test Data
		{ "Canadian", "Molson", 5, "Lager", 10 },
		{ "Shock Top", "Anheuser-Busch", 5.2, "Witbier", 10 },
		{ "MGD", "Miller", 4.7, "Lager", 15 },
		{ "Steamwhistle", "Steamwhistle", 5.0, "Pilsner", 20 },
		{ "Guiness", "Guiness", 4.1, "Stout", 45 },

		//Invalid Test Data
		{ " ", "Anheuser-Busch", 4.0, "Light Lager", 10 },
		{ "100", "100", 100, "100", 100 },
		{ "Fruitesse", "Liefmans", -4.20, "Fruit Lambic", 7 },
		{ "RED BOX", "RED BOX", 9999, "RED BOX", -32 },
		{ "          ", "Butt", 900, "DELICIOUS", 250000 }
	};

	bool expectedResult[10] = { true, true, true, true, true, false, false, false, false, false };
	istringstream iss;

	printf("\n***TESTING BEER CONSTRUCTOR***\n\n");

	bool validDetails = false;

	string testResult = "";
	int counter = 0;
	int typeCounter = 0;


	while (counter < kNumberOfBeers)
	{
		if ((counter % 5 == 0) && (counter != 0)){
			++typeCounter;
		}

		printf("Test Type           : %s\n", testType[typeCounter].c_str());
		printf("Name tested         : %s\n", testData[counter].testName.c_str());
		printf("Brewery tested      : %s\n", testData[counter].testBrewery.c_str());
		printf("Alcohol % tested      : %f\n", testData[counter].testAlcohol);
		printf("Type tested         : %s\n", testData[counter].testType.c_str());
		printf("IBU tested          : %d\n", testData[counter].testIBU);
		printf("Expected Result     : %d\n", expectedResult[counter]);
		printf("Actual result       : ");
		try{
			Beer::Beer(testData[counter].testName, testData[counter].testBrewery, testData[counter].testAlcohol, testData[counter].testType, testData[counter].testIBU);
			printf("1\n");
			//the only way this stuff will happen is if the beer constructor doesnt throw an exception, aka the contruction passed
			if (expectedResult[counter] == true)
			{
				testResult = "PASS";
			}
			else
			{
				testResult = "FAIL";
			}
		}
		//this stuff happens if the construction fails and an exception is thrown
		catch (...){
			printf("0\n");
			testResult = "PASS";
		}

		printf("Test Result         : %s\n\n", testResult.c_str());
		++counter;
	}
}




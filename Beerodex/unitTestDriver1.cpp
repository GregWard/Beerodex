
/*
* FILE : unitTestDriver1.cpp
* PROJECT : DS-OOP - Bringing it all together...
* PROGRAMMER : Jeremy Anderson & Greg Ward
* FIRST VERSION : 2015 - 03 - 31
* DESCRIPTION : This file contains the logic used by the first test harness. The harness tests the effectiveness of our GetInt() function
*				by passing in five valid and five invalid integers and interpreting the results.
*/


#include "commonlibs.h"





/**
*\brief This function is called to test the GetInt method by passing it a bunch of values and interpreting the results.
* THe test results are displayed on the screen.
*
* \return None
*
*/

void testGetInt(void)
{
	string testType[2] = { "Normal", "Exception" };
	string testData[kNumberOfIntegers] = { "5\n", "100\n", "20\n", "-38\n", "0\n", "MANANA\n", "RAWBERRY\n", "102.1\n", "Questionable Hairpiece\n", "32X\n" };
	bool expectedResult[10] = { true, true, true, true, true, false, false, false, false, false };
	istringstream iss;

	int number = 0;

	printf("\n***TESTING INTEGER INPUTS***\n\n");

	bool testInt = false;

	string testResult = "";
	int counter = 0;
	int typeCounter = 0;
	while (counter < kNumberOfIntegers){
		if ((counter % 5 == 0) && (counter != 0)){
			++typeCounter;
		}
		iss.str(testData[counter]);
		printf("Test Type           : %s\n", testType[typeCounter].c_str());
		printf("Value tested        : %s", testData[counter].c_str());
		printf("Expected Result     : %d\n", expectedResult[counter]);
		printf("Actual result       : ");
		try{
			testInt = Bartender::GetInt(number, iss);
			printf("%d\n", testInt);
			if (expectedResult[counter] == true)
			{
				testResult = "PASS";
			}
			else
			{
				testResult = "FAIL";
			}
		}
		catch (string& buffer){
			printf("0\n", buffer.c_str());
			testResult = "PASS";
		}

		printf("Test Result         : %s\n\n", testResult.c_str());
		++counter;
	}
}
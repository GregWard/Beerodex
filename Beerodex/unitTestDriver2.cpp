/*
* FILE : unitTestDriver2.cpp
* PROJECT : DS-OOP - Bringing it all together...
* PROGRAMMER : Jeremy Anderson & Greg Ward
* FIRST VERSION : 2015 - 03 - 31
* DESCRIPTION : This file contains the logic used by the second test harness. The harness tests the effectiveness of our GetFloat() function
*				by passing in five valid and five invalid float values and interpreting the results.
*/


#include "commonlibs.h"






/**
*\brief This function is called to test the GetFloat method by passing it a bunch of values and interpreting the results.
* THe test results are displayed on the screen.
*
* \return None
*

*/
void testGetFloat(void)
{
	string testType[2] = { "Normal", "Exception" };
	string testData[kNumberOfFloats] = { "2258\n", "-999.99\n", "-50\n", "-0.000000001\n", "12345.67890\n", "MANANA\n", "RAWBERRY\n", "102.1theEdge\n", "Questionable Hairpiece\n", "32X\n" };
	bool expectedResult[10] = { true, true, true, true, true, false, false, false, false, false };
	istringstream iss;

	float number = 0;

	printf("\n***TESTING FLOAT INPUTS***\n\n");

	bool testFloat = false;

	string testResult = "";
	int counter = 0;
	int typeCounter = 0;
	while (counter < kNumberOfFloats){
		if ((counter % 5 == 0) && (counter != 0)){
			++typeCounter;
		}
		iss.str(testData[counter]);
		printf("Test Type           : %s\n", testType[typeCounter].c_str());
		printf("Value tested        : %s", testData[counter].c_str());
		printf("Expected Result     : %d\n", expectedResult[counter]);
		printf("Actual result       : ");
		try{
			testFloat = Bartender::GetFloat(number, iss);
			printf("%d\n", testFloat);
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
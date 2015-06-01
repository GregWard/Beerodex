/*
* FILE : commonLibs.h
* PROJECT : DS-OOP - Bringing it all together...
* PROGRAMMER : Jeremy Anderson & Greg Ward
* FIRST VERSION : 2015 - 03 - 31
* DESCRIPTION : This file contains the libraries used through out the program as well as the #defines used
*
*/



#ifndef COMMON_H
#define COMMON_H

//#define testHarness  //this will be commented out for regular program operation, or left active to run the test harness instead

#pragma warning(disable:4996)

//this is used to for the sorting/searching keys used in the BeerFridge Class as well as in the SortBy and FindBeer structs containing the overloaded () operators
#define kName 1
#define kBrewery 2
#define kAlcoholContent 3
#define kType 4
#define kIBU 5
#define kBeersToDisplay 20

//the menu options used in the view layer switch statements
#define kMenuOptionOne '1'
#define kMenuOptionTwo '2'
#define kMenuOptionThree '3'
#define kMenuOptionFour '4'
#define kMenuOptionFive '5'
#define kMenuOptionSix '6'
#define kMenuOptionSeven '7'

#include <iostream>
#include <conio.h>
#include <regex>
#include <set>
#include <string>
#include <new>
#include <fstream>
#include <sstream>

#define kInputOutputFile "JeremyAnd.txt"

#define kNumberOfIntegers 10	//number of integers to test in the test harness
#define kNumberOfFloats 10		//number of floats to test in the test harness
#define kNumberOfBeers 10		//number of beers to test in the test harness



//Our own header files
#include "beer.h"
#include "SortBy.h"

//The multiset we use for our program
typedef std::multiset<Beer, SortBy> TheBeers;

#include "FindBeer.h"
#include "BeerFridge.h"
#include "Bartender.h"


//PROTOTYPES
string random(int len);
string randomType(int len);

#endif COMMON_H
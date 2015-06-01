/*
* FILE : BeerFridge.cpp
* PROJECT : DS-OOP - Bringing it all together...
* PROGRAMMER : Jeremy Anderson & Greg Ward
* FIRST VERSION : 2015 - 03 - 31
* DESCRIPTION : This file contains the logic used in the BeerFridge Data Access layer class.
*
*/

#include "commonLibs.h"





/// \brief To instantiate a new BeerFridge object - given a set of attribute values
/// \details <b>Details</b>
///
/// This method takes acts as the default constructor for the BeerFridge class.
///
/// \return As this is a <i>constructor</i> for the BeerFridge class, nothing is returned
///
/// \see ~BeerFridge()

BeerFridge::BeerFridge()
{

	ifstream is; 

	is.open(kInputOutputFile, ios::in | ios::binary); //load the file

	if (is.fail())
	{
		printf("We have failed to open the file %s", kInputOutputFile);
	}
	else
	{
		is >> OurBeers;

		if (is.fail() && !is.eof()) //check for an error and not just the eof flag that may have been set
		{
			printf("There was an error in writing to the file...");
		}
		

		if (is.is_open())
		{
			is.clear(); //clear out any error flags
			is.close();
			if (is.fail()) //if the file failed to close
			{
				printf("\nERROR: Closing file was unsuccessful, changes to databased may not be saved.\nPress Any Key to continue...");
				_getch();
			}
		}

	}

	
}


/// \brief Called upon to <i>destroy</i> a BeerFridge object - once it loses <b>scope</b>
/// \details <b>Details</b>
///
/// The destructor destroys a BeerFridge object once it has lost scope, freeing up any memory used by the object.
///
/// \return As this is a <i>destructor</i> for the BeerFridge class, nothing is returned
///
/// \see BeerFridge()

BeerFridge::~BeerFridge()
{
	DumpFridge(); // dumps all list contents to a file
}


/**
*\brief This method will get the list that holds all the items  key (the value in which the list will be sorted by).
*
*
* \return
The type defined list OurBeers. This list holds all the data of our database.
*
* \see AddNewBeer(), DeleteABeer(), EmptyFridge(),
*/


TheBeers BeerFridge::GetBeerList(void)
{
	return OurBeers;
}





/**
*\brief This method will 'sort' the contents of the BeerFridge by creating a temporary fridge and placing
* the beer in that fridge, in order and display a progress bar so the user doesn't get scared that the 
* program has frozen (for sorting those extra large beer collections)
*
* \return
Nothing is returned by this method
*
* \see BeerSearch()
*/


void BeerFridge::SortFridge(void)
{
	TheBeers tmpFridge;
	int completed = 0;
	TheBeers::iterator prvIt = OurBeers.begin();
	int listSize = OurBeers.size();

	printf("We are sorting your fridge.\nPlease wait while we sort all the things.\n\n");
	for (TheBeers::const_iterator it = OurBeers.begin(); it != OurBeers.end(); )
	{
		completed = (tmpFridge.size()*100 /listSize); //used to update the user as to how far alone we are in their sort

		tmpFridge.insert(*it);//copy the item to our new sorted fridge

		prvIt = it++; //move the iterator tracking previous items up

		OurBeers.erase(prvIt); //now that we've placed our beer in the new fridge, delete it from the other so we are efficient in our memory

		printf("PERCENTAGE COMPLETE: %d%%", completed);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	}

	OurBeers = tmpFridge;
	
}





/**
*\brief This method will create a new Beer object and insert it into the Beerfrige if it is instantiated correctly.
*
* \return
Nothing is returned by this method
*
* \see AddRandomData()
*/

void BeerFridge::AddNewBeer()
{
	Beer* newbeer = NULL;

	float newAlcoholContent = 0;
	int newIBU = 0;
	string newName = "";
	string newBrewery = "";
	string newType = "";
	bool completedEntry = false;

	system("cls");

	while (completedEntry == false)
	{
		try
		{
			if ((Bartender::GetDetails(newName, newBrewery, newAlcoholContent, newType, newIBU)) != true) //as long as the user has not decided to skip entry of the new beer...
			{
				newbeer = new Beer(newName, newBrewery, newAlcoholContent, newType, newIBU);
				OurBeers.insert(*newbeer);
				delete newbeer;
			}
			completedEntry = true;
		}
		catch (bad_alloc& error)
		{
			printf("MEMORY ALLOCATION ERROR: %s", error.what());
			completedEntry = true;
		}
		catch (string& error)
		{
			if (error == newName)
			{
				printf("%s is not a valid Beer Name.\n\n Press any key to go back to start of entry.\n", error.c_str());
				_getch();
			}
			if (error == newBrewery)
			{
				printf("%s is not a valid Brewery entry.\n\n Press any key to go back to start of entry.\n", error.c_str());
				_getch();
			}
			if (error == newType)
			{
				printf("%s is not a valid Beer Type.\n\n Press any key to go back to start of entry.\n", error.c_str());
				_getch();
			}
		}
		catch (float& error)
		{
			printf("%f is not a valid Alcohol Content. Only values from 0-100 will be accepted.\n\n Press any key to go back to start of entry.\n", error);
			_getch();
		}
		catch (unsigned int& error)
		{
			printf("%d is not a valid IBU. Only values from 0-1000 will be accepted.\n\n Press any key to go back to start of entry.\n", error);
			_getch();
		}
		system("cls");
	}
}





/**
*\brief This method will display the contents of the BeerFridge in an organized chart, 20 entries at a time. 
*
* \return
Nothing is returned by this method
*
*/

void BeerFridge::DisplayBeerList(void)
{
	int counter = 1;

	system("cls");
	if (OurBeers.size() == 0)
	{
		printf("There are no beers in the database. Press any key to return to main.");
		_getch();
	}

	else
	{
		printf("\n #| %-15s %-15s %-15s %-7s %-5s \n", "Name", "Brewery", "Type", "Alc %", "IBU");
		printf("--|------------------------------------------------------------\n");
		for (TheBeers::iterator it = OurBeers.begin(); it != OurBeers.end();)
		{
			printf("%2d| %-15s %-15s %-15s %-7.1f %-5d \n", counter, it->GetDisplayName().c_str(), it->GetDisplayBrewery().c_str(), it->GetDisplayType().c_str(), it->GetAlcoholContent(), it->GetIBU());
			++counter;
			++it;
			if ((counter > kBeersToDisplay) && (it != OurBeers.end())){
				printf("\n * Push 'x' to return to main menu, or any other key to display more *\n");
				char ch = _getch();
				if (ch == 'x'){
					break;
				}
				counter = 1;
				system("cls");
				printf("\n #| %-15s %-15s %-15s %-7s %-5s \n", "Name", "Brewery", "Type", "Alc %", "IBU");
				printf("--|------------------------------------------------------------\n");
			}
			
			if (it == OurBeers.end())
			{
				printf("\n * End of Display. Press any key to return to main menu. *\n");
				_getch();
				system("cls");
			}
		}
		printf("\n\n");
	}
	system("cls");
}





/**
*\brief This method will prompt the user for a number of entries to generate and then create and attempt to insert that many Beer objects
* into the BeerFridge. The objects will be populated with random data and this function will mainly be used for testing purposes.
*
* \return
Nothing is returned by this method
*
*/

void BeerFridge::AddRandomData(void){

	srand(time(NULL));
	Beer* newbeer = NULL;
	string *name = new string;
	string *brewery = new string;
	float alcohol = 0.00;
	string *type = new string;
	int ibu = 0;

	int howMany = 0;
	bool validInput = false;
	printf("\nHow many random entries to generate? ");
	
	while (validInput == false) //while we don't have valid user input...
	{
		try
		{
			Bartender::GetInt(howMany);
			validInput = true;
		}
		catch (string& error)
		{
			printf("%s is invalid. Please input a valid number.\n",error.c_str());
		}
	}
	printf("\n");
	int numberAdded = 0;
	for (int counter = 0; counter < howMany; ++counter){

		*name = random(rand() % 15 + 1);
		*brewery = random(rand() % 16);
		alcohol = (rand() % 1000 + 1) / 10.0;
		*type = randomType(rand() % 16);
		ibu = rand() % 2500 + 1;
		try{
			newbeer = new Beer(*name, *brewery, alcohol, *type, ibu);
			OurBeers.insert(*newbeer);
			delete newbeer;
			++numberAdded;
		}
		catch (...){
			printf("ERROR: Random entry #%d not successful.\n",counter);
		}
	}
	printf("\n%d/%d entries successfully added to database.\n", numberAdded, howMany);
	printf("Push any key to continue.");
	_getch();

	delete name;
	delete brewery;
	delete type;
	system("cls");
}





/**
*\brief This method will call a function to search the BeerFridge for a Beer matching the user's specifications. If found, it will display the Beer
* and offer different options of what to do with it (delete, modify, continue)
*
* \param searchString			- string to search for
* \param searchIBU				- IBU value to search for
* \param searchAlcoholContent	- alcohol content value to search for
* \param searchBy				- what value we are searching by
*
* \return
Nothing is returned by this method
*
* \see FindBeer()
*
*/

void BeerFridge::BeerSearch(string& searchString,int& searchIBU,float& searchAlcoholContent,int& searchBy)
{
	char button = ' ';

	bool matchesFound = false;
	TheBeers::iterator it = OurBeers.begin(); //create our iterator
	
		system("cls");

			if (OurBeers.size() == 0)
			{
				printf("Database is empty. Please add data before trying to search.\n");
				printf("Press any key to return to the Main Menu.");
				_getch();
			}
			else
			{
				int counter = 1; //a counter so only 20 items display at a time
				button = ' '; //reset the value of the button
				printf("\n#(In Database)| %-15s %-15s %-15s %-7s %-5s \n", "Name", "Brewery", "Type", "Alc %", "IBU");
				printf("--------------|------------------------------------------------------------\n");
				for (it = OurBeers.begin(); it != OurBeers.end();)
				{
					if ((it = find_if(it, OurBeers.end(), FindBeer(searchString, searchIBU, searchAlcoholContent, searchBy))) != OurBeers.end()) //if we find a beer and aren't at the end of the list
					{
						//this will print the contained items information and it's position in the list, the user will use that position to choose which item to change if they choose to
						printf("%-14d| %-15s %-15s %-15s %-7.1f %-5d \n", distance(OurBeers.begin(), it) + 1, it->GetDisplayName().c_str(), it->GetDisplayBrewery().c_str(), it->GetDisplayType().c_str(), it->GetAlcoholContent(), it->GetIBU());
						++counter;
						matchesFound = true; //so we only prompt if a match is found!
						++it;
					}
					if ((counter > kBeersToDisplay) && (it != OurBeers.end())){
						printf("\n1. Modify Item\t 2.Delete Item\t 3. Back to Search Menu\t 4. Keep Going\n"); //give them an option to change or stop searching at this point
						button = _getch();
						if (button >= kMenuOptionOne && button <= kMenuOptionThree) //if they select 1,2,3 then stop the loop
						{
							break;
						}
						counter = 1;
						system("cls");
						printf("\n#(In Database)| %-15s %-15s %-15s %-7s %-5s \n", "Name", "Brewery", "Type", "Alc %", "IBU"); //if proceeding, repring the display
						printf("--------------|------------------------------------------------------------\n");
					}
					if (it == OurBeers.end())
					{

						printf("\n * End of search. *\n");
						if (matchesFound == true)
						{
							printf("1. Modify An Item\t 2. Delete Item\t\t 3. Back to Search Menu\n"); //give them an option to change or stop searching at this point
							while (button != kMenuOptionOne && button != kMenuOptionTwo && button != kMenuOptionThree)
							{
								button = _getch();
							}
						}
						else
						{
							printf("No Matches found. Press any key to go back to search menu.\n");
							_getch();
						}
					}
				}

				searchString.clear();

				int itemPosition = 0;
				if (button == kMenuOptionOne || button == kMenuOptionTwo)
				{
					bool validEntry = false;
					while (validEntry == false)
					{
						printf("Select item to change by number (shown in the left hand column)\n or 'x' to cancel: ");
						getline(cin, searchString);
						cin.clear();
						if (searchString == "x")
						{
							break;
						}
						sscanf(searchString.c_str(), "%d", &itemPosition);
						if (itemPosition <= OurBeers.size() && itemPosition > 0)
						{
							if (button == kMenuOptionOne)
							{
								ChangeABeer(--itemPosition);
								validEntry = true;
							}
							else if (button == kMenuOptionTwo)
							{
								DrinkABeer(--itemPosition); //subtract one as we added one to the printout in the beer search
								validEntry = true;
							}
						}
						else
						{
							printf("Please enter a valid entry number. Or press 'x' to cancel\n");
						}
					}

				}
			}

	system("cls"); //ABC - Always Be Clearin'!
}





/**
*\brief This method will be called once the user has located a Beer they wish to delete. It will prompt them one time to make sure
* that they want to delete the Beer, and then erase the Beer from the BeerFridge.
*
* \param beerPosition - the position in the BeerFridge that the Beer is in
*
* \return
Nothing is returned by this method
*
* \see FindBeer()
* \see BeerSearch()
*
*/

void BeerFridge::DrinkABeer(int beerPosition)
{
	TheBeers::iterator it = OurBeers.begin();
	char confirmDelete = ' ';
	system("cls");
	advance(it, beerPosition);
	printf("Are you sure you want to delete:\n\n");
	printf("Beer Name: %s\n", it->GetName().c_str());
	printf("Brewery: %s\n", it->GetBrewery().c_str());
	printf("Beer Type: %s\n", it->GetType().c_str());
	printf("Alcohol Content: %.2f\n", it->GetAlcoholContent());
	printf("IBU: %d\n", it->GetIBU());
	printf("\nPress 'y' to delete beer, press any key to go back to search.\n");

	confirmDelete = _getch();

	if (confirmDelete == 'y')
	{
		OurBeers.erase(it);
		printf("Hopefully you drank that beer...Beer Deleted\nPress any key to return to search.");
		_getch();
	}
	system("cls");
}





/**
*\brief This method will be called once the user has located a Beer they wish to modify. It will prompt them to select from a 
* menu which attribute they wish to modify and then ask them to enter a new value. It will ensure the value is valid and then
* update the Beer in the BeerFridge
*
* \param beerPosition - the position in the BeerFridge that the Beer is in
*
* \return
Nothing is returned by this method
*
* \see FindBeer()
* \see BeerSearch()
*
*/

void BeerFridge::ChangeABeer(int beerPosition)
{
	TheBeers::iterator it = OurBeers.begin();
	string newString = "";
	float newAContent = 0;
	int newIBU = 0;
	char confirmChange = ' ';
	bool isAccepted = false;
	bool quit = false;

	istringstream iss;

	advance(it, beerPosition); // move our iterator to where the desired beer to modify is in the database

	Beer tmpBeer = *it; //use the default copy construct so that we may edit the beer to be displayed

	do{
		system("cls");
							//present menu
		printf("Beer Name: %s\n", it->GetName().c_str());
		printf("Brewery: %s\n", it->GetBrewery().c_str());
		printf("Beer Type: %s\n", it->GetType().c_str());
		printf("Alcohol Content: %.2f\n", it->GetAlcoholContent());
		printf("IBU: %d\n\n", it->GetIBU());

		printf("What would you like to change for this beer \n");
		printf("___________________________________\n");
		printf("1.\tName\n");
		printf("2.\tBrewery\n");
		printf("3.\tBeer Type\n");
		printf("4.\tAlcohol Content\n");
		printf("5.\tIBU\n");
		printf("6.\tTAKE ME BACK!!!!\n");

		confirmChange = _getch();
		isAccepted = false;

		switch (confirmChange) //a switch to handle the modifications
		{
		case (kMenuOptionOne) :
			while (isAccepted == false)
			{
				try
				{
					printf("Enter a new name or press enter to skip and not change entry: ");
					getline(cin, newString);
					if (newString == "")
					{
						isAccepted = true;
					}
					else
					{
						tmpBeer.SetName(newString); //set the temporary beer variable
						OurBeers.erase(it); //erase the old one and then inser the new accepted beer
						it = OurBeers.insert(tmpBeer); //the insert returns the location of the insertion, set our iterator to this
						isAccepted = true;
					}
				}
				catch (string& error)
				{
					printf("%s is an invalid name.\n", error.c_str());
				}
			}
				   break;
		case (kMenuOptionTwo) :
			while (isAccepted == false)
			{
				try
				{
					printf("Enter a new brewery or press enter to skip and not change entry: ");
					getline(cin, newString);
					if (newString != "")
					{
						tmpBeer.SetBrewery(newString);
						OurBeers.erase(it);
						it = OurBeers.insert(tmpBeer);
					}
					isAccepted = true;
				}
				catch (string& error)
				{
					printf("%s is an invalid brewery.\n", error.c_str());
				}
			}
				   break;
		case (kMenuOptionThree) :
			while (isAccepted == false)
			{
				try
				{
					printf("Enter a new beer type or press enter to skip and not change entry: ");
					getline(cin, newString);
					if (newString != "")
					{
						tmpBeer.SetType(newString);
						OurBeers.erase(it);
						it = OurBeers.insert(tmpBeer);
					}
					isAccepted = true;
				}
				catch (string& error)
				{
					printf("%s is an invalid type.\n ", error.c_str());
				}
			}
				   break;
		case (kMenuOptionFour) :
			while (isAccepted == false)
			{
				try
				{
					printf("Enter a new Alcohol Content or press enter to skip and not change entry: ");
					getline(cin, newString);
					iss.str(newString);
					if (newString.length() != 0)
					{
						if (Bartender::GetFloat(newAContent,iss) == true)
						{
							tmpBeer.SetAlcoholContent(newAContent);
							OurBeers.erase(it);
							it = OurBeers.insert(tmpBeer);
						}
						
					}
					isAccepted = true;
				}
				catch (float& error)
				{
					printf("%f is an invalid alcohol content.\n ", error);
				}
			}
				   break;
		case (kMenuOptionFive) :
			while (isAccepted == false)
			{
				try
				{
					printf("Enter a new IBU or press enter to skip and not change entry: ");
					getline(cin, newString);
					iss.str(newString);
					if (newString.length() != 0)
					{
						if (Bartender::GetInt(newIBU,iss) == true)
						{
							tmpBeer.SetIBU(newIBU);
							OurBeers.erase(it);
							it = OurBeers.insert(tmpBeer);
						}
						
					}
					isAccepted = true;
				}
				catch (int& error)
				{
					printf("%d is an invalid IBU.\n", error);
				}
			}
				   break;
		case (kMenuOptionSix) :
			quit = true;
		default:
			break;
		}

		system("cls");

	} while (quit != true);
}



/**
*\brief This method will be called to output the contents of the BeerFridge to a text file.
*
* \return
Nothing is returned by this method
*
*/

void BeerFridge::DumpFridge()
{
	ofstream outputStream;

	outputStream.open(kInputOutputFile, ios::out | ios::binary);

	if (outputStream.fail())
	{
		printf("There was an error opening the outputfile...\n");
	}
	else
	{
		for (TheBeers::iterator it = OurBeers.begin(); it != OurBeers.end(); ++it)
		{
			outputStream << *it;
			if (outputStream.fail())
			{
				printf("Error writing data to file...stopping output and closing program...");
				break;
			}
		}

		outputStream.close();

		if (outputStream.fail())
		{
			printf("There was an error in closing the output file");
		}
	}
}

/**
*\brief This method will be called to empty (erase) the contents of the BeerFridge
*
* \return
Nothing is returned by this method
*
*/

void BeerFridge::EmptyFridge()
{
	this->OurBeers.clear();
	system("cls");
}





/**
*\brief This overloaded operator is called to read data from a file and store it in the database
*
* \param istream& is - the input stream of data to be stored
*
* \param TheBeers& list - the list of Beers to add the new Beers to
*
* \return istream& is - the input stream of data to be stored
*
*/

void operator >>(istream& is, TheBeers& list)
{
	Beer* tmpBeer = NULL;
	string readName = "";
	string readBrewery = "";
	string readOther = ""; //will be used to grab the alcohol content and IBU from the file
	string readType = "";
	int readIBU = 0;
	float readAContent = 0;
	int counter = 0;

	while (!is.eof())
	{
		
		try
		{
			getline(is, readName, '\n'); //get the name
			getline(is, readBrewery, '\n'); //get the brewery
			Bartender::GetFloat(readAContent, is);
			getline(is, readType, '\n'); //get the beer type
			Bartender::GetInt(readIBU, is);

			tmpBeer = new Beer(readName, readBrewery, readAContent, readType, readIBU); //call the construct to create the beer
			list.insert(*tmpBeer); //copy beer into multiset
			delete tmpBeer; //delete the temporary holder
			printf("Added %.5d Files", ++counter);
			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		}
		catch (bad_alloc& error) //if there's an error with instantiating a new beer one of the catch blocks will handle it
		{
			printf("MEMORY ALLOCATION ERROR: %s", error.what());
		}
		catch (string& error) //if there was an error BUT we are at EOF, reading in EOF as data therefore do not flag error
		{
			if(!is.eof())
			{
				printf("CORRUPTION WITH DATABASE FILE! %s is an invalid string entry.\n Will continue to read from file...Press any key to continue.", error.c_str());
				_getch();
			}
			
		}
		catch (float& error)//if there was an error BUT we are at EOF, reading in EOF as data therefore do not flag error
		{
			if (!is.eof())
			{
				printf("CORRUPTION WITH DATABASE FILE! %f is an invalid alcohol content entry.\n Will continue to read from file...Press any key to continue.", error);
				_getch();
			}

		}
		catch (unsigned int& error)//if there was an error BUT we are at EOF, reading in EOF as data therefore do not flag error
		{
			if (!is.eof())
			{
				printf("CORRUPTION WITH DATABASE FILE! %s id an invalid IBU entry.\n Will continue to read from file...Press any key to continue.", error);
				_getch();
			}

		}
	}
	//return is;
}
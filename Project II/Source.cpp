/*---------------------------------------------------
-	Budget Program									-
-	Created by: Rey Christopher D. Aparece			-
-													-
-	Description: This program will read in budget	-
-	information from a file and will calculate how	-
-	much the user has spent and how much they have	-
-	left in their budget. A load from last save		-
-	feature has been implemented.					-
-													-
-	*go to bottom for more information on the		-
-	programming process								-
---------------------------------------------------*/

#include "budgetStuff.h"
#include <iostream>
#include <fstream>
#include <iomanip>

//function will generate menu
void menu();

int main()
{
	//just so the world knows I made this
	std::cout << "COSC1437 Final Project" << std::endl;
	std::cout << "Created by: Rey Christopher D. Aparece" << std::endl;
	system("pause");
	system("CLS");

	//quit will check if user quits flag will check for correct choice
	bool quit = false;
	bool flag = false;

	//use for decision making
	int choice;

	//used to calculate how many items were added
	int amtHouse = 0;
	int amtUtility = 0;
	int amtFood = 0;

	//this will check for the id tag and add items to appropriate classes
	std::string idChoice;

	//input files
	std::ifstream inFile1;
	std::ifstream inFile2;
	inFile1.open("spentitems.txt");
	inFile2.open("budget.txt");
	
	//temporarily initialized classes, will be replaced once information is loaded
	Housing home("", 0, "", 0.0);
	Utilities utes("", 0, "", 0.0);
	Food foods("", 0, "", 0.0);

	do {
		//will clear the screen just to make the output cleaner
		system("CLS");
		menu();
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice) {
		case 1:
			//load info from spentitems.txt
			while (!inFile1.eof()) {
				//variables for child class
				std::string id;
				std::string name;

				double cost;

				//read in info from spentitems.txt
				inFile1 >> id;
				inFile1 >> name;
				inFile1 >> cost;

				//initizlize temp object of SpentItemType
				SpentItemType temp(id, name, cost);

				//check id tag
				if (id.compare("H") == 0) {
					++amtHouse;

					//set information for home object
					home.SetInformation(id, amtHouse, temp, "", "", 0);
				}
				else if (id.compare("U") == 0) {
					++amtUtility;

					//set information for utes object
					utes.SetInformation(id, amtHouse, temp, "", "", 0);
				}
				else if (id.compare("F") == 0) {
					++amtFood;

					//set information for foods object
					foods.SetInformation(id, amtHouse, temp, "", "", 0);
				}

				/*NOTE: I'm not too sure about the redundancy of this code
				but from prior experience, exluding it will cause the program
				to read in the last line twice from the file.*/
				if (inFile1.eof())
					break;
			}

			//load info from budget.txt
			while (!inFile2.eof()) {
				//variables for parent class
				std::string budID;
				std::string budName;
				double amt;

				inFile2 >> budID;
				inFile2 >> budName;
				inFile2 >> amt;

				if (budID.compare("H") == 0) {
					home.SetBudgetItemInformation(budID, budName, amt);
				}
				else if (budID.compare("U") == 0) {
					utes.SetBudgetItemInformation(budID, budName, amt);
				}
				else if (budID.compare("F") == 0) {
					foods.SetBudgetItemInformation(budID, budName, amt);
				}

				if (inFile2.eof())
					break;
			}
			std::cout << "File loaded\n\n";
			system("pause");
			break;

		case 2:
			system("CLS");
			//will be used to check for valid input
			std::cout << "Please enter a new item\n";
			std::cout << "Please enter the budget item ID: ";

			//this will loop until user has made correct choice
			do {
				std::cin >> idChoice;
				if (idChoice.compare("H") == 0 || idChoice.compare("U") == 0 || idChoice.compare("F") == 0)
				{
					flag = true;
				}
				else {
					std::cout << "Please only enter H, U, or F: ";
					flag = false;
				}
			} while (!flag);

			//add new items to respective classes
			if (idChoice.compare("H") == 0) {
				home.AddNewSpentItem(idChoice);
			}
			else if (idChoice.compare("U") == 0) {
				utes.AddNewSpentItem(idChoice);
			}
			else if (idChoice.compare("F") == 0) {
				foods.AddNewSpentItem(idChoice);
			}
			break;

		case 3:
			system("CLS");
			//output info to screen and separate txt files
			home.PrintInformation();
			utes.PrintInformation();
			foods.PrintInformation();
			system("pause");
			break;

		case 4:
			//save information for later changes
			home.SaveInformation();
			utes.SaveInformation();
			foods.SaveInformation();
			std::cout << "Saved\n\n" << std::endl;
			system("pause");
			break;

		case 5:
			//quit
			system("CLS");
			std::cout << "Thanks! Good Bye\n";
			quit = true;
			break;

		default:
			std::cout << "Invalid Choice" << std::endl;
			system("pause");
		}
	} while (!quit);

	inFile1.close();
	inFile2.close();
	return 0;


}

//function to create menu
void menu() {
	std::cout << std::left << std::setw(10) << "1." << "Load Budget & Spent Items data\n"
		<< std::left << std::setw(10) << "2." << "Add Budget Item\n"
		<< std::left << std::setw(10) << "3." << "Print Budget Report\n"
		<< std::left << std::setw(10) << "4." << "Save Budget & Spent Information\n"
		<< std::left << std::setw(10) << "5." << "Exit Budget" << std::endl;
}


/*PROGRAMMING PROCESS:
  While not necessarily difficult, I tried to do this all in one go and I ended
  up completing it within 5 or so hours (including coffee breaks). I started by
  creating classes. I made a minor change to two things, which was change the private
  members of BudgetItems to protected and made the SpentItemsType array to a vector. I've solved this issue before, but I couldn't 
  figure out how to access it.
  
  After creating my classes, I moved on to my methods
  file; I looked at the requirements on the project document and coded along the lines
  of it. I defined all the methods for all the required functions, but I actually
  ended up not using a handful of them for my code (such as the get functions; 
  you'll probably see that in my source code). Figuring out the save and load
  function was pretty simple as it was similar to the print functions, with 
  the exception that I cleared the file first and apprehended each group one after
  the other - which is why the new spentitems file has each item grouped in terms
  of id tag.
  
  The main function was fairly simple and actually tried to clean it up using a
  separate method to generate the menu. I added a bit of flair, such as the screen
  clearing and displaying all the information and the intro screen.*/
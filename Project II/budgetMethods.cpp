#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "budgetStuff.h"


			/*------------------------SPENTITEM CLASS------------------------*/

//constructor
SpentItemType::SpentItemType(std::string id = "NoID", std::string name = "NoName", double amt = 0) {
	SpentItemTypeID = id;
	SpentItemTypeName = name;
	SpentItemTypeAmount = amt;
}

//member functions
void SpentItemType::SetSpentItemInformation(std::string id, std::string name, double amt) {
	SpentItemTypeID = id;
	SpentItemTypeName = name;
	SpentItemTypeAmount = amt;

	while (SpentItemTypeAmount <= 0)
	{
		std::cout << "Enter amount greater than 0: ";
		std::cin >> SpentItemTypeAmount;
	}
}

//return the id
std::string SpentItemType::GetSpentItemTypeID() {
	return SpentItemTypeID;
}

//return the name
std::string SpentItemType::GetSpentItemTypeName() {
	return SpentItemTypeName;
}

//return amount
double SpentItemType::GetSpentItemTypeAmount() {
	return SpentItemTypeAmount;
}

			/*-----------------------BUDGETITEMS CLASS-----------------------*/

//constructor
BudgetItems::BudgetItems(std::string id = "NoID", std::string name = "NoName", double amt = 0) {
	BudgetItemID = id;
	BudgetItemName = name;
	BudgetItemAmount = amt;
	
}

//member functions
void BudgetItems::SetBudgetItemInformation(std::string id, std::string name, double amt) {
	BudgetItemID = id;
	BudgetItemName = name;
	BudgetItemAmount = amt;

	//loop until budget information is set
	while (BudgetItemAmount <= 0)
	{
		std::cout << "Enter amount greater than 0: ";
		std::cin >> BudgetItemAmount;
	}
}

//return id
std::string BudgetItems::GetBudgetItemID() {
	return BudgetItemID;
}

//return name
std::string BudgetItems::GetBudgetItemName() {
	return BudgetItemName;
}

//return amount
double BudgetItems::GetBudgetItemAmount() {
	return BudgetItemAmount;
}



			/*-------------------------HOUSING CLASS-------------------------*/
//constructor
Housing::Housing(std::string id, int num, std::string name, double amt) : BudgetItems(id, name, amt) {
	itemID = id;
	Numberofitem = num;
	SpentItemType item;
}

//this function will set information
void Housing::SetInformation(std::string itmID, int numIt, SpentItemType itNm, std::string bdgtID, std::string bdgtNm, double bdgtAmt) {
	itemID = itmID;
	Numberofitem = numIt;
	itemName.push_back(itNm);
	BudgetItemID = bdgtID;
	BudgetItemName = bdgtNm;
	BudgetItemAmount = bdgtAmt;
}

//function to add new item
void Housing::AddNewSpentItem(std::string id) {
	std::string name;
	double amt;

	std::cout << "Please enter the budget item name: ";
	std::cin.get();
	getline(std::cin, name);

	std::cout << "Please enter the budget amount: ";
	std::cin >> amt;

	SpentItemType temp(id, name, amt);
	itemName.push_back(temp); //add itemName to vector
}

//return number of items
int Housing::GetNumberOfItem() {
	return Numberofitem;
}

//return the total spent
double Housing::GetTotalSpentAmount() {
	double amt = 0;
	for (int i = 0; i < 10; i++) {
		amt += itemName[i].GetSpentItemTypeAmount();
	}

	return amt;
}

//return the amount left in budget
double Housing::GetAmountLeftInBudget(double spentAmt) {
	return BudgetItemAmount - spentAmt;
}

//print info
void Housing::PrintInformation() {
	//used to calculate amount spent
	double amt = 0;

	//output to file
	std::ofstream outFile;
	outFile.open("Housing_ApareceReyChristopher.txt");
	
	outFile << "Housing item ID is " << itemID << std::endl;

	//will output information to file
	for (int i = 0; i < itemName.size(); i++) {
		outFile << std::right << std::setw(2) << itemName[i].SpentItemTypeID
			<< std::right << std::setw(15) << itemName[i].SpentItemTypeName
			<< std::right << std::setw(10) << itemName[i].GetSpentItemTypeAmount() << std::endl;

		//calculate amount spent
		amt += itemName[i].GetSpentItemTypeAmount();
	}

	//total spent and amount left will be outputted in two decimal places
	outFile << std::fixed << std::setprecision(2) 
		<< "The total of all the items purchased is " << amt
		<< "\nThe amount left in the Housing Budget is " << BudgetItemAmount - amt;
	outFile.close();

	//print to screen
	amt = 0;
	std::cout << "Housing item ID is " << itemID << std::endl;

	for (int i = 0; i < itemName.size(); i++) {
	std::cout << std::right << std::setw(2) << itemName[i].SpentItemTypeID
			<< std::right << std::setw(15) << itemName[i].SpentItemTypeName
			<< std::right << std::setw(10) << itemName[i].GetSpentItemTypeAmount() << std::endl;

		amt += itemName[i].GetSpentItemTypeAmount();
	}

	std::cout << std::fixed << std::setprecision(2) 
		<< "The total of all the items purchased is " << amt
		<< "\nThe amount left in the Housing Budget is " << BudgetItemAmount - amt
		<< std::endl;
	std::cout << "-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n\n\n";
}

//save info for later use
void Housing::SaveInformation() {
	std::ofstream outFile;
	//clear file before writing
	outFile.open("spentitems.txt", std::ofstream::out | std::ofstream::trunc);
	
	//output to spentitems.txt
	for (int i = 0; i < itemName.size(); i++) {
		outFile << itemName[i].SpentItemTypeID << " "
			<< itemName[i].SpentItemTypeName << " "
			<< itemName[i].GetSpentItemTypeAmount() << std::endl;
	}

	outFile.close();
}



			/*------------------------UTILITIES CLASS------------------------*/
//constructor
Utilities::Utilities(std::string id, int num, std::string name, double amt) : BudgetItems(id, name, amt) {
	itemID = id;
	Numberofitem = num;
	SpentItemType item;
}

/*NOTE: member functions all work the same as the housing class */
void Utilities::SetInformation(std::string itmID, int numIt, SpentItemType itNm, std::string bdgtID, std::string bdgtNm, double bdgtAmt) {
	itemID = itmID;
	Numberofitem = numIt;
	itemName.push_back(itNm);
	BudgetItemID = bdgtID;
	BudgetItemName = bdgtNm;
	BudgetItemAmount = bdgtAmt;
}

void Utilities::AddNewSpentItem(std::string id) {
	std::string name;
	double amt;

	std::cout << "Please enter the budget item name: ";
	std::cin.get();
	getline(std::cin, name);

	std::cout << "Please enter the budget amount: ";
	std::cin >> amt;

	SpentItemType temp(id, name, amt);
	itemName.push_back(temp);

}

int Utilities::GetNumberOfItem() {
	return Numberofitem;
}

double Utilities::GetTotalSpentAmount() {
	double amt = 0;
	for (int i = 0; i < 10; i++) {
		amt += itemName[i].GetSpentItemTypeAmount();
	}

	return amt;
}

double Utilities::GetAmountLeftInBudget(double spentAmt) {
	return BudgetItemAmount - spentAmt;
}

void Utilities::PrintInformation() {
	double amt = 0;

	//output to file
	std::ofstream outFile;
	outFile.open("Utilities_ApareceReyChristopher.txt");

	outFile << "Utilities item ID is " << itemID << std::endl;

	for (int i = 0; i < itemName.size(); i++) {
		outFile << std::right << std::setw(2) << itemName[i].SpentItemTypeID
			<< std::right << std::setw(15) << itemName[i].SpentItemTypeName
			<< std::right << std::setw(10) << itemName[i].GetSpentItemTypeAmount() << std::endl;

		amt += itemName[i].GetSpentItemTypeAmount();
	}

	outFile << std::fixed << std::setprecision(2) 
		<< "The total of all the items purchased is " << amt
		<< "\nThe amount left in the Utilities Budget is " << BudgetItemAmount - amt;
	outFile << "-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n\n\n";
	outFile.close();

	//print to screen
	amt = 0;
	std::cout << "Utilities item ID is " << itemID << std::endl;

	for (int i = 0; i < itemName.size(); i++) {
		std::cout << std::right << std::setw(2) << itemName[i].SpentItemTypeID
			<< std::right << std::setw(15) << itemName[i].SpentItemTypeName
			<< std::right << std::setw(10) << itemName[i].GetSpentItemTypeAmount() << std::endl;

		amt += itemName[i].GetSpentItemTypeAmount();
	}

	std::cout << std::fixed << std::setprecision(2) 
		<< "The total of all the items purchased is " << amt
		<< "\nThe amount left in the Utilities Budget is " << BudgetItemAmount - amt
		<< std::endl;
	std::cout << "-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n\n\n";

}

void Utilities::SaveInformation() {
	std::ofstream outFile;

	//apprehend to spentitems.txt
	outFile.open("spentitems.txt", std::ios_base::app);

	for (int i = 0; i < itemName.size(); i++) {
		outFile << itemName[i].SpentItemTypeID << " "
			<< itemName[i].SpentItemTypeName << " "
			<< itemName[i].GetSpentItemTypeAmount() << std::endl;
	}

	outFile.close();
}


/*---------------------------FOOD CLASS--------------------------*/

//constructor
Food::Food(std::string id, int num, std::string name, double amt) : BudgetItems(id, name, amt) {
	itemID = id;
	Numberofitem = num;
	SpentItemType item;
}

/*NOTE: member functions all work the same as the housing class */
void Food::SetInformation(std::string itmID, int numIt, SpentItemType itNm, std::string bdgtID, std::string bdgtNm, double bdgtAmt) {
	itemID = itmID;
	Numberofitem = numIt;
	itemName.push_back(itNm);
	BudgetItemID = bdgtID;
	BudgetItemName = bdgtNm;
	BudgetItemAmount = bdgtAmt;
}

void Food::AddNewSpentItem(std::string id) {
	std::string name;
	double amt;

	std::cout << "Please enter the budget item name: ";
	std::cin.get();
	getline(std::cin, name);

	std::cout << "Please enter the budget amount: ";
	std::cin >> amt;

	SpentItemType temp(id, name, amt);
	itemName.push_back(temp);
}

int Food::GetNumberOfItem() {
	return Numberofitem;
}

double Food::GetTotalSpentAmount() {
	double amt = 0;
	for (int i = 0; i < 10; i++) {
		amt += itemName[i].GetSpentItemTypeAmount();
	}

	return amt;
}

double Food::GetAmountLeftInBudget(double spentAmt) {
	return BudgetItemAmount - spentAmt;
}

void Food::PrintInformation() {
	double amt = 0;

	//output to file
	std::ofstream outFile;
	outFile.open("Food_ApareceReyChristopher.txt");

	outFile << "Food item ID is " << itemID << std::endl;

	for (int i = 0; i < itemName.size(); i++) {
		outFile << std::right << std::setw(2) << itemName[i].SpentItemTypeID
			<< std::right << std::setw(25) << itemName[i].SpentItemTypeName
			<< std::right << std::setw(10) << itemName[i].GetSpentItemTypeAmount() << std::endl;

		amt += itemName[i].GetSpentItemTypeAmount();
	}

	outFile << std::fixed << std::setprecision(2) 
		<< "The total of all the items purchased is " << amt
		<< "\nThe amount left in the Food Budget is " << BudgetItemAmount - amt;
	outFile << "-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n\n\n";
	outFile.close();

	//print to screen
	amt = 0;
	std::cout << "Food item ID is " << itemID << std::endl;

	for (int i = 0; i < itemName.size(); i++) {
		std::cout << std::right << std::setw(2) << itemName[i].SpentItemTypeID
			<< std::right << std::setw(15) << itemName[i].SpentItemTypeName
			<< std::right << std::setw(10) << itemName[i].GetSpentItemTypeAmount() << std::endl;

		amt += itemName[i].GetSpentItemTypeAmount();
	}

	std::cout << std::fixed << std::setprecision(2) 
		<< "The total of all the items purchased is " << amt
		<< "\nThe amount left in the Food Budget is " << BudgetItemAmount - amt
		<< std::endl;
	std::cout << "-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n\n\n";

}

void Food::SaveInformation() {
	std::ofstream outFile;
	//apprehend to spentitems.txt
	outFile.open("spentitems.txt", std::ios_base::app);

	for (int i = 0; i < itemName.size(); i++) {
		outFile << itemName[i].SpentItemTypeID << " "
			<< itemName[i].SpentItemTypeName << " "
			<< itemName[i].GetSpentItemTypeAmount() << std::endl;
	}

	outFile.close();
}
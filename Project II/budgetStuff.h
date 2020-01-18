#ifndef BUDGETSTUFF_H_
#define BUDGETSTUFF_H_

#include <iostream>
#include <vector>

class SpentItemType {
	private:
		double SpentItemTypeAmount;

	public:
		std::string SpentItemTypeID;
		std::string SpentItemTypeName;

		//constructor
		SpentItemType(std::string, std::string, double);

		//member functions
		void SetSpentItemInformation(std::string, std::string, double);
		std::string GetSpentItemTypeID();
		std::string GetSpentItemTypeName();
		double GetSpentItemTypeAmount();
};


class BudgetItems {
	protected:
		double BudgetItemAmount;

	public:
		std::string BudgetItemID;
		std::string BudgetItemName;

		//constructor
		BudgetItems(std::string, std::string, double);

		//member functions
		void SetBudgetItemInformation(std::string, std::string, double);
		std::string GetBudgetItemID();		
		std::string GetBudgetItemName();
		double GetBudgetItemAmount();
		virtual void PrintInformation() = 0;
		virtual void SaveInformation() = 0;

};

class Housing : public BudgetItems {
	private:
		std::string itemID;
		int Numberofitem;
		std::vector<SpentItemType> itemName;

	public:
		//constructor
		Housing(std::string, int num, std::string, double);

		//member functions
		void SetInformation(std::string, int, SpentItemType, std::string, std::string, double);
		void AddNewSpentItem(std::string id);
		int GetNumberOfItem();
		double GetTotalSpentAmount();
		double GetAmountLeftInBudget(double);
		virtual void PrintInformation();
		virtual void SaveInformation();
};

class Food : public BudgetItems {
	private:
		std::string itemID;
		int Numberofitem;
		std::vector<SpentItemType> itemName;

	public:
		//constructor
		Food(std::string, int num, std::string, double);

		//member functions
		void SetInformation(std::string, int, SpentItemType, std::string, std::string, double);
		void AddNewSpentItem(std::string);
		int GetNumberOfItem();
		double GetTotalSpentAmount();
		double GetAmountLeftInBudget(double);
		virtual void PrintInformation();
		virtual void SaveInformation();
};

class Utilities : public BudgetItems {
	private:
		std::string itemID;
		int Numberofitem;
		std::vector<SpentItemType> itemName;

	public:
		//constructor
		Utilities(std::string, int num, std::string, double);

		//member functions
		void SetInformation(std::string, int, SpentItemType, std::string, std::string, double);
		void AddNewSpentItem(std::string);
		int GetNumberOfItem();
		double GetTotalSpentAmount();
		double GetAmountLeftInBudget(double);
		virtual void PrintInformation();
		virtual void SaveInformation();
};
#endif // !BUDGETSTUFF_H_

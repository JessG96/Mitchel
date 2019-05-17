#includes "stdafx.h"
#include "MitchCloud.h"
#include <istream>
#include <time.h>
usinig namespace std;

//===============REGISTER CLASS IMPLEMENTATION===========================

void Register::login()
{
  string username;
  string password;
  
  cout << "Please enter your username." << endl;
  cin >> username;
  cout << "Please enter your password." << endl;
  cin >> password;
  
  do 
  {
    if(m_clerkID.checkUsername(username) == true && m_clerkID.checkPassword(password) == true){
      m_currentUser = m_clerkID;
      break;
    }
    
    if(m_custID.checkUsername(username) == true && m_custID.checkPassword(password) == true){
      m_currentUser = m_custID;
      break;
    }
    
    if(m_managerID.checkUsername(username) == true &&  m_managerID.checkPassword(password) == true){
      m_currentUser = m_managerID;
      break;
    }
    
    if(m_salesAnID.checkUsername(username) == true && m_salesAnID.checkPassword(password) == true){
      m_currentUser = m_salesAnID;
      break;
    }
    
    //Prompt again if wrong username, password or are a different user
    cout << "Please enter your username." << endl;
    cin >> username;
    cout << "Please enter your password." << endl;
    cin >> password;
  }while(true);
}

int Register::displayMenu()
{
  int userInput;
  do
  {
    m_transactionFile << "User: " << m_currentUser.getUsername() << " shows the menu of items to order " << endl;
    cout << "Menu" << endl << "====" << endl;
    
    for(int i = 0; i < m_menu.size(); i++){
      cout << i + 1 << ") ";
      m_menu[i].displayMenuItem();
      cout << endl;
    }
    cout << "Select product from menu or 0 to end" << endl;
    cin >> userInput;
  }while((userInput < 0) || (userInput >= m_menu.size()));
  
  if(userInput == 0){
    m_transactionFile << "User: " << m_currentUser.getUsername() << " selected to end order." << endl;
  }
  else{
    m_transactionFile << "User: " << m_currentUser.getUsername() << " selected item # " << userInput << endl;
  }
  return userInput;
}

void Register::createMenu()
{
  m_menu.push_back(MenuItem("Vanilla Bean IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Chocolate IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Butter Pecan IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Dark Roast Coffee IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Coffee Chocolate Chunk IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Double Chocolate Chunk IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Banana Cream Pie IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Caramel Fudge Brownie IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Caramel Sea Salt IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Cookies & Cream IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Key Lime Pie IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Bing Cherry Chocolate Chunk IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Cookie Dough IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Fresh Strawberry IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Rocky Road IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Fresh Mint Choco Chunk IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Chocolate Peanut Butter Cup IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Blue Cosmo IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Black Raspberry Choco Chunk IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Peanut Butter Choco Chunk IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Pralines & Cream IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Pistachio IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Vanilla Bean Yogurt", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Mango Sorbet", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Raspberry Sorbet", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Vegan Salted Caramel Pecan", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Vegan Chocolate", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("PeanutButter Pretzel Yogurt", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Mint Choco Chunk", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Wildberry Crumble Icecream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Lemon Blackberry Yogurt", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Amaretto Cookie IceCream", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Coffee & Cookies Yogurt", 2.50, "Scoop"));
	m_menu.push_back(MenuItem("Turtle", 26.95, "Pie"));
	m_menu.push_back(MenuItem("Cookies & Cream", 26.95, "Pie"));
	m_menu.push_back(MenuItem("Chocolate Peanut Butter Cup", 26.95, "Cake"));
}

void Register::displayReceipt()
{
  m_sale->displaySale();
  m_transactionFile << "Receipt Printed" << endl;
}

void Register::startSale()
{
 m_sale = new Sale;
  openTransactionLog();
  m_transactionFile << "User: " << m_currentUser.getUsername() << " logged in" << endl;
  m_transactionFile << "Sale started" << endl;
}

void Register::endSale()
{
 m_transactionFile << "Sale is finished." << endl;
  delete m_sale;
  closeTransactionLog();
}

void Register::addSaleItem(int menuSelection, int quantity)
{
 m_transactionFile << "User: " << m_currentUser.getUsername() << " is ordering Item # " << m_sale->getNumberItemsInOrder() + 1 << endl;
 m_sale->createSaleItem(m_menu[menuSelection].getUnits(), quantity);
 
 m_transactionFile << "User: " << m_currentUser.getUsername() << " ordered " << m_menu[menuSelection].getDescription() <, endl;
 m_transactionFile << "User: " << m_currentUser.getUsername() << " selected the amout " << quantity << " " << m_menu[menuSelection].getUnits() << endl;
 
 m_transactionFile << "Price is $" << m_menu[menuSelection].getCost() * quantity << endl;
 m_transactionFile << "subTotal is $" << m_sale->getTotal() << endl;                                   
}

void Register::makePayment()
{
 int type;
  do
  {
    cout << "Please enter payment type, 1 for cash, 2 for credit and 3 for phone pay." << endl;
  }while(type < 1 || type > 3);

  Payment *payment;
  switch(type)
  {
    case 1:
      payment = new Cash();
      break;
    case 2:
      payment = new CreditCard();
      break;
    case 3:
      payment = new PhonePay();
      break;
  }
  payment->setPayment(m_sale->getTotal());
  payment->promptForActNum();
  cout << "Payment transaction is" << payment->getTransaction() << endl;
  m_transactionFile << "Payment chosen: " << payment->getTransaction() << " was successful" << endl;
  delete payment;
}

void Register::openTransactionLog()
{
 time_t now;
 const int MAX_FILE_NAME = 128;
 char fileName[MAX_FILE_NAME];
  
 fileName[0] = '\0';
  
 now = time(NULL);
 if(now ! = -1){
   strftime(fileName, MAX_FILE_NAME, "Log_%m_%d_%Y_%H_%M_%S.txt", gmtime(&now));
 }
 m_transactionFile.open(fileName);
}

void Register::closeTransactionLog()
{
	m_transactionFile.close();
}

void Register::makePayment(int paymentType, string accountNum)
{
	Payment *payment;
	switch(paymentType)
	{
	case 1:
			payment = new Cash();
		break;
	case 2:
		payment = new CreditCard();
		break;
	case 3:
		payment = new PhonePay();
		break;
	}
	payment->setPayment(m_sale->getTotal());
		payment->setAccountNum(accountNum);
	cout << "Payment transaction is" << payment->getTransaction() << endl;
	m_transactionFile << "Payment chosen: " << payment->getTransaction() << " successful" << endl;
delete payment;
}

void Register::interactiveSale()
{
	m_transactionFile << "User: " << m_currentUser.getUsername() << " selected Interactive Transaction" << endl;

	int choice;
	int quantity;

	do
	{
		choice = displayMenu();
		if (choice == 0)
		{
			break;
		}
		cout << "Enter quantity of product" << endl;
		cin >> quantity;
		system("cls");
		addSaleItem(choice, quantity);
		displayReceipt();
	} while (choice != 0);
	makePayment();
}

void Register::salesTransaction()
{
	int input;
	do
	{
		cout << "What type of transaction, File or Interactive? Enter 1 for File or 2 for Interactive." << endl;
		cin >> input;

	} while (input > 2 || input < 1);

	if (input == 1)
	{
		fileSale();
	}
	else
	{
		interactiveSale();
	}
}

void Register::fileSale()
{
	m_transactionFile << "User: " << m_currentUser.getUsername() << " selected File Transaction" << endl;

	string fileName;
	cout << "Enter file name to input data from" << endl;
	cin >> fileName;

	ifstream inputFile(fileName, ifstream::in);
	if (!inputFile.is_open())
	{
		cout << "Error, file: " << fileName << " unable to open" << endl;
		return;
	}
	int commandNumber;
	int item;
	int quantity;
	int paymentType;
	string accountNumber;

	while (inputFile.good())
	{
		inputFile >> commandNumber;
		switch (commandNumber)
		{
		case 1:
			inputFile >> item >> quantity;
			m_transactionFile << "Read Command 1, selection type, item read is " << item << " quantity of item is " << quantity << endl;
			addSaleItem(item, quantity);
			break;
		case 2:
			inputFile >> paymentType;
			m_transactionFile << "Read Command 2, selected Payment Type is " << paymentType << endl;
			accountNumber = " ";
			if (paymentType != 1) //not a cash payment get account number
			{
				inputFile >> accountNumber;
			}
			makePayment(paymentType, accountNumber);
			break;

		default:
			m_transactionFile << "Invalid command read from file. Command number read was: " << commandNumber << endl;
		}
	}
	inputFile.close();
}

bool Register::performAnotherTransaction()
{
	string input;
	cout << "Would you like to perform another transaction? [Yes/No]" << endl;
	cin >> input;
	for (int i = 0; i < input.size(); i++)
	{	

	input.at(i) = toupper(input.at(i));
}	
	if (input == "YES")
	{
		return true;
	}
	else
	{
		return false;
	}
}
//===============================CLERK USERINFO IMPLEMENTATION=========================================
bool UserInfo::checkUsername(string name)
{
	if (name != m_userName)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool UserInfo::checkPassword(string password)
{
	if (password != m_Password)
	{
		return false;
	}
	else
	{
		return true;

	}
}
//=======================SALE CLASS IMPLEMENTATION==================================================
void Sale::createSaleItem(MenuItem item, int amount)
{
	m_sale.push_back(Item(amount, item));
}

void Sale::displaySale()
{
	cout << endl << endl;
	cout << "Reciept" << endl;
	cout << "=======" << endl;
	for (int i = 0; i < m_sale.size(); i++)
	{

		m_sale[i].displayItem();
	}
	cout << "Final Total is $" << getTotal();
	cout << endl << endl;
}

double Sale::getTotal()
{
	double finalTotal = 0;
	for (int i = 0; i < m_sale.size(); i++)
	{
		finalTotal += m_sale[i].getSubTotal();
	}
	return finalTotal;
}

//=======================================MENUITEM CLASS IMPLEMENTATION===============================
string MenuItem::getDescription()
{
	return m_description;
}

double MenuItem::getCost()
{
	return m_cost;
}

void MenuItem::displayMenuItem()
{
	cout << m_description << " $" << m_cost << " per " << m_units;
}

MenuItem::MenuItem(string description, double cost, string unit)
{
	m_description = description;
	m_cost = cost;
	m_units = unit;
}

string MenuItem::getUnits()
{
	return m_units;
}
//===============================ITEM CLASS IMPLEMENTATION===========================================
double Item::getSubTotal()
{
	return	m_menuItem.getCost() *m_quantity;
}

void Item::displayItem()
{
	m_menuItem.displayMenuItem();
	cout << "    Quantity is " << m_quantity << " Sub Total is $" << m_quantity * m_menuItem.getCost() << endl;
}

//==========================CASH CLASS IMPLEMENTATION============================================
string Cash::getTransaction()
{
	string transaction;
	transaction = "Cash Transaction: Amount = $";
	transaction += to_string(getPayment());

	return transaction;
}

//========================CREDITCARD CLASS IMPLEMENTATION====================================================
string CreditCard::getTransaction()
{
	string transaction;
	transaction = "Credit Card Transaction: Amount = $";
	transaction += to_string(getPayment());
	transaction += " Card Number = ";
	transaction += m_creditNumber;

	return transaction;
}

void CreditCard::promptForActNum()
{
	cout << "Please enter Credit Card Number" << endl;
	cin >> m_creditNumber;
}

//======================PHONEPAY CLASS IMPLEMENTATION===========================================
string PhonePay::getTransaction()
{
	string transaction;
	transaction = "Phone Pay Transaction: Amount = $";
	transaction += to_string(getPayment());
	transaction += " Phone Number = ";
	transaction += m_phoneNumber;

	return transaction;
}

void PhonePay::promptForActNum()
{
	cout << "Please enter Phone Number" << endl;
	cin >> m_phoneNumber;
}

//Code by: Jessica Gehring

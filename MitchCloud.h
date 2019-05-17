#include <string>
#include <vector>
#include <fstream>
using namespace std;

#ifndef MITCHCLOUD_H
#define MITCHCLOUD_H

class Sale;

class MenuItem
{
public:
	string getDescription();
		string getUnits();
	double getCost();
	void displayMenuItem();
	MenuItem(string, double, string);

private:
	string m_description;
	double m_cost;
	string m_units;
};
//////////////////////////////////////////////////////////////////////////////////
class UserInfo
{
public:
	UserInfo() {m_Password = " "; m_userName = " ";}
	UserInfo(string username, string password) : m_userName(username), m_Password(password) {}
	bool checkUsername(string);
	bool checkPassword(string);
	string getUsername() { return m_userName;}
	string getPassword() { return m_Password; }

private:
	string m_Password;
	string m_userName;
};
//////////////////////////////////////////////////////////////////////////////////
class Payment
{
public:
	void setPayment(double payment) { m_paymentAmount = payment; }
	double getPayment() { return m_paymentAmount; }
	virtual void setAccountNum(string accountNum) {};
	virtual string getAccountNum() { return " "; }
	virtual string paymentType() = 0;
	virtual string getTransaction() = 0;
	Payment() {m_paymentAmount = 0;}
	virtual void promptForActNum() {};
private:
	double m_paymentAmount;
};
//////////////////////////////////////////////////////////////////////////////////
class Cash : public Payment
{
public:
	virtual string paymentType() {return "cash";}
	virtual string getTransaction();
};
//////////////////////////////////////////////////////////////////////////////////
class CreditCard : public Payment
{
public:
	virtual string paymentType() { return "credit"; }
	virtual string getTransaction();
	virtual string getAccountNum() { return m_creditNumber; }
	virtual void setAccountNum(string creditNum) { m_creditNumber = creditNum;}
	virtual void promptForActNum();
private:
	string m_creditNumber;
};
//////////////////////////////////////////////////////////////////////////////////
class PhonePay : public Payment
{
public:
	virtual string paymentType() { return "phonePay"; }
	virtual string getTransaction();
	virtual string getAccountNum() { return m_phoneNumber; }
	virtual void setAccountNum(string phoneNum) { m_phoneNumber = phoneNum; }
	virtual void promptForActNum();
private:
	string m_phoneNumber;
};
//////////////////////////////////////////////////////////////////////////////////
class Register
{
public:
	void login();
	int displayMenu();
	void createMenu();
	void startSale();
	void endSale();
	void addSaleItem(int, int);
	void displayReceipt();
	void makePayment(); //interactive
	void makePayment(int, string); //non-interactive
	void salesTransaction();
	Register() : m_clerkID("ICE", "CUBE"), m_custID("FLOYD", "THINICE"), m_managerID("METALLICA", "UNDERICE"), m_salesAnID("ZEPPELIN", "ICEANDSNOW") {}
	bool performAnotherTransaction();

private:
	UserInfo m_clerkID;
	UserInfo m_custID;
	UserInfo m_managerID;
	UserInfo m_salesAnID;
		UserInfo m_currentUser;
	vector <MenuItem> m_menu;
	Sale *m_sale;
	ofstream m_transactionFile;

	//void addLogEntry(string);
	void openTransactionLog();
	void closeTransactionLog();
	void interactiveSale();
	void fileSale();
};
//////////////////////////////////////////////////////////////////////////////////
class Item
{
public:
Item(int qty, MenuItem menuItem) : m_quantity(qty), m_menuItem(menuItem){};
	void displayItem();
	double getSubTotal();
private:
	int m_quantity;
	MenuItem m_menuItem;
};
//////////////////////////////////////////////////////////////////////////////////
class Sale
{
public:
	Sale() {};
	void createSaleItem(MenuItem, int);
	void displaySale();
	double getTotal();
		int getNumberItemsInOrder() { return m_sale.size();}
private:
	vector <Item> m_sale;
};
#endif

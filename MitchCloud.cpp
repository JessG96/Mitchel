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
  else //FINISH MOVING CODE OVER
}












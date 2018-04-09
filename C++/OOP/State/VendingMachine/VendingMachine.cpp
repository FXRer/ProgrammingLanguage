
#include<iostream>
#include<string>

#include "VendingMachine.h"


Account* State::getAccount(void)
{
  return m_Account;
}
void State::setAccount(Account* account)
{
  m_Account = account;
}

double State::getBalance(void)
{
  return m_Balance;
}

void State::setBalance(double balance)
{
  m_Balance = balance;
}

string State::getStateName(void)
{
  return m_StateName;
}

RedState::RedState(State* state)
{
  this->m_Balance = state->getBalance();
  this->m_Account = state->getAccount();
  initialise();
}

void RedState::deposit(double amount)
{
  m_Balance += amount;
  checkStateChange();
}

void RedState::withdraw(double amount)
{
  double newAmount = amount + m_ServiceFee;
  if(m_Balance - newAmount < m_LowerLimit)
    cout<<"No funds available for withdrawal!"<<endl;
  else
    m_Balance -= newAmount;
}

void RedState::payInterest()
{
  //No interest is paid
}

void RedState::checkStateChange()
{
  if (m_Balance > m_UpperLimit)
  {
    m_Account->setState(reinterpret_cast<State*>(new SilverState(this)));
    delete this;
    return;
  }
}

void RedState::initialise()
{
  m_StateName = "Red";
  //Should come from a data source
  m_Interest = 0.0;
  m_LowerLimit = -100.0;
  m_UpperLimit = 0.0;
  m_ServiceFee = 15.0;
}

SilverState::SilverState(State* state)
{
  this->m_Balance = state->getBalance();
  this->m_Account = state->getAccount();
  initialise();
}

SilverState::SilverState(double balance, Account* account)
{
  this->m_Balance = balance;
  this->m_Account = account;
  initialise();
}

void SilverState::deposit(double amount)
{
  m_Balance += amount;
  checkStateChange();
}

void SilverState::withdraw(double amount)
{
  m_Balance -= amount;
  checkStateChange();
}

void SilverState::payInterest()
{
  m_Balance = m_Balance * m_Interest;
  checkStateChange();
}

void SilverState::checkStateChange()
{
  if (m_Balance < m_LowerLimit)
  {
    m_Account->setState(reinterpret_cast<State*>(new RedState(this)));
    delete this;
    return;
  }
  else if (m_Balance > m_UpperLimit)
  {
    m_Account->setState(reinterpret_cast<State*>(new GoldState(this)));
    delete this;
    return;
  }
}

void SilverState::initialise()
{
  m_StateName = "Silver";
  //Should come from a data source
  m_Interest = 1.0;
  m_LowerLimit = 0.0;
  m_UpperLimit = 1000.0;
}

GoldState::GoldState(State* state)
{
  this->m_Balance = state->getBalance();
  this->m_Account = state->getAccount();
  initialise();
}

void GoldState::deposit(double amount)
{
  m_Balance += amount;
  checkStateChange();
}

void GoldState::withdraw(double amount)
{
  m_Balance -= amount;
  checkStateChange();
}

void GoldState::payInterest()
{
  m_Balance = m_Balance * m_Interest;
  checkStateChange();
}

void GoldState::checkStateChange()
{
  if (m_Balance < 0.0)
  {
    m_Account->setState(reinterpret_cast<State*>(new RedState(this)));
    delete this;
    return;
  }
  else if (m_Balance < m_LowerLimit)
  {
    m_Account->setState(reinterpret_cast<State*>(new SilverState(this)));
    delete this;
    return;
  }
  else if (m_Balance > m_UpperLimit)
  {
    cout<<"Your account is too big now. Please consider using Swiss banks"<<endl;
  }
}

void GoldState::initialise()
{
  m_StateName = "Gold";
  //Should come from a data source
  m_Interest = 5.0;
  m_LowerLimit = 1000.0;
  m_UpperLimit = 10000000.0;
}

Account::Account(string owner):m_Owner(owner)
{
  m_State = reinterpret_cast<State*>(new SilverState(0.0, this)); //default
}

Account::~Account()
{
  delete m_State;
}

double Account::getBalance(void)
{
  return m_State->getBalance();
}

void Account::deposit(double amount)
{
  m_State->deposit(amount);
  cout<<"Deposited $"<<amount<<endl;
  cout<<"Balance   $"<<getBalance()<<endl;
  cout<<"Status     "<<m_State->getStateName()<<endl;
  cout<<"\n";
}

void Account::withdraw(double amount)
{
  m_State->withdraw(amount);
  cout<<"Withdrew  $"<<amount<<endl;
  cout<<"Balance   $"<<getBalance()<<endl;
  cout<<"Status     "<<m_State->getStateName()<<endl;
  cout<<"\n";
}

void Account::payInterest()
{
  m_State->payInterest();
  cout<<"Interest Paid --------"<<endl;
  cout<<"Balance   $"<<getBalance()<<endl;
  cout<<"Status     "<<m_State->getStateName()<<endl;
  cout<<"\n";
}

void Account::setState(State* state)
{
  m_State = state;
}

State* Account::getState(void)
{
  return m_State;
}


//The Main method
int main()
{
  Account* account = new Account("Dr. Who");
  account->withdraw(10.00);
  account->withdraw(30.00);
  account->withdraw(70.00);
  account->deposit(234.00);
  account->deposit(5000.00);
  account->withdraw(5200.00);
  account->deposit(1500.00);
  account->deposit(1.00);
  account->withdraw(1200.00);

  delete account;

  return 0;
}



// OUTPUT:
//Withdrew  $10
//Balance   $-10
//Status     Red

//Withdrew  $30
//Balance   $-55
//Status     Red

//No funds available for withdrawal!
//Withdrew  $70
//Balance   $-55
//Status     Red

//Deposited $234
//Balance   $179
//Status     Silver

//Deposited $5000
//Balance   $5179
//Status     Gold

//Withdrew  $5200
//Balance   $-21
//Status     Red

//Deposited $1500
//Balance   $1479
//Status     Silver

//Deposited $1
//Balance   $1480
//Status     Gold

//Withdrew  $1200
//Balance   $280
//Status     Silver



// Source: https://advancedcppwithexamples.blogspot.com/2010/11/c-example-of-state-design-pattern.html

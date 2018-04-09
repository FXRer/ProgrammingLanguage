
using namespace std;
 
//Forward Declaration
class Account;
 
// The 'State' abstract class
class State
{
public:
  Account* getAccount(void);
  void setAccount(Account* account);
  double getBalance(void);
  void setBalance(double balance);
  string getStateName(void);
  virtual void deposit(double amount)=0;
  virtual void withdraw(double amount)=0;
  virtual void payInterest(void) = 0;
protected:
  Account* m_Account;
  double m_Balance;
  double m_Interest;
  double m_LowerLimit;
  double m_UpperLimit;
  string m_StateName;;
};
 
// A 'ConcreteState' class
// Red indicates that account is overdrawn
class RedState : State
{
public:
  RedState(State* state);
  void deposit(double amount);
  void withdraw(double amount);
  void payInterest();
  void checkStateChange();
 
private:
 
  RedState(); //Not allowed
  void initialise();
  double m_ServiceFee;
};
 
// A 'ConcreteState' class
// Silver indicates less interest bearing state
class SilverState : State
{
public:
  SilverState(State* state);
  SilverState(double balance, Account* account);
  void deposit(double amount);
  void withdraw(double amount);
  void payInterest();
  void checkStateChange();
 
private:
  SilverState(); //Not allowed
  void initialise();
};
 
// A 'ConcreteState' class
// Gold indicates high interest bearing state
class GoldState : State
{
public:
  GoldState(State* state);
  void deposit(double amount);
  void withdraw(double amount);
  void payInterest();
  void checkStateChange();
 
private:
  GoldState(); //Not allowed
  void initialise();
};
 
 
// The 'Context' class - defined here as its used for forward declaration
class Account
{
public:
  Account(string owner);
  ~Account();
  double getBalance(void);
  void deposit(double amount);
  void withdraw(double amount);
  void payInterest();
  void setState(State* state);
  State* getState(void);
private:
  State* m_State;
  string m_Owner;
  Account();
};

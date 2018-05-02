//C++ Code
#include<iostream>
#include<string>
 
using namespace std;
 
class IFridge
{
public:
	virtual string Run(void) = 0;
};
 
class FridgeSamsung : public IFridge
{
public:
	string Run(void)
	{
		return "You are now running Samsung Fridge\n";
	}
};
 
class FridgeWhirlpool : public IFridge
{
public:
	string Run(void)
	{
		return "You are now running Whirlpool Fridge\n";
	}
};
 
class IWashingMachine
{
public:
	virtual string Run(void) = 0;
};
 
class WashingMachineSamsung : public IWashingMachine
{
public:
	string Run(void)
	{
		return "You are now running Samsung Washing Machine\n";
	}
};
 
class WashingMachineWhirlpool : public IWashingMachine
{
public:
	string Run(void)
	{
		return "You are now running Whirlpool Washing Machine\n";
	}
};
 
class IFactory
{
public:
	virtual IFridge* GetFridge(void) = 0;
	virtual IWashingMachine* GetWashingMachine(void) = 0;
};
 
class FactorySamsung : public IFactory
{
	IFridge* GetFridge(void)
	{
		return new FridgeSamsung();
	}
 
	IWashingMachine* GetWashingMachine(void)
	{
		return new WashingMachineSamsung();
	}
};
 
class FactoryWhirlpool : public IFactory
{
	IFridge* GetFridge(void)
	{
		return new FridgeWhirlpool();
	}
 
	IWashingMachine* GetWashingMachine(void)
	{
		return new WashingMachineWhirlpool();
	}
};
 
int main()
{
	IFridge* fridge;	//Client just knows about fridge and washingMachine.
	IWashingMachine* washingMachine; //and factory. He will write operations which
	IFactory* factory; //work on fridges and washingMachines.
 
	factory = new FactorySamsung; 
	//This is the only place where the client
	//has to make a choice. 
 
	//The rest of the code below will remain same, even 
	//if the factory is changed. He can change the factory and the same range
	//of products but from a different factory will be returned. No need to 
	//change any code.
 
	fridge = factory->GetFridge();
	cout << fridge->Run();
	washingMachine = factory->GetWashingMachine();
	cout << washingMachine->Run();
	cout << "\n";
 
	delete factory;
	factory = new FactoryWhirlpool;
 
	//See same client code.
	fridge = factory->GetFridge();
	cout << fridge->Run();
	washingMachine = factory->GetWashingMachine();
	cout << washingMachine->Run();
	cout << "\n";
	delete factory;
	return 1;
}

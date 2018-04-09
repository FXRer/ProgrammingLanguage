/*
Design Patterns: Elements of Reusable Object-Oriented Software, page 87
 
Applicability:
	Use the Abstract Factory pattern when:
		- a system should be independent of how its products are created, 
		  composed and represented,
		- a system should be configured with one of multiple families of 
		  products,
		- a family or related product objects are designed to be used 
		  together, and you need to enforce this constraint,
		- you want to provide a class library of products, and you want 
		  to reveal just their interfaces, not their implementations.
 
Consequences:
	Using the Abstract Factory pattern:
		- isolates concrete classes,
		- makes exchanging product families easier,
		- promotes consistency among products,
		- BUT supporting new kinds of products is difficult.
*/
 
#include <iostream>
#include <string>
 
using namespace std;
 
// The 'AbstractProductA' abstract class. Baseclass for the Wildebeast 
// and Bison classes.
class Herbivore
{
	private:
		string m_Name;
 
	public:
		Herbivore(string theAnimalName)
		{
			m_Name = theAnimalName;
		}
 
		string getName()
		{
			return m_Name;
		}
};
 
 
// The 'ProductA1' class
class Wildebeest : public Herbivore
{
	public:
		// Empty constructor - construction occurs in the Herbivore 
		// constructor.
		Wildebeest(string theAnimalName) : Herbivore(theAnimalName) {}
};
 
 
// The 'ProductA2' class
class Bison : public Herbivore
{
	public:
		// Empty constructor - construction occurs in the Herbivore 
		// constructor.
		Bison(string theAnimalName) : Herbivore(theAnimalName) {}
};
 
 
// The 'AbstractProductB' abstract class. Pure abstract class, and 
// baseclass for the Lion and Wolf classes.
class Carnivore
{
	private:
		string m_Name;
 
	public:
		Carnivore(string theAnimalName)
		{
			m_Name = theAnimalName;
		}
 
		// Having a pure virtual function like this makes the Carnivore 
		// class an abstract class which cannot be instantiated, but you 
		// can legally create a pointer to one (which we do).
		virtual void eat(Herbivore h) = 0;
 
		string getName()
		{
			return m_Name;
		}
};
 
 
// The 'ProductB1' class
class Lion : public Carnivore
{
 
	public:
		// Empty constructor - construction occurs in the Carnivore 
		// constructor
		Lion(string theAnimalName) : Carnivore(theAnimalName) {}
 
		virtual void eat(Herbivore h)
		{
			// Eat Wildebeast
			cout << this->getName() << " eats " << h.getName() << endl;
		}
};
 
 
// The 'ProductB2' class
class Wolf : public Carnivore
{
	public:
		// Empty constructor - construction occurs in the Carnivore 
		// constructor
		Wolf(string theAnimalName) : Carnivore(theAnimalName) {}
 
		virtual void eat(Herbivore h)
		{
			// Eat Bison
			cout << this->getName() << " eats " + h.getName() << endl;
		}
};
 
 
// The 'AbstractFactory' abstract class. Pure abstract class - cannot be 
// instantiated, but again we can create pointers to one.
class ContinentFactory
{
	public:
		virtual Herbivore* CreateHerbivore() = 0;
		virtual Carnivore* CreateCarnivore() = 0;
};
 
 
// The 'ConcreteFactory1' class
class AfricaFactory : public ContinentFactory
{
	public:
		virtual Herbivore* CreateHerbivore()
		{
			return new Wildebeest("William Wildebeest");
		}
 
		virtual Carnivore* CreateCarnivore()
		{
			return new Lion("Lenny Lion");
		}
};
 
 
// The 'ConcreteFactory2' class
class AmericaFactory : public ContinentFactory
{
	virtual Herbivore* CreateHerbivore()
	{
		return new Bison("Bob Bison");
	}
 
	virtual Carnivore* CreateCarnivore()
	{
		return new Wolf("Walter Wolf");
	}
};
 
 
// The 'Client' class. This class calls the factory classes to create 
// animals of the relevant type.
class AnimalWorld
{
	private:
		Herbivore* m_Herbivore;
		Carnivore* m_Carnivore;
 
	public:
		// Constructor. Creates a suitable pair of herbivores and 
		// carnivores for the continent.
		AnimalWorld(ContinentFactory *pFactory)
		{
			m_Herbivore = pFactory->CreateHerbivore();
			m_Carnivore = pFactory->CreateCarnivore();
		}
 
		void runFoodChain()
		{
			m_Carnivore->eat(*m_Herbivore);
		}
};
 
 
// Let the carnage begin...
int main()
{
	// Create and run the African animal world
	ContinentFactory *pAfrica = new AfricaFactory;
	AnimalWorld *pWorld = new AnimalWorld(pAfrica);
	pWorld->runFoodChain();
 
	// Create and run the American animal world
	ContinentFactory *pAmerica = new AmericaFactory;
	pWorld = new AnimalWorld(pAmerica);
	pWorld->runFoodChain();
 
	return 0;
}


// OUTPUT:
// Lenny Lion eats William Wildebeest
// Walter Wolf eats Bob Bison



// Source: https://r3dux.org/2011/07/an-example-abstract-factory-design-pattern-implementation-in-c/

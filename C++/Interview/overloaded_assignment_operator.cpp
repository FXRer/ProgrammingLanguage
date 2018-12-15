#include <cstring>
#include <cassert>
#include <iostream>


class Fraction {
	
	public:		
		// Default constructors
		Fraction() :
			mNumerator(0),
			mDenominator(1)
		{}
	
		Fraction(int numerator, int denominator) : 
			mNumerator(numerator),
			mDenominator(denominator)
		{
			assert(denominator != 0);
		}
		
		// Copy constructor
		Fraction(const Fraction& copy) : 
			mNumerator(copy.mNumerator),
			mDenominator(copy.mDenominator)
		{
			// no need to check for a denominator of 0 here since copy must already be a valid Fraction
			std::cout << "Copy constructor called\n"; // just to prove it works			
		}
	
		// Overloaded assignement operator
		Fraction& operator=(const Fraction& fraction) {
			// Do the copy
			mNumerator = fraction.mNumerator;
			mDenominator = fraction.mDenominator;
			
			return *this;
		}
		
		friend std::ostream& operator<<(std::ostream& out, const Fraction &f1);
		
	private:
		int mNumerator;
		int mDenominator;
};


std::ostream& operator<<(std::ostream& out, const Fraction &f1)
{
	out << f1.mNumerator << "/" << f1.mDenominator;
	return out;
}

int main()
{
    Fraction fiveThirds(5, 3);
    Fraction f, f1 = fiveThirds; // calls copy constructor
    f = fiveThirds; // calls overloaded assignment
    std::cout << f << std::endl;
    std::cout << f1 << std::endl;
 
    return 0;
}

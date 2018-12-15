#include <iostream>


class A {
	public:
		A() {};
		virtual ~A() {};

	protected:		
		void print() {show ();};
			
	private:
		void show () {std::cout << "I am A" << std::endl;};	
};

class B : public A
{
	public:
		B() {};
		virtual ~B() {};
		
		void display() {print();};
		
	private:
		//void show () {std::cout << "I am B" << std::endl;};	
};

int main ()
{
	B b;
	
	b.display();

	return 0;
}

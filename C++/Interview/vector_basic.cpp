#include <iostream>
#include <vector>
#include <iostream>

int main() {

	std::vector<int> myIntVector {7, 4, 22, 9, 35};
	std::vector<int>::iterator myIntIter;
	
	
	std::cout << myIntVector.size() << std::endl;
	std::cout << myIntVector.capacity() << std::endl;
	std::cout << myIntVector.at(3) << std::endl;
	myIntVector.push_back(112);
	
	for (myIntIter = myIntVector.begin(); myIntIter < myIntVector.end(); )
		std::cout << *myIntIter++ << std::endl;

	myIntVector.pop_back();
		
}

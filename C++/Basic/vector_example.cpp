#include <iostream>
#include <vector>
#include <algorithm>

void printVector(const std::vector<int> &array) {
	
	std::cout<<"[";
    std::for_each(array.begin(), array.end(),
	[](int element)
//	for (auto &element : array) 
	{
	    std::cout<<" "<<element;
	}

	);
	std::cout<<" ]"<<std::endl;
}

int main() {
	
	std::vector<int> array;
	
	array.reserve(3); 
	printVector(array);

	array.push_back(999); 
	printVector(array);

	array.resize(5); 
	printVector(array);
	
	array.push_back(333);
	printVector(array);
	
	array.reserve(1);
	printVector(array);
	
	array.resize(3); 
	printVector(array);

	array.resize(6, 1); 
	printVector(array);

	std::vector<int> newElements = {1, 3, 4, 2, -7, 8};
	printVector(newElements);
	
	return 0;
}

// OUTPUT:
// [ ]
// [ 999 ]
// [ 999 0 0 0 0 ]
// [ 999 0 0 0 0 333 ]
// [ 999 0 0 0 0 333 ]
// [ 999 0 0 ]
// [ 999 0 0 1 1 1 ]


#include <iostream>
#include <vector>
#include "Sorting.hpp"
using std::endl;
using std::cout;
using std::vector;

template<typename Type>
void print_vector(vector<Type> vec){
	for( auto item : vec ){
		cout << item << ", ";
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	vector<int> vec{5,4,3,2,65,7,3,124,6,2,3,6,7,8,1,10};
	Sorting<int> sorting;

	print_vector<int>(vec);

	sorting.Quick(vec);

	print_vector<int>(vec);


	return 0;
}

#include <iostream>
#include <stdlib.h>

int getArraySize()
{
	std::cout << "Please enter array size: ";
	int arrSize{};
	std::cin >> arrSize;
	if (arrSize <= 0)                        //any non-integer chars results in arrSize being 0
	{
		std::cerr << "Error";
		return -1;
	}
	return arrSize;
}

void writeInputToArray(int* arr, int length)
{
	std::cout << "Please enter the number to array: ";
	for (int i = 0; i < length; ++i)
	{
		std::cin >> arr[i];
	}
}

int main()
{
	//get array size from user (with input check)
	int arraySize = getArraySize();
	if (arraySize == -1)
	{
		exit(EXIT_FAILURE);
	}

	//alocate dynamic array
	int *permutationArray = new int[arraySize];
	
	//get values for array (with input check)
	writeInputToArray(permutationArray, arraySize);

	//build actual array
	//build road map
	//get number to check
	//print road to number
	//special cases:
		//if -1 print all roads and exit
		//if anything else print error and exit
}

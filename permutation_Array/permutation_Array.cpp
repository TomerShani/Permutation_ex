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

int lengthOfPath(int num, const int* arr)
{
	int count = 1;
	int index = num;
	while (arr[index] != num)
	{
		index = arr[index];
		++count;
	}
	return count;
}

void setPath(int num, int* base, const int* arr)
{
	int index = num;
	int count = 0;
	while (arr[index] != num)
	{
		base[count] = arr[index];
		index = arr[index];
		++count;
	}
	base[count] = arr[index];
}

// print function for debugging and inspecting
void printMap(int** map, const int* permArr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << "Path of " << i << ": ";
		for (int j = 0; j < lengthOfPath(i, permArr); ++j)
		{
			std::cout << map[i][j] << " ";
		}
		std::cout << '\n';
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
	
	//get values for array
	writeInputToArray(permutationArray, arraySize);
	//input inspection of the array
	
	//build path map
	int** map = new int* [arraySize];
	for (int i = 0; i < arraySize; ++i)
	{
		map[i] = new int[lengthOfPath(0, permutationArray)];
		setPath(i, map[i], permutationArray);
	}
	printMap(map, permutationArray, arraySize);

	//get number to check
	//print path to number
	//special cases:
		//if -1 print all paths and exit
		//if anything else print error and exit

}

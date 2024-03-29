﻿#include <iostream>
#include <stdlib.h>
#include "permutation_Array.h"

int main()
{
	int arraySize = getArraySize();
	int* permutationArray = new int[arraySize];
	writeInputToArray(permutationArray, arraySize);
	if (!isPermutationLegal(permutationArray, arraySize))
	{
		delete[] permutationArray;
		std::cerr << "Error";
		exit(EXIT_FAILURE);
	}
	int** map = new int* [arraySize];
	for (int i = 0; i < arraySize; ++i)
	{
		map[i] = new int[lengthOfPath(i, permutationArray)];
		setPath(i, map[i], permutationArray);
	}
	while (true)
	{
		int numCheck = getNumToFind();
		if (numCheck <= -2 || numCheck >= arraySize)
		{
			std::cerr << "Error";
			freeMap(map, arraySize);
			delete[] permutationArray;
			exit(EXIT_FAILURE);
		}
		if (numCheck == -1)
		{
			std::cout << "Total number of different paths is: ";
			std::cout << getNumOfPaths(permutationArray, arraySize) << '\n';
			printAllPaths(map, permutationArray, arraySize);
			freeMap(map, arraySize);
			delete[] permutationArray;
			exit(EXIT_SUCCESS);
		}
		std::cout << "path to " << numCheck << " is: ";
		printPath(numCheck, map, permutationArray, arraySize);
		std::cout << '\n';
	}
}

int getArraySize()
{
	std::cout << "Please enter array size: ";
	int arrSize{};
	std::cin >> arrSize;
	if (arrSize <= 0)                        //any non-integer chars results in arrSize being 0
	{
		std::cerr << "Error";
		exit(EXIT_FAILURE);
	}
	return arrSize;
}

void writeInputToArray(int* arr, int length)
{
	std::cout << "Please enter the numbers to array: ";
	for (int i = 0; i < length; ++i)
	{
		std::cin >> arr[i];
		if (std::cin.fail())
		{
			delete[] arr;
			std::cerr << "Error";
			exit(EXIT_FAILURE);
		}
	}
}

bool isPermutationLegal(const int* arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		bool isFound = false;
		for (int j = 0; j < length; ++j)
		{
			if (arr[j] == i)
			{
				isFound = true;
			}
		}
		if (!isFound)
		{
			return false;
		}
	}
	return true;
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

int getNumToFind()
{
	std::cout << "please enter a number to find: ";
	int num{};
	std::cin >> num;
	if (std::cin.fail())
	{
		return -2; // errorcode - free all and exit!
	}
	return num;
}

void freeMap(int** map, int length)
{
	for (int i = 0; i < length; ++i)
	{
		delete[] map[i];
	}
	delete[] map;
}

int getNumOfPaths(const int* permArr, int length)
{
	double sum = 0.0;
	for (int i = 0; i < length; ++i)
	{
		sum += 1.0 / lengthOfPath(i, permArr);
	}
	return static_cast<int>(sum + 0.5); // add 0.5 to solve accuracy problems
}

void printAllPaths(int** map, const int* permArr, int length)
{
	bool* checklist = new bool[length];
	for (int i = 0; i < length; ++i)
	{
		checklist[i] = false;
	}
	int count = 1;
	for (int i = 0; i < length; ++i)
	{
		if (checklist[i] == false)
		{
			std::cout << "path " << count << " is: ";
			printPath(i, map, permArr, length);
			std::cout << '\n';
			++count;
			for (int j = 0; j < lengthOfPath(i, permArr); ++j)
			{
				checklist[map[i][j]] = true;
			}
		}
	}

	delete[] checklist;
}

void printPath(int num, int** map, const int* permArr, int length)
{
	for (int j = 0; j < lengthOfPath(num, permArr); ++j)
	{
		std::cout << map[num][j] << " ";
	}
}

// print function for debugging and inspecting
void printMap(int** map, const int* permArr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << "Path of " << i << ": ";
		//		for (int j = 0; j < lengthOfPath(i, permArr); ++j)
		//		{
		//			std::cout << map[i][j] << " ";
		//		}
		printPath(i, map, permArr, length);
		std::cout << '\n';
	}
}



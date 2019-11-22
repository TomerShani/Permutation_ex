#pragma once

int getArraySize();
void writeInputToArray(int* arr, int length);
bool isPermutationLegal(const int* arr, int length);
int lengthOfPath(int num, const int* arr);
void setPath(int num, int* base, const int* arr);
void printPath(int num, int** map, const int* permArr, int length);
int getNumToFind();
void freeMap(int** map, int length);
int getNumOfPaths(const int* permArr, int length);
void printAllPaths(int** map, const int* permArr, int length);
void printMap(int** map, const int* permArr, int length);
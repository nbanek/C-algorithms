// Bubble Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <chrono>

using namespace::std;
using namespace std::chrono;

void swap(int &a, int &b) { //swap function
	int temp = b;
	b = a;
	a = temp;
}

int main()
{
	srand(time(NULL)); //Generate random seed

	vector<int> vec;

	for (int i = 0; i < 1000; i++) {
		vec.push_back(rand() % time(NULL)); //push random values into vector
	}

	auto start = high_resolution_clock::now();

	for (int i = 0; i < vec.size(); i++) { //Traverse list to determine if swaps are necessary
		for (int j = 0; j < vec.size() - 1; j++) {
			if (vec[j + 1] < vec[j]) {
				swap(vec[j + 1], vec[j]);
			}
		}
	}

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(stop - start);

	cout << duration.count();

	
}



// Linear Search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	vector<int> vec; //Creat very large array

	for (int i = 0; i < 10000000; i++) {
		vec.push_back(i);
	}

	int item; //The item we want to locate in the array
	cin >> item;

	auto start = high_resolution_clock::now(); //Used to calculate loop speed
	
	for (int i = 0; i < vec.size(); i++) { //Linear search by for loop
		if (vec[i] == item) {
			cout << item << " is in list" << endl;
			break;
		}
		else if (i >= vec.size() - 1)
			cout << item << " is not in list" << endl;
	}

	/*int loc = 0;  //Linear search by while loop
	bool found = false;
	while (loc != vec.size() && !found) {
		if (vec[loc] == item) {
			cout << item << " is in list" << endl;
			found = true;
		}
		else if (item >= vec.size() - 1) {
			cout << item << " is not in list" << endl;
			break;
		}
		loc++;

	}*/

	auto stop = high_resolution_clock::now(); //Used to calculate loop speed

	auto duration = duration_cast<milliseconds>(stop - start); //Loop speed in ms

	cout << duration.count() << " ms";

}



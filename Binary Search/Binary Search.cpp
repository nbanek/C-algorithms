
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> v, int target) {

	int max = v.size() - 1;
	int min = 0;
	int mid;
	bool found = false;

	while (min <= max && !found) {
		mid = (max + min) / 2;

		if (target == v[mid]) {
			found = true;
		}
		else if (target < v[mid]) {
			max = mid - 1;
		}
		else {
			min = mid + 1;
		}
	}
	if (found)
		return mid;
	else
		return -1;
	
}


int main()
{
	vector<int> vec = {-1, 0, 3, 5, 9, 12};
	int target = 101;



	cout << search(vec, 9);

}



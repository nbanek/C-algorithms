#include "pch.h"
#include <iostream>
#include <array>

using namespace std;

void sort(int arr[], int size) {

	for (int i = 1; i < size; i++) {

		int temp = arr[i];
		int j = i - 1;

		while (temp < arr[j] && j >= 0) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}

}



int main(){

	int arr[9] = { 5, 2, 3, 6, 2, 3, 2, 4, 6};
	int size = sizeof(arr) / sizeof(arr[0]);

	sort(arr, size);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " " << endl;
	}



}


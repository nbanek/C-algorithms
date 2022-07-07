#include "pch.h"
#include <iostream>

using namespace std;

void merge(int arr[], int low, int mid, int high) {
	int i, j, k;
	int left = mid - low + 1;
	int right = high - mid;

	int *l = new int[left];
	int *r = new int[right];

	for (i = 0; i < left; i++) {
		l[i] = arr[low + i];
	}
	for (i = 0; i < right; i++) {
		r[i] = arr[mid + 1 + i];
	}

	i = 0;
	j = 0;
	k = low;
	while (i < left && j < right) {
		if (l[i] <= r[j]) {
			arr[k] = l[i];
			i++;
		}
		else {
			arr[k] = r[j];
			j++;
		}
		k++;
	}

	while (i < left) {
		arr[k] = l[i];
		i++;
		k++;
	}

	while (j < right) {
		arr[k] = l[j];
		j++;
		k++;
	}


}

void mergesort(int arr[], int low, int high) {

	int mid;

	if (low < high) {

		mid = (high + low) / 2;

		mergesort(arr, low, mid);
		mergesort(arr, mid + 1, high);
		merge(arr, low, mid, high);

	}





}

int main() {

	int arr[4] = { 3, 2, 1, 0 };

	int size = sizeof(arr) / sizeof(arr[0]);

	mergesort(arr, 0, size - 1);

	for (int i = 0; i < 4; i++) {
		cout << arr[i] << endl;
	}


	return 0;
}
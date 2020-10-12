#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void max_heapify(vector<int>& arr, int i, int size) {
	int largestVal;
	int l = (2 * i) + 1;
	int r = (l + 1);

    if (l < size && arr[l] > arr[i])
        largestVal = l;
    else
        largestVal = i;

    if (r < size && arr[r] > arr[largestVal])
        largestVal = r;

    if (largestVal != i)
    {
        swap(arr[i], arr[largestVal]);
        max_heapify(arr, largestVal, size);
    }
}

void build_max_heap(vector<int>& arr) {
	// do something
}

void heapSort(vector<int>& arr) {
	// do something
}
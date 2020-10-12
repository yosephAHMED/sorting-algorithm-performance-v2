#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void max_heapify(vector<int>& arr, int i, int size) {
    // maintains max-heap

    // stores index of child whose value is largest of the 3 elements
	int largestVal;

    // left child
	int l = (2 * i) + 1;

    // right child
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
    // format array to be a max-heap

    // start at half of array then do max_heapify
    for (int i = (arr.size() / 2); i >= 0; i--)
        max_heapify(arr, i, arr.size());
}

void heapSort(vector<int>& arr) {
    // format the array to make max heap
    build_max_heap(arr);

    // largest element of array is at index 0
    int size = arr.size();

    // swap largest element with last element in array
    for (int i = arr.size() - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        size--;
        
        // create new max-heap
        max_heapify(arr, 0, size);
    }
}
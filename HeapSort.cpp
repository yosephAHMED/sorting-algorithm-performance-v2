#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// external link to numSteps found in Source.cpp
extern long long int numSteps;

void max_heapify(vector<int>& arr, int i, int size) {
    // maintains max-heap

    // stores index of child whose value is largest of the 3 elements
	int largestVal;

    // left child
	int l = (2 * i) + 1;

    // right child
	int r = (l + 1);

    // two assignments
    numSteps += 2;


    if (l < size && arr[l] > arr[i])
        largestVal = l;
    else
        largestVal = i;

    // three boolean comparisons in the if statement + 1 assignment
    numSteps += 3;

    if (r < size && arr[r] > arr[largestVal])
        largestVal = r;

    // three boolean comparisons in the if statement + 1 assignment
    numSteps += 3;

    if (largestVal != i)
    {
        swap(arr[i], arr[largestVal]);
        max_heapify(arr, largestVal, size);
    }

    // one boolean comparison + two function calls
    numSteps += 3;
}

void build_max_heap(vector<int>& arr) {
    // format array to be a max-heap

    // start at half of array then do max_heapify
    for (int i = (arr.size() / 2); i >= 0; i--)
        max_heapify(arr, i, arr.size());

    // initial i assignment (+1 steps), boolean comparison and decrement i (+2 steps), function call (+1 steps)
    numSteps += 4;
}

void heapSort(vector<int>& arr) {
    // format the array to make max heap

    build_max_heap(arr);

    // function call (+1 steps)
    numSteps++;

    // largest element of array is at index 0
    int size = arr.size();

    // assignment (+1 steps)
    numSteps++;

    // swap largest element with last element in array
    for (int i = arr.size() - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        size--;
        
        // create new max-heap
        max_heapify(arr, 0, size);
    }

    // i assignment (+1 steps), boolean comparison and decrement i (+2 steps), 2 function calls (+2 steps), decrement size (+1 steps)
    numSteps += 6;
}
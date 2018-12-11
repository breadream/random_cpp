// complete binary tree  (doesn't have to be a full binary tree)
// - every level must be completely filled 
// - all the leaf elements must lean towards the left 
// - the last leaf element might not have a right sibling 
// https://www.programiz.com/dsa/heap-sort
// Heap Sort has O(nlogn) time complexities for all the cases ( best case, average case and worst case).

#include <iostream>
#include <vector>

using namespace std;

// To heapify a subtree rooted with node i (an index in arr[]
// n == size of heap
void heapify(vector<int> &arr, int n, int i)
{
	int max = i; // initialize max as root 
	int left = 2*i + 1; // left child
	int right = 2*i + 2; // right child

	// if left child is larger than root 
	if (left < n && arr[left] > arr[max])
		max = left;
	// if right child is larger than largest so far 
	if (right < n && arr[right] > arr[max])
		max = right;

	// if the largest is not root 
	if (i != max)
	{
		swap(arr[i], arr[max]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, max);
	}
}

void heapSort(vector<int> &arr, int n)
{
	// Build heap 
	// we start by heapifying the lowest smallest trees and 
	// gradually move up until we reach the root element 
	for (int i = n/2 -1; i >= 0; i--)
		heapify(arr, n, i);
	
	/*
	 * 1. Since the tree satisfies Max-Heap property, 
	 * then the largest element is stored at the root node
	 * 2. Remove the root element and put at the end of the array (nth position)
	 * Put the last item of the tree (heap) at the vacant place.
	 * 3. Reduce the size of the heap by 1 and heapify the root element again 
	 * so that we have highest element at root.
	 * 4. The process is repeated until all the items of the list is sorted. */
	// Extract an element from heap, one by one 
	for (int i = n-1; i >= 0; i--)
	{
		// Move current root to end 
		swap(arr[i], arr[0]); // step 2
		// call max heapify on the reduced heap 
		heapify(arr, i, 0); // step 3
	}	
}

int main()
{
	int array [] = {2, 6, 1, 3, 3, 9, 0};
	vector<int> a (array, array + sizeof(array)/sizeof(int));
	heapSort(a, a.size());
	for (int value : a)
		cout << value << " ";
	return 0;
}


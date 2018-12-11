#include <iostream>
#include <vector>

using namespace std;

// To heapify a subtree rooted with node i (an index in arr[]
// n == size of heap
void heapify(vector<int> &arr, int n, int i)
{
	int max = i; // initialize max as root 
	cout << max << endl;
	int left = 2*i + 1; 
	int right = 2*i + 2;

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
	for (int i = n/2 -1; i >= 0; i--)
		heapify(arr, n, i);
	
	// Extract an element from heap, one by one 
	for (int i = n-1; i >= 0; i--)
	{
		// Move current root to end 
		swap(arr[i], arr[0]);
		// call max heapify on the reduced heap 
		heapify(arr, i, 0);
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


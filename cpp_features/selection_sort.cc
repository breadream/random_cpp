void selectionSort(vector<int> &arr, int n) 
{ 
	int i, j, min_idx; 

	for (i = 0; i < n-1; i++) 
	{ 
		min_idx = i; // the first index of unsorted subarray

		// Find an index of the minimum element in unsorted array 
		for (j = i+1; j < n; j++) 
          min_idx = arr[j] < arr[min_idx] ? j : i;

		// Swap the found minimum element with the first element 
      if (min_idx != i)
		swap(arr[min_idx], arr[i]); 
	} 
} 

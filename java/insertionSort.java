void insertionSort (int arr[]) {
	int n = arr.length-1; // not to be out of bound 
	// j is initialized as increased i 
	for (int i = 0, j = i; i < n; j = ++i) {
			int key = a[i + 1]; // starting with one position ahead 

			/* Move elements of arr[0..i-1], that are 
			  greater than key, to one position ahead 
			  of their current position */
			while (key < a[j]) {
				a[j + 1] = a[j];
				if (j-- == 0) 
					break;
			}
			a[j + 1] = ai;
	}
}

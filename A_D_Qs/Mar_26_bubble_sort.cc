void bubbleSort(vector<int>& arr) 
{ 
   int i, j; 
   for (i = 0; i < arr.size()-1; i++)       
       // Last i elements are already in place    
       for (j = 0; j < n-1-i; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

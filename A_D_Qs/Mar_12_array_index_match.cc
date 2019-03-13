  static int indexEqualsValueSearch(int[] arr) {
     int low = 0, high = arr.length-1;
     int mid = 0;
    
     while (low <= high)
     { 
        mid = low + (high - low) / 2;
        if (arr[mid] < mid)
           low = mid + 1;
       // it should be the first element that satisfies the condition 
       else if (arr[mid] == mid && (mid == 0 || arr[mid-1] < mid-1))
           return mid;
        else 
           high = mid - 1;
     }
    
     return -1;
  }

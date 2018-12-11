int partition(vector <int> &list, int left, int right){
  int pivot, temp;
  int low, high;

  low = left;
  high = right + 1;
  pivot = list[left]; // pivot; leftmost element 

  do{
    do {
      low++; // low starts at 'left+1'
    } while (low<=right && list[low]<pivot);

    do {
      high--; //high starts at 'right'
    } while (high>=left && list[high]>pivot);

    // if low and high don't intersect,  swap list[low] & list[high] 
    if(low<high)
		swap(list[low], list[high]);
    
  } while (low<high);

  // if low and high intersect, swap list[left] & list[high]
	swap(list[low], list[high]);

  // return the current pivot index 
  return high;
}

void quick_sort(vector<int> &list, int left, int right){
  if(left<right){
    // Divide
    int q = partition(list, left, right); // q: pivot location 

    quick_sort(list, left, q-1); // (left ~ right before pivot ) Conquer the first half
    quick_sort(list, q+1, right); // (right after pivot ~ right) Conquer the second half
  }

}
https://gmlwjd9405.github.io/2018/05/10/algorithm-quick-sort.html

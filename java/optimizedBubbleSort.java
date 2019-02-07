private static void bubbleSort(int arr[]) {

  /*
    n: the array length
    i: the element 1 position/index behind the target position/index we are bubbling up to
    t: the position/index that the LAST swap happened
    Off by one is annoying for this but...just stay with it and this will make sense.
  */

  int n = arr.length;
  int i = n - 1;

  while (i > 0) {

    /*
      This variable remembers the LAST POSITION
    */
    int t = 1;

    /*
      We will start j at position 1 (index 0) and move
      it up to (and including) position i (index i - 1)
      Our goal is to bubble up the items until we have the item
      that belongs at POSITION i + 1 (which maps to index i + 2)
      where it is supposed to be.
    */
    for (int j = 1; j <= i; j++) {

      /*
        Tried keeping this similar to the example
        discussed, but here we must index back from
        0.
        Adjust back to indexing off of 0 so we
        don't out of bounds. Any operation touching
        the actual array must index back to 0.
        Off of 1:
          arr[j] > arr[j + 1]
            swap(arr, j, j + 1);
        Off of 0:
          arr[j - 1] > arr[j]
            swap(arr, j - 1, j);
        t = j; stays the same since this does not access
        the array. We can still say the swap happened at
        position j (really means index j - 1).
      */

      if (arr[j - 1] > arr[j]) {
        swap(arr, j - 1, j);
        t = j;
      }

    }

    /*
      We now can put i one position behind where the
      LATEST swap happened (that is what t represents).
      We know that everything past (and including) POSITION
      i + 2 is already sorted.
    */
    i = t - 1;

  }

}

private static void swap(int arr[], int first, int second) {
  int temp = arr[first];
  arr[first] = arr[second];
  arr[second] = temp;
}

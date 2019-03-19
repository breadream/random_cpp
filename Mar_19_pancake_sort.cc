#include <iostream>
#include <vector>

using namespace std;

void flip (vector<int>& arr, int k )
{
    int start = 0, end = k;
    while (start < end)
    {
       int temp = arr[start];
       arr[start] = arr[end];
       arr[end] = temp;
       start++;
       end--;
    }
}
vector<int> pancakeSort(const vector<int>& arr) 
{
  // your code goes here
  vector<int> res(arr);
  int maxIdx = 0;
  int k = arr.size();
  int sizeArray = res.size(); 
  
  while (sizeArray > 0) {
      int max = INT_MIN;
      for (int i = 0; i < sizeArray; i++)
      {
        if (res[i] > max)
        {
          max = res[i];
          maxIdx = i;
        }
      }
      k = maxIdx;
      flip(res, k);
      flip(res, sizeArray-1);
      sizeArray--; 
  } 
  return res; 
}

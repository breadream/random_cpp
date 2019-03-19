#include <iostream>
#include <vector>



using namespace std;


int shiftedArrSearch(const vector<int>& arr, int target)
{
	int start = 0;
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i-1] > arr[i])
		{
			start = i;
			break;
		}
	}

	int mid1 = (start - 1) / 2, left1 = 0, right1 = start-1;
	int mid2 = (arr.size() - start) / 2, left2 = start, right2 = arr.size()-1;;

	while (left1 <= right1)
	{
		mid1 = left1 + (right1 - left1) / 2;
		if (arr[mid1] == target)
			return mid1;
		else if (arr[mid1] > target)
		{
			left1 = mid1 + 1;
		}
		else 
		{
			right1 = mid1 - 1;
		}
	}

	while (left2 <= right2)
	{
		mid2 = left2 + (right2 - left2) / 2;
		if (arr[mid2] == target)
			return mid2;
		else if (arr[mid2] > target)
		{
			left2 = mid2 + 1;
		}
		else 
		{
			right2 = mid2 - 1;
		}
	}
	return -1;
}

    int search(const vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int mid;
        while (low <= high)
        {
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
			{
				if (nums[mid] < target && target <= nums[high] )
					low = mid + 1;
				else
					high = mid - 1;
			}
			else
			{
				if (nums[low] <= target && target < nums[mid])
					high = mid - 1;
				else
					low = mid + 1;
			}
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < nums[high]) // [mid . . . high]; sorted, the pivot point is on the left
            {
                if (nums[mid] < target && target <= nums[high])  // target is in the range
                    low = mid + 1;
                else  // target is in first half
                    high = mid - 1;
            }
            else  // the pivot point is on the right
            {
                if (nums[low] <= target && target < nums[mid]) // target is in the range
                    high = mid - 1;
                else // target is in the second half
                    low = mid + 1;
            }
        }
        return -1;
    }

int main() {
   	int arr[] = {9, 12, 17, 2, 4, 5};
    vector<int> output (arr, arr + sizeof(arr[0]) / sizeof(arr));

	  int result = shiftedArrSearch(output, 2);
	  cout << result << endl;

  return 0;
}

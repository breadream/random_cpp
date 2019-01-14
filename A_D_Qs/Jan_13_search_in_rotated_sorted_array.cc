class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while (low <= high)
        {
            int mid = (high - low) / 2 + low; // to avoid overflow 
            if (nums[mid] == target)
                return mid;
            // right part is monotomically increasing or the pivot point is on the left
            else if (nums[mid] < nums[high])  
            {
                // must use "<=" in order to make sure the target is in the right part
                if (nums[mid] < target && target <= nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
            // left part is monotomically increasing or the pivot point is on the right
            else
            {
                // "<=" was used to make sure the target is in the left part
                if (nums[low] <= target && target < nums[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
        }
        return -1;
    }
};

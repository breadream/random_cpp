class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2]; // just random number 
        for (int i = 0; i < nums.size()-2; i++)
        {
            int j = i+1, k = nums.size()-1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > target)
                    k--;
                else
                    j++; 
                if (abs(target - sum) < abs(target - ans)) // abs(target - ans); minimum difference so far 
                    ans = sum;
            }
        }
        return ans;
    }
};

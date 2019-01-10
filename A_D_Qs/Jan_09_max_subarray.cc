class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int local_max, global_max;
        // initialize them as the first element
        local_max = global_max = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            // compare current element vs 
            // the combined version of current element & max subarray up until the current element
            local_max = max(nums[i], local_max + nums[i]); 
            // update global maximum
            global_max = max(global_max, local_max);
        }
        return global_max;
    }
};

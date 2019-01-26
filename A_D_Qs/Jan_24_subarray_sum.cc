class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> map; // <sum(i), frequency of sum(i)>
        int curr_sum = 0, count = 0;
        map[0] = 1;   
        for (int i = 0; i < nums.size(); i++)
        {
            curr_sum += nums[i];
            if (map.count(curr_sum-k))
                count += map.find(curr_sum-k)->second;
            ++map[curr_sum];
        }
        return count;
    }
};

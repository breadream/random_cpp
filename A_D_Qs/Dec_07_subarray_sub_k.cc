class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		unordered_map <int, int> map; // <sum(i), # of sum(i) in the array>
		map[0] = 1; // occurrence of sum 0 = 1
		int curr_sum = 0, count = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			curr_sum += nums[i];
			if (map.count(curr_sum-k))
				count += map.find(curr_sum-k)->second; // if (curr_sum-k) is already in map, add it together
	 		++map[curr_sum];
		}
		return count;
	}
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // K,V = number, number's index  
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int diffNum = target - nums[i];
            if (map.count(diffNum))
            {
                res.push_back(map.find(diffNum)->second);
                res.push_back(i);
                break;
            }
            map[nums[i]] = i; // to avoid same numbers
        }
        return res;
    }
};

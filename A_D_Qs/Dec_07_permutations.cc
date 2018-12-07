//http://forum.codecall.net/topic/64715-how-to-generate-all-permutations/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        permute_helper (ans, 0, nums);
        return ans; 
    }
private:    
    void permute_helper (vector<vector<int>>& ans, int begin, vector<int>& nums)
    {
        if (begin == nums.size()-1)
        {
            ans.emplace_back(nums);
            return;
        }
        // we fix one element in the initial position and try to change the rest of them 
        // call the same function recursively with one less element 
        for (int i = begin; i < nums.size(); i++)
        {
            swap(nums[i], nums[begin]);    
            permute_helper(ans, begin+1, nums); // one more element ahead 
            swap(nums[i], nums[begin]); // replace back 
        }
    }
};

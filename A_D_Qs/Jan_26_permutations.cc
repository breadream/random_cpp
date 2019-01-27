class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        backtrack(res, 0, nums);
        return res;
    }
private:
    void backtrack (vector<vector<int>>& res, int pivot, vector<int>& nums)
    {
        if (pivot == nums.size()-1)
        {
            res.push_back(nums);
            return;
        }
        // https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
        // start from swapping itself and with next one, next one...
        // ABC -> A <-> A => 'A'BC, A <-> B => 'B'AC, A <-> C => 'C'BA
        // recursively do this process to the rest of un-fixed integers
        for (int i = pivot; i < nums.size(); i++)
        {
            swap(nums[i], nums[pivot]);
            // fix the pivot point and permute the rest of numbers
            // nums[0 ... pivot] -> fixed, nums[pivot+1 ... end] -> to be permuted 
            backtrack(res, pivot+1, nums); 
            swap(nums[i], nums[pivot]);
        }
    }
};

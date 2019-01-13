class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans (nums.size(), 1);
        for (int i = 0, prod = 1; i < nums.size(); i++)
        {
             ans[i] *= prod; 
             prod *= nums[i];  // product is fed with each number  
        }
        
        for (int i = nums.size()-1, prod = 1; i >= 0; i--) // feed in numbers in the opposite way 
        {
             ans[i] *= prod; 
             prod *= nums[i]; 
        }
        return ans;
    }
};

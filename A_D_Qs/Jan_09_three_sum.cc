class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() <= 2)
            return ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            if (a > 0) // if the first element is positive, there's no way to make the sum as 0
                break;
            if (i > 0 && nums[i-1] == a) // if it is same as 'a', skip..
                continue;
            for (int j = i+1, k = nums.size()-1; j < k;)
            {
                int b = nums[j];
                int c = nums[k];
                int sum = a + b + c;
                if (sum == 0)
                {
                    ans.emplace_back(vector<int>({a, b, c}));
                    while (j < k && nums[++j] == b); // skip same numbers as 'b'
                    while (j < k && nums[--k] == c); // skip same numbers as 'c'
                }
                else if (sum < 0)
                    j++;
                else 
                    k--;
            }
        }
        return ans;
    }
};

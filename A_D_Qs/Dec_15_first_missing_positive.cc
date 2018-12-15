class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // numbers greater than M can be ignored because missing positive number is [1, N+1]
        int n = nums.size();
        
        // if n is less than 0 or greater than n, mark it with a special number (n+7)
        for (int i = 0; i < n; i++)
            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = n + 7; 
        // now all the numbers are within the ragne [1, N]
        
        
        // once all numbers become positive, a number that is in range [1, N] goes negative 
        for(int i = 0; i < n; i++)
        {
            int numToIndex = std::abs(nums[i]); // make current element to positive
            if (numToIndex > n) // if that index is more than n, skip it 
                continue;
            numToIndex--; // to count the number from 0, e.g.) num '1' -> [0]  
            if (nums[numToIndex] > 0) // avoid double negative & make 
                nums[numToIndex] *= -1;
        }
        
        for (int i = 0 ; i < n; i++)
            if (nums[i] >= 0) // find the index of the number that is not negative 
                return i+1;
        
        return n+1; // if no positive number found, array contains [1,N] numbers
    }
};

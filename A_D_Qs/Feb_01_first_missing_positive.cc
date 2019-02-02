class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // if element is less than 0 or greater than n, mark it with a special number (n+1)
        // if all numbers are greater than nums.size(), we can simply return 1
        for (int & i : nums)
            if (i <= 0 || i > nums.size())
                i = n+1;
        
        // now all the numbers are within the range [1, N+1] and positive 
        for(const int &num: nums)
        {
            int index = abs(num);   
            cout << index << endl;
            if (index > nums.size()) // if index is more than array size, skip it 
                continue;
            if (nums[--index] > 0) // to count the number from 0, e.g.) num '1' -> [0]  
                nums[index] *= -1; // make the number that is in range [1, N+1] goes negative 
        }
        
        for (int i = 0 ; i < nums.size(); i++)
            if (nums[i] >= 0) // find the index of the number that is not negative 
                return i+1;
        
        return nums.size()+1; // if no positive number found, array contains all number in [1,N] 
    }
};

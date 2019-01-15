class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // if the given sequence is in descending order, no next larger permutation is possible 
        // (1) we need to find the first pair of two successive numbers that satisfy a[i-1] < a[i] (from the right)
        // no re-arrangement of the right side of a[i-1] can make larger permutation since it's in descending order
        // next step is to rearrange the subarray starting a[i-1] to the right 
        // (2) we need the permutation just larger than current one 
        // (3) so let's replace a[i-1] with the number just larger than itself 
        // after swapping we need the smallest permutation formed by the numbers only the right side of 'new' a[i-1] 
        // (4) the permutation after a[i-1] should be in ascending order to get the smallest number 
        int p = 0;
        int q = 0;
        int temp;
        for (int i = nums.size()-1; i > 0; i--)
            if (nums[i-1] < nums[i])
            {
                p = i-1; // step (1), we find the index of i-1
                break;
            }
        
        for (int i = nums.size()-1; i > p; i--) // p = i-1
            if (nums[i] > nums[p]) // the number that is just larger than a[i-1]
            {
                q = i; // step (2) 
                break;
            }
                
        // if the original permutation is in descending order, we need to reverse all of them to get the smallest  
        if (p + q == 0) 
        {
            reverse(0, nums.size()-1, nums);
            return;
        }
        
        swap(nums[p], nums[q]); // step (3)
      
        reverse(p+1, nums.size()-1, nums); // step (4)
    }
    
    void reverse (int start, int end, vector<int>& nums)
    {
        while (start < end)
        {
            int num = nums[start];
            nums[start] = nums[end];
            nums[end] = num;  
            ++start;
            --end;
        }
    }
};

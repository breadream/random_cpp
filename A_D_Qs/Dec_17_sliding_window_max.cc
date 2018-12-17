class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // containing index 
        vector<int> ans;
        // A window ending at current element, only pick the decreasing sequence to the dq
        // The front element in the dq will be the maximum element
        for (int i = 0; i < nums.size(); i++)
        {
            // remove elements that are out of the window
            if (!dq.empty() && dq.front() == i-k)
                dq.pop_front();
            
            // pop the elements in dq that are less than current element-
            // because those element can't be maximum element
            while (!dq.empty() && nums[dq.back()] < nums[i]) // nums[i] == current element
                dq.pop_back();
            
            // push the current element to the queue
            dq.push_back(i);
            
            if (i >= k-1) // once we reach k elements in nums 
                ans.emplace_back(nums[dq.front()]);
        }
        return ans;
    }
};

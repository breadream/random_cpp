class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0)
            return 0;
        int ans = 0;
        vector<int> max_left (height.size()), max_right(height.size());
        
        max_left[0] = height[0]; // the begin is the same 
        for (int i = 1; i < height.size(); i++)
            max_left[i] = max(max_left[i-1], height[i]);
        
        max_right[height.size()-1] = height[height.size()-1]; // the end is the same
        for (int i = height.size()-2; i >= 0; i--)    
            max_right[i] = max(max_right[i+1], height[i]);
        
        for (int i = 1; i < height.size()-1; i++)
            ans += min(max_left[i], max_right[i]) - height[i]; // find the trapped water by subtracting height[i] 
        
        return ans;
    }
};

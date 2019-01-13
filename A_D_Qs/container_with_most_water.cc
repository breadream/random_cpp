class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = INT_MIN;
        int col, row;
        for (int i = 0, j = height.size(); i < j;)
        {
            col = min(height[i], height[j-1]); 
            row = j - 1 - i; 
            max = std::max(col * row, max);
            if (height[i] < height[j-1])
                ++i;
            else
                --j;
        }
        
        return max;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN;
        int col, row, area;
        for (int left = 0, right = height.size()-1; left < right;)
        {
            col = min (height[left], height[right]);
            area = col * (right - left);
            maxArea = max (area, maxArea);
            if (height[left] < height[right])
                left++;
            else
                right--;    
        }
        return maxArea;
    }
};

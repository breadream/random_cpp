 int largestRectangleArea(vector<int>& heights) {
        stack<int> stack; // to store each bar's index
        stack.push(-1); // to mark the end
        int maxArea = 0;
        
        for (int i = 0; i < heights.size(); i++)
        {
            // keep pushing the current bar's index onto the stack 
            // until we get two successive numbers in descending order 
            // heights[stack.top()] -> previous bar  
            while (stack.top() != -1 && heights[stack.top()] >= heights[i])
            {
                int topVal = stack.top();
                stack.pop();
                // find out the area of rectangle formed using the current element 
                // as the height of the rectangle 
                // and the difference between the current element's index 
                // and the element stack[top-1]-1 as the width 
                maxArea = std::max(maxArea, heights[topVal] * (i-stack.top()-1));
                // heights[topVal] = height
                // i - stack[top-1] -1 = width
            }
            stack.push(i);
        }
        
        while (stack.top() != -1)
        {
            int len = heights.size();
            int topVal = stack.top();
            stack.pop();
            maxArea = std::max(maxArea, heights[topVal] * (len-stack.top()-1));
        }
        return maxArea;     
    }

i int largestRectangleArea(vector<int>& heights) {
        stack<int> stack; // to store each bar's index
        stack.push(-1); // to mark the end
        int maxArea = 0;
        
        for (int i = 0; i < heights.size(); i++)
        {
            // if we found two successive numbers in desecnding order
            while (stack.top() != -1 && heights[stack.top()] >= heights[i])  
            {
                int topVal = stack.top();
                stack.pop();
                // heights[topVal] = height of the rectangle
                // (i - stack.top()-1) = width of the rectangle 
                // (i; anchor point, stack.top()+1; left end of the rectangle)
                maxArea = std::max(maxArea, heights[topVal] * (i-(stack.top()+1)));
            }
            // keep pushing the current bar's index onto the stack 
            // until we get two successive numbers in descending order 
            stack.push(i);
        }
        
        // process the indices still in the stack
        while (stack.top() != -1)
        {
            int len = heights.size();
            int topVal = stack.top();
            stack.pop();
            maxArea = std::max(maxArea, heights[topVal] * (len-(stack.top()+1)));
        }
        return maxArea;     
    }

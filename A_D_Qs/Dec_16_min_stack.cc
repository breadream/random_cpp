class MinStack {
    stack<int> s1, s2;
public:
    /** initialize your data structure here. */
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= getMin()) 
            s2.push(x);
    }
    
    void pop() {
        if (s1.top() == s2.top())
            s2.pop();
        s1.pop();
    }
    
    int top() {
        int topVal = s1.top();
        return topVal;
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

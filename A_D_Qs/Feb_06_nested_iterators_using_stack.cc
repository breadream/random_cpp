/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    // push from back to front in order to get the top element when popping the stack
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size()-1; i >=0; i--)
            s.push(nestedList[i]);
    }
 
    int next() {
        int num = s.top().getInteger();
        s.pop();
        return num;
    }

    bool hasNext() {
        while (!s.empty())
        {
            NestedInteger curr = s.top();
            if (curr.isInteger())
                return true;
            // if the current one is not integer, pop it and keep flattening it 
            s.pop();
            
            vector<NestedInteger> &nested = curr.getList();
            for (int i = nested.size()-1; i >= 0; i--)
                s.push(nested[i]);
        }
        return false;
    }
    
private:
    stack<NestedInteger> s;        
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

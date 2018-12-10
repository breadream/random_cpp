class MedianFinder {
public:
    /** initialize your data structure here. */
    
    void addNum(int num) {
        lowers.push(num);
        highers.push(lowers.top());
        lowers.pop();
        if (lowers.size() < highers.size())
        {
            lowers.push(highers.top());
            highers.pop();
        }
    }
    
    double findMedian() {
        return lowers.size() > highers.size() ? (double) lowers.top() : (lowers.top() + highers.top()) / 2.0;
    }
private:    
     priority_queue<int> lowers; // descending order; find the largest among lower numbers 
     priority_queue<int, vector<int>, greater<int> > highers; // ascending order; find the smallest number among larger numbers
         
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

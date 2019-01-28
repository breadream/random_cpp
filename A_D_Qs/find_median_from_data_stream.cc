class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue <int> lowers;  // descending order, find the largest among the lower numbers
    priority_queue <int, vector<int>, greater<int>> highers; // ascending order, find the smallest among the higher numbers 
    
    void addNum(int num) {
        lowers.push(num); // push the current number and the number is sorted into the queue 
        highers.push(lowers.top()); // get the largest number from lowers queue  
        lowers.pop(); // pop the largest number since it's stored in highers queue
        // balance the sizes 
        if (lowers.size() < highers.size())
        {
            lowers.push(highers.top());
            highers.pop();
        }
    }
    
    double findMedian() {
        return lowers.size() > highers.size() ?  lowers.top() : (lowers.top() + highers.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

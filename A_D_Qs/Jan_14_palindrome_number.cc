
class Solution {
public:
    bool isPalindrome(int x) {
        // if the number is negative, return false
        if (x < 0)
            return false;
        // use a double ended queue
        deque <int> dq;
        
        // push all digits into deque
        while (x > 0)
        {
            dq.push_back(x % 10);
            x /= 10;
        }
        
        // if it has single number, return true
        if (dq.size() == 1)
            return true;
        
        // compare first and last digits of input number 
        while (!dq.empty())
        {
            if (dq.front() != dq.back())
                return false;
            dq.pop_front();
            if (dq.empty())
                return true;
            dq.pop_back();
        }
        return true;
    }
};

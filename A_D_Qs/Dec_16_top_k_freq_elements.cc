class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == k)
            return nums;
        unordered_map<int, int> numToFreq;
        unordered_map<int, queue<int>> FreqToNum;
        priority_queue<int> q;
        vector<int> res;
        
        for (int i : nums)
        {
            if (numToFreq.count(i))
                ++numToFreq[i];
            else 
                numToFreq[i] = 0;
        }
        
        for (auto it = numToFreq.begin(); it != numToFreq.end(); it++)
        {
            FreqToNum[it->second].push(it->first);
            q.push(it->second);
        }
        
        while (k > 0)
        {
            int key = q.top();
            q.pop();
            res.emplace_back(FreqToNum[key].front());
            FreqToNum[key].pop();
            k--;
        }
        return res;
    }
};

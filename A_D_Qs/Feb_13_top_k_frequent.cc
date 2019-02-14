class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == k)
            return nums;
        
        unordered_map<int, int> numToFreq;
        // if we find a same number, which implies the same key, we're gonna push it into queue 
        unordered_map<int, queue<int>> freqToNum; 
        priority_queue <int> q;
        vector<int> ans;
        //  populate the map
        for (const int & i : nums)
            numToFreq[i] = numToFreq.count(i) ? numToFreq[i]+1 : 0;
        
        // populate the freqToNum
        for (auto it = numToFreq.begin(); it != numToFreq.end(); it++)
        {
            freqToNum[it->second].push(it->first);
            q.push(it->second); // priority queue keeps track of the frequency
        }
        
        while (k > 0)
        {
            int key = q.top();
            q.pop();   
            ans.emplace_back(freqToNum[key].front());
            freqToNum[key].pop();
            k--;
        }
        return ans;
    }
};

class Solution {
public:
    // basic idea is to consume the most frequent task first
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq (26, 0);
        for (char c : tasks)
            freq[c-'A']++; 
        sort(freq.begin(), freq.end()); // in ascending order
        int intervals = 0;
        // freq[25] holds the most frequent task
        while (freq[25] > 0) // there's still tasks to consume
        {
            int i = 0; 
            while (i <= n) // to prevent same tasks
            {
                if (freq[25] == 0) // if the most frequent task is finished, move onto next one 
                    break;
                if (i < 26 && freq[25-i] > 0)  
                    freq[25-i]--;
                intervals++;
                i++; // go to the second most frequent task
            }
            sort(freq.begin(), freq.end()); // update the frequency 
        }
        return intervals;
    }
};

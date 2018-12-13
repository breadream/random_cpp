class Solution {
public:
    // basic idea is to consume the most frequent task first
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> map (26, 0);
        for (auto c : tasks) // get the occurrences of each alphabet
            map[c-'A']++;
        sort(map.begin(), map.end()); // asecnding order
        int interval = 0;
        while (map[25] > 0) // there's still an element to be consumed 
        {
            int i = 0;
            while (i <= n)
            {
                if (map[25] == 0) // if the end is 0, break
                    break;
                if (i < 26 && map[25-i] > 0)
                    map[25-i]--;
                interval++;
                i++;
            }
            sort(map.begin(), map.end()); // update the index
        }
        return interval;
    }
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector <int> starts, ends;
        int rooms= 0, s_ptr = 0, e_ptr = 0;
        for (auto interval : intervals)
        {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        
        return rooms;
    }
};

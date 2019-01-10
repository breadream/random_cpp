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
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() <= 1)
            return intervals;
        vector<Interval> ans;
        // sort a collection of intervals increasing order of start value
        // lambda exp ; [introducer_capture](int parameters) -> return_type{ return statement; }
        sort(intervals.begin(), intervals.end(), [](const Interval& l, const Interval& r){ return l.start < r.start; }); 
        for (int i = 1; i < intervals.size(); i++)
        {
            // if the start value is less than or equal to either of previous start or end value
            if (intervals[i].start <= intervals[i-1].start || intervals[i].start <= intervals[i-1].end)
            {
                intervals[i].start = min(intervals[i-1].start, intervals[i].start);
                intervals[i].end = max (intervals[i-1].end, intervals[i].end);
                intervals[i-1].start = intervals[i-1].end = -1; // nullify the previous interval
            }
        }
        
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i].start != -1 && intervals[i].end != -1)
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};

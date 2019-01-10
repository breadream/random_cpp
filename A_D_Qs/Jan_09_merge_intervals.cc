     if (intervals.size() <= 1) return intervals;
        vector<Interval> ans;
        int size = intervals.size();
        std::sort(intervals.begin(), intervals.end(), [](const Interval& l, const Interval& r) { 
            return l.start < r.start; });
        
        for (int i = 1; i < size; i++) 
            if (intervals[i-1].start >= intervals[i].start || intervals[i-1].end >= intervals[i].start) {
                intervals[i].start = min(intervals[i-1].start, intervals[i].start);
                intervals[i].end = max(intervals[i-1].end, intervals[i].end);
                intervals[i-1].start = intervals[i-1].end = -1; // nullify a vector 
            }
        
        
        for (int i = 0; i < size; i++)
            if (intervals[i].start != -1 && intervals[i].end != -1) // erase a null vector 
                ans.push_back(intervals[i]);
                
                
        return ans;  

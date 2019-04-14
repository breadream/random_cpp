 vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // same as greater as compare method, resulting in ascending order
        priority_queue<vector<int>, vector<vector<int>>, compare> pq(points.begin(), points.end());
        vector<vector<int>> ret;
        int i = 0;
        while(i < K) 
        {
            ret.push_back(pq.top());
            pq.pop();
            i++;
        }
        return ret;
    }
private:
    struct compare 
    {
        bool operator() (const vector<int>& p, const vector<int>& q)
        {
            return p[0]*p[0] + p[1]*p[1] > q[0]*q[0] + q[1]*q[1];
        }
    };

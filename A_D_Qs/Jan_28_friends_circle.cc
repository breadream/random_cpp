class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) 
    {
        int circles = 0;
        for (int s = 0; s < M.size(); s++) // s = student
            // every time we see a new student, increment the number of circles and explore current student
            if (M[s][s]) 
            {
                circles++; 
                explore (s, M);
            }
        return circles;
    }
private:
    void explore (int s, vector<vector<int>>& M)
    {
        if (!M[s][s])
            return; 
        M[s][s] = 0;
        for (int f = 0; f < M[s].size(); f++)
            if (M[s][f] == 1) // explore current student's friend 
                explore(f, M);
    }
};

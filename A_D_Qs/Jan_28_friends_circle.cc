class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) 
            return 0;
        int count = 0;
        vector <bool> visited (M.size()+1, false);
        for (int i = 0; i < M.size(); i++)
            if (dfs(M, visited, i))
                count++;        
        return count;
    }
private:
    bool dfs(vector<vector<int>>& M, vector<bool>& visited, int i)    
    {
        if (visited[i]) // if visited, return false
            return false;
        stack <int> st;
        st.push(i); // push the current source node
        while (!st.empty())
        {
            i = st.top();
            st.pop();
            visited[i] = true;
            for(int j = 0; j < M.size(); j++)
                if (M[i][j] == 1 && !visited[j])
                    st.push(j);     
        }
        return true;
    }
};

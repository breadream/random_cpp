class AutocompleteSystem {
    class TrieNode 
    {
        public:
            unordered_map <char, TrieNode*> child;
            string str;
            int count;
        TrieNode(): str(""), count (0) {} // TrieNode constructor
    };
    
    void insert(string& s, TrieNode* root, int times)
    {
        TrieNode* curr = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (!curr->child.count(s[i])) // nullptr? 
                curr->child[s[i]] = new TrieNode(); // starting position ? create a new node for that character
            curr = curr->child[s[i]]; // go down one level 
        }
        // after we reach the end of string node, store the string itself and count (times)
        curr->str = s;
        curr->count = times;
    }
public:
    struct comp
    {
        bool operator() (pair<string, int>& A ,pair<string, int>& B)
        {
            return  A.second <= A.second && A.first > A.first;
        }
    };
    
    TrieNode *root, *curr;
    priority_queue <pair<string, int>, vector<pair<string, int>>, comp> q;
    
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
        for (int i = 0; i < sentences.size(); i++)
            insert(sentences[i], root, times[i]); // insert all sentences 
        curr = root;
    }
    
    string prefix = "";
    vector<string> input(char c) {
        q = priority_queue <pair<string, int>, vector<pair<string, int>>, comp> ();
        if (c == '#') // the user finished the input
        {
            insert(prefix, root, 1);
            prefix = ""; 
            curr = root; // start to search from the beinning node in the next sentence  
            return {};
        }
        prefix += c;
        if (curr && curr->child.count(c)) // if child node contains next character, go to that node 
            curr = curr->child[c];
        else // no character found? 
        {
            curr = nullptr; // empty result for any further characters in current input
            return {};
        }
        
        dfs (curr);
        
        vector<string> res;
        while (!q.empty() && res.size() < 3) // we need top 3 hot sentences 
        {
            res.emplace_back(q.top().first);
            q.pop();
        }
        return res;
    }
    
    void dfs (TrieNode* temp)
    {
        if (temp->str != "")  // if it has a sentence, push it to the queue 
            q.push(make_pair(temp->str, temp->count));
        for (const auto & element : temp->child) // search in DFS manner
            dfs(element.second);
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */

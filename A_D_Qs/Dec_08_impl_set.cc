class RandomizedSet {
public:
    unordered_map<int, int> map;        
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.count(val))
            return false;
        else
            map[val] = 1;
        return true;       
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!map.count(val))
            return false;
        else
            map.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        auto it = map.begin();
        int rand_idx = rand() % map.size();
        std::advance(it, rand_idx);
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

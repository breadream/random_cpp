class LRUCache{
 public:
     LRUCache(int capacity) : cap(capacity){
     }

     int get(int key) {
         // the key doesn't exist
         if (!map.count(key)) 
             return -1;
         // move the recently used item to the front
         cache.splice(cache.begin(), cache, map.find(key)->second);
         return (map.find(key)->second)->second;
     }

     void put(int key, int value) {
         // if the key & value pair exists already, remove the old one 
         if (map.count(key))
             cache.erase(map.find(key)->second);
         
         cache.push_front({key, value});
         map[key] = cache.begin();
         if (map.size() > cap)
         {
             int key = cache.rbegin()->first; // rbegin() -> reverse
             cache.pop_back();
             map.erase(key);
         }
     }

 private: 
    int cap;
    list <pair<int, int>> cache;
    unordered_map <int, list<pair<int, int>>::iterator> map;
 };

// A way to perform the update is as follows
Point p(1, 2);
unordered_map <Point, string, HashPoint> table;
table[p] = "Something";
auto val = table[p];
table.erase(p);
p.x = 4;
table[p] = val;

// Above approach involves a wasteful copy to val
// A much more efficient approach is below
Point p(1, 2);
unordered_map<Point, string, HashPoint> table;
table[p] = "Something";
auto it = table.find(p);
p.x = 4;
std::swap(table[p], it->second);
table.erase(it);

// equivalent approach 
Point p(1, 2);
unordered_map<Point, string, HashPoint> table;
table[p] = "Something";
auto it = table.find(p);
p.x = 4;
table[p] = std::move(it->second);
table.erase(it);

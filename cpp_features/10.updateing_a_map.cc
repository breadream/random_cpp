// find out what is incorrect in the code below

// Attempt 1 
unordered_map <Point, string, HashPoint> table;
Point p {1, 2};
table[p] = "Something";
p.x = 3;

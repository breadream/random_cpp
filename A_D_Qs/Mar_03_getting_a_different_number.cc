int getDifferentNumber( const vector<int>& arr ) 
{
    unordered_set <int> set;
    for (int i = 0; i < arr.size(); i++)
        set.insert(arr[i]);
  
    for (int i = 0; i < arr.size(); i++)
      if (!set.count(i))
         return i;
  
    return arr.size(); 
}

void reverse(vector<char>& arr, int start, int end)
{
   while (start < end)
   {
      char temp = arr[start];
      arr[start] = arr[end];
      arr[end] = temp;
      start++;
      end--;
   }
}


vector<char> reverseWords( const vector<char>& arr ) 
{
     vector<char> res (arr.rbegin(), arr.rend()); 
     int i = 0, wordStart = 0; 
     while (i < res.size()) 
     {
        i++;
        if (i == res.size())
        {
          reverse(res, wordStart, i-1);
        }
        else if (res[i] == ' ')
        {
          reverse(res, wordStart, i-1);
          wordStart = i+1;
        }
     }
     return res;
}

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
     int wordEnd = 0, wordStart = 0; 
     while (wordEnd < res.size()) 
     {
        wordEnd++;
        if (wordEnd == res.size())
        {
          reverse(res, wordStart, i-1);
        }
        else if (res[wordEnd] == ' ')
        {
          reverse(res, wordStart, i-1);
          wordStart = wordStart + 1;
        }
     }
     return res;
}

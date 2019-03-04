// CPP program to check if a string is 
// substring of other. 
#include <bits/stdc++.h> 
using namespace std; 

// Returns true if s1 is substring of s2 
int isSubstring(string text, string pattern) 
{ 
	int textSize = text.size();
  	int patternSize = pattern.size();
  
  	for (int start = 0; start <= textSize-patternSize; start++)
    {
      int end = 0;
      for (end = 0; end < patternSize; end++)
      {
          if (text[start + end] != pattern[end])
          	break;
      }
      if (end == patternSize)
          return start;
    }
  return -1;
} 

/* Driver program to test above function */
int main() 
{ 
	string pattern = "for"; 
	string text = "geeksforgeeks"; 
	int res = isSubstring(text, pattern); 
	if (res == -1) 
		cout << "Not present"; 
	else
		cout << "Present at index " << res; 
	return 0; 
} 

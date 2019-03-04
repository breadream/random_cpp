
/* https://bowbowbow.tistory.com/6?category=159621
 * KMP (Knuth Morris Pratt) algorithm  (pattern matching method)
 * O(N + M) where N == text.length, M = pattern.length
 * (Naive approach is O(N*M))
 * -- prefix and suffix 
 * e.g. for 'apple'
 * prefix; 'a', 'ap', 'app', 'appl', 'apple'
 * suffix; 'e', 'le', 'ple', 'pple', 'apple',
 * -- pi[i] 
 *  from the given text, the longest length of possible prefix == suffix
 * e.g. 'ABAABAB' 
 *  i  |  substring  |  pi[i]
 *  0     A				  0
 *  1  	  AB          	  0
 *  2	 'A' B 'A'        1
 *	3	 'A' BA 'A'       1
 *	4    'AB' A 'AB'      2
 *	5 	 'ABA''ABA'       3
 *	6	 'AB' AAB 'AB'    2
 *
 * Let's say we want to find the pattern 'ABCDABE' from the text 'ABCDABCDABEE'
 * index 	0  1  2  3  4  5  6  7  8  9  10 11
 * text  	A  B  C  D  A  B  C  D  A  B  E  E 
 * pattern  A  B  C  D  A  B 'E'  -> 6th index of pattern doesn't match
 *
 * the key of KMP is to take advantage of already matched pattern 
 *  
 * index 	0  1  2  3  4  5  6  7  8  9  10 11
 * text  	A  B  C  D  A  B  C  D  A  B  E  E 
 * pattern 'A  B  C  D  A  B' E   -> we focus on matched pattern instead of the unmatched *
 *
 * we can go to next step like below 
 *
 *                           (i) -> current location of a character in text 
 * index 	0  1  2  3  4  5  6  7  8  9  10 11
 * text  	A  B  C  D  A  B  C  D  A  B  E  E 
 * pattern 			   'A  B' C  D  A  B  E   
 *                           (j) -> current location of a character in pattern
 *
 * but how can we do that? 
 * because the prefix 'AB' and the suffix 'AB' match, which is also the longest match 
 * index 	0  1  2  3  4  5  6  7  8  9  10 11
 * text  	A  B  C  D  A  B  C  D  A  B  E  E 
 * pattern 'A  B' C  D 'A  B' E  -> pi[5] of the pattern'ABCDABE' is 2 
 *
 * so basically KMP jumps over in text using pi[i] by using already matched up string 
 *
 *
 *
 * more examples
 * text: "ABABABABBABABABABC",  pattern: "ABABABABC"
 *
 *                                 (i) -> "ABABABAB" matched, try using pi[7] 
 * index 	0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17
 * text     A  B  A  B  A  B  A  B  B  A  B  A  B  A  B  A  B  C
 * pattern 'A  B  A  B  A  B  A  B' C			   
 *                                 (j) -> by using pi[7] = 6,
 *                                 move the pattern to compare i with j of 6
 *                                  
 *
 *                                 (i) -> "ABABAB" matched, try using pi[5]
 * index 	0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17
 * text     A  B  A  B  A  B  A  B  B  A  B  A  B  A  B  A  B  C
 * pattern 		 'A  B  A  B  A  B' A  B  C			   
 *                                 (j) -> by using pi[5] = 4,
 *                                 move the pattern to compare i with j of 4 
 *
 *
 *                                 (i) -> "ABAB" matched, try using pi[3]
 * index 	0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17
 * text     A  B  A  B  A  B  A  B  B  A  B  A  B  A  B  A  B  C
 * pattern 		 	   'A  B  A  B' A  B  A  B  C			   
 *                                 (j) -> by using pi[3] = 2,
 *                                 move the pattern to compare i with j of 2 
 *
 *
 *                                 (i) -> "AB" matched, try using pi[1]
 * index 	0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17
 * text     A  B  A  B  A  B  A  B  B  A  B  A  B  A  B  A  B  C
 * pattern 		 	         'A  B' A  B  A  B  A  B  C			   
 *                                 (j) -> by using pi[1] = 0,
 *                                 move the pattern to compare i with j of 0 
 *
 *                                    (i) -> 1++
 * index 	0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17
 * text     A  B  A  B  A  B  A  B  B  A  B  A  B  A  B  A  B  C
 * pattern 		 	                   A  B  A  B  A  B  A  B  C			   
 *                                    (j) -> == 0 
 * */

#include <iostream>
#include <vector>

using namespace std; 

vector<int> makeTable (const string& pattern){
    int patternSize = pattern.size();
	int j = 0;
    vector<int> table (patternSize, 0);

    for(int i = 1; i < patternSize; i++)
	{
        while(j > 0 && pattern[i] != pattern[j]) // if i-th pattern and j-th pattern don't match
            j = table[j-1];
        if(pattern[i] == pattern[j]) // if they match, increment j
            table[i] = ++j;
    }
    return table;
}

vector<int> KMP(string text, string pattern){
	vector<int> table = makeTable(pattern);
    vector<int> ans;

    int textSize = text.size();
	int patternSize = pattern.size();
	int j = 0;

    for(int i = 0 ; i < textSize; i++) // i is stable only j changes
	{
        while(j > 0 && text[i] != pattern[j]) // 'while' is used to jump all intermediate part 
            j = table[j-1]; // j is altered by table

        if(text[i] == pattern[j])
		{
            if(j == patternSize-1) // j (comparison index) == length of pattern --> real match
			{
                ans.emplace_back(i-patternSize+1);
                j = table[j]; // just in case for another match
			}
            else
			{
                j++;
			}
        }
    }
    return ans;
}


int main()
{
	string pattern = "ABAABAB";
	vector<int> table = makeTable(pattern);
	cout << "Checking table generator; ";
	for (const int c : table)
		cout << c << " "; 
	cout << endl;

	cout << "Testing KMP; ";
	vector<int> kmpTable = KMP("ABABABABBABABABABC", "ABABABABC");

	for (const int c : kmpTable)
		cout << c << " "; 
	cout << endl;

	return 0;
}

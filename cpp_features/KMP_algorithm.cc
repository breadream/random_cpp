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
 *                                 (j) -> by using pi[3] = 4,
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

vector<int> kmp(string s, string p){
    vector<int> ans;
    auto pi = getPi(p);
    int n = s.size(), m = p.size(), j = 0;

    for(int i = 0 ; i < n ; i++)
	{
		/* skip over the intermediate part 
		 * while statement was used instead of if
		 * because we want to pass as many as chars 
		 * by using given information */
        while(j > 0 && s[i] != p[j])  // i is stable only j changes
            j = pi[j-1]; // j is altered by pi array 

        if(s[i] == p[j])
		{
			// j is just the comparison index
			// so if it reaches to the length of pattern 
			// we find the real match
            if(j == m-1)
                ans.push_back(i-m+1);
                j = pi[j]; // just in case for another match
            else
                j++;
        }
    }
    return ans;
}

// same technique is used in here 
// Naive approach is O(m^3)
// but can be reduced to O(m)
vector<int> getPi(string p){
    int m = p.size(), j = 0;
    vector<int> pi(m, 0);

    for(int i = 1; i < m ; i++)
	{
        while(j > 0 && p[i] != p[j])
            j = pi[j-1];
        if(p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

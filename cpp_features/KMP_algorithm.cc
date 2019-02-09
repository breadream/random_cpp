/* KMP (Knuth Morris Pratt) algorithm  (pattern matching method)
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
 * */



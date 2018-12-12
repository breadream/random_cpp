class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set <String> dict = new HashSet<String>();
        dict.addAll(wordList);
        return helper(beginWord, endWord, dict);
    }
    
    private int helper(String beginWord, String endWord, Set<String> dict) {
        if (!dict.contains(endWord)) 
            return 0;
        Queue <String> queue = new LinkedList<String>();
        queue.add(beginWord);
        int dist = 0;
        while (!queue.isEmpty()) { 
            int q_size = queue.size();
            for (int i = 0; i < q_size; i++) { // do it layer by layer 
                String word = queue.remove();
                if (word.equals(endWord))  
                    return dist + 1;
                for (int j = 0; j < word.length(); j++) {
                    char [] arr = word.toCharArray();
                    for (char c = 'a'; c <= 'z'; c++) {
                        arr[j] = c;
                        String temp_word= new String(arr);
                        if (!temp_word.equals(word) && dict.contains(temp_word)) {
                            queue.add(temp_word);
                            dict.remove(temp_word); // to avoid duplicate
                        }
                    }
                }
            } // if one layer of BFS is done, increase the distance
            dist++;
        }
        return 0;
    }
        
};

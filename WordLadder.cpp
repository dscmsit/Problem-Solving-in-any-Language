// LEETCODE 127. Word Ladder {Hard} {LinkedList}

// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord

// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

// Example 1:
// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

// Example 2:
// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: 0
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence. 

// Constraints:

// 1 <= beginWord.length <= 10
// endWord.length == beginWord.length
// 1 <= wordList.length <= 5000
// wordList[i].length == beginWord.length
// beginWord, endWord, and wordList[i] consist of lowercase English letters.
// beginWord != endWord
// All the words in wordList are unique.

### Solution

```
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList1) {
        Set<String> wordList = new HashSet<>();
        for(int i =0; i< wordList1.size(); i++)
            wordList.add(wordList1.get(i));
        if(!wordList.contains(endWord))
            return 0;
        Queue<String> q = new LinkedList<>();
        wordList.add(endWord);
        
        q.offer(beginWord);
        int level =0;
        
        while(!q.isEmpty())
            {
            level++;
            int size = q.size();
            
            for(int i = 0; i < size; i++)
                {
                
                String curr = q.poll();
                
                for( int j = 0; j < curr.length(); j++)
                    {
                    char c[] = curr.toCharArray();
                    for(char x ='a'; x<='z'; x++)
                        {
                    c[j]  =x;
                        
                        String temp = String.valueOf(c);
                        if(temp.equals(endWord))
                            return level+1;
                        if(curr!= temp && wordList.contains(temp))
                            {
                            q.add(temp);
                            wordList.remove(temp);
                            
                            }
                        }
                        
                    }
                
                }
            
            }
        
        return 0;
        
    }
}
```

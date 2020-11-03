## Search Autocomplete System
### Problem Statement
Design a search autocomplete api which generates top k historical 'hot' sentences that have a similar prefix to the input given to the system. The hotness of the word is indicated by the frequency of the word. Higher the frequency hotter the word. If multiple words have the same hotness return any of the phrases such that total suggested phrases is always less than or equal to k.    
```
For example, assume following historical phrases are present in the system:
"i love coding"; Freq = 5 times
"island"; Freq = 3 times
"ironman"; Freq = 2 times
"i love soccer"; Freq = 2 times

Input: "i" 
Output: ["i love coding", "island", "i love soccer"] 
Explanation: Prefixes of all 4 matches the input but since the output is arranged from higher hotness to lower, "i love coding", "island" and "i love soccer" is returned.

Input: "i " 
Output: ["i love coding", "i love soccer"] 
Explanation: Since these two are the only sentences which have the same prefix as input these two are returned. 

Input: "a" 
Output: []
Explanation: Since none the prefixes of historical sentences match the input no suggestions are returned.
```
##### End Points
The system will contain 2 end points:
1. New Phrase - Allows user to input historical data and its frequency. 
2. Get Suggestions - Allows user to provide input to the system for which suggestions are to be generated.

##### Constraints 
The input sentences will only contain alphabet and whitespaces.

### Solution
In order to efficiently store all the historical sentences we use a Trie data structure. Each trie node contains the character and its children, stored in a hash map, so that we are able to access the specific child in O(1) time. Using the trie data structure allows us to save space as phrases having similar prefixes have the same node. Thus, whenever a new phrase is provided we simply add the new phrase to trie.

For a given input to the system we traverse the given input in the trie and retrieve the node which represents the last character of the input string. Then we perform a depth-first-search(dfs) from the retrieved node to get all the suggestions. Whenever we reach the terminal node, we add the generated string and its frequency to a min-heap (priority queue). Whenever the number of elements in the min heap is greater than k we pop an element from the heap. Once the dfs is complete, the contents of the heap are our generated suggestions in reverse order.

All data structures - hashmap, heap, trie have been implemented from scratch

##### Time Complexity
New Phrase - Each insert operation in trie takes **O(L)** time where *L* is the length of the given phrase. We either simply lookup each chracter of the given phrase in the trie or create new node for the character is the character is not present.

Get Suggestions - Traversing the tree to the node representing the last character of the input will take *m* time where m is the length of the input string. The DFS will take *n* time where n is the number of nodes in the subtree of the node found by traversing the input. Since we are limiting the number of entries in heap to k+1, each insert and delete operation will take *log k* time. 
Therefore get suggestions will have **O(m + n + p log k)** time complexity, where 'p' is the number of historical phrases that match the given input.

### Instructions to execute
In the root project folder execute following commands:

```
$ make
$ ./main
```
Select the right options and provide current inputs.



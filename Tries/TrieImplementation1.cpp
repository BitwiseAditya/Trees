/* Problem statement
Implement Trie Data Structure to support these operations:

insert(word) - To insert a string "word" in Trie
search(word) - To check if string "word" is present in Trie or not.
startsWith(word) - To check if there is any string in the Trie that starts with the given prefix string "word".


Three type of queries denote these operations:

Type 1: To insert a string "word" in Trie.
1 word

Type 2: To check if the string "word" is present in Trie or not.
2 word

Type 3: To check if there is any string in the Trie that starts with the given prefix string "word".
3 word


Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= Q <= 5*10^4
1 <= W <= 10

Where 'Q' is the number of queries, and 'W' is the length of the "word".
All input of "word" will consist of only lowercase letters a-z.
Sample Input 1 :
5
1 hello
1 help
2 help
3 hel
2 hel 
Sample Output 1 :
true
true
false
 Explanation to Sample Input 1 :
Query 1: "hello" is inserted
Query 2: "help" is inserted
Query 3: "true" is printed as "help" is present
Query 4: "true" is printed as "hello" and "help" is present having the prefix "hel"
Query 5: "false" is printed as "hel" is not present
Sample Input 2 :
10
1 aaaa
1 aaaaaa
1 bcd
2 aaaaa
3 aaaaa
3 bc
2 bc
1 bc
3 bcda
2 bc
Sample Output 2 :
false
true
true
false
false
true
 Explanation to Sample Input 2 :
Query 1: "aaaa" is inserted
Query 2: "aaaaaa" is inserted
Query 3: "bcd" is inserted
Query 4: "false" is printed as "aaaaa" is not present
Query 5: "true" is printed as "aaaaaa" is present having the prefix "aaaaa"
Query 6: "true" is printed as "bcd" is present having the prefix "bc"
Query 7: "false" is printed as "bc" is not present
Query 8: "bc" is inserted
Query 9: "false" is printed as no word is present having the prefix "bcda"
Query 10: "true" is printed as "bc" is present */   

#include <bits/stdc++.h>
using namespace std;
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
 struct node{
     struct node * arr[26];
     bool flag;
 };

class Trie {

public:
    
    struct node * root;

    /** Initialize your data structure here. */
    Trie() {
       root = new node();
       root->flag = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        struct node * temp = root;
        int n = word.length();
        for(int i=0; i<n; i++){
           if(temp->arr[word[i] - 'a'] == NULL){
               temp->arr[word[i] - 'a'] = new node();
           }
           temp = temp->arr[word[i] - 'a'];
           temp->flag = false;
        }
        temp->flag = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        struct node * temp = root;
         int n = word.length();
         for(int i=0; i<n; i++){
             if(temp->arr[word[i] - 'a'] == NULL){
                 return false;
             }
             temp = temp->arr[word[i] - 'a'];
         }
         if(temp->flag) return true;
         else return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         struct node * temp = root;
         int n = prefix.length();
         for(int i=0; i<n; i++){
             if(temp->arr[prefix[i] - 'a'] == NULL){
                 return false;
             }
             temp = temp->arr[prefix[i] - 'a'];
         }
         return true;
    }
};





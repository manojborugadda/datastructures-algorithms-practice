/**
Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is prefix of another. 
Examples: 
 
Input: arr[] = {"zebra", "dog", "duck", "dove"}
Output: dog, dov, du, z
Explanation: dog => dog
             dove => dov 
             duck => du
             zebra => z

Input: arr[] =  {"geeksgeeks", "geeksquiz", "geeksforgeeks"};
Output: { geeksf, geeksg, geeksq }
*/



class TrieNode {  ////TC:O(N*LEN)
  public:
        TrieNode*child[26];
        bool isEndOfWord;
        int count;
        
        TrieNode() {// default constructor
            for(int i = 0;i<26;i++) {
                child[i] = NULL;
            }
            isEndOfWord = false;
            count = 0;
        }
};


class Solution {
    public:
    
    void insertfunc(TrieNode* root,string word) {
        if(word.size() == 0) {
            root->isEndOfWord = true;
            return;
        }
        TrieNode* curr = root;
        for(int i = 0;i<word.length();i++) {
            int index = word[i]-'a';
            if(curr->child[index] == NULL) {
                curr->child[index] = new TrieNode();
            }
            curr->count++;
            curr = curr->child[index];
        }
        curr->count++;
        curr->isEndOfWord = true;
    }
    
    string buildPrefix(TrieNode*root,string word) {
        TrieNode* curr = root;
        string str = "";
        for(int i = 0;i<word.length();i++) {
            int index = word[i]-'a';
            if(curr->child[index]->count == 1) {
                str+= word[i];
                break;
            }
            str+= word[i];
            curr = curr->child[index];
        }
        return str;
    }
    
    vector<string> findPrefixes(string arr[], int n) {
        vector<string>ans;
        TrieNode* root = new TrieNode();
        //inserting the words
        for(int i= 0;i<n;i++) {
            insertfunc(root,arr[i]);
        }
        
        for(int i= 0;i<n;i++) {
            ans.push_back(buildPrefix(root,arr[i]));
        }
        
        return ans;
    }
    
};



//-------------------------------------another approach for solving this problem
/***

class Node{
public:
    Node* links[26];
    int cntPrefix = 0;
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(auto i:word){
            if(!node->links[i-'a'])
                node->links[i-'a'] = new Node();
            node = node->links[i-'a'];
            node->cntPrefix++;
        }
    }
    int check(string word){
        Node* node = root;
        for(int i = 0;i < word.size();i++){
            node = node->links[word[i]-'a'];
            if(node->cntPrefix == 1) return i+1;
        }
        return 0;
    }
};
class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n){
        Trie node;
        for(int i = 0;i < n;i++)
            node.insert(arr[i]);
        vector <string> ans;
        for(int i = 0;i < n;i++)
            ans.push_back(arr[i].substr(0,node.check(arr[i])));
        return ans;
    }
    
};

**/

#include <iostream>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    char val;
    int num;
    bool isEnd;
    TrieNode * sons[26];

    TrieNode() {
        val = ' ';
        num = 0;
        isEnd = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        if(s=="")
            return;
        auto curNode = this->root;
        for(auto curWord : s){
            int idx = curWord - 'a';
            if(curNode.sons[idx]==NULL){

                curNode.sons[idx]->val = curWord;
                curNode.sons[idx]->num = 1;
            }
            else
                curNode.sons[idx]->num++;
            curNode = curNode.sons[idx];
        }
        curNode.isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        if(s=="")
            return true;
        auto curNode = this->root;
        for(auto curWord:key){
            int idx = curWord - 'a';
            if(curNode.sons[idx]==NULL)
                return false;
            else{
                curNode = curNode.sons[idx];
            }
        }
        return curNode.isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if(s=="")
            return true;
        auto curNode = this->root;
        for(auto curWord:key){
            int idx = curWord - 'a';
            if(curNode.sons[idx]==NULL)
                return false;
            else{
                curNode = curNode.sons[idx];
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    char val;
    int num;
    bool isEnd;
    unordered_map<char, TrieNode*> sons;

    TrieNode() {
        val = ' ';
        num = 0;
        isEnd = false;
    }
};

class WordDictionary {
/**
 * It's something like the trie problem
 * The only difference is in the search pattern "."
 * We can implement it by searching each of the sons in the trie
 * when we have a "."
 */
private:
	TrieNode* root;
	bool helper(string word, TrieNode * root){
		if(word=="")
			return true;
		auto curNode = root;
		//for(auto w : word){
		auto w = word[0];
			if(w!='.'){
				if(curNode->sons.find(w)==curNode->sons.end()){
					return false;
				}
				else{
					if(word.length()==1)
						return curNode->sons[w]->isEnd?true:false;
					return helper(string(++word.begin(),word.end()),curNode->sons[w]);
				}
			}else{
				if(curNode->sons.size()==0)
					return false;
				if(word.length()==1){
					for(auto nextNode : curNode->sons){
						if(nextNode.second->isEnd)
							return true;
					}
					return false;
				}
				for(auto nextNode : curNode->sons){
					if(helper(string(++word.begin(),word.end()),nextNode.second)) return true;
				}
				return false;
			}
			
		//}
		return true;
	}
public:
	WordDictionary(){
		root = new TrieNode();
	}
    // Adds a word into the data structure.
    void addWord(string word) {
        if(word=="")
            return;
        auto curNode = this->root;
        for(auto idx : word){
        	if(curNode->sons.find(idx)==curNode->sons.end()){
        		curNode->sons[idx]=new TrieNode();
        		curNode->sons[idx]->val = idx;
        		curNode->sons[idx]->num = 1;
        	}
        	else
        		curNode->sons[idx]->num++;
        	curNode = curNode->sons[idx];
        }
        curNode->isEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
    	return helper(word, this->root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
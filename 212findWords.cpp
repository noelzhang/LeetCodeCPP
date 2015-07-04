class TrieNode {
public:
    // Initialize your data structure here.
    char val;
    int num;
    int idx;
    bool isEnd;
    unordered_map<char, TrieNode*> sons;

    TrieNode() {
        val = ' ';
        num = 0;
        idx = -1;
        isEnd = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    Trie(TrieNode * root_val){
    	this->root = root_val;
    }

    // Inserts a word into the trie.
    void insert(string s, int idx) {
        if(s=="")
            return;
        auto curNode = this->root;
        for(auto c : s){
            if(curNode->sons.find(c)==curNode->sons.end()){
                curNode->sons[c]=new TrieNode();
                curNode->sons[c]->val = c;
                curNode->sons[c]->num = 1;
            }
            else
                curNode->sons[c]->num++;
            curNode = curNode->sons[c];
        }
        curNode->isEnd = true;
        curNode->idx = idx;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        if(key=="")
            return true;
        auto curNode = this->root;
        for(auto idx:key){
            if(curNode->sons.find(idx)==curNode->sons.end())
                return false;
            else{
                curNode = curNode->sons[idx];
            }
        }
        return curNode->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if(prefix=="")
            return true;
        auto curNode = this->root;
        for(auto idx:prefix){
            if(curNode->sons.find(idx)==curNode->sons.end())
                return false;
            else{
                curNode = curNode->sons[idx];
            }
        }
        return true;
    }

private:
    TrieNode* root;
};


class Solution {
private:
	vector<string> ans;
	int width;
	int height;
	void helper(vector<string>& words,vector<vector<char>>& board, Trie & wordsTrie, int i, int j){
		if(board[i][j]=='!')//mark for the path we have visited
			return;
		if(wordsTrie.root->sons.find(board[i][j])==wordsTrie.root->sons.end())
			return;
		else{
			char tmp = board[i][j];
			if(wordsTrie.root->sons[board[i][j]]->isEnd){
				wordsTrie.root->sons[board[i][j]]->isEnd=false;
				ans.push_back(words[wordsTrie.root->sons[board[i][j]]->idx]);
			}

			board[i][j]='!';//mark!
			//check the neighbor points recursively
			if(i>0) helper(words, board,wordsTrie,i-1,j);
			if(i<width-1) helper(words, board,wordsTrie,i+1,j);
			if(j>0) helper(words, board,wordsTrie,i,j-1);
			if(j<height-1) helper(words, board,wordsTrie,i,j+1);

			board[i][j]=tmp;//set the original word back
		}
	}
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    	width = board.size();
    	if(width==0)
    		return ans;
    	height = board[0].size();
    	if(height==0)
    		return ans;
    	if(words.size()==0)
    		return ans;
        Trie wordsTrie;
        for(int i = 0; i<words.size(); ++i){
        	wordsTrie.insert(words[i], i);
        }
        for(int i= 0;i<width;i++){
        	for(int j =0; j<height;++j){
        		helper(words, board,wordsTrie,i,j);
        	}
        }
        return ans;
    }
};
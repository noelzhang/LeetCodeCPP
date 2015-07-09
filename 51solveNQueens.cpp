#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> ans;
    bool isValid(vector<string> &cur, int level, int i, int n){
        for(int j = 0; j < level; j++){
            if (cur[j][i]=='Q') {
                return false;
            }
            if ((i-j-1)>=0 && cur[level-j-1][i-j-1]=='Q') {
                return false;
            }
            if ((i+j+1)<n && cur[level-j-1][i+j+1]=='Q') {
                return false;
            }
        }
        return true;
    }
    void helper(vector<string> &cur, int level, int n){
        if (level == n) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if(isValid(cur, level, i,n)){
                cur[level][i] = 'Q';
                helper(cur, level + 1, n);
                cur[level][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if (!n) {
            return ans;
        }
        
        string tmp(n,'.');
        vector<string> cur(n,tmp);
        helper(cur, 0, n);
        
        return ans;
    }
};


int main(int argc, char ** argv){
    Solution s;
    s.solveNQueens(4);
    return 0;
}
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    bool isValid(vector<vector<char>>& board, int i, int j, char num){
        for (int k = 0; k < 9; k++) {
            if (board[i][k]==num) {
                return false;
            }
            if (board[k][j]==num) {
                return false;
            }
        }
        int ii = i/3, jj = j/3;
        ii *= 3;
        jj *= 3;
        for (int p = 0; p<3; p++) {
            for (int q=0; q<3; q++) {
                if (board[ii+p][jj+q]==num) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool helper(vector<vector<char>>& board){
        bool m=true;
        for (int i = 0; i< 9 ; i++) {
            for (int j = 0; j<9; j++) {
                if(board[i][j]=='.'){
                    m = false;
                    for (int num=1; num<=9; num++) {
                        if (isValid(board, i, j, num+'0')) {
                            board[i][j]='0'+num;
                            if(helper(board))
                                return true;
                        }
                    }
                    board[i][j]='.';
                    return false;
                }
            }
        }
        return m;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};


int main(int argc, char ** argv){
    Solution s;
    vector<string> aa = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    vector<vector<char>> aaa;
    for (int i =0; i<9; i++) {
        vector<char> tmp(aa[i].begin(),aa[i].end());
        aaa.push_back(tmp);
    }
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout<<aaa[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    s.solveSudoku(aaa);
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout<<aaa[i][j];
        }
        cout<<endl;
    }
    return 0;
}
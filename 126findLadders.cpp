/*************************************************************************
	> File Name: 126findLadders.cpp
	> Author: Noelzhang
	> Mail: beitong.zhang.gr@dartmouth.edu
	> Created Time: Sun Jul 26 09:29:27 2015
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
private:
    vector<vector<string> > res;
    
    void DFS(string cur,vector<string> path, unordered_map<string, vector<string> > & treeMap, string end){
        if (cur == end) {
            path.push_back(end);
            res.push_back(path);
            return;
        }
        path.push_back(cur);
        for(auto s : treeMap[cur]){
            DFS(s, path, treeMap, end);
        }
    }
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        dict.erase(start);
        dict.erase(end);
        unordered_map<string, int> treeLevel;
        unordered_map<string, vector<string> > treeMap;
        queue<string> BFSQueue;
        BFSQueue.push(start);
        treeLevel[start]=0;
        treeMap[start] = vector<string>();
        int levelMark = INT_MAX;//level mark, to control the termination of the loop
        while (!BFSQueue.empty()) {
            auto currentString = BFSQueue.front();
            cout<<currentString<<endl;
            BFSQueue.pop();
            if (treeLevel[currentString] == levelMark) {
                break;
            }
            else {
                string tmp = currentString;
                for (int i = 0; i < tmp.length(); ++i) {
                    for (char c = 'a'; c <= 'z'; ++c) {
                        tmp[i] = c;
                        if(tmp == end){
                            levelMark = treeLevel[currentString]+1;
                            treeLevel[tmp] = levelMark;
                            treeMap[currentString].push_back(tmp);
                        }
                        if(dict.find(tmp)!=dict.end() && treeLevel.find(tmp)==treeLevel.end()){
                            BFSQueue.push(tmp);
                            treeMap[currentString].push_back(tmp);
                            treeMap[tmp]=vector<string>();
                            treeLevel[tmp] = treeLevel[currentString] + 1;
                        }
                        else if(dict.find(tmp)!=dict.end() && treeLevel[tmp]==treeLevel[currentString]+1){
                            treeMap[currentString].push_back(tmp);
                        }
                    }
                    tmp = currentString;
                }
            }
        }
        if(levelMark==INT_MAX)
            return res;
        DFS(start,vector<string>(), treeMap, end);
        return res;
    }
};
//"red", "tax", ["ted","tex","red","tax","tad","den","rex","pee"]
int main(int argc, char ** argv){
    Solution s;
    unordered_set<string> aa;
    //aa.insert("a");
    aa.insert("b");//aa.insert("c");//aa.insert("den");aa.insert("rex");aa.insert("pee");
    s.findLadders("a", "c", aa);
	return 0;
}

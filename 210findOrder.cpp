#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;


class Solution {
private:
    vector<int> res;
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, vector<int>> coursesMap;//adj. table
        unordered_map<int, vector<int>> coursesMapReversed;//adj. table
        //unordered_map<int, int> inEdge;//No. of incoming edge
        unordered_set<int> zeroIncoming;
        for(auto p : prerequisites){
            if(coursesMap.find(p.second)==coursesMap.end()){
                vector<int> tmp;
                tmp.push_back(p.first);
                coursesMap[p.second]=tmp;
            }
            else
                coursesMap[p.second].push_back(p.first);
            if(coursesMapReversed.find(p.first)==coursesMapReversed.end()){
                vector<int> tmp;
                tmp.push_back(p.second);
                coursesMapReversed[p.first]=tmp;
            }
            else
                coursesMapReversed[p.first].push_back(p.second);
            zeroIncoming.insert(p.first);
            zeroIncoming.insert(p.second);
        }
        int num = (int)zeroIncoming.size();
        vector<int> others;
        for (int i = 0; i < numCourses; ++i)
        {
            if(zeroIncoming.find(i)==zeroIncoming.end())
                others.push_back(i);
        }
        auto itr = zeroIncoming.begin();
        while(itr!=zeroIncoming.end()){
            if(coursesMapReversed.find(*itr)!=coursesMapReversed.end()){
                itr = zeroIncoming.erase(itr);
            }
            else{
                itr++;
            }
        }
        while(!zeroIncoming.empty()){
            auto cur = *zeroIncoming.begin();
            res.push_back(cur);
            zeroIncoming.erase(zeroIncoming.begin());
            for(auto node: coursesMap[cur]){
                coursesMapReversed[node].erase(coursesMapReversed[node].begin());
                if(coursesMapReversed[node].size()==0)
                    zeroIncoming.insert(node);
            }
        }
        if(res.size()==num){
            res.insert(res.begin(),others.begin(),others.end());
            return res;
        }
        else
            return vector<int>();
    }
    
};


int main(int argc, char ** argv){
    vector<pair<int, int>> aa;
    aa.push_back(make_pair(1, 0));
    Solution s;
    s.findOrder(2, aa);
    
    return 0;
}
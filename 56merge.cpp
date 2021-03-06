#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;



struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if (intervals.size()==0) {
            return ans;
        }
        
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval &b){
            return a.start < b.start;
        });
        Interval cur = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if (cur.end>=intervals[i].start) {
                cur.end = max(cur.end, intervals[i].end);
            }
            else{
                ans.push_back(cur);
                cur = intervals[i];
            }
        }
        ans.push_back(cur);
        return ans;
    }
};

int main(int argc, char** argv){
    Solution s;
    vector<Interval> aa;
    aa.push_back(Interval(1,4));
    aa.push_back(Interval(0,4));
    s.merge(aa);
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    	vector<Interval> ans;
        if(intervals.size()==0){
        	ans.push_back(newInterval);
        	return ans;
        }
        auto itr = intervals.begin()
        for (;itr != intervals.end();++itr){
        	if(itr -> start > newInterval.start){
        		intervals.insert(itr,newInterval);
        		break;
        	}
        }
        if(itr==intervals.end())
        	intervals.push_back(newInterval);
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
/**
 * Given an array of integers, find out whether there are two 
 * distinct indices i and j in the array such that the difference
 * between nums[i] and nums[j] is at most t and the difference 
 * between i and j is at most k.
 */

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k<1||t<0) return false;
        unordered_map<long, long> mp;
        for (int i = 0; i < nums.size(); ++i)
        {
        	long n=(long)nums[i]-INT_MIN;
        	long buck=(long)n/((long)t+1);
        	if(mp.find(buck)!=mp.end() 
        		||	(mp.find(buck-1)!=mp.end() && n-mp[buck-1]<=t)
        		||	(mp.find(buck+1)!=mp.end() && mp[buck+1]-n<=t) )
        		return true;
        	if(mp.size()>=k){
        		long b = ((long)nums[i-k]-INT_MIN)/((long)t+1);
        		mp.erase(b);
        	}
        	mp[buck]=n;
        }
        return false;
    }
};
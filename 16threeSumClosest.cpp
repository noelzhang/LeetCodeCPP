class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	int res = INT_MAX;
    	int elRes = 0;
        if(nums.size()<3)
        	return res;
        sort(nums.begin(),nums.end());
        for(auto itr = nums.begin(); itr != prev(nums.end(), 2); ++itr){
        	auto left = next(itr);
        	auto right = prev(nums.end());
        	while(left != right){
        		int curSum = *itr + *left + *right;
        		if(res > abs(target - curSum)){
        		    res = abs(target - curSum);
        		    elRes = curSum;
        		}
        		if(curSum> target)
        			right--;
        		else
        			left++;
        	}
        }
        return elRes;
    }
};
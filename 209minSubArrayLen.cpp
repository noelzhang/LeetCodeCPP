class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
       	int ans = INT_MAX;
    	int firstIdx = -1, secondIdx = 0;
    	int curSum = 0;
    	while(1){
    		if(curSum<s){
    			if(secondIdx == nums.size())
    				break;
    			curSum+=nums[secondIdx++];
    		}
    		if(curSum>=s){
    			ans = min(ans, secondIdx-firstIdx);
    			curSum -= nums[firstIdx++];
    		}
    	}

    	return ans==INT_MAX?0:ans;
    }
};
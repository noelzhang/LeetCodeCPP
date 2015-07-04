class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0,candidate2 = 1;
        int count1 = 0, count2 = 0;
        vector<int> ans;
        for(auto n : nums){
        	if(n==candidate1)
        		count1++;
        	else if(n==candidate2)
        		count2++;
        	else{
        		if(count2==0){
        			candidate2 = n;
        			count2 = 1;
        		}
        		else if(count1==0){
        			candidate1 = n;
        			count1 = 1;
        		}
        		else{
        			count1--;
        			count2--;
        		}
        	}
        }
        count1=0;count2=0
        for(auto n:nums){
        	if(n==candidate2)
        		count2++;
        	if(n==candidate1)
        		count1++;
        }
        int len = nums.size()/3;
        if(count1>len)
        	ans.push_back(candidate1);
        if(count2>len)
        	ans.push_back(candidate2);
        return ans;


    }
};
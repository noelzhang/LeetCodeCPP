class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3)
        	return res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i< nums.size() - 3; ++i){
        	int firstNum = nums[i];
        	unordered_set<int> numSet;
        	for (int j = 1 + i; j < nums.size(); ++j)
        	{
        		if(numSet.find(-firstNum - nums[j])==numSet.end()){
        			if(numSet.find(nums[j])==numSet.end())
        				numSet.insert(nums[j]);
        		}
        		else{
        			vector<int> tmp = {firstNum, -firstNum - nums[j], nums[j]};
        			res.push_back(tmp);
        		}
        		while(j<nums.size() && nums[j+1] == nums[j])
        			++j;
        	}
        	while(i<nums.size() && nums[i+1] == firstNum)
        		++i;
        }
        return res;
    }
};
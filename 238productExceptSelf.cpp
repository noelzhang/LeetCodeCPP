class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        if(!nums.size())
			return ans;
		for(int i = 1; i<nums.size();++i){
			ans[i] = ans[i-1] * nums[i-1];
		}
		int rightSide=1;
		for(int i = nums.size()-1; i>=0;--i){
			ans[i]*=rightSide;
			rightSide *= nums[i];
		}
		return ans;
    }
};

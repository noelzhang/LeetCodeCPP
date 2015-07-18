#include <vector>
#include <iostream>

using namespace std;


class Solution {
private:
	int findMostLeft(vector<int> & nums, int target){
		int start = 0, end = nums.size();
		while(start<end){
			int mid = (start + end)/2;
			if (target>nums[mid])
			{
				start = mid+1;
			}
			else{
				end = mid;
			}
		}
		return start;
	}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
    	if(!nums.size())
    		return ans;
        int start = findMostLeft(nums, target);
        if(start==nums.size()||nums[start]!=target)
        	return vector<int>(2,-1);
        ans.push_back(start);
        ans.push_back(findMostLeft(nums,target+1)-1);
        return ans;
    }
};

int main(int argc, char ** argv){
    Solution s;
    vector<int> aa={5,7,7,8,8,10};
    s.searchRange(aa,8 );
}
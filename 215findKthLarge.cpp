#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
	int helper(vector<int> & nums, int start, int end, int k){
		int pivot = nums[start];
		int u =  start+1 , v = end;
		while(u<=v){
			if(nums[u]<pivot && nums[v]>pivot)
				swap(nums[u++],nums[v--]);
			else{
				if(nums[u]>=pivot)
					u++;
				if(nums[v]<=pivot)
					v--;
			}
		}
		swap(nums[start],nums[v]);
		if(v==k-1)
			return pivot;
		else if(v>k-1)
			return helper(nums,start,v-1,k);
		else
			return helper(nums,v+1,end,k);
	}
public:
	int findKthLargest(vector<int>& nums, int k) {
		return helper(nums,0,nums.size()-1,k);
	}
};

int main(int argc, char ** argv){
	Solution s;
	vector<int> a = {2,1,3};
	cout<<s.findKthLargest(a, 2);
}
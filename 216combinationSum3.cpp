/**
 * Find all possible combinations of k numbers that add up to a number n, 
 * given that only numbers from 1 to 9 can be used and each combination s
 * hould be a unique set of numbers. 
 * Ensure that numbers within the set are sorted in ascending order.
 */
class Solution {
private:
	vector<vector<int>> ans;
	void helper(vector<int> curAns, int idx, int k, int n){
		if(idx>n)
			return;
		if(k==1){
			if(n<=9){
				curAns.push_back(n);
				ans.push_back(curAns);
			}
			return;
		}
		if(k>n||k*9<n)
			return;
		for(int i=idx;i<=9;i++){
			if(k-1>n-i)
				break;
			curAns.push_back(i);
			helper(curAns,i+1,k-1,n-i);
			curAns.pop_back();
		}
	}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curAns;
        helper(curAns,1,k,n);
        return ans;
    }
};
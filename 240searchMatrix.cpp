class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()||!matrix[0].size()){
        	return false;
        }
        int i = 0, j = matrix[0].size()-1;
        while(i<matrix.size() && j>=0){
        	int cur = matrix[i][j];
        	if(matrix[i][j]==target)
        		return true;
        	else if(cur > target)
        		j--;
        	else
        		i++;
        }
        return false;
    }
};
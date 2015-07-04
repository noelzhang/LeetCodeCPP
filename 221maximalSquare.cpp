class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    	int ans = 0;
    	if(matrix.size()<1||matrix[0].size()<1)
    		return 0;
    	int cols = matrix[0].size();
    	int rows = matrix.size();
        vector<int> dpTemp(cols,0);
        vector<vector<int>> dp(rows,dpTemp);
        for (int i = 0; i < cols; ++i){
        	dp[0][i] = matrix[0][i] =='1' ? 1 : 0;
        	ans= max(ans, dp[0][i]);
        }
        for (int i = 0; i < rows; ++i){
        	dp[i][0] = matrix[i][0] =='1' ? 1 : 0;
        	ans= max(ans, dp[i][0]);
        }
        for (int i = 1; i < cols; ++i)
        {
        	for (int j = 1; j < rows; ++j)
        	{
        		if(matrix[i][j]=='0'){
        			dp[i][j]=0;
        			continue;
        		}
        		if(matrix[i-1][j-1]=='0'||matrix[i-1][j]=='0'||matrix[i][j-1]=='0'){
        			dp[i][j]=1;
        			continue;
        		}
        		if(dp[i-1][j-1]==dp[i-1][j]&&dp[i-1][j-1]==dp[i][j-1]){
        			dp[i][j]=dp[i-1][j-1]+1;
        			ans= max(ans, dp[i][j]);
        			continue;
        		}
        		else{
        			dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
        			ans= max(ans, dp[i][j]);
        		}
        	}
        }
        return ans;
    }
};

/*************************************************************************
	> File Name: 123maxProfit.cpp
	> Author: Noelzhang
	> Mail: beitong.zhang.gr@dartmouth.edu
	> Created Time: Sun Jul 26 16:36:47 2015
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*Say you have an array for which the ith element 
 is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. 
 You may complete at most two transactions.*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;
        for(auto p : prices){
            release2 = max(release2, hold2 + p);
            hold2 = max(hold2, release1 - p);
            release1 = max(release1, hold1 + p);
            hold1 = max(hold1, -p);
        }
        return release2;
    }
};

int main(int argc, char ** argv){
	return 0;
}

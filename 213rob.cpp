#include <vector>
#include <iostream>


using namespace std;


class Solution {
public:
    int rob1(vector<int>& num){
        if(num.size()==0)
            return 0;
        if(num.size()==1)
            return num[0];
        int prev=0,last=num[0];
        for(int i = 1;i<num.size();i++){
            int cur=max(prev+num[i],last);
            prev=last;
            last=cur;
        }
        return last;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        auto aa = nums.begin();
        for(int i =0;i<nums.size();i++)
            aa++;
        vector<int> l1(nums.begin(),aa);
        vector<int> l2(++nums.begin(), nums.end());
        return max(rob1(l1),rob1(l2));
    }
};

int main(int argc, char** argv){
    Solution s;
    vector<int> aa={1,1,1};
    s.rob(aa);
}
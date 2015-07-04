#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0)
            return ans;
        string cur=to_string(nums[0]);
        if(nums.size()==1){
            ans.push_back(cur);
            return ans;
        }
        int i;
        for(i =0;i<nums.size()-1;++i){
            if(nums[i]!=nums[i+1]-1){
                if(cur==to_string(nums[i])){
                    ;
                }
                else{
                    cur+="->";
                    cur+=to_string(nums[i]);
                }
                ans.push_back(cur);
                cur=to_string(nums[i+1]);
            }
        }
        if(nums[nums.size()-1]==nums[nums.size()-2]+1){
            cur+="->";
            cur+=to_string(nums[i]);
            ans.push_back(cur);
        }
        else
            ans.push_back(cur);
            
        return ans;
    }
};

int main(int argc, char** argv){
    Solution s;
    vector<int> aa={0,1,3};
    s.summaryRanges(aa);
}
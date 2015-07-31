#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(!nums.size())
            return res;
        deque<pair<int, int>> window;
        //window.push_back(make_pair(nums[0],0));
        for(int i = 0; i< nums.size(); ++i){
            int sz = (int)window.size();
            for(int j = sz - 1; j >= 0; j--){
                if(nums[i] >= window[j].first){
                    window.pop_back();
                }else{
                    break;
                }
            }
            
            window.push_back(make_pair(nums[i], i));
            if(i >= k-1){
                    if(window[0].second + k <= i){
                        window.pop_front();
                    }
                res.push_back(window[0].first);
            }
        }
        
        
        
        return res;
    }
};


int main(int argc, char ** argv){
    Solution s;
    vector<int> aa = {1,3,-1,-3,5,3,6,7};
    s.maxSlidingWindow(aa, 3);
    
    return 0;
}
/**
 * this method got a TLE in leetcode, KMP is needed!!
 */
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
    string shortestPalindrome(string s) {
        auto len = s.length();
        if(len<2)
            return s;
        int mid,longest=1;
        for(mid =(len-1)/2;mid>0;mid--){
            int begin,end;
            if(s[mid+1]==s[mid]){
                begin=mid-1;
                end = mid+2;
                
                while(begin>=0&&s[begin]==s[end]){
                    begin--;
                    end++;
                }
                if(begin==-1){
                    longest = end;
                    break;
                }
            }
            begin = mid-1;
            end = mid+1;
            while(begin>=0&&s[begin]==s[end]){
                begin--;
                end++;
            }
            if(begin==-1){
                longest = end;
                break;
            }
        }
        auto ss=s.substr(longest,len-longest);
        reverse(ss.begin(),ss.end());
        return ss+s;
    }
};

int main(int argc, char** argv){
    Solution s;
    cout<<s.shortestPalindrome("aaaaaaaaaaaaaaaa");
    return 0;
}
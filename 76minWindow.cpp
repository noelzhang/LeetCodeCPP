#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        string ans;
        int ansLen=INT_MAX;
        int lenT = (int)t.length(),lenS = (int)s.length();
        if(!lenT)
        	return ans;
        unordered_map<char, int> hasFind, need2Find;
        int count=0,fast = 0, slow = 0;
        //first loop, build up the need2Find map;
        for (int i = 0; i < lenT; ++i)
        {
        	if(need2Find.find(t[i])==need2Find.end())
        		need2Find[t[i]]=1;
        	else
        		need2Find[t[i]]++;
        }
        //second loop, use 2 pointer to find the min window
        while(fast<lenS){
        	if(hasFind.find(s[fast])==hasFind.end()){
        		if(need2Find.find(s[fast])!=need2Find.end()){
        			hasFind[s[fast]]=1;
        			count++;
        		}
        		else{
        			fast++;
        			continue;
        		}
        	}
        	else{
        		hasFind[s[fast]]++;
        		if(hasFind[s[fast]]<=need2Find[s[fast]]){
        			count++;
        		}
        	}
        	if(count==lenT){//find one window
        		while(1){
        			if(hasFind.find(s[slow])==hasFind.end()){
        				slow++;
        				continue;
        			}
                    else{
                        if (hasFind[s[slow]]==need2Find[s[slow]]) {
                            if(fast-slow < ansLen){
                                ansLen=fast-slow;
                                ans = s.substr(slow,fast-slow+1);
                            }
                            count--;
                            hasFind[s[slow]]--;
                            slow++;
                            break;
                        }
                        else{
                            hasFind[s[slow]]--;
                            slow++;
                        }
        			}
        		}
        	}
            fast++;
        }
        return ans;
    }
};

int main(int argc, char ** argv){
    Solution s;
    cout<<s.minWindow("abc", "b");
    return 0;
}
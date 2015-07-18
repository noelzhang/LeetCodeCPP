#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(!s.length()||!words.size())
        	return ans;
        int wordLen = (int)words[0].length();
        unordered_map<string, int> need;
        //build up the needed map
        for(auto w : words){
        	if(need.find(w)==need.end())
        		need[w] = 1;
        	else
        		need[w]++;
        }
        for(int i=0; i<wordLen; ++i){
        	unordered_map<string, int> found;
            for(auto n: need)
                found[n.first] = 0;
        	int slow = i, fast = i;
        	int count = 0;
        	while(fast<s.length()){
        		string curStr = s.substr(fast,wordLen);
        		if(found.find(curStr) == found.end()){
        			count = 0;
        			fast += wordLen;
        			slow = fast;
                    for(auto n: need)
                        found[n.first] = 0;
	        		continue;
        		}
        		else if(found[curStr] < need[curStr]){
        			++found[curStr];
        			++count;
        			if(count == words.size()){
        				ans.push_back(slow);
        			}
        			fast += wordLen;
        		}
        		else{
        			while(slow<fast){
	        			string slowStr = s.substr(slow, wordLen);
	        			if(slowStr == curStr){
	        				slow += wordLen;
                            if (count==words.size()) {
                                ans.push_back(slow);
                            }
	        				break;
	        			}
	        			else{
	        				slow += wordLen;
	        				count--;
	        				found[slowStr]--;
	        			}
        			}
        			fast += wordLen;
        		}
        	}
        }
        return ans;
    }
};


int main(int argc, char ** argv){
    Solution s;
    string aa = "barfoothefoobarman";
    vector<string> aaa = {"foo", "bar"};
    s.findSubstring(aa, aaa);
    return 0;
}
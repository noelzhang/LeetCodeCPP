#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    	vector<string> ans;
        if(words.size()==0)
            return ans;
    	for (int i = 0; i < words.size(); ++i)
    	{
    		int begin = i,end = 0;
    		int curLen = -1;
    		while(i < words.size()){
    			if(curLen + words[i].length()+1 <= maxWidth){
    				end = i;
    				curLen += words[i++].length()+1;
    			}
                else{
                    //i++;
                    break;
                }
    				
    		}
    		if(i == words.size()){//last line
    			string cur = words[begin++];
    			for (int j = begin; j <= end; ++j)
    			{
    				cur += " ";
    				cur += words[j];
    			}
    			for (int j = 0; j < maxWidth - curLen; ++j)
    			{
    				cur += " ";
    			}
    			ans.push_back(cur);
    			break;
    		}
    		else{//common lines
    			i--;
    			string cur = words[begin++];
    			int spaceNum = maxWidth - curLen;
                int m,n;
                if(end-begin+1==0){
                    m=0;
                    n=spaceNum;
                }else{
    			m = spaceNum % (end - begin + 1);
    			n = spaceNum / (end - begin + 1);
                }
    			string space1,space2;
    			for (int j = 0; j <= n; ++j)
    			{
    				space1 += " ";
    			}
    			space2 = space1 + " ";
    			int j = 0;
    			for (; j < m; ++j)
    			{
                    cur += space2;
    				cur += words[begin+j];

    			}
    			for (; j< end - begin +1; ++j){
                    cur += space1;
    				cur += words[begin+j];
    				
    			}
                if(end-begin+1==0){
                    cur+= space1.substr(0,space1.length()-1);
                }
    			ans.push_back(cur);
    		}
    	}
    	return ans;
    }
};
//{"This", "is", "an", "example", "of", "text", "justification."};//
int main(int argc, char ** argv){
    Solution s;
    vector<string> aa={"Listen","to","many,","speak","to","a","few."};
    //aa.push_back("");
    auto ans = s.fullJustify(aa, 6);
    for(auto a : ans){
        cout<<a<<endl;
    }
}
/**
 * Implement a basic calculator to evaluate a simple expression string.
 * The expression string may contain open ( and closing parentheses ),
 * the plus + or minus sign -, non-negative integers and empty spaces.
 * You may assume that the given expression is always valid.
 */

class Solution {
public:
    int calculate(string s) {
    	stack<int> sign;
    	sign.push(1);
        int ans = 0, signMark = 1;
        for(int i =0;i<s.length();++i){

        	switch(s[i]){
        		case ' ':
        			break;
        		case '(':
        			int tmp = sign.top()*signMark;
        			sign.push(tmp);
        			signMark = 1;
        			break;
        		case '-':
        			signMark = -1;
        			break;
        		case '+':
        			signMark = 1;
        			break;
        		case ')':
					sign.pop();
					break;
				default:
					int curNum = s[i++]-'0';
					while(i<s.length()&&(s[i]-'0')>=0&&(s[i]-'0')<=9){
						curNum=curNum*10+s[i]-'0';
						i++;
					}
					i--;
					ans+= curNum*signMark*sign.top();
        	}
        }
        return ans;
    }
};
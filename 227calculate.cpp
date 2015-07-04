/**
 * Implement a basic calculator to evaluate a simple expression string.
 * The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . 
 * The integer division should truncate toward zero.
 * You may assume that the given expression is always valid.
 */
class Solution {
private:
	stack<int> stck;
public:
    int calculate(string s) {
    	int ans=0,curNum=0;
    	char sign = '+';
        for(int i = 0; i< s.length(); i++){
        	
        	switch(s[i]){
        		case ' ':
        			break;
        		case '*':
        			sign = '*';
        			break;
        		case '/':
        			sign = '/';
        			break;
        		case '+':
        			sign = '+';
        			break;
        		case '-':
        			sign = '-';
        			break;
        		default:
        			curNum = s[i++]-'0';
        			while(i<s.length() && (s[i]-'0')>=0 && (s[i]-'0')<=9){
        				curNum = curNum * 10 + s[i++] - '0';
        			}
        			i--;
        			if(sign == '+'){
        				stck.push(curNum);
        			}
        			if(sign == '-'){
        				stck.push(-curNum);
        			}
        			if(sign == '*'){
        				curNum = curNum * stck.top();
        				stck.pop();
        				stck.push(curNum);
        			}
        			if(sign == '/'){
        				curNum = curNum / stck.top();
        				stck.pop();
        				stck.push(curNum);
        			}
        	}
        }
        while(!stck.empty()){
        		ans=+stck.top();
        		stck.pop();
        }
        return ans;
    }
};
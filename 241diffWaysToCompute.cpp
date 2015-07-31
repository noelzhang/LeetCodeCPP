class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> res;
		if(input.length()==0)
			return res;
		for (int i = 0; i < input.length(); ++i)
		{
			auto cur = input[i];
			if(cur == '-'||cur == '+'||cur == '*'){
				auto res1 = diffWaysToCompute(input.substr(0,i));
				auto res2 = diffWaysToCompute(input.substr(i+1,input.length()-i-1));
				for(auto r1 : res1){
					for(auto r2 : res2){
						switch(cur){
							case '-':
							res.push_back(r1 - r2);
							break;
							case '+':
							res.push_back(r1 + r2);
							break;
							default:
							res.push_back(r1 * r2);
						}

					}
				}
			}
		}
		if(res.empty())
			res.push_back(atoi(input.c_str()));
		return res;
	}
};
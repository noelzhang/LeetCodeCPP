#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		int ans;
		int digit = log(n)/log(10);
		int p = pow(10,digit);
		int top = n / p;
		int next = n % p;
		if(top>1)
			return top
	}
	int countDigitOne(int n) {
		int ones = 0, m = 1, r = 1;
		while (n > 0) {
			ones += (n + 8) / 10 * m + (n % 10 == 1) * r;
			r += n % 10 * m;
			m *= 10;
			n /= 10;
		}
		return ones;
	}
};

int main(int argc, char ** argv){
    Solution s;
    s.countDigitOne(1001);
}
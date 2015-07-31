class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int>> result;
		if (num.size() < 4) return result;
		sort(num.begin(), num.end());
		unordered_map<int, vector<pair<int, int> > > cache;
		for (size_t a = 0; a < num.size(); ++a) {
			for (size_t b = a + 1; b < num.size(); ++b) {
				cache[num[a] + num[b]].push_back(pair<int, int>(a, b));
			}
		}
		for (int c = 0; c < num.size(); ++c) {
			for (size_t d = c + 1; d < num.size(); ++d) {
				const int key = target - num[c] - num[d];
				if (cache.find(key) == cache.end())
					continue;
				const auto& vec = cache[key];
				for (size_t k = 0; k < vec.size(); ++k) {
					if(c <= vec[k].second)
						continue;
					result.push_back({ num[vec[k].first], num[vec[k].second], num[c], num[d] });
				}
			}
		}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};
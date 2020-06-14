#include "bits/stdc++.h"
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

class Solution {
public:

  vector<int> twoSum(vector<int>& nums, int target ) {
		unordered_map<int, int> dict;
		for(int i = 0; i < nums.size(); i++) dict.insert({nums[i], i});
		for(int i = 0; i < nums.size(); i++) {
			int complement = target - nums[i];
			if(dict.find(complement) != dict.end() && dict.at(complement) != i){
				return {i, dict[complement]};
			}
		}
        return {};
    }
};

int main () {
	vector<int> nums{2, 3, 4, 5};
	vector<int> ans = Solution().twoSum(nums, 6);

	cout << ans[0] << " " << ans[1];

	return 0;
}

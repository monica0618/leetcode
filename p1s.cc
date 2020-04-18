#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target ) {
		vector<int> ans(2);
        for(int i = 0; i < nums.size() - 1; i++){
			for(int j = i + 1; j < nums.size(); j++){
				if(nums[i] + nums[j] == target){
					ans[0] = i;
					ans[1] = j;
				}
			}
		}
		return ans;
    }
};

int main () {
	vector<int> nums{2, 3, 4, 5};
	vector<int> ans = Solution().twoSum(nums, 6);

	cout << ans[0] << " " << ans[1];

	return 0;
}

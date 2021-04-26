#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums){
	unsigned short prev1 = nums.back(), prev2 = 0;
	unsigned short money_robbed = prev1;

	for(int i = nums.size() - 2; i >= 0; --i){
		money_robbed = nums[i] + prev2 > prev1 ? nums[i] + prev2 : prev1;
		prev2 = prev1;
		prev1 = money_robbed;
	}
	return money_robbed;	
}

int main(){
	vector<int> nums = {1, 2, 3, 1};
	cout << rob(nums) << endl;
	vector<int> nums1 = {2, 7, 9, 3, 1};
	cout << rob(nums1) << endl;
}

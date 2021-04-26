#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums){
        int sum, res;
        sum = 0; res = nums[0];

        for(int i = 0; i < nums.size(); ++i){
                sum += nums[i];
                if(res < sum) res = sum;
                if(sum < 0) sum = 0;
        }
        return res;
}

int main(){
        //vector<int> nums({-2, 1, -3, 4, -1, 2, 1, -5, 4});
        vector<int> nums({5, 4, -1, 7, 8});
        cerr << maxSubArray(nums) << '\n';
}

#include <bits/stdc++.h>
using namespace std;
#define DEBUG 1
using ull = unsigned long long;
using ll = long long;

int rob(vector<int> &nums){
        // if array only has one house
        if(nums.size() == 1) return nums.back();

        int m1 = 0, m2 = 0;
        int prev1 = 0, prev2 = 0;
        // compute max money from houses 2..n
        for(int i = nums.size() - 1; i >= 1; --i){
                m1 = max(prev1, nums[i] + prev2);
                prev2 = prev1;
                prev1 = m1;
        }

        prev1 = prev2 = 0;
        // compute max money from houses 1..n-1
        for(int i = nums.size() - 2; i >= 0; --i){
                m2 = max(prev1, nums[i] + prev2);
                prev2 = prev1;
                prev1 = m2;
        }

        return max(m1, m2);
}

int main(){
        vector<int> v1 = {0};
        vector<int> v2 = {1, 2, 3, 1};
        cout << rob(v1) << endl;
        cout << rob(v2) << endl;

        return 0;
}

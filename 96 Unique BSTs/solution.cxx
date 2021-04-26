#include <bits/stdc++.h>
using namespace std;
#define DEBUG 1
using ull = unsigned long long;
using ll = long long;

int numTrees(int n){
        vector<int> dp(n+1);
        dp[0] = 1; dp[1] = 1;

        for(int i = 2; i <= n; ++i){
                dp[i] = 0;
                for(int j = 1; j <= i; ++j){
                        dp[i] += (dp[j-1] * dp[i-j]);
                }
        }

        return dp[n];
}

int main(){

        cout << numTrees(3);

        return 0;
}

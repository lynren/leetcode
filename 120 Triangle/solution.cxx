#include <bits/stdc++.h>
using namespace std;
#define DEBUG 1
using ull = unsigned long long;
using ll = long long;

int minimumTotal(vector<vector<int>> &triangle){
        int n = triangle.size();
        vector<int> dp(triangle.back());

        // for each layer from the bottom to top
        for(int layer = n - 2; layer >= 0; --layer){
                for(int i = 0; i <= layer; ++i){
                        dp[i] = min(dp[i], dp[i+1]) + triangle[layer][i];
                }
        }

        return dp[0];
}

int main(){

        return 0;
}

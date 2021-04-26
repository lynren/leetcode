#include <bits/stdc++.h>
using namespace std;
#define DEBUG 1
using ull = unsigned long long;
using ll = long long;

int minCostClimbingStairs(vector<int> &cost){
        int prevprev, prev;
        prevprev = cost[0];
        prev = cost[1];

        for(size_t i = 2; i < cost.size(); ++i){
                int opt_i = min(cost[i] + prev, cost[i] + prevprev);
                prevprev = prev, prev = opt_i;
        }
        return min(prevprev, prev);
}

int main(){
        vector<int> a = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        cout << minCostClimbingStairs(a);


        return 0;
}

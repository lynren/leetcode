#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n){
        vector<vector<int>> paths(m, vector<int>(n));
        
        // init dp
        paths[m-1][n-1] = 1;

        // compute bottom row
        for(int i = n-2; i >= 0; --i){
                paths[m-1][i] = 1;
        }

        // compute right most colum
        for(int i = m-2; i >= 0; --i){
                paths[i][n-1] = 1;
        }

        for(int i = m-2; i >= 0; --i){
                for(int j = n-2; j >= 0; --j){
                        paths[i][j] = paths[i+1][j] + paths[i][j+1];
                }
        }

        return paths[0][0];
}

int main(){
        cerr << uniquePaths(3, 7);

        return 0;
}

#include <bits/stdc++.h>
using namespace std;

int uniquePaths(vector<vector<int>> &obstacleGrid){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<unsigned long long>> paths(m, vector<unsigned long long>(n));
        
        // init dp
        paths[m-1][n-1] = obstacleGrid[m-1][n-1] == 0 ? 1 : 0;

        // compute bottom row
        for(int i = n-2; i >= 0; --i){
                if(obstacleGrid[m-1][i] == 1)
                        paths[m-1][i] = 0;
                else
                        paths[m-1][i] = paths[m-1][i+1];
        }

        // compute right most colum
        for(int i = m-2; i >= 0; --i){
                if(obstacleGrid[i][n-1] == 1)
                        paths[i][n-1] = 0;
                else
                        paths[i][n-1] = paths[i+1][n-1];
        }

        for(int i = m-2; i >= 0; --i){
                for(int j = n-2; j >= 0; --j){
                        paths[i][j] = 0;
                        if(obstacleGrid[i][j] == 0){
                                paths[i][j] += paths[i+1][j];
                                paths[i][j] += paths[i][j+1];
                        }
                }
        }

        return paths[0][0];
}

int main(){
        vector<vector<int>> v = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
        cerr << uniquePaths(v);


        return 0;
}

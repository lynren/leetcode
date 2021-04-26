#include <bits/stdc++.h>
using namespace std;
#define DEBUG 1
using ull = unsigned long long;
using ll = long long;

bool isInterleave(string s1, string s2, string s3){
        if(s1.size() + s2.size() != s3.size())
                return false;

        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1));
        for(size_t i = 0; i <= s1.size(); ++i){
                for(size_t j = 0; j <= s2.size(); ++j){
                        if(i == 0 && j == 0)
                                dp[i][j] = true;
                        else if(i == 0)
                                dp[i][j] = s2[j-1] == s3[j-1] && dp[i][j-1];
                        else if(j == 0)
                                dp[i][j] = s1[i-1] == s3[i-1] && dp[i-1][j];
                        else
                                dp[i][j] = (s1[i-1] == s3[i+j-1] && dp[i-1][j]) ||
                                        (s2[j-1] == s3[j+i-1] && dp[i][j-1]);
                }
        }

        return dp[s1.size()][s2.size()];

}

int main(){
        cout << isInterleave("aabcc", "dbbca", "aadbbcbcac");
        cout << isInterleave("aabcc", "dbbca", "aadbbcbccc");
        cout << isInterleave("", "", "");

        return 0;
}

#include <bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;
#define DEBUG 1
using ull = unsigned long long;
using ll = long long;

int longestCommongSubsequence(string text1, string text2){
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));

        for(int i = 0; i < text1.size(); ++i)
                dp[i][0] = 0;
        for(int i = 0; i < text2.size(); ++i)
                dp[0][i] = 0;

        for(int i = 1; i <= text1.size(); ++i){
                for(int j = 1; j <= text2.size(); ++j){
                        if(text1[i-1] == text2[j-1])
                                dp[i][j] = 1 + dp[i-1][j-1];
                        else
                                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

                }
        }

        return dp[text1.size()][text2.size()];
}

int main(){
        cout << longestCommongSubsequence("abcde", "ace") << endl;
        cout << longestCommongSubsequence("abc", "abc") << endl;
        cout << longestCommongSubsequence("abc", "def") << endl;
        return 0;
}
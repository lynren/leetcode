#include <bits/stdc++.h>
using namespace std;
#define DEBUG 1
using ull = unsigned long long;
using ll = long long;

/* Bottom up dp solution
 * S = [s1, s2, ..., sn], T = [t1, t2, ..., tm].
 * Match s1 to tj. Then s2 must be matched in T[t_j+1, ..., tm].
 *
 * After each iteration of the while loop, S[s_idx] is not matched.
 * Since s_idx starts at 0 and is incremented once S[s_idx] is matched,
 * then S is a subsequence of T when s_idx = n+1.
 */

bool isSubsequence(string s, string t){
        if(s.size() > t.size()) return false;

        size_t t_idx = 0, s_idx = 0;
        while(s_idx < s.size() && t_idx < t.size()){
                // match characters
                if(s[s_idx] == t[t_idx]){
                        ++s_idx; ++t_idx;
                }
                else{
                        ++t_idx;
                }
        }

        return s_idx == s.size();
}

int main(){

        //string s = "abc", t = "ahbgdc";
        string s = "axc", t = "ahbgdc";
        cout << isSubsequence(s, t);

        return 0;
}

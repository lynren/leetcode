#include <bits/stdc++.h>
using namespace std;
#define DEBUG 1
using ull = unsigned long long;
using ll = long long;

/* Start at s[0] and expand.
 * Any valid string s does not contain leading 0s.
 * Hence s[0] must be in [1,9].
 * We can only expand s[0] into two nodes if s[0] + s[1] <= 26,
 * otherwise we expand s[0] into one node.
 * This creates a tree rooted at s[0].
 * We then expand the tree bfs style to reach level s.size().
 *
 * Denote the "suffix" of a node to be the numbers after the last space.
 * Every nodes suffix contains two or less digits.
 * Let bt = # nodes with suffix containing 1 digit in level i-1.
 * Let at = # nodes with suffix containing 2 digits in level i-1.
 * Let bt_next = # nodes with suffix containing 1 digit in level i.
 * Let at_next = # nodes with suffix containing 2 digits in level i.
 * Since there is no decoding starting with 0, every bt node has a suffix in [1-9].
 *
 * In level i, we process s[i].
 * If s[i-1]*10 + s[i] <= 26, then all bt nodes can expand to at type nodes.
 * Hence we set at_next = bt.
 * If s[i] != 0, then we can expand all bt nodes to bt type nodes.
 * Hence we set bt_next = bt if s[i] != 0. bt_next = 0 otherwise.
 * All at nodes can only expand to bt type nodes, but only if s[i] != 0.
 * Hence we set bt_next = bt + at if s[i] != 0. bt_next = 0 otherwise.
 *
 * At the last level of the tree, we have the count of at nodes and bt nodes.
 * at+bt are the total amount of nodes decoding all symbols.
 */
int numDecodings(string s){
        int at = 0, bt = 1;
        if(s[0] == '0') return 0;

        for(size_t i = 1; i < s.size(); ++i){
                int temp = at;
                if( ((int)s[i-1] - 48)*10 + ((int)s[i]-48) <= 26)
                        at = bt;
                else
                        at = 0;
                if(s[i] == '0')
                        bt = 0;
                else
                        bt += temp;
        }

        return at + bt;
}

int main(){
        cout << numDecodings("12") << endl;
        cout << numDecodings("226") << endl;
        cout << numDecodings("0") << endl;
        cout << numDecodings("11106") << endl;

        return 0;
}

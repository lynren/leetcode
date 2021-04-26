#include <vector>
#include <iostream>

using namespace std;

int main(){
        int n;
        cin >> n;
        int ways[n+1];

        // initialization
        ways[0] = 1;
        ways[1] = 1;
        int steps[] = {1, 2};

        for(int i = 2; i <= n; ++i){
                ways[i] = 0;
                for(int j = 0; j < 2; ++j){
                        if(i - steps[j] >= 0){
                                ways[i] += ways[i-steps[j]];
                        }
                }
        }
        cout << "ways to get to " << n << "th step: " << ways[n];

        return 0;
}

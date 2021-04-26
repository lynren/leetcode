#include <vector>
#include <iostream>

using namespace std;

int main(){
        int n;
        cin >> n;

        // initialization
        int n1 = 1, n2 = 1;
        int ways;
        for(int i = 2; i <= n; ++i){
                ways = n1 + n2;
                n1 = n2;
                n2 = ways;
        }

        cout << ways;

        return 0;
}

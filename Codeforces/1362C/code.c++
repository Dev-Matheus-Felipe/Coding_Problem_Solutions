#include <bits/stdc++.h>
using namespace std;

#define lli long long int

int main(){
    int Q;
    cin >> Q;

    while(Q--){
        lli n;
        cin >> n;

        lli pos, res = 0;
        for(pos = 0; (1LL << pos) <= n; pos++){

            lli half = (1LL << pos);
            lli blocks =  (n + 1) / (half * 2);
            
            res += 2 * blocks - 1;
            
            lli rem = (n + 1) % (half * 2);

            if(rem){
                res += ((half < rem) ? 2 : 1);
            }
        }

        cout << res << endl;
    }

    return 0;
}
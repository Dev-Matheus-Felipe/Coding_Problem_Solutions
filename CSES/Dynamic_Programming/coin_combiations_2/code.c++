#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    cin >> N >> X;

    vector<int> coins(N), dp(X + 1, 0);
    for(int& c: coins) cin >> c;

    dp[0] = 1;
    
    for(int c: coins){
        for(int sum = c; sum <= X; sum++){
            dp[sum] = (dp[sum] + dp[sum - c]) % MOD;
        }
    }

    cout << dp[X] << '\n';
    return 0;
}
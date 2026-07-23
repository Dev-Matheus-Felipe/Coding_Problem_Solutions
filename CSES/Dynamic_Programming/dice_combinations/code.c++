#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int getWays(int N, int calc, vector<int>& dp){
    if(N == 0) return 1;

    if(dp[N] != -1) return dp[N];


    for(int i = 1; i <= 6; i++){
        if(N-i < 0) continue;
        
        if(dp[N-i] == -1) 
            dp[N-i] = getWays(N-i, calc, dp) % MOD;

        calc = (calc + dp[N-i]) % MOD;
    }

    return calc;
}

int main(){
    int N; cin >> N;

    vector<int> dp(N+1, -1);
    dp[0] = 1;  

    int result = getWays(N, 0, dp);
    cout << result << endl;
    return 0;
}
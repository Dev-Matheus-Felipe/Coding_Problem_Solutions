#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main(){
    int N, target;
    cin >> N >> target;

    vector<int> coins(N);
    for(int& c: coins) cin >> c;

    vector<long long> dp(target + 1, INF);
    dp[0] = 0;

    for(int c: coins){
        for(int j = c; j <= target; j++){
            if(j - c >= 0 && dp[j-c] != INF){
                dp[j] = min(dp[j], dp[j-c] + 1);
            }
        }
    }

    cout << (dp[target] == INF ? -1 : dp[target]) << endl;

    return 0;
}
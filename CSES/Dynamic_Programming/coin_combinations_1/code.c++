#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int N, X;
    cin >> N >> X;

    vector<int> nums(N);
    for(int& n: nums) cin >> n;

    vector<int> dp(X+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= X; i++){
        for(int n: nums){
            if(i >= n){
                dp[i] = (dp[i] + dp[i-n]) % MOD;
            }
        }
    }

    cout << dp[X] << '\n'; 
    return 0;
}
#include <bits/stdc++.h>
using namespace std; 

int main(){
    int N, X;
    cin >> N >> X;

    vector<int> prices(N), pages(N);

    for(int& p: prices) cin >> p;
    for(int& p: pages) cin >> p;

    vector<int> dp(X+1, 0);

    for(int j = 0; j < N; j++){
        for(int i = X; i >= 0; i--){
            if(i - prices[j] >= 0){
                dp[i] = max(dp[i], dp[i-prices[j]] + pages[j]);
            }
        }
    }

    cout << dp[X] << '\n';
}
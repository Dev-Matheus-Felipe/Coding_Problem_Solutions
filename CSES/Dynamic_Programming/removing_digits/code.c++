#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    if(N < 10){
        cout << 1 << '\n';
        return 0;
    }

    vector<int> dp(N+1, 0);
    for(int i = 1; i < 10; i++){
        dp[i] = 1;
    }

    for(int i = 10; i <= N; i++){
        int biggest = 0, index = i;

        while (index > 0) {
            biggest = max(biggest, index % 10);
            index /= 10;
        }

        dp[i] = dp[i-biggest] + 1;
    }

    cout << dp[N] << '\n';

    return 0;
}
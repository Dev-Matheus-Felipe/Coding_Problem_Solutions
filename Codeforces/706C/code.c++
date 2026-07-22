#include <bits/stdc++.h>
using namespace std;

#define si pair<string, long long>

const long long INF = -1e18;

int main(){
    long long Q = 0;
    int N;

    cin >> N;
    
    vector<vector<long long>> energy(N, vector<long long>(2, INF));
    vector<vector<si>> dp(N, vector<si>(2));

    for(int i = 0; i < N; i++){
        int x; cin >> x;
        Q += x;

        dp[i][0].second = x;
        dp[i][1].second = 0;
    }

    for(int i = 0; i < N; i++){
        string s; cin >> s;
        dp[i][0].first = s;

        reverse(s.begin(), s.end());
        dp[i][1].first = s;
    }

    energy[0][0] = dp[0][0].second;
    energy[0][1] = dp[0][1].second;

    for(int i = 1; i < N; i++){
        for(int j = 0; j < 2; j++){
            if(energy[i-1][0] != INF && dp[i][j].first >= dp[i-1][0].first)
                energy[i][j] = max(energy[i][j], dp[i][j].second + energy[i-1][0]);

            if(energy[i-1][1] != INF && dp[i][j].first >= dp[i-1][1].first)
                energy[i][j] = max(energy[i][j], dp[i][j].second + energy[i-1][1]);

        }
    }

    long long sum = max(energy[N-1][0], energy[N-1][1]);
    cout << (sum == INF ? -1 : Q - sum) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
#define ii pair<long, int>
const long INF = 1e18;
 
int main() {
    int N, M;
    cin >> N >> M;
 
    vector<vector<ii>> G(N);
    int u, v, w;
 
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        --u; --v;
 
        G[u].push_back({v,w});
    }
 
    vector<long> dp(N, INF);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
 
    dp[0] = 0;
    pq.push({0, 0});
 
    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();
 
        long current = top.second, dist = top.first;
        if(dp[current] < dist) continue;
 
        for(ii v: G[current]){
            int neighbor = v.first, weight = v.second;
            if(dp[neighbor] > dist + weight){
                dp[neighbor] = dist + weight;
                pq.push({dp[neighbor], neighbor});
            }
        }
    }
 
    for(int i = 0; i < N - 1; i++){
        cout << dp[i] << ' ';
    }
 
    cout << dp[N -1] << endl;
 
    return 0;
}
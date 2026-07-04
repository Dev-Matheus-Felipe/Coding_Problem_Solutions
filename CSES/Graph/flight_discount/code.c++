#include <bits/stdc++.h>
using namespace std;
 
#define ii pair<int, int>
#define li pair<long long, int>
 
struct PQueue {
    long long dist;
    int v, used = 0;
 
    bool operator>(const PQueue& other) const {
        return dist > other.dist;
    }
};
 
const long long INF = 1e18;
 
int main() {
    int N, M;
    cin >> N >> M;
 
    vector<vector<ii>> G(N);
    int u, v, w;
 
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        --u; --v;
 
        G[u].push_back({v, w});
    }
 
    vector<vector<long long>> dp(N, vector<long long>(2, INF));
 
    priority_queue<
        PQueue,
        vector<PQueue>,
        greater<PQueue>
    > pq;
 
    dp[0][0] = 0;
    dp[0][1] = INF;
 
    pq.push({0,0});
 
    while(!pq.empty()){
        PQueue top = pq.top();
        pq.pop();
 
        int current = top.v, used = top.used;
        long long dist = top.dist;
 
        if(dist > dp[current][used]) continue;
 
        for(ii v: G[current]){
            int neighbor = v.first, weight = v.second;
            
            if(dp[neighbor][used] > dist + weight){
                dp[neighbor][used] = dist + weight;
                pq.push({dp[neighbor][used], neighbor, used});
            }
 
            if (used == 0 &&
                dp[neighbor][1] > dist + weight/ 2) {
                dp[neighbor][1] = dist + weight/ 2;
                pq.push({dp[neighbor][1], neighbor, 1});
            }
        }
    }
 
    cout << dp[N - 1][1] << endl;
    
    return 0;
}
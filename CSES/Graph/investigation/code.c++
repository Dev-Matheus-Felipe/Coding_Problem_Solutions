#include <bits/stdc++.h>
using namespace std;

#define ll pair<long long, long long>

const long long INF = 1e18;

struct Vertice {
    long long minA = INF , maxA = 0;
    vector<ll> adjs;

};

int main(){
    int N, M;
    cin >> N >> M;

    vector<Vertice> G(N);
    int u, v, w;

    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        --u; --v;

        G[u].adjs.push_back({v, w});
    }

    priority_queue<
        ll,
        vector<ll>,
        greater<ll>
    > pq;

    vector<ll> dp(N, {INF, 0});

    dp[0] = {0, 1};
    G[0].minA = G[0].maxA = 0;

    pq.push({0, 0});

    while(!pq.empty()){
        ll top = pq.top();
        pq.pop();

        long long dist = top.first, u = top.second;
        
        if(dp[u].first < dist) continue;
        
        for(ll v: G[u].adjs){
            long long neighbor = v.first, weight = v.second;

            if(dp[neighbor].first < dist + weight) continue;

            if(dp[neighbor].first == dist + weight){
                G[neighbor].maxA = max(G[u].maxA + 1, G[neighbor].maxA);
                G[neighbor].minA = min(G[u].minA + 1, G[neighbor].minA);
                
                dp[neighbor].second = (dp[neighbor].second + dp[u].second) % 1000000007;

            } else {
                dp[neighbor] = {dist + weight, dp[u].second};

                G[neighbor].maxA = G[u].maxA + 1;
                G[neighbor].minA = G[u].minA + 1;

                pq.push({dp[neighbor].first, neighbor});
            }
        }
    }

    cout << dp[N-1].first << " " << dp[N-1].second 
    << " "  << G[N-1].minA << " " << G[N-1].maxA << endl;
    return 0;
}
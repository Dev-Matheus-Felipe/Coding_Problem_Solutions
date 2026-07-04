#include <bits/stdc++.h>
using namespace std;

#define iii pair<int, pair<bool, int>>
#define ib pair<int, bool>
#define ii pair<int, int>
#define INF 1e9

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<ii>> G(v);
    
    int a, b, w;
    for(int i = 0; i < e; i++){
        cin >> a >> b >> w;
        a--; b--;

        G[a].push_back({b,w});
        G[b].push_back({a,w});
    }
    
    priority_queue<
        iii,
        vector<iii>,
        greater<iii>
    > pq;

    vector<vector<int>> dp(v, vector<int>(2, INF));
    pq.push({0, {0,0}});
    dp[0][0] = 0;

    while(!pq.empty()){
        iii top = pq.top();
        pq.pop();

        int current = top.second.second, dist = top.first;
        bool valid = top.second.first;

        if(dist > dp[current][valid])
            continue;

        for(ii v: G[current]){
            int neighbor = v.first, weight = v.second;
            int np = valid ^ 1;

            if(dp[neighbor][np] > dist + weight){
                dp[neighbor][np] = dist + weight;
                pq.push({dp[neighbor][np] , {np, neighbor}});

            }
        }
    }

    cout << (dp[v -1][0] == INF ? -1 : dp[v - 1][0]) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
const int INF = 1e9;


int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<ii>> G(N);
    int u, v, w;

    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        --u; --v;

        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }

    int start;
    cin >> start;
    --start;

    vector<int> dp(N, INF);
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    dp[start] = 0;
    pq.push({0, start});

    int biggest = 0, lowest = INF;

    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();

        int dist = top.first, current = top.second;
        
        if(dp[current] < dist) continue;
        biggest = max(biggest, dist);
        
        for(ii v: G[current]){
            int neighbor = v.first, weight = v.second;
            if(dist + weight < dp[neighbor]){

                dp[neighbor] = dist + weight;
                pq.push({dp[neighbor], neighbor});
            }
        }
    }

    for(ii n: G[start]) lowest = min(lowest, n.second);
    cout << biggest - lowest << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
const long long INF = 1e18;
 
int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
 
    vector<vector<long long>> dist(N, vector<long long>(N, INF));
    long long u, v, w;
 
    for(int i = 0; i < N; i++) dist[i][i] = 0;
 
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        --u; --v;
 
        dist[u][v] = dist[v][u] = min(dist[u][v], w);
    }
 
    for(int k = 0; k < N; k++)
        for(int u = 0; u < N; u++)
            for(int v = 0; v < N; v++)
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
 
 
    int a, b;
    for(int i = 0; i < Q; i++){
        cin  >> a >> b;
        --a; --b;
 
        cout << (dist[a][b] == INF ? -1 : dist[a][b]) << endl;
    }
 
    return 0;

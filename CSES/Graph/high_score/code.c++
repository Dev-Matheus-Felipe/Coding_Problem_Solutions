#include <bits/stdc++.h>
using namespace std;
 
const long long INF = -1e18;
#define ii pair<int,int>
 
struct Edge {
    int u, v, w;
};
 
void DFS_VISITA(vector<vector<ii>>& G, vector<bool>& vis, int u){
    vis[u] = true;
 
    for(ii v: G[u])
        if(!vis[v.first])
            DFS_VISITA(G, vis, v.first);
}
 
long long BFORD(vector<vector<ii>>& G, vector<Edge>& edges, int N){
    vector<long long> dist(N, INF);
    dist[0] = 0;
 
    for(int i = 0; i < N - 1; i++){
        for(Edge edge: edges){
            int u = edge.u, v = edge.v, w = edge.w;
 
            if(dist[u] != INF)
                dist[v] = max(dist[v], dist[u] + w);
        }
    }
 
    
    vector<bool> vis(N, false);
    queue<long long> q;
 
    for(Edge edge: edges){
        int u = edge.u, v = edge.v, w = edge.w;
            
        if(dist[u] != INF && dist[u] + w > dist[v]){
            dist[v] = dist[u] + w;
            q.push(u);
        }
    }
    
 
    while(!q.empty()){
        long long top = q.front();
        q.pop();
 
        DFS_VISITA(G, vis, top);
    }
 
 
    return vis[N - 1] ? -1 : dist[N - 1];
}
 
int main() {
    int N, M;
    cin >> N >> M;
 
    vector<vector<ii>> G(N);
    vector<Edge> edges(M);
    int u, v, w;
 
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        --u; --v;
 
        edges[i] = {u, v, w};
        G[u].push_back({v, w});
    }
 
    cout << BFORD(G, edges, N) << endl;
    return 0;
}
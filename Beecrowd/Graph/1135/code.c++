#include <bits/stdc++.h>
using namespace std;

#define ii pair<long long, long long>

struct Vertice {
    vector<ii> adjs;
    int pi = 0;
    int floor;
    char color = 'B';
};

void DFS_VISITA(vector<Vertice> &G, vector<long long> &dp, int u, long long dist, int floor){
    G[u].floor = floor;
    G[u].color = 'C';
    dp[u] = dist;

    for(ii v: G[u].adjs)
        if(G[v.first].color == 'B'){
            G[v.first].pi = u;
            DFS_VISITA(G, dp, v.first, dist + v.second, floor + 1);
        }
}

int LCA(int a, int b, vector<Vertice> &G){

    while(G[a].floor > G[b].floor) a = G[a].pi;
    while(G[b].floor > G[a].floor) b = G[b].pi;

    while(a != b){
        a = G[a].pi;
        b = G[b].pi;
    }

    return a;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int v;    
    while(cin >> v){
        if(v == 0) break;

        vector<Vertice> G(v);
        
        long long w, u;
        for(int i=1; i <= v - 1; i++){
            cin >> u >> w;

            G[i].adjs.push_back({u, w});
            G[u].adjs.push_back({i, w});
        }

        vector<long long> dp(v, 0);
        DFS_VISITA(G, dp, 0, 0, 0);

        int cases;
        cin >> cases;

        long long a, b;
        for(int i = 0; i < cases; i++){
            cin >> a >> b;

            int lca = LCA(a, b, G);
            long long result = dp[a] + dp[b] - 2LL * dp[lca];

            cout << result;
            if(i < cases - 1) cout << " ";
        }

        cout << '\n';
        
    }
    
    return 0;
}



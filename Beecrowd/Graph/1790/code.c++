#include <bits/stdc++.h>
using namespace std;

int result = 0, acc = 0;

struct Vertice {
    vector<int> adjs;
    char color = 'B';
    int pi = -1;
};

void DFS_VISITA(vector<Vertice>& G, vector<int>& low, vector<int>& dist, int u){
    G[u].color = 'C';

    dist[u] = low[u] = acc++;

    for(int v: G[u].adjs){
        if(G[v].color == 'B'){
            G[v].pi = u;

            DFS_VISITA(G, low, dist, v);

            low[u] = min(low[u], low[v]);
            if(low[v] > dist[u]) result++;

        } else if(G[u].pi != v){
            low[u] = min(low[u], dist[v]);
        }

    }
}

int main() {
    int N, M;

    while(cin >> N >> M){
        acc = result = 0;

        vector<int> low(N, -1), dist(N, -1);
        vector<Vertice> G(N);
        int u, v;

        for(int i = 0; i < M; i++){
            cin >> u >> v;
            --u; --v;

            G[u].adjs.push_back(v);
            G[v].adjs.push_back(u);
        }

        DFS_VISITA(G, low, dist, 0);

        cout << result << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

struct Vertice {
    vector<ii> adjs;
    char color = 'B';
};

struct Edge {
    int u, v, cost;
};

int acc = 0;

int Find(int x, vector<int>& parents){
    if(parents[x] == x) return x;
    return parents[x] = Find(parents[x] , parents);
}

void Kruskal(vector<Edge>& edges, vector<Vertice>& G, int Vsize){
    vector<int> parents(Vsize);
    int isValid = 0;

    for(int i = 0; i < Vsize; i++) parents[i] = i;
    for(Edge edge: edges){
        int u = edge.u, v = edge.v, cost = edge.cost;
        int a = Find(u, parents), b = Find(v, parents);

        if(a != b){
            if(a > b) swap(a, b);

            parents[b] = a;
            isValid++;

            G[u].adjs.push_back({v, cost});
            G[v].adjs.push_back({u, cost});

            if(isValid == Vsize) break;
        }
        
    }
}

int DFS_VISITA(vector<Vertice>& G, int u){
    G[u].color = 'C';

    for(ii v: G[u].adjs){
        if(G[v.first].color == 'B'){
            acc += v.second;
            DFS_VISITA(G, v.first);
            acc += v.second;
        }
    }

    return acc;
}

int main() {
    int N, M, START;    
    cin >> N >> M >> START;

    vector<Edge> edges(M);
    vector<Vertice> G(N);
    int u, v, w;

    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        --u; --v;

        edges[i] = {u, v, w};
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
        return a.cost < b.cost;
    });

    Kruskal(edges, G, N);

    cout << DFS_VISITA(G, START) << endl;
    return 0;
}
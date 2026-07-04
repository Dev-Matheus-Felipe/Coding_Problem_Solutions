#include <bits/stdc++.h>
using namespace std;

int tempo = 0;

struct Vertice {
    vector<int> adj;
    char cor = 'B';
};

void DFS_Visita(vector<Vertice> &G, int u){
    tempo++;
    G[u].cor = 'C';

    for(int v : G[u].adj)
        if(G[v].cor == 'B')
            DFS_Visita(G, v);
        
    G[u].cor = 'P';
    tempo++;
}

void DFS(vector<Vertice> &G, int N){
    tempo = 0;
    for(int i=0; i<G.size(); i++){
        G[i].cor = 'B';
  
    }

    DFS_Visita(G, N);
}

int main() {
    int N;
    cin >> N;

    while(N--){
        int start, v, e;
        cin >> start >> v >> e;

        vector<Vertice> G(v);

        while(e--){
            int u, v;
            cin >> u >> v;

            G[u].adj.push_back(v);
            G[v].adj.push_back(u);
        }

        DFS(G, start);
        cout << tempo - 2 << endl;

    }

    return 0;
}
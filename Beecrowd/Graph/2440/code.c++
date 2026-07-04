#include <bits/stdc++.h>
using namespace std;

struct Vertice {
    vector<int> adjs;
    char color = 'B';
};

void DFS_VISITA(vector<Vertice> &G,  int u){
    G[u].color = 'P';

    for(int v: G[u].adjs)
        if(G[v].color == 'B')
            DFS_VISITA(G, v);
}

int DFS(vector<Vertice> &G){
    int count = 0;
    for(int v = 0; v < (int)G.size(); v++)
        if(G[v].color == 'B'){
            count++;
            DFS_VISITA(G, v);
        }

    return count;
}

int main(){
    int v, e, a, b;
    cin >> v >> e;

    vector<Vertice> G(v);

    for(int i = 0; i < e; i++){
        cin >> a >> b;
        --a; --b;

        G[a].adjs.push_back(b);
        G[b].adjs.push_back(a);
    }

    cout << DFS(G) << endl;

    return 0;
}
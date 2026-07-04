#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Vertice {
    vector<int> adjs;
    char color = 'B';
};

bool result = false;

void DFS_VISITA(vector<Vertice> &G, int u){
    if(result) return;
    G[u].color = 'C';

    for(int v: G[u].adjs){
        if(G[v].color == 'C'){
            result = true;
            break;

        }else if(G[v].color == 'B')
            DFS_VISITA(G, v);
    }

    G[u].color = 'P';

}

void DFS(vector<Vertice> &G, int size){
    for(int i = 0; i < size; i++)
        if(G[i].color == 'B')
            DFS_VISITA(G, i);
    
}

int main() {
    int c;
    cin >> c;

    int v, e;
    while(c--){
        result = false;
        
        cin >> v >> e;
        vector<Vertice> G(v);

        int a, b;
        for(int i = 0; i < e; i++){
            cin >> a >> b;

            a--; b--;
            G[a].adjs.push_back(b);
        }

        DFS(G, G.size());
        cout << (result ? "SIM" : "NAO") << endl;
    }

    
    return 0;
}
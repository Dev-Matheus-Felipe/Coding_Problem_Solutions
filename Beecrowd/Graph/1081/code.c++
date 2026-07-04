#include <bits/stdc++.h>
using namespace std;

struct Vertice {
    vector<int> adjs;
    char color;
};

void DFS_VISITA(vector<Vertice> &G, int u, int d){
    G[u].color = 'C';

    for(int v: G[u].adjs){
        if(G[v].color == 'B'){
            for(int i = 0; i < d; i++)
                cout << ' ';
            
            cout << u << '-' << v << " pathR(G," << v << ")\n";
            DFS_VISITA(G, v, d + 2);
        }else {
            for(int i = 0; i < d; i++)
                cout << ' ';
            
            cout << u << '-' << v << endl;
        }
    }
    
}

void DFS(vector<Vertice> &G){
    for(Vertice &v: G)
        v.color = 'B';

    for(int u = 0; u < (int)G.size(); u++){
        if(G[u].color == 'B'){
            DFS_VISITA(G, u, 2);
            
            if(G[u].adjs.size() > 0)
                cout << endl;
        }
    }
}

int main() {
    int n, v, e;

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v >> e;
        
        vector<Vertice> G(v);
        for(int i = 0; i < e; i++){
            int a, b;
            cin >> a >> b;

            G[a].adjs.push_back(b);
        }

        for(int j = 0; j < v; j++)
            sort(G[j].adjs.begin(),G[j].adjs.end());
        

        printf("Caso %d:\n", i);
        DFS(G);
    }
    return 0;
}
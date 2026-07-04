#include <bits/stdc++.h>
using namespace std;

struct Vertice {
    vector<int> adjs;
    char color = 'B';
};

void DFS_VISITA(vector<Vertice>&G, int u){
    G[u].color = 'C';
    
    for(int v: G[u].adjs){
        if(G[v].color == 'B'){
            DFS_VISITA(G, v);
        }
    }
}

string DFS(vector<Vertice>& G){
    string result = "normal";
    int acc = 0;

    for(int i = 0; i < (int)G.size(); i++){
        if(G[i].color == 'B'){
            if(++acc >= 2){
                result = "falha";
                break;
            }
        
            DFS_VISITA(G, i);            
        }
    }

    return result;
}

int main() {
    int N, M, index = 0;
    while(cin >> N >> M && (N != 0 || M != 0)){
        index++;
        vector<Vertice> G(N);
        int u, v;
    
        for(int j = 0; j < M; j++){
            cin >> u >> v;
            --u; --v;
            
            G[u].adjs.push_back(v);
            G[v].adjs.push_back(u);
        }

        cout << "Teste " << index << endl  << DFS(G) << "\n\n";
    }

    return 0;
}
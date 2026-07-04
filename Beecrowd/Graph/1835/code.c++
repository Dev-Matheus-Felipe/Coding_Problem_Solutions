#include <bits/stdc++.h>
using namespace std;

struct Vertice {
    vector<int> adjs;
    char color = 'B';
};

void DFS_VISITA(vector<Vertice>& G, int u){
    G[u].color = 'C';

    for(int v:  G[u].adjs)
        if(G[v].color == 'B')
            DFS_VISITA(G, v);
    
}

int DFS(vector<Vertice>& G, int size){
    int count = -1;
    
    for(int u = 0; u < size; u++)
        if(G[u].color == 'B'){
            count++;
            DFS_VISITA(G, u);
        }

    return count;
}

int main(){
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++){
        int v, e;
        cin >> v >> e;

        vector<Vertice> G(v);
        int a, b;

        for(int j = 0; j < e; j++){
            cin >> a >> b;
            a--; b--;

            G[a].adjs.push_back(b);
            G[b].adjs.push_back(a);
        }

        int result = DFS(G, v);

        if(result == 0) 
            printf("Caso #%d: a promessa foi cumprida\n", i);

        else 
            printf("Caso #%d: ainda falta(m) %d estrada(s)\n", i, result);
        
    }

    return 0;
}
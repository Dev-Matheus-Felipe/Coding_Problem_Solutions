#include <bits/stdc++.h>
using namespace std;
 
#define ii pair<int, int>
 
struct Vertice {
    vector<int> adjs;
    char color = 'B';
};
 
vector<ii> edges;
 
void DFS_VISITA(vector<Vertice>& G, int u){
    G[u].color = 'C';
    
    for(int v: G[u].adjs)
        if(G[v].color == 'B')
            DFS_VISITA(G, v);
}
 
int DFS(vector<Vertice>& G, ii size){
    int result = -1;
    int vert = 0;
 
    for(int i = 0;  i < size.first; i++){
        if(G[i].color == 'B'){
            result++;
            
            if(vert != i){
                edges.push_back({vert, i});
                vert = i;
            }
 
            DFS_VISITA(G, i);
        }
    }
 
    return result;
}

int main() {
    int N, M;
    cin >> N >> M;
 
    vector<Vertice> G(N);
    int u, v;
 
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        --u; --v;
 
        G[u].adjs.push_back(v);
        G[v].adjs.push_back(u);
    }
 
    cout << DFS(G, {N, M}) << endl;
 
    for(ii edge: edges)
        cout << edge.first + 1 << " " << edge.second  + 1 << endl;
    
 
    return 0;
}
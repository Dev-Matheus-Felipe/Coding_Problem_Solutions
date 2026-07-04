#include <bits/stdc++.h>
using namespace std;
 
bool isFound = false;
int start = -1, lastV = -1;
 
struct Vertice {
    vector<int> adjs;
    char color = 'B';
    int pi = -1;
};
 
void DFS_VISITA(vector<Vertice>& G, int u){
    G[u].color = 'C';
    
    for(int v: G[u].adjs){
        if(G[v].color == 'B'){
            G[v].pi = u;
            DFS_VISITA(G, v);
            
            if(isFound) return;
        }
        
        else if(G[v].color == 'C'){
            start = v;
            lastV = u;
            
            isFound = true;
            return;
        }
    }
    
    G[u].color = 'P';
}
 
void DFS(vector<Vertice>& G, int N){
    for(int i = 0; i < N; i++){
        if(G[i].color == 'B' && !isFound){
            DFS_VISITA(G, i);
        }
    }
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
    }
    
    vector<int> cicle;
    int size = 0;
 
    DFS(G, N);
 
    if(start == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
 
    cicle.push_back(start + 1);
    size++;
 
    while(true){
        cicle.push_back(lastV + 1);
        lastV = G[lastV].pi;
    
        size++;
        if(lastV == start) break;
    }
 
    cicle.push_back(start + 1);
    size++;
 
    cout << size << endl;
 
    for(int i = size - 1; i >= 0; i--){
        cout << cicle[i];
 
        if(i > 0) cout << ' ';
    }
 
    cout << endl;
    return 0;
}
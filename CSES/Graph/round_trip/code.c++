#include <bits/stdc++.h>
using namespace std;
 
#define ii pair<int, int>
 
struct Vertice {
    vector<int> adjs;
    char color = 'B';
    int pi = -1;
};
 
ii cords = {-1, -1};
bool found = false;
 
void DFS_VISITA(vector<Vertice>& G, int u){
    if(found) return;
    G[u].color = 'C';
 
    for(int v: G[u].adjs){
        if(G[v].color == 'C' && G[u].pi != v){
            cords = {v, u};
            found = true;
        }
 
        if(G[v].color == 'B'){
            G[v].pi = u;
            DFS_VISITA(G, v);
        }
    }
 
    G[u].color = 'P';
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
 
    
    for(int i = 0; i < N; i++){
        DFS_VISITA(G, i);
 
        if(found) break;
    }
 
    if(!found){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
 
    v = cords.first, u = cords.second;  
 
    string res = to_string(v + 1) + ' ';
    int count = 2;
 
 
    
    while(u != v){
        res += to_string(u + 1) + ' ';
        count++;
 
        u = G[u].pi;
    }
 
    res += to_string(v + 1);
 
    cout << count << endl << res << endl;
    return 0;
}
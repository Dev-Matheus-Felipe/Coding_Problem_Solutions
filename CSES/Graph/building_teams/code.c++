#include <bits/stdc++.h>
using namespace std;
 
#define ii pair<int, int>
 
struct Vertice {
    vector<int> adjs;
    int color = 0;
};
 
int BFS(vector<Vertice>& G){
    queue<int> q;
 
    for(int i = 0; i < G.size(); i++){
        if(G[i].color == 0){
            q.push(i);
 
            G[i].color = 1;
            
            while(!q.empty()){
                int u = q.front();
                q.pop();
 
                int color = G[u].color;
 
                for(int v: G[u].adjs){
                    if(G[v].color == 0){
                        G[v].color = (color == 1 ? 2 : 1);
                        q.push(v);
                    }
 
                    if(color != 0 && G[v].color == color) return 1;
                }
            }
        }
    }
 
    return 0;
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
 
    if(BFS(G)){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    for(int i = 0; i < N; i++){
        cout << G[i].color;
        if(i < N - 1) cout << " ";
    }
 
    cout << endl;
    return 0;
}
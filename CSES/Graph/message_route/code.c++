#include <bits/stdc++.h>
using namespace std;
 
#define ii pair<int, int>
 
struct Vertice {
    vector<int> adjs;
    int pi = -1;
};
 
bool BFS(vector<Vertice>& G, int N){
    vector<bool> vis(N, false);
    queue<int> q;
    
    vis[0] = true;
    q.push(0);
 
    while(!q.empty()){
        int u = q.front();
        q.pop();
 
        for(int v: G[u].adjs){
            if(!vis[v]){
                vis[v] = true;
                G[v].pi = u;
                q.push(v);
 
                if(v == N - 1) 
                    return true;
            }
        }
    }
 
    return false;
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
 
    int result = BFS(G, N);
   
    if(!result){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
 
    int pi = G[N - 1].pi, count = 1;
    vector<int> path;
    path.push_back(N);
 
    while(pi != -1){
        path.push_back(pi + 1);
        count++;
 
        pi = G[pi].pi;
    }
 
    cout << count << endl;
    for(int i = path.size() - 1; i >=0; i--){
        cout << path[i];
 
        if(i > 0) cout << " ";
    }
 
    cout << endl;
    return 0;
}
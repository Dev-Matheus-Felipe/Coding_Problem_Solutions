#include <bits/stdc++.h>
using namespace std;

vector<int> low, tin;
vector<bool> onStack;
stack<int> s;

int globalTime = 0;
int kindoms = 0;

struct Vertice {
    vector<int> adjs;
    int kindom = -1;
};

void DFS_VISITA(vector<Vertice>&G, int u){
    low[u] = tin[u] = ++globalTime;
    onStack[u] = true;
    s.push(u);

    for(int v: G[u].adjs){
        if(tin[v] == -1){
            DFS_VISITA(G, v);
            low[u] = min(low[u], low[v]);
        }

        else if(onStack[v]){
            low[u] = min(low[u], tin[v]);
        }
    }

    if(low[u] == tin[u]){
        kindoms++;

        G[u].kindom = kindoms;
        while(true){
            int x = s.top();
            G[x].kindom = kindoms;
            onStack[x] = false;
            s.pop();

            if(x == u) break;
        }
    }
}

void DFS(vector<Vertice>& G, int N){
    onStack.assign(N, false);
    low.assign(N, -1);
    tin.assign(N, -1);
    
    for(int i = 0; i < N; i++)
        if(tin[i] == -1)
            DFS_VISITA(G, i);
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<Vertice> G(N);
    int u, v;

    for(int i = 0; i < M; i++){
        cin >> u >> v;
        --u; --v;

        G[u].adjs.push_back(v);
    }

    DFS(G, N);
    cout << kindoms << endl;

    for(int i = 0; i < N; i++){
        cout << G[i].kindom;
        if(i < N - 1) cout << " ";
    }
    
    cout << '\n';
    return 0;
}
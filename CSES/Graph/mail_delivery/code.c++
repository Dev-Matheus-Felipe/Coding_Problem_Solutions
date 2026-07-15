#include <bits/stdc++.h>
using namespace std;

vector<int> path;
int id = 0;

struct Edge {
    int to;
    int id;
};

bool isPossible(vector<vector<Edge>>& G, int N){
    int size = 0;
    for(int u= 0; u < N; u++){
        for(auto _: G[u]) size++;

        if(size % 2 != 0) return false;
        size = 0;
    }

    return true;
}

void DFS(vector<vector<Edge>>& G, vector<bool>& used, int u){
    while(!G[u].empty()){
        Edge e = G[u].back();
        G[u].pop_back();

        if(used[e.id]) continue;
        used[e.id] = true;

        DFS(G, used, e.to);
    }

    path.push_back(u + 1);
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> G(N);
    vector<bool> used(M, false);
    int u, v;

    while(M--){
        cin >> u >> v;
        --u; --v;

        G[u].push_back({v, id});
        G[v].push_back({u, id});

        id++;
    }

    if(!isPossible(G, N)){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    DFS(G, used, 0);

    for(bool x : used) {
        if (!x) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for(int i = 0; i < (int)path.size(); i++){
        cout << path[i];
        if(i < (int)path.size() - 1) cout << " ";
    }

    cout << endl;
    return 0;
}
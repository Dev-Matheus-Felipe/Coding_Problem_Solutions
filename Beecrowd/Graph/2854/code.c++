#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Vertice {
    vector<string> adjs;
    char color = 'B';
};

void DFS_VISITA(unordered_map<string, Vertice> &G, string u){
    G[u].color = 'C';

    for(string v: G[u].adjs)
        if(G[v].color == 'B')
            DFS_VISITA(G, v);
}

int DFS(unordered_map<string, Vertice> &G){
    int count = 0;

    for(auto const&par: G){
        if(par.second.color == 'B'){
            count++;
            DFS_VISITA(G, par.first);
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<string, Vertice> G;
    string u, p, v;
    for(int i = 0; i < m; i++){
        cin >> u >> p >> v;

        G[u].adjs.push_back(v);
        G[v].adjs.push_back(u);
    }

    int result = DFS(G);
    cout << result << endl;
    return 0;
}
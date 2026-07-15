#include <bits/stdc++.h>
using namespace std;

vector<int> path;
int id = 0;

struct Edge {
    int to;
    int id;
};

bool isPossible(vector<vector<Edge>>& G, vector<int>& in, vector<int>& out, int N){
    int sCount = 0, eCount = 0, sIndex, eIndex;
    for(int i= 0; i < N; i++){
        if(abs(out[i] - in[i]) > 1) return false;

        else if(out[i] - in[i] == 1 ){
            sCount++;
            sIndex = i;
        
        }else if(in[i] - out[i] == 1 ){
            eCount++;
            eIndex = i;
        }
    }

    return (sIndex == 0 && eIndex == N - 1 && eCount == 1 && sCount == 1);
}

void DFS(vector<vector<Edge>>& G, vector<int>& out, int u){
    while(out[u] != 0){
        out[u]--;

        Edge e = G[u].back();
        G[u].pop_back();

        DFS(G, out, e.to);
    }

    path.push_back(u + 1);
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> in(N, 0), out(N, 0);
    vector<vector<Edge>> G(N);
    
    int u, v;

    while(M--){
        cin >> u >> v;
        --u; --v;

        out[u]++; in[v]++;
        G[u].push_back({v, id});

        id++;
    }

    if(!isPossible(G, in, out, N)){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    DFS(G, out, 0);

    for(vector<Edge> v: G){
        if (v.size() > 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    reverse(path.begin(), path.end());

    for(int i = 0; i < (int)path.size(); i++){
        cout << path[i];
        if(i < (int)path.size() - 1) cout << " ";
    }

    cout << endl;
    return 0;
}
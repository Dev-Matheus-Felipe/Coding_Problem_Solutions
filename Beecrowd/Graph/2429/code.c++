#include <bits/stdc++.h>
using namespace std;

int Ccount = 0, SCC = 0, totalTime = 0;

void DFS_VISITA(
    vector<vector<int>>& G, 
    vector<int>& disc, 
    vector<int>& low, 
    vector<bool>& inStack,
    stack<int>& s,
    int u
){
    disc[u] = low[u] = totalTime++;
    inStack[u] = true;   
    s.push(u);

    for(int v: G[u]){
        if(disc[v] == -1){
            DFS_VISITA(G, disc, low, inStack, s, v);
            low[u] = min(low[u], low[v]);

        
        }else if(inStack[v]){
            low[u] = min(low[u], disc[v]);
        }
    }

    if(low[u] == disc[u]){
        SCC++;

        while (true) {
            int x = s.top();
            s.pop();

            inStack[x] = false;

            if (x == u) break;
        }
    }
}

string DFS(vector<vector<int>>& G, int N){
    vector<int> disc(N, -1), low(N, -1);
    vector<bool> inStack(N, false);
    stack<int> s;

    for(int i = 0; i < N; i++){
        if(disc[i] == -1){
            if(++Ccount > 1) return "N";
            DFS_VISITA(G, disc, low, inStack, s, i);
        }
    }

    return(SCC == 1 ? "S" : "N");
}


int main() {
    int N, u, v;
    cin >> N;

    vector<vector<int>> G(N);
    for(int i = 0; i < N; i++){
        cin >> u >> v;
        --u; --v;

        G[u].push_back(v);
    }

    cout << DFS(G, N) << endl;
    return 0;
}
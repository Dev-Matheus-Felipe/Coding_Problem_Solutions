#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

struct Vertice {
    vector<int> adjs;
    char color = 'B';
};

bool hasLoop = false;

bool DFS_VISITA(vector<Vertice>& G, int u){
    G[u].color = 'C';

    for(int v: G[u].adjs){
        if(G[v].color == 'C'){
            hasLoop = true;
            return true;
        }

        if(G[v].color == 'B'){
            bool result = DFS_VISITA(G, v);
            if(result) return true;
        }
    }

    G[u].color = 'P';
    return false;
}

bool DFS(vector<Vertice>& G){
    for(int i = 0; i < G.size(); i++){
        if(G[i].color == 'B'){
            if(DFS_VISITA(G, i)) 
                return true;
        }
    }

    return false;
}



int dfs_dp(int u, vector<int>& dp, vector<Vertice>& G){
    if(dp[u] != -1)
        return dp[u];

    int best = 0;

    for(int v : G[u].adjs){
        best = max(best, dfs_dp(v, dp, G));
    }

    return dp[u] = best + 1;
}



int main() {
    int N, amount;
    while(cin >> N){
        hasLoop = false;

        vector<Vertice> G(N);

        for(int i = 0; i < N; i++){
            cin >> amount;
            int v;

            while(amount--){
                cin >> v;
                G[i].adjs.push_back(--v);
            }
        }

        bool result = DFS(G);

        if(result){
            cout << -1 << endl;
            continue;
        }

        vector<int> dp(N, -1);
        int largestPath =  0;

        for(int i = 0; i < N; i++){
            if(dp[i] == -1){
                largestPath = max(largestPath, dfs_dp(i, dp, G));
            }
        }

        cout << largestPath << endl;

    }

    return 0;
}
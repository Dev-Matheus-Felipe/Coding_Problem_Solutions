#include <bits/stdc++.h>
using namespace std;

#define li pair<long long, int>

vector<int> low, tin, root;
vector<bool> onStack;
stack<int> s;

int globalTime = 0;

struct Vertice {
    vector<int> adjs;
    int coins = 0;
};

void DFS_VISITA(vector<Vertice>& G, int u){
    tin[u] = low[u] = ++globalTime;
    onStack[u] = true;
    s.push(u);

    for(int v: G[u].adjs){
        if(tin[v] == -1){
            DFS_VISITA(G, v);
            low[u] = min(low[u], low[v]);
        
        } else if(onStack[v]) low[u] = min(low[u], tin[v]);
    }

    if(low[u] == tin[u]){
        while(true){
            int x = s.top();
            s.pop();

            onStack[x] = false;
            root[x] = u;

            if(x == u) break;
        }
    }
}

void DFS(vector<Vertice>& G, int N){
    onStack.assign(N, false);
    low.assign(N, -1);
    tin.assign(N, -1);
    
    root.assign(N, 0);
    for(int i = 0; i < N; i++)
        if(tin[i] == -1)
            DFS_VISITA(G, i);
}

long long KHAN(vector<vector<int>>& adjs, vector<long long>& coins_counter, int N){
    vector<int> inDegree(N, 0);
    vector<long long> dp(N, 0);
    queue<int> q;

    for(int i = 0; i < N; i++)
        for(int to: adjs[i])
            inDegree[to]++;

    for(int i = 0; i < N; i++){
        if(inDegree[i] == 0) q.push(i);
        dp[i] = coins_counter[i];
    }

    long long result = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        result = max(result, dp[u]);

        for(int to: adjs[u]){
            dp[to] = max(dp[to], dp[u] + coins_counter[to]);

            inDegree[to]--;
            if(inDegree[to] == 0) q.push(to);
        }
    }

    return result;
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<Vertice> G(N);
    int u, v;

    for(int i = 0; i < N; i++) cin >> G[i].coins;
    while(M--){
        cin >> u >> v;
        --u; --v;

        G[u].adjs.push_back(v);
    }

    DFS(G, N);

    vector<long long> coins_counter(N, 0);

    for(int i = 0; i < N; i++)
        coins_counter[root[i]] += G[i].coins;

    vector<vector<int>> adj_cond(N);
    for (int v = 0; v < N; v++) {
        for (int u : G[v].adjs)
            if (root[v] != root[u]){
                adj_cond[root[v]].push_back(root[u]);
            }
    }

    cout << KHAN(adj_cond, coins_counter, N) << endl;
    return 0;
}
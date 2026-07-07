#include <bits/stdc++.h>
using namespace std;

long long KHAN(vector<vector<int>>& G, vector<int>& weights, int N){
    vector<long long> ways(N, 0);
    queue<int> q;

    for(int i = 0; i < N; i++)
        if(weights[i] == 0)
            q.push(i);

    ways[0] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(int v: G[u]){
            if(ways[u])
                ways[v] = (ways[v] ? ((ways[v] + ways[u]) % 1000000007) : ways[u]);

            weights[v]--;
            if(weights[v] == 0) q.push(v);
        }
    }

    return ways[N -1];
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> weights(N, 0);
    vector<vector<int>> G(N);
    int u, v;

    for(int i = 0; i < M; i++){
        cin >> u >> v;
        --u; --v;
        
        G[u].push_back(v);
        weights[v]++;
    }

    cout << KHAN(G, weights, N) << endl;

    return 0;
}
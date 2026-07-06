#include <bits/stdc++.h>
using namespace std;

int KHAN(
    vector<vector<int>>& G,
    vector<int>& weights,
    vector<int>& path,
    int N
){
    vector<int> dist(N, -1);
    queue<int> q;
    
    dist[0] = 1;
    path[0] = 0;

    for(int i = 0; i < N; i++)
        if(weights[i] == 0)
            q.push(i);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v: G[u]){
            if(dist[u] != -1 && dist[v] < dist[u] + 1){
                dist[v] = dist[u] + 1;
                path[v] = u;
            }

            weights[v]--;
            if(weights[v] == 0) q.push(v);
        }
    }

    return dist[N -1];
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> weights(N, 0), path(N, -1);
    vector<vector<int>> G(N);
    int u, v;

    while(M--){
        cin >> u >> v;
        --u; --v;

        G[u].push_back(v);
        weights[v]++;
    }

    int result = KHAN(G, weights, path, N);    
    if(result == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    vector<int> reversedPath;
    int c = path[N - 1];
    
    reversedPath.push_back(N);

    while(true){
        reversedPath.push_back(c + 1);
        if(c == 0) break;
        c = path[c];
    }

    cout << result << endl;
    for(int i = reversedPath.size() - 1; i >=0; i--){
        cout << reversedPath[i];
        if(i > 0) cout << " ";
    }

    cout << endl;

    return 0;
}
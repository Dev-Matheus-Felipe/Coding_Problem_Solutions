#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
const int INF = 1e9;

struct Edge {
    int v, w, id;
};

void DFS_VISITA(vector<vector<ii>>& path, vector<bool>& edges, int u){
    for(ii v: path[u]){
        if(edges[v.second] == false){
            edges[v.second] = true;
            DFS_VISITA(path, edges, v.first);
        }
    }
    
}

int main() {
    int N, M, START, END;
     
    while(cin >> N >> M && (N != 0 || M != 0)){
        cin >> START >> END;
        
        vector<vector<ii>> path(N);
        vector<bool> edges(M, false);
        
        vector<vector<Edge>> G(N);
        int u, v, w;
        
        for(int i = 0; i < M; i++){
            cin >> u >> v >> w;

            G[u].push_back({v, w, i});
        }

        for(int i = 0; i < 2; i++){
            vector<int> dp(N, INF);
            priority_queue<
                ii, 
                vector<ii>, 
                greater<ii>
            > pq;
        
            dp[START] = 0;
            pq.push({0, START});
        
            while(!pq.empty()){
                ii top = pq.top();
                pq.pop();

                int current = top.second, dist = top.first;
        
                if(dist > dp[current]) continue;

                for(Edge v: G[current]){
                    int neighbor = v.v, weight = v.w, id = v.id;

                    if(i == 0){
                        if(dp[neighbor] > dist + weight){
                            path[neighbor].clear();
                            path[neighbor].push_back({current, id});
                            
                        } else if(dp[neighbor] == dist + weight)
                            path[neighbor].push_back({current, id});
                    }

                    if(dp[neighbor] >= dist + weight && !edges[id]){
                        dp[neighbor] = dist + weight;
                        pq.push({dp[neighbor], neighbor});

                    }
                }

            }

            if(i == 1)
                cout << (dp[END] == INF ? -1 : dp[END]) << endl;

            else DFS_VISITA(path, edges, END);
        }
    }

    return 0;
}
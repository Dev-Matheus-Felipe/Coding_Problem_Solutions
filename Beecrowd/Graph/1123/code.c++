#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define INF 1e9

int main() {
    int N, M, C, K;

    while(cin >> N >> M >> C >> K){
        if(N == 0 && M == 0 && C == 0 && K == 0)
            break;
        
        vector<vector<ii>> G(N);
        int u,v, w, lowest = 0;

        for(int i = 0; i < M; i++){
            cin >> u >> v >> w;

            G[u].push_back({v,w});
            G[v].push_back({u,w});
    
        }


        priority_queue<ii, vector<ii>, greater<ii>> pq;
        vector<int> dp(N, INF);
        
        pq.push({0, K});
        dp[K] = 0;

        while(!pq.empty()){
            ii top = pq.top();
            pq.pop();

            int distAtual = top.first;
            int atual = top.second;

            for(ii v: G[atual]){
                int vizinho = v.first;
                int peso = v.second;

                if(atual < C){
                    if(vizinho == atual + 1 && distAtual + peso < dp[vizinho]){
                        dp[vizinho] = distAtual + peso;
                        pq.push({dp[vizinho], vizinho});
                    }
            
                } else if(distAtual + peso < dp[vizinho]){
                    dp[vizinho] = distAtual + peso;
                    pq.push({dp[vizinho], vizinho});
                }
            }
            
            
        }

        cout << dp[C-1] << endl;
    }
    return 0;
}
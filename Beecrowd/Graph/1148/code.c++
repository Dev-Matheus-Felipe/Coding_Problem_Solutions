#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define INF 1e9

int main(){
    int v, e;

    while(true){
        cin >> v >> e;
        if(v == 0 && e == 0) break;

        vector<vector<ii>> arry(v);
        for(int i=0; i < e; i++){
            int u, v, w;
            cin >> u >> v >> w;

            u--;v--;
            arry[u].push_back({v,w});
        }

        int n;
        cin >> n;

        while(n--){
            int start, end;

            cin >> start >> end;
            start--; end--;

            priority_queue<ii, vector<ii>, greater<ii>> pq;
            vector<int> dp(v, INF);
            
            pq.push({0,start});
            dp[start] = 0;

            while(!pq.empty()){
                ii top = pq.top();
                pq.pop();

                int distAtual = top.first, atual = top.second;
                for(ii v: arry[atual]){
                    int vizinho = v.first;
                    int peso = v.second;

                    auto it = find_if(arry[vizinho].begin(), arry[vizinho].end(),
                        [atual](pair<int,int> p) {
                            return p.first == atual;
                    });

                    if(it != arry[vizinho].end() && distAtual < dp[vizinho]){
                        dp[vizinho] = distAtual;
                        pq.push({dp[vizinho], vizinho});

                    }else if(distAtual + peso < dp[vizinho]){
                        dp[vizinho] = distAtual + peso;
                        pq.push({dp[vizinho], vizinho});
                    }
                }
            }

            if(dp[end] == INF) cout << "Nao e possivel entregar a carta";
            else cout << dp[end];

            cout << endl;
        }

        cout << endl;
    }
    return 0;
}
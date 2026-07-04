#include <bits/stdc++.h>
using namespace std;
 
#define ii pair<long long, int>
 
 
int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<vector<ii>> G(N);
    int u, v, w;
 
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        --u; --v;
 
        G[u].push_back({v, w});
    }
 
 
    vector<int> count(N, 0);
    string result = "";
 
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, 0});
 
    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();
 
        long long dist = top.first;
        int u = top.second;
 
        count[u]++;
 
        if(count[u] > K) continue;
        if(u == N - 1) result += to_string(dist) + ' ';
 
        for(ii next: G[u]){
            int neighbor = next.first, weight = next.second;    
            pq.push({dist + weight, neighbor});
        }
    }
 
    if(result.length() > 0) result.pop_back();
 
    cout << result << endl;
 
    return 0;
}
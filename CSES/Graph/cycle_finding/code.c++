#include <bits/stdc++.h>
using namespace std;
 
struct Edge {
    int u, v, w;
};
 
const long long INF = 1e18;
 
vector<int> BFORD(vector<Edge>& edges, int N){
    vector<long long> dist(N + 1, 0), parents(N + 1, -1);
    
    for(int i = 0; i < N - 1; i++){
        
        for(Edge edge: edges){
            int u = edge.u, v = edge.v, w = edge.w;
            
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                parents[v] = u;
            }
        }
        
    }
    
    int x = -1;
 
    for(Edge edge: edges){
        int u = edge.u, v = edge.v, w = edge.w;
        
        if(dist[u] != INF && dist[u] + w < dist[v]){
            dist[v] = dist[u] + w;
            parents[v] = u;
            x = v;
        }
    }
 
    if(x == -1) return {};
 
    int firstV = x;
    for(int i = 0; i < N; i++)
        firstV = parents[firstV];
    
    
    vector<int> result;
    int current = firstV;
    
    do{
        result.push_back(current);
        current = parents[current];
    } while(current != firstV);
    
    result.push_back(firstV);
    reverse(result.begin(), result.end());
 
    return result;
}
 
int main() {
    int N, M;
    cin >> N >> M;
 
    vector<Edge> edges(M);
    int u, v, w;
 
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
 
        edges[i] = {u, v, w};
    }
 
    vector<int> result = BFORD(edges, N);
    if(result.size() == 0) {
        cout << "NO" << endl;
        return 0;
    }
 
    cout << "YES" << endl;
 
    for(int i = 0; i < (int)result.size(); i++){
        cout << result[i];
 
        if(i < (int)result.size() - 1 ) cout <<  " ";
    }
 
    cout << endl;
    return 0;
}
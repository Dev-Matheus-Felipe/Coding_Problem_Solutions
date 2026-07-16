#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

struct Edge {
    int from, to, w;

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int Find(vector<int>& parents, int x){
    if(parents[x] == x) return x;
    return parents[x] = Find(parents, parents[x]);
}

long long Kruskal(vector<Edge>& edges, int N){
    long long totalCost = 0;
    vector<int> parents(N);
    int size = 0;

    for(int i = 0; i < N; i++) parents[i] = i;
    
    for(Edge edge: edges){
        int u = edge.from, v = edge.to, w = edge.w;
        int a = Find(parents, u), b = Find(parents, v);

        if(a != b){
            if(b > a) swap(a, b);
            parents[a] = b;
            totalCost += w;

            if(++size == N - 1) break;
        }


    }

    if(size != N - 1){
        cout << "IMPOSSIBLE\n";
        return -1;
    
    } return totalCost;
}

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<Edge> edges(M);
    int from, to, weight;

    for(int i = 0; i < M; i++){
        cin >> from >> to >> weight;
        --from; --to;

        edges[i] = {from, to, weight};
    }

    sort(edges.begin(), edges.end());

    long long result = Kruskal(edges, N);
    if(result != -1) cout << result << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int Find(int x, vector<int>& parents){
    if(parents[x] == x) return x;
    return parents[x] = Find(parents[x], parents);
}

bool Kruskal(vector<Edge>& edges, int Vsize, int& result){
    vector<int> parents(Vsize);
    int amountV = 0;

    for(int i = 0; i < Vsize; i++) parents[i] = i;

    for(Edge edge: edges){
        int u = edge.u, v = edge.v, cost = edge.w;
        int a = Find(u, parents), b = Find(v, parents);

        if(a != b){
            if(a > b) swap(a, b);
            parents[b] = a;
            amountV++;
            result += cost;

            if(Vsize - 1 == amountV ) break;
        }
    }

    return amountV  == Vsize - 1;
}

int main() {
    int N, M;

    while(cin >> N >> M){
        vector<Edge> edges(M);
        int u, v, w;

        for(int i = 0; i < M; i++){
            cin >> u >> v >> w;
            --u; --v;

            edges[i] = {u, v, w};
        }

        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.w <b.w;
        });

        int result = 0;
        bool isPossible = Kruskal(edges, N, result);

        cout << (isPossible ? to_string(result) : "impossivel") << endl;
    }


    return 0;
}
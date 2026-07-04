#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;

    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

int Find_Parent(int x, vector<int> &parents){
    if(parents[x] == x) return x;

    return parents[x] = Find_Parent(parents[x], parents);
}

int Kruskal(vector<Edge> &edges, vector<int> &parents, int size){
    int count = 0, result = 0;
    for(int i = 0; i < (int)edges.size(); i++){
        int a = Find_Parent(edges[i].u, parents), b = Find_Parent(edges[i].v, parents);

        if(a != b){
            result += edges[i].w;

            if(a > b) swap(a, b);
            parents[b] = a;
            count++;
        }

        if(count == size - 1) break;
    }

    return result;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges;
    int u, v, w;

    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        u--; v--;
        
        edges.push_back({u,v,w});
    }

    vector<int> parents(N);
    for(int i = 0; i < N; i++)
        parents[i] = i;

    sort(edges.begin(), edges.end());

    int result = Kruskal(edges, parents, N);
    cout << result << endl;

    return 0;
}
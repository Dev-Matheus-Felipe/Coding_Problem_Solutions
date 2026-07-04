#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int x, v, w;
};

int Find(vector<int> &parent, int x){
    if(parent[x] == x) return x;
    parent[x] = Find(parent, parent[x]);

    return parent[x];
}

int Kruskal(vector<Edge> edge, int v){
    vector<int> parent(v);

    int count = 0, i = 0;
    for(int i = 0; i < v; i++)
        parent[i] = i;

    for(Edge e: edge) {
        int a = Find(parent, e.x), b = Find(parent, e.v);
        if(a == b ) continue;
        
        parent[a] = b;
        count += e.w;
    }

    return count;
}

int main() {
    int v, e;
    
    while(cin >> v >> e){
        if(v == 0 && e == 0) break;
        
        vector<Edge> edge(e);
        int totalCost = 0;

        for(int i = 0; i < e; i++){
            cin >> edge[i].x >> edge[i].v >>  edge[i].w;
            totalCost += edge[i].w;
        }

        sort(edge.begin(), edge.end(), [](const Edge &a, const Edge &b){
            return a.w < b.w;
        });

        int cost = Kruskal(edge, v);
        cout << totalCost - cost << endl;
    }

    return 0;
}
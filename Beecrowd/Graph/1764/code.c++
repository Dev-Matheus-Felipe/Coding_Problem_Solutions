#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int x, y, z;
};

int Find_Parent(vector<int> &parents, int x){
    if(parents[x] == x) return x;
    parents[x] = Find_Parent(parents, parents[x]);

    return parents[x];
}

int Kruskal(vector<Edge> edges, int v){
    vector<int> parents(v);
    int weight = 0;

    for(int i=0; i < v; i++)
        parents[i] = i;

    for(Edge e: edges){
        int a = Find_Parent(parents, e.x), b = Find_Parent(parents, e.y);
        if(a == b) 
            continue;

        if(a > b) swap(a, b);
        parents[b] = a;
        weight += e.z;
    }

    return weight;
}

int main(){
    int v, e;
    while(cin >> v >> e){
        if(v == 0 & e == 0) break;

        vector<Edge> edges;
        int x, y, z;

        for(int i=0; i < e; i++){
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
        }

        sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b){
            return a.z < b.z;
        });

        cout << Kruskal(edges, v) << endl;
    }

    return 0;
}
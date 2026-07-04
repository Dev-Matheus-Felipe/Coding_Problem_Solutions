#include <bits/stdc++.h>
using namespace std;

int Find(int x, vector<int> &parent){
    if(parent[x] == x) return x;
    parent[x] = Find(parent[x], parent);

    return parent[x];
}

int Kruskal(vector<vector<int>> &edges, vector<int> &parent, vector<int> &size, int n){
    int count = 0, edgeCount = 0;

    for(vector<int> &e: edges){
        int u = e[0], v = e[1], w = e[2];
        int a = Find(u, parent), b = Find(v, parent);
        
        if( a != b ){
            if(size[a] > size[b]) swap(a,b);
            
            size[b] += size[a];
            parent[a] = b;

            count += w;
            edgeCount++;
       }

       if(edgeCount == n - 1) break;
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    vector<int> parent(n), size(n);
    for(int i=0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        u--; v--;
        edges.push_back({u,v,w});
    }

    for(int i=0; i < n; i++){
        parent[i] = i;
        size[i] = 1;
    }

    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b){
        return a[2] < b[2];
    });

    int count = Kruskal(edges, parent, size, n);

    cout << count << endl;
    return 0;
}
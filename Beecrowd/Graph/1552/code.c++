#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

struct Edge {
    int u, v;
    double w;
};

int Find(int x, vector<int>& parents){
    if(parents[x] == x) return x;
    return parents[x] = Find(parents[x], parents);
}

double Kruskal(vector<Edge>& edges, int v){
    double count = 0;
    int aux = 0;
    vector<int> parents(v);

    for(int i = 0; i < v; i++) 
        parents[i] = i;

    for(Edge e: edges){
        int a = Find(e.u, parents), b = Find(e.v, parents);
        if(a != b){
            if(a > b) swap(a, b);

            parents[b] = a;
            count += e.w;
            aux++;

            if(aux == v) break;
        }
    }

    return count;
}

int main() {
    int n, v;
    cin >> n;
    
    cout << setprecision(2) << fixed;
    while(n--){
        cin >> v;
                
        vector<Edge> edges;
        vector<ii> pts;

        int a, b;
        for(int i = 0; i < v; i++){
            cin >> a >> b;
            pts.push_back({a, b});
        }

        
        for(int i = 0; i < pts.size() - 1; i++){
            for(int j = i + 1; j < pts.size(); j++){
                int dx = pts[j].first - pts[i].first;
                int dy = pts[j].second - pts[i].second;

                double dist = sqrt(dx * dx + dy * dy);
                edges.push_back({i, j, dist});
            }
            
        }
        
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
            return a.w < b.w;
        });

        double result = Kruskal(edges, v);
        cout << result / 100 << endl;

    }

    return 0;
}
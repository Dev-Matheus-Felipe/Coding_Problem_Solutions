#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

struct Edges {
    int u, v, w;  
};

int Find(int x, vector<int>& parents){
    if(parents[x] == x) return x;
    return parents[x] = Find(parents[x], parents);
} 

ii Kruskal(vector<Edges> & edges, int N){
    vector<int> parents(N);
    int biggest = 0, lowest = 0, v = 0;

    for(int i = 0; i < N; i++) parents[i] = i;
    for(Edges e: edges){
        int a = Find(e.u, parents), b = Find(e.v, parents);
        if(a != b){
            if(a < b) swap(a, b);

            parents[b] = a;
            lowest += e.w;
            if(++v == N) break;
        }
    }

    sort(edges.begin(), edges.end(), [](const Edges &a, const Edges &b){
        return a.w > b.w;
    });

    v = 0;
    for(int i = 0; i < N; i++) parents[i] = i;
    for(Edges e: edges){
        int a = Find(e.u, parents), b = Find(e.v, parents);
        if(a != b){
            if(a < b) swap(a, b);

            parents[b] = a;
            biggest += e.w;
            if(++v == N) break;
        }
    }


    return {biggest, lowest};
}

int main(){
    int N;
    cin >> N;

    vector<Edges> edges(N);
    int u, v, w;

    for(int i = 0; i < N; i++){
        cin >> u >> v >> w;
        --u; --v;

        edges[i] = {u, v, w};
    }

    sort(edges.begin(), edges.end(), [](const Edges &a, const Edges &b){
        return a.w < b.w;
    });

    ii result = Kruskal(edges, N);

    cout << result.first << '\n' << result.second << endl;
    return 0;
}
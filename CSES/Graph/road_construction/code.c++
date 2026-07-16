#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

struct Edge {
    int from, to;
};

int biggest = 0, Nsize = 0;

int Find(vector<ii>& parents, int x){
    if(parents[x].first == x) return x;
    return parents[x].first = Find(parents, parents[x].first);
}

ii Kruskal(vector<ii>&parents, ii edge){
    int a = Find(parents, edge.first), b = Find(parents, edge.second);
    if(a != b){
        if(parents[a].second < parents[b].second) swap(a, b);

        parents[b].first = a;
        parents[a].second += parents[b].second;

        biggest = max(biggest, parents[a].second);
        Nsize--;
        
    }

    return {Nsize, biggest};
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<ii> parents(N);
    Nsize = N;
    
    for(int i = 0;  i< N; i++) 
        parents[i] = {i, 1};
    
    int to, from;
    for(int i = 0; i < M; i++){
        cin >> to >> from;
        --to; --from;

        ii result = Kruskal(parents, {to, from});

        cout << result.first << " " << result.second << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    int u, v;

    while(M--){
        cin >> u >> v;
        --u; --v;

        G[u].push_back(v);
    }

    
    return 0;
}
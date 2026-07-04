#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    int N, M, P;
    cin >> N  >> M >> P;
    
    vector<vector<int>> G(N, vector<int>(N, INF));
    int a, b;

    for(int i = 0; i < N; i++) G[i][i] = 0;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        --a; --b;

        G[a][b] = 1;
        G[b][a] = 1;
    }

    for(int k = 0; k < N; k++)
        for(int u = 0; u < N; u++)
            for(int v = 0; v < N; v++)
                G[u][v] = min(G[u][v], G[u][k] + G[k][v]);

    for(int i = 0; i < P; i++){
        cin >> a >> b;
        --a; --b;

        cout << (G[a][b] == INF ? "Deu ruim" : "Lets que lets") << endl;
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    cout << fixed << setprecision(6);

    int N, M;
    while(cin >> N >> M){
        vector<vector<double>> dist(N, vector<double>(N, 0.0));
        int u, v;
        double w;

        for(int i = 0; i < N; i++) dist[i][i] = INF;
        for(int i = 0; i < M; i++){
            cin >> u >> v >> w;
            --u; --v;

            w /= 100;

            dist[v][u] = dist[u][v] = w;
        }

        for(int k = 0; k < N; k++)
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++){
                    if(dist[i][k] != INF && dist[k][j] != INF)
                        dist[i][j] = max (
                        dist[i][j], 
                        dist[i][k] * dist[k][j]
                    );
                }

        cout << dist[0][N-1] * 100 << " percent" <<  endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct Vertice {
    int value;
    char color = 'B';
};

void DFS_VISITA(vector<vector<Vertice>> &G, int x, int y, int sizeX, int sizeY, int &c){
    G[x][y].color = 'C';
    c++;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];

        if(nx >= 0 && nx < sizeX && ny >=0 && ny < sizeY 
        && G[nx][ny].value == G[x][y].value && G[nx][ny].color == 'B'){
            DFS_VISITA(G, nx, ny, sizeX, sizeY, c);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Vertice>> G(n, vector<Vertice>(m));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> G[i][j].value;

    int minV = INF;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(G[i][j].color == 'B'){
                int c = 0;

                DFS_VISITA(G,i, j, n, m, c);
                minV = min(minV, c);
            }


    cout << minV << endl;
    return 0;
}
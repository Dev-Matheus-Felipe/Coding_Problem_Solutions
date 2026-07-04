#include <bits/stdc++.h>
using namespace std;
 
#define ii pair<int, int>
 
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
 
void DFS_VISITA(vector<vector<char>>& G, int x, int y, ii size){
    G[x][y] = '#';
 
    for(int i = 0; i < 4; i++){
        int nx = dx[i] + x, ny = dy[i] + y;
 
        if(nx < 0 || ny < 0 || nx >= size.first  || ny >= size.second || 
        G[nx][ny] == '#')
            continue;
 
        DFS_VISITA(G, nx, ny, size);
    }
}
 
 
int main() {
    int N, M;
    cin >> N >> M;
 
    vector<vector<char>> G(N, vector<char>(M));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> G[i][j];
 
 
    int result = 0;
 
    for(int i = 0;  i < N; i++)
        for(int j = 0; j < M; j++){
            if(G[i][j] == '.'){
                result++;
                DFS_VISITA(G, i, j, {N, M});
            }
        }
 
    cout << result << endl;
 
    return 0;
}
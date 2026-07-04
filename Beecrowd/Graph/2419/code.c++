#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> G(M, vector<char>(N));
    int count = 0;

    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            cin >> G[i][j];
        
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(G[i][j] == '.') continue;

            if(i == N - 1 || i == 0 || j == 0 || j == M - 1){
                count++;
                continue;
            }

            for(int k = 0; k < 4; k++){
                int nx = i + dx[k], ny = j + dy[k];

                if(nx >=0 && nx < M && ny >= 0 && ny < N && G[nx][ny] == '.'){
                    count++;
                    break;
                }
            }

        }
    }
            
    cout << count << endl;
    return 0;
}
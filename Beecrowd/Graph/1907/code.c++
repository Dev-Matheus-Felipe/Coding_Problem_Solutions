#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

int max_x = 0, max_y = 0;

void BFS(vector<vector<char>> &M, int sx, int sy){
    queue<pair<int,int>> q;

    M[sx][sy] = '#';
    q.push({sx, sy});

    while(!q.empty()){
        pair<int,int> top = q.front();
        q.pop();

        int x = top.first, y = top.second;        

        for(int i=0; i < (int)dx.size(); i++){
            int nx = dx[i] + x, ny = dy[i] + y;

            if(nx >= 0 && nx < max_x && ny >= 0 && ny < max_y &&
            M[nx][ny] == '.'){
                M[nx][ny] = '#';
                q.push({nx, ny});
            }
            
        }
    }
}

int BFS_COUNT(vector<vector<char>> &M){
    int count = 0;

    for(int i=0; i < max_x; i++)
        for(int j=0; j < max_y; j++)
            if(M[i][j] == '.'){
                BFS(M, i, j);
                count++;
            }
        
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;

    max_x = v; max_y = e;
    vector<vector<char>> M(v, vector<char>(e));

    for(int i=0; i < v; i++)
        for(int j=0; j < e; j++)
            cin >> M[i][j];


    int result = BFS_COUNT(M);
    cout << result << endl;
    
    return 0;
}
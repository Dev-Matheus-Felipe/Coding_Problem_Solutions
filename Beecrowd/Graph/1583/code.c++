#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>

vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

void BFS(vector<vector<char>> &G, int sx, int sy, int n, int m){
    queue<ii> q;
    q.push({sx,sy});

    while(!q.empty()){
        ii top = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = top.first + dx[i], ny = top.second + dy[i];

            if(nx >=0 && nx < n && ny >= 0 && ny < m && G[nx][ny] == 'A'){
                G[nx][ny] = 'T';
                q.push({nx,ny});
            }
        }
    }
}

int main() {
    int n, m;
    while(cin >> n >> m && (n != 0 && m != 0)){
        vector<vector<char>> G(n, vector<char>(m));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> G[i][j];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(G[i][j] == 'T') 
                    BFS(G,i,j, n, m);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cout << G[i][j];

            cout << endl;
        }

        cout << endl;
    }

    return 0;
}
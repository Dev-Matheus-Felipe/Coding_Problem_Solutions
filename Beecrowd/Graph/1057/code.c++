#include <bits/stdc++.h>
using namespace std;

struct Position {
    vector<pair<int, int>> pos;
    int steps = 0;
};

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};


string BFS(vector<vector<char>> &G, vector<pair<int,int>> &players, int size){
    bool dp[10][10][10][10][10][10] = {};
    queue<Position> q;

    q.push({players, 0});

    while(!q.empty()){
        Position top = q.front();
        q.pop();

        int y1 = top.pos[0].second, y2 = top.pos[1].second, y3 = top.pos[2].second;
        int x1 = top.pos[0].first, x2 = top.pos[1].first, x3 = top.pos[2].first;

        if(dp[x1][y1][x2][y2][x3][y3]) continue;
        dp[x1][y1][x2][y2][x3][y3] = true;

        if(G[x1][y1] == 'X' && G[x2][y2] == 'X' && G[x3][y3] == 'X')
            return to_string(top.steps);

        for(int i=0; i < 4; i++){
            vector<pair<int, int>> newPos;

            for(int j=0; j < 3; j++){
                int nx = top.pos[j].first + dx[i];
                int ny = top.pos[j].second + dy[i];
                
                if(nx >=0 && nx < size && ny >=0 && ny < size && G[nx][ny] != '#')
                    newPos.push_back({nx,ny});
                
                else newPos.push_back({top.pos[j].first, top.pos[j].second});
            }

            bool changed = true;

            while(changed) {
                changed = false;

                for(int a = 0; a < 3; a++) {
                    for(int b = a + 1; b < 3; b++) {
                        if(newPos[a] == newPos[b]) {

                            if(newPos[a] != top.pos[a]) {
                                newPos[a] = top.pos[a];
                                changed = true;
                            }

                            if(newPos[b] != top.pos[b]) {
                                newPos[b] = top.pos[b];
                                changed = true;
                            }
                        }
                    }
                }
            }

            q.push({newPos, top.steps + 1});
        }
    }

    return "trapped";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;

    for(int i=1; i<= n; i++){
        cin >> m;

        vector<vector<char>> G(m, vector<char>(m));
        vector<pair<int, int>> players;

        for(int j=0; j < m; j++){
            for(int k=0; k < m; k++){
                cin >> G[j][k];

                if(G[j][k] != 'X' && isalpha(G[j][k])){
                    players.push_back({j,k});
                    G[j][k] = '.';
                }
            }
        }

        string result = BFS(G, players, m);
        cout << "Case " << i << ": " << result << endl;
    }

    return 0;
}
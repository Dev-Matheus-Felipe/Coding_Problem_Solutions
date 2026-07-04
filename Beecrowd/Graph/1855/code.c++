#include <bits/stdc++.h>
using namespace std;

struct Vertice {
    char value;
    char color = 'B';
};

pair<int, int> getCordenates(char point){
    pair<int, int> result;
    if(point == '>') result = {0 ,1};
    else if(point == '<') result = {0, -1};
    else if(point == 'v') result = {1, 0};
    else if(point == '^') result = {-1, 0};

    return result;
}

int main(){
    int m, n;
    cin >> n >> m;

    vector<vector<Vertice>> G(m, vector<Vertice>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> G[i][j].value;

    queue<pair<int, int>> q;
    pair<int, int> nc;


    q.push({0,0});
    G[0][0].color = 'P';

    while(!q.empty()){
        pair<int, int> top = q.front();
        q.pop();

        int x = top.first, y = top.second;
        
        if(G[x][y].value == '*'){
            cout << '*' << endl;
            return 0;
        }
        
        if(G[x][y].value != '.')
            nc = getCordenates(G[x][y].value);
        
        int nx = x + nc.first, ny = y + nc.second;
        if(nx >=0 && nx < m && ny >=0 && ny < n && G[nx][ny].color == 'B' ){
            G[nx][ny].color = 'P';
            q.push({nx, ny});
        }
    }

    cout << "!\n";
    return 0;
}
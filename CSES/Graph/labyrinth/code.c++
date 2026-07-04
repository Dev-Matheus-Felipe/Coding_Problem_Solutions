#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> ii;
 
struct pos {
    int x;
    int y;
    int c=0;
};
 
char p[4] = {'L','R','U','D'};
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
 
 
pos BFS(vector<vector<char>> &g, int n, int m, int a, int b, vector<vector<ii>>& paths ,vector<vector<char>>& lastLetters){
    queue<pos> q; 
    
    q.push({a,b,0});
    paths[a][b] = {-1, -1};
    g[a][b] = '#';
    
    while(!q.empty()){
        pos house = q.front(); 
        q.pop();
        
        int x = house.x, y = house.y;
        
        for(int k=0; k<4; k++){
            int sx = dx[k] + x;
            int sy = dy[k] + y;
            
            if(sx<0||sy<0||sx>=n||sy>=m || g[sx][sy] == '#')
            continue;
            
            paths[sx][sy] = {x, y};
            lastLetters[sx][sy] = p[k];
            
            if(g[sx][sy] == 'B'){
                return {sx, sy,house.c+1};
            }
            
            
            q.push({sx,sy,house.c+1});
            g[sx][sy] = '#';
            
        }
    }
    return {-1,-1,-1};  
}
 
 
int main() {
    int n,m;
    cin >> n >> m;
    
    vector<vector<ii>> paths(1100, vector<ii>(1100));
    vector<vector<char>> lastLetters(1100, vector<char>(1100));
    vector<vector<char>> g(n,vector<char>(m));
 
    int x, y;
    char a;
 
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> a;
            g[i][j] = a;
 
            if(g[i][j] == 'A'){
                x = i; y = j;
            }
        }
    
    pos house = BFS(g,n,m,x,y, paths, lastLetters);
 
    if(house.c == -1){
        cout << "NO" << endl;
        return 0;
    }
    
    cout << "YES" << endl << house.c << endl;
    
    x = house.x, y =  house.y;
    string result = "";
 
    while(paths[x][y].first != -1 && paths[x][y].second != -1){
        result += lastLetters[x][y];
        
        int aux = x;
        x = paths[x][y].first;
        y = paths[aux][y].second;
    }
 
    reverse(result.begin(), result.end());
    cout << result << endl;
 
    return 0;
}
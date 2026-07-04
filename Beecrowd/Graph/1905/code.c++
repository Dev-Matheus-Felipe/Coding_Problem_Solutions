#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

string BFS(vector<vector<int>> &M){
    queue<pair<int,int>> q;

    q.push({0,0});
    while(!q.empty()){
        pair<int,int> top = q.front();
        q.pop();

        int x = top.first, y = top.second;

        if(M[x][y]) continue;
        M[x][y] = 1;

        if(x == 4 && y == 4) 
            return "COPS";

        for(int i=0; i < dx.size(); i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if(nx >= 0 && nx < 5 && ny >=0 && ny < 5)
                q.push({nx,ny});
        }
        
    }

    return "ROBBERS";
}

int main(){
    int n;
    cin >> n;

    while(n--){
        vector<vector<int>> M(5, vector<int>(5));
        for(int i=0; i < 5; i++)
            for(int j=0; j < 5; j++)
                cin >> M[i][j];

        string result = BFS(M);
        cout << result << endl;
    }

    return 0;
}
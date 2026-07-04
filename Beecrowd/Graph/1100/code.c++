#include <bits/stdc++.h>
using namespace std;

#define ii  pair<int, int>

struct Moviment {
    ii pos;
    int count = 0;
};

vector<int> dx = {1,2,2,1,-1,-2,-2,-1}, dy = {2,1,-1,-2,-2,-1,1,2};

int BFS(ii start, ii end){
    vector<vector<bool>> dp(8, vector<bool>(8, false));
    queue<Moviment> q;

    q.push({start, 0});
    while(!q.empty()){
        Moviment top = q.front();
        q.pop();

        if(dp[top.pos.first][top.pos.second]) continue;
        dp[top.pos.first][top.pos.second] = true;

        if(top.pos.first == end.first && top.pos.second == end.second)
            return top.count;

        for(int i = 0; i < 8; i++){
            int nx = top.pos.first + dx[i], ny = top.pos.second + dy[i];
            if(nx >= 0 && ny >= 0 && nx < 8 && ny < 8)
                q.push({{nx,ny}, top.count + 1});
            
        }
    }
}


int main() {
    string n,m;
    
    while(cin >> n >> m){
        ii start = {n[0] - 97, n[1] - '1'};
        ii end = {m[0] - 97, m[1] - '1'};

        int result = BFS(start, end);
        cout << "To get from " << n << " to " << m << " takes " << result << " knight moves.\n"; 
    }

 
    return 0;
}
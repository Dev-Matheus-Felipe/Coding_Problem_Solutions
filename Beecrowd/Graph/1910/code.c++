#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

const int LIMIT = 1e5;

int BFS(vector<int>& blockeds, int S, int D){
    vector<bool>dp(LIMIT + 10, false);
    queue<ii> q;

    dp[S] = true;
    q.push({S, 0});

    while(!q.empty()){
        ii top = q.front();
        q.pop();

        int chanel = top.first, clicks = top.second;

        vector<int> ops = {
            chanel * 2,
            chanel * 3, 
            chanel + 1, 
            chanel - 1, 
            (chanel % 2 == 0 ? chanel / 2 : -1 )
        };

        for(int op: ops) {
            if(op <= 0 || op > LIMIT || dp[op] || blockeds[op] == 0)
                continue;

            if(op == D) return clicks + 1;

            dp[op] = true;
            q.push({op, clicks + 1});
        }
    }

    return -1;
}

int main(){
    int O, D, K;
    while(cin >> O >> D >> K){
        if(!O && !D && !K) break;

        vector<int> blockeds(LIMIT + 10, -1);
        int a;

        for(int i = 0; i < K; i++){
            cin >> a;
            blockeds[a] = 0;
        }

        cout << BFS(blockeds, O, D) << endl;
    }

    return 0;
}
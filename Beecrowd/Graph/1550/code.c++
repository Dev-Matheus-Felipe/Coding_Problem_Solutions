#include <bits/stdc++.h>
using namespace std;

struct Value {
    int current;
    int dist = 0;
};

int BFS(int n, int target){
    vector<bool> dp(99999, false);
    queue<Value> q;
    
    q.push({n, 0});
    dp[n] = true;

    while(!q.empty()){
        Value top = q.front();
        q.pop();

        int current = top.current, dist = top.dist;

        if(current == target)
            return dist;

        int next = current + 1;
        if(!dp[next]){
            q.push({next, dist + 1});
            dp[next] = true;
        }

        string Scurrent = to_string(current);
        reverse(Scurrent.begin(), Scurrent.end());

        next = stoi(Scurrent);        
        if(!dp[next]){
            q.push({next, dist + 1});
            dp[next] = true;
        }

    }

    return 0;
}

int main() {
    int c;
    cin >> c;
    while(c--){
        int target, n;

        cin >> n >> target;

        int result = BFS(n, target);
        cout << result << endl;
    }
    
    return 0;
}
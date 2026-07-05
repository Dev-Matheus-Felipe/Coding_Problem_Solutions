#include <bits/stdc++.h>
using namespace std;

string KHAN(vector<vector<int>>& G, int N){
    vector<int> in_degree(N, 0);
    queue<int> q;
    
    for(int i = 0; i < N; i++)
    for(int to: G[i])
    in_degree[to] += 1;
    
    for(int i = 0; i< N; i++)
        if(in_degree[i] == 0)
            q.push(i);
    
    string result = "";
    int index = 0;

    while(!q.empty()){
        int top = q.front();
        q.pop();

        result += to_string(top + 1) + " ";
        index++;

        for(int to: G[top]){
            in_degree[to] -= 1;

            if(in_degree[to] == 0)
                q.push(to);
        }

    }

    if(result.length() > 0) result.pop_back();

    return (index != N ? "IMPOSSIBLE" : result);
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    int u, v;

    for(int i = 0; i < M; i++){
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
    }

    cout << KHAN(G, N) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ci pair<string, int>

int BFS(unordered_map<string, vector<string>> &G, string start, string end){
    unordered_map<string, bool> dp;
    queue<ci> q;

    q.push({start, 0 });
    dp[start] = true;

    while(!q.empty()){
        ci top = q.front();
        q.pop();

    
        string current = top.first;
        int dist = top.second;
        
        if(current == end) return top.second;
        
        for(string v: G[current])
        if(dp[v] == false){
            q.push({v, dist + 1});
            dp[v] = true;
        }
    }

    return 0;
}

void setPos(string u, string v, string &start, string &end){
    if(u == "Entrada") start = u;
    else if(u == "Saida") end = u;
    else if(v == "Entrada") start = v;
    else if(v == "Saida") end = v;
}

int main() {
    string start, end;
    int n, m;

    cin >> n >> m;

    string u, v;

    unordered_map<string, vector<string>> G(n);
    for(int i = 0; i < m; i++){
        cin >> u >> v;

        if(u.size() > 1 || v.size() > 1)
            setPos(u, v, start,end);
        
    
        G[u].push_back(v);
        G[v].push_back(u);
        
    }

    int getCheese = BFS(G, start, "*");
    int getExit = BFS(G, "*", end);

    cout << getCheese + getExit<< endl;
    return 0;
}
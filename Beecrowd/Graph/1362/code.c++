#include <bits/stdc++.h>
using namespace std;

vector<string> shirts = {"XXL", "XL", "L", "M", "S", "XS"};
vector<int> matchR;
vector<bool> vis;

bool dfs(vector<vector<int>>&G, int x){
    if(vis[x]) return false;
    vis[x] = true;

    for(int v: G[x]){
        if(matchR[v] == -1 || dfs(G, matchR[v])){
            matchR[v] = x;
            return true;
        }
    }

    return false;
}

int khun(vector<vector<int>>& G, int nLeft){
    int matching = 0;

    for (int i = 0; i < nLeft; i++) {
        vis.assign(nLeft, false);
        if (dfs(G, i)) {
            matching++;
        }
    }

    return matching;
}

int main(){
    int T, nRight, nLeft;
    cin >> T;
    
    while(T--){
        cin >> nRight >> nLeft;

        matchR.assign(nRight, -1);

        unordered_map<string, vector<int>> getPos;
        vector<vector<int>> G(nLeft);

        int aux = 0, count = 0;
        for(int i = 0; i < nRight; i++){
            getPos[shirts[count]].push_back(i);
            if(aux + 1 == nRight / 6){
                count++;
                aux = 0;

            }else aux++;
        }

        string a, b;
        for(int i = 0; i < nLeft; i++){
            cin >> a >> b;

            for(int value : getPos[a])
                G[i].push_back(value);
            
            for(int value : getPos[b])
                G[i].push_back(value);
        }

        int result = khun(G, nLeft);
        cout << (result == nLeft ? "YES" : "NO") << endl;
    }

    return 0;
}
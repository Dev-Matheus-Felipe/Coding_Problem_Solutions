#include <bits/stdc++.h>
using namespace std;

vector<int> low, tin;
vector<bool> onStack;
stack<int> s;

vector<int> err(2, -1);
int globalTime = 0;
bool found = false;

void DFS_VISITA(vector<vector<int>>& G, int u){
    low[u] = tin[u] = ++globalTime;
    onStack[u] = true;
    s.push(u);

    for(int v: G[u]){
        if(tin[v] == -1){
            DFS_VISITA(G, v);
            low[u] = min(low[u], low[v]);
        
        } else if(onStack[v]) low[u] = min(low[u], tin[v]);
    }

    if(low[u] == tin[u]){
        while(true){
            int x = s.top();
            s.pop();

            onStack[x] = false;
            if(x == u) break;
            
        }

        if(u != 0 && !found){
            found = true;
            err[1] = u + 1;
            err[0] = 1;
        }
    }
}

string DFS(vector<vector<int>>& G, int N){
    onStack.assign(N, false);
    low.assign(N, -1);
    tin.assign(N, -1);

    for(int i = 0; i < N; i++){
        if(tin[i] == -1){
            if(i != 0){
                err[1] = 1;
                err[0] = i + 1;

                return "NO";
            }
            
            DFS_VISITA(G, i);
        }
    }

    return found ? "NO" : "YES";
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    int u, v;

    while(M--){
        cin >> u >> v;
        --u; --v;

        G[u].push_back(v);
    }

    string result = DFS(G, N);
    cout << result << endl;

    if(result == "NO"){
        cout << err[1]  << " " << err[0] << endl;
    }

    return 0;
}
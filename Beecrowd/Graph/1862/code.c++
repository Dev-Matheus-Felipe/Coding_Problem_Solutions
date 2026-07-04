#include <bits/stdc++.h>
using namespace std;

struct Vertice {
    vector<int> adjs;
    char color = 'B';
};

bool isFailed = false;
int acc = 0;

void DFS_VISITA(vector<Vertice>&G, int u, int& countV, int amountV){
    if(isFailed) return;

    G[u].color = 'C';
    
    if(amountV != (int)G[u].adjs.size()){
        isFailed = true;
        return;
    }

    countV++;
    
    for(int v: G[u].adjs){
        if(G[v].color == 'B'){
            DFS_VISITA(G, v, countV, amountV);
        }
    }
}

vector<int> DFS(vector<Vertice>& G){
    vector<int> result;
    int countV = 0;

    for(int i = 0; i < (int)G.size(); i++){
        if(G[i].color == 'B'){
            countV = 0;
            acc++;

            int amountV = G[i].adjs.size();
            
            DFS_VISITA(G, i, countV, amountV);
            result.push_back(countV);
            
            if(countV != amountV) isFailed = true;
            if(isFailed) break;
        }
    }

    return result;
}

int main() {
    int N;
    cin >> N;

    vector<Vertice> G(N);
    char l;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> l;
            
            if(l == 'S'){
                G[i].adjs.push_back(j);
            }
        }
    }

    vector<int> result = DFS(G);
    
    if(isFailed){
        cout << -1 << endl;
        return 0;
    }

    sort(result.begin(), result.end(), greater<int>());

    cout << acc << endl;

    for(int i = 0; i < (int)result.size(); i++){
        cout << result[i];

        if(i < (int)result.size() - 1) cout << ' ';
    }

    cout << endl;

    return 0;
}
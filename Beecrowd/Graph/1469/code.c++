#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int result;

struct Vertice {
    vector<int> adjs;
    char color = 'B';
};

void CLEAR_G(vector<Vertice>& G){
    for(Vertice &v: G)
        v.color = 'B';
}

void DFS_VISITA(vector<Vertice> &G, vector<int>& verticeP, vector<int>& ages, int u){
    result = min(result, ages[verticeP[u]]);
    G[u].color = 'P';

    for(int v: G[u].adjs)
        if(G[v].color == 'B')
            DFS_VISITA(G, verticeP, ages, v);
}

void DFS(vector<Vertice> &G, vector<int>& verticeP, vector<int>& ages, int u){
    result = INF;
    for(int v: G[u].adjs)
        if(G[v].color == 'B')
            DFS_VISITA(G, verticeP, ages, v);
}

int main(){
    int v, e, c;
    while(cin >> v >> e >> c){
        vector<int> ages(v), pessoaV(v), verticeP(v);
        vector<Vertice> G(v);

        for(int i = 0; i < v; i++){
            cin >> ages[i];
            pessoaV[i] = i;
            verticeP[i] = i;
        }

        int a, b;
        for(int i = 0; i < e; i++){
            cin >> a >> b;
            --a; --b;

            G[b].adjs.push_back(a);
        }

        while(c--){
            char l; cin >> l;
            CLEAR_G(G);

            int x, y;
            if(l == 'P'){
                cin >> x;

                int VP = pessoaV[x - 1];
                DFS(G, verticeP, ages, VP);

                cout << (result != INF ? to_string(result) : "*") << endl;
            
            }else {
                cin >> x >> y;
                --x; --y;

                swap(pessoaV[x], pessoaV[y]);
                swap(verticeP[pessoaV[x]], verticeP[pessoaV[y]]);
            }
        }
    }

    return 0;
}
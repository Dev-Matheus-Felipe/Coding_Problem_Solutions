#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f

struct Vertice{
    vector<int> adj; 
    char cor = 'B';    
    int pai = -1;     
    int d = 0;        
};

bool BFS(vector<Vertice> &G, int s){
    for(Vertice &u: G){
        u.cor = 'B';
        u.d = inf;
        u.pai = -1;
    }

    G[s].cor = 'C';
    G[s].d = 0;
    G[s].pai = -1;

    queue<int> qv;
    qv.push(s);

    while(!qv.empty()){
        int u = qv.front();
        qv.pop();

        for(int v: G[u].adj)
            if(G[v].cor == 'B'){
                G[v].cor = 'C';
                G[v].d = G[u].d + 1;
                G[v].pai = u;
                qv.push(v);
            }

            G[u].cor = 'P';
    }

    for(Vertice v : G)
        if(v.cor == 'B') return false;
    
    return true;
}


int main() {
    int v,e;

    while(cin >> v >> e){
        if(v == 0 && e == 0) break;

        vector<Vertice> G(v);
        vector<Vertice> GT(v);

        while(e--){
            int x,y,z;
            cin >> x >> y >> z;
            x--; y--;

            G[x].adj.push_back(y);
            GT[y].adj.push_back(x);

            if(z == 2){
                G[y].adj.push_back(x);
                GT[x].adj.push_back(y);
            }
            
        }

        bool g1 = BFS(G, 0), g2 = BFS(GT, 0);
        
        cout << (g1 && g2 ? 1 : 0) << endl;
    }

    return 0;
}
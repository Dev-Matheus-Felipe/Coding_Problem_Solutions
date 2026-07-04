#include <bits/stdc++.h>
using namespace std;

int tempo = 0;

struct Vertice {
    vector<char> adj;
    char cor = 'B';
};

void DFS_Visita(vector<Vertice> &G, int u, vector<char> &line){
    tempo++;
    G[u].cor = 'C';

    line.push_back('a' + u);

    for(int v : G[u].adj)
        if(G[v].cor == 'B')
            DFS_Visita(G, v, line);
        
    G[u].cor = 'P';
    tempo++;
}

void DFS(vector<Vertice> &G, int &count){
    tempo = 0;

    for(int i=0; i<G.size(); i++)
        G[i].cor = 'B';

    for(int i=0; i<G.size(); i++){
        if(G[i].cor == 'B'){
            vector<char> line;
            DFS_Visita(G, i, line);

            sort(line.begin(), line.end());

            for(char l : line)
                printf("%c,", l);

            cout << '\n';
            count++;
        }
    }
}

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        int count = 0, v, e;
        cin  >> v >> e;

        vector<Vertice> G(v);

        while(e--){
            char u, x;
            cin >> u >> x;

            G[u - 97].adj.push_back(x - 97);
            G[x - 97].adj.push_back(u - 97);
        }

        printf("Case #%d:\n", i + 1);
        DFS(G, count);
        
        cout << count << " connected components\n\n";

    }

    return 0;
}
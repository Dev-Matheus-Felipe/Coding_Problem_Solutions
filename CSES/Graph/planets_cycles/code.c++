#include <bits/stdc++.h>
using namespace std;

stack<int> s;

struct Vertice {
    int to, time = -1;
    char color = 'B';
};
  
void DFS_VISITA(vector<Vertice>& G, int u){
    G[u].color = 'C';
    s.push(u);

    int v = G[u].to;
    if(G[v].color == 'B')
        DFS_VISITA(G, v);

    else if(G[v].color == 'C'){
        int count = 0;
        while(true){
            count++;
            
            if(s.top() == v) break;
            s.pop();
        }
        
        G[u].time = G[v].time = count;
        s.pop();
    }

    if(!s.empty() && s.top() == u){
        G[u].time = G[v].time + 1;
        s.pop();

    } else if(s.empty() || s.top() != u)
        G[u].time = G[v].time;

    G[u].color = 'P';
}

void DFS(vector<Vertice>& G, int N){
    for(int i = 0; i < N; i++){
        if(G[i].color == 'B'){
            DFS_VISITA(G, i);
        }
    }
}

int main(){
    int N;
    cin >> N;

    vector<Vertice> G(N);
    int v;

    for(int u = 0; u < N; u++){
        cin >> v;
        G[u].to = --v;
    }


    DFS(G, N);

    for(int i = 0; i < N; i++){
        cout << G[i].time;
        if(i < N - 1) cout << " ";
    }
    
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ic pair<int, char>
bool possible = false;

struct Vertice {
    vector<int> adjs;
    char color = 'B';
};

bool BFS(vector<Vertice>& G){
    queue<ic> q;

    q.push({0, 'R'});
    G[0].color = 'R';

    while(!q.empty()){
        ic top = q.front();
        q.pop();

        int current = top.first;
        char color = top.second;

        for(int v: G[current].adjs){
            if(G[v].color == color ) return false;

            if(G[v].color == 'B'){
                G[v].color = color == 'R' ? 'L' : 'R';
                q.push({v, G[v].color});
            }
        }
    }

    return true;
}

int main() {
    int N;
    cin >> N;

    vector<Vertice> G(N);
    int p;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> p;
            
            if(p == 0) G[i].adjs.push_back(j);
        }
    }

    cout << (BFS(G) ? "Bazinga!" : "Fail!") << endl;

    return 0;
}
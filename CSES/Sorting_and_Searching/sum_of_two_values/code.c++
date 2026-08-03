#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    cin >> N >> X;

    unordered_map<int, int> pos;
    pos.reserve(N);
    pos.max_load_factor(0.7);

    int S, E, V;

    bool found = false;
    for(int i = 1; i <= N; i++){
        cin >> V;

        if(found) continue;

        auto it = pos.find(X - V);
        if(it != pos.end()){
            S = it->second;
            E = i;

            found = true;
        }

        pos[V] = i;
    }


    if(!found){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << S << ' ' << E << '\n';  
    return 0;
}
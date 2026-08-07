#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
ii operations[2] = {
    {-1, 0}, {0, 1}
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> pos(N, 0), arry(N, 0);
    int x, res = 1;

    for(int i = 0; i < N; i++){
        cin >> x;
        --x;

        pos[x] = i;
        arry[i] = x;
    }

    for(int i = 1; i < N; i++){
        if(pos[i] < pos[i-1]){
            res++;
        }
    }

    
    while(M--){
        int a, b;
        cin >> a >> b;

        --a; --b;
        
        int va = arry[a], vb = arry[b];
        set<ii> changes;

        for(ii op: operations){
            if(va + op.first >= 0 && va + op.second < N) 
                changes.insert( {va + op.first, va + op.second });

            if(vb + op.first >= 0 && vb + op.second < N) 
                changes.insert({ vb + op.first, vb + op.second });
        }

        for(ii c: changes){
            int x = c.first, y = c.second;
            if(pos[x] > pos[y]) res--;
        }

        swap(pos[va], pos[vb]);
        swap(arry[a], arry[b]);

        for(ii c: changes){
            int x = c.first, y = c.second;
            if(pos[x] > pos[y]) res++;
        }

        cout << res << '\n';
       
    }

    return 0;
}



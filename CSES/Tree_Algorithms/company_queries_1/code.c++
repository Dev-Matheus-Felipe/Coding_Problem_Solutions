#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;

    int LOG = 1;
    while((1 << LOG) <= N) LOG++;

    vector<vector<int>> up(N, vector<int>(LOG, -1));

    for(int i = 1; i < N; i++){
        cin >> up[i][0];
        up[i][0]--;
    }

    for(int j = 1; j < LOG; j++)
        for(int v = 0; v < N; v++)
            if(up[v][j-1] != -1)
                up[v][j] = up[ up[v][j-1] ][j-1];

    int B, K;
    while(Q--){
        cin >> B >> K;
        --B;

        for(int j = 0; j < LOG; j++)
            if(K & (1 << j) && B != -1)
                B = up[B][j];

        cout << (B == -1 ? B : B + 1) << endl;
    }

    return 0;
}
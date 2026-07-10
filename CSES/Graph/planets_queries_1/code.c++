# include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    
    int LOG = 31, p;
    vector<vector<int>> up(N, vector<int>(LOG));
    vector<int> parents(N);

    for(int i = 0; i < N; i++){
        cin >> p;
        --p;

        parents[i] = p;
        up[i][0] = p;
    }

    for(int j = 1; j < LOG; j++)
        for(int v = 0; v < N; v++)
            up[v][j] = up[ up[v][j-1] ][j-1];

    int X; K;
    while(Q--){
        cin >> X >> K;
        --X;

        for(int j = 0; j < LOG; j++){
            if(K & (1LL  << j))
                X = up[X][j];
            
        }

        cout << X + 1 << '\n';
    }

    return 0;
}
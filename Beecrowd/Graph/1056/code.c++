#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> matchR;
vector<bool> vis;

bool khun(int x){
    if(vis[x]) return false;
    vis[x] = true;

    for(int v: G[x]){
        if(matchR[v] == -1 || khun(matchR[v])){
            matchR[v] = x;
            return true;
        }
    }

    return false;
}

int main(){
    int T;
    cin >> T;

    int nLeft, nRight;
    for(int i = 1; i <= T; i++){
        cin >> nRight;

        vector<int> rightNums(nRight);
        matchR.assign(nRight, -1);
        G.clear();
        
        for(int k = 0; k < nRight; k++)
            cin >> rightNums[k];
        
        
        cin >> nLeft;
        G.assign(nLeft, {});
        
        int a;
        for(int k = 0; k < nLeft; k++){
            cin >> a;

            for(int j = 0; j < nRight; j++){
                int v1 = rightNums[j], v2 = a;         
                if(v1 == 0){
                    if(v2 == 0) G[k].push_back(j);
                }
                else{
                    if(v2 % v1 == 0) G[k].push_back(j);
                }       
                
            }
        }

        int count = 0;
        for(int k = 0; k < nLeft; k++){
            vis.assign(nLeft, false);
            if(khun(k)) count++;
        }

        cout << "Case " << i << ": " << count << endl;
    }

    return 0;
}
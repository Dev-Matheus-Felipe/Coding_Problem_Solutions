#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

int main(){
    int M, S, E;
    cin >> M;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    int res = 0;
    
    while(M--){
        cin >> S >> E;

        pq.push({E, S});
    }

    S = E = 0;
    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();

        if(top.second >= E){
            res++;
            S = top.second;
            E = top.first;
        }
    }

    cout << res << endl;
    return 0;
}
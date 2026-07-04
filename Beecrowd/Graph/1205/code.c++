#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define INF 1e9

struct Vertice {
    int soldiers = 0;
    vector<int> adjs;
};

int main(){
    cout << fixed << setprecision(3);

    int v, e, b;
    double p;
    
    while(cin >> v >> e >> b >> p){
        vector<Vertice> G(v);
        int SV, EV;
        
        int v1, v2;
        for(int i=0; i < e; i++){
            cin >> v1 >> v2;
            v1--; v2--;

            G[v1].adjs.push_back(v2);
            G[v2].adjs.push_back(v1);
        }

        int soldiers, target;
        cin >> soldiers;

        for(int i=0; i < soldiers; i++){
            cin >> target;
            G[target - 1].soldiers += 1;
        }

        cin >> SV >> EV;
        SV--; EV--;

        priority_queue<
            ii,
            vector<ii>,
            greater<ii>
        > pq;

        vector<int> dp(v, INF);

        pq.push({G[SV].soldiers, SV});
        dp[SV] = G[SV].soldiers;

        while(!pq.empty()){
            ii top = pq.top();
            pq.pop();

            int dist = top.first, current = top.second;

            if(dp[current] < dist)
                continue;

            for(int neighbor: G[current].adjs) {
                if(dp[neighbor] > dist + G[neighbor].soldiers){
                    dp[neighbor] = dp[current] + G[neighbor].soldiers;
                    pq.push({dp[neighbor], neighbor});
                }
            }
        }

        if(dp[EV] == INF || dp[EV] > b){
            cout << 0.000 << endl;
            continue;
        }

        double result = pow(p, dp[EV]);
        cout << result << endl;
    }
    
    return 0;
}



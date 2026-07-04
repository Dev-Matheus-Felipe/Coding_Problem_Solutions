#include <bits/stdc++.h>
using namespace std;

#define si pair<string, int>
#define INF 1000000000

struct Edge {
    si connection;
    char letter;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string start, end;
    int n;

    while(cin >> n){
        if(n == 0) break;
        cin >> start >> end;

        unordered_map<string, vector<Edge>> G;
        string u, v, w;

        while(n--){
            cin >> u >> v >> w;
            G[u].push_back({{v, w.size()}, w[0]});
            G[v].push_back({{u, w.size()}, w[0]});
        }

        queue<Edge> pq;

        unordered_map<string, unordered_map<char, int>> dp;

        pq.push({{start, 0}, '#'});
        dp[start]['#'] = 0;

        while(!pq.empty()){
            Edge top = pq.front();
            pq.pop();

            string current = top.connection.first;    
            int dist = top.connection.second;
            char oldLetter = top.letter;


            if (dist != dp[current][oldLetter]) continue;

            for (Edge gc : G[current]) {

                string neighbor = gc.connection.first;
                int weight = gc.connection.second;
                char newLetter = gc.letter;

                if (newLetter == oldLetter) continue;

                int newCost = dist + weight;

                if (!dp[neighbor].count(newLetter) ||
                    newCost < dp[neighbor][newLetter]) {

                    dp[neighbor][newLetter] = newCost;
                    pq.push({{neighbor, newCost}, newLetter});
                }
            }
        }

        if (!dp.count(end))
            cout << "impossivel\n";

        else {
            int lowest = INF;
            for (auto &p : dp[end]) {
                char ch = p.first;
                int cost = p.second;

                lowest = min(lowest, cost);
            }
            
            cout << lowest << '\n';
        }
    }

    return 0;
}
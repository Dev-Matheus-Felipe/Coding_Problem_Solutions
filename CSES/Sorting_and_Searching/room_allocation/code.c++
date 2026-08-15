#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

int main(){
    int N, res = 0;
    cin >> N;

    vector<tuple<int, int, int>> indexs;
    vector<int> rooms(N);
    int sa, sd;

    for(int i = 0; i < N; i++){
        cin >> sa >> sd;

        indexs.push_back({sa, sd, i});
    }

    sort(indexs.begin(), indexs.end());
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    auto [a, d, idx] = indexs[0];

    rooms[idx] = ++res;
    pq.push({d, 1});

    for(int i = 1; i < N; i++){
       auto [a, d, idx] = indexs[i];

        ii top = pq.top();

        if(a > top.first){
            rooms[idx] = top.second;
            pq.pop();

            pq.push({d, top.second});
            
        } else {
            rooms[idx] = ++res;
            pq.push({d, res});
        }
    }
    
    cout <<  res << '\n';
    for(int r: rooms){
        cout << r << " ";
    }

    cout << '\n';
    return 0;
}
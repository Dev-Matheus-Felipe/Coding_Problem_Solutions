#include <bits/stdc++.h>
using namespace std;

#define ii pair<long long, long long>

int main(){
    int N;
    cin >> N;

    vector<ii> tasks(N);
    int dr, dl;
    
    for(int i = 0; i < N; i++){
        cin >> dr >> dl;

        tasks[i] = {dr, dl};
    }

    sort(tasks.begin(), tasks.end());

    long long acc = 0, res = 0;
    for(ii task: tasks){
        dr = task.first, dl = task.second;

        acc += dr;
        res += (dl - acc);
    }

    cout << res << '\n';

    return 0;
}
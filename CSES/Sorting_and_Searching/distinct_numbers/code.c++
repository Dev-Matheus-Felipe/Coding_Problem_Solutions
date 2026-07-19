#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    set<int> us;
    while(N--){
        int v; cin >> v;
        us.insert(v);
    }

    cout << us.size() << '\n';
    return 0;
}
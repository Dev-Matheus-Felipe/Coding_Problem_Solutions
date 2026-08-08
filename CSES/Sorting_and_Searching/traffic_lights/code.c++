#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, N;
    cin >> X >> N;

    multiset<int> values;
    set<int> pos;

    values.insert(X);
    pos.insert(0);
    pos.insert(X);

    int p;
    while(N--){
        cin >> p;

        auto right = pos.upper_bound(p);
        auto left = right;
        
        --left;

        values.erase(values.find(*right - *left));
        values.insert(*right - p);
        values.insert(p - *left);

        cout << *values.rbegin();
        if(N >= 1) cout << ' ';

        pos.insert(p);
    }

    cout << '\n';


    return 0;
}
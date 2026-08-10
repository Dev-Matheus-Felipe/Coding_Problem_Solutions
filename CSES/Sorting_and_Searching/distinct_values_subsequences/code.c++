#include <bits/stdc++.h>
using namespace std;

const long long int MOD = 1e9 + 7;

int main(){
    int Q;
    cin >> Q;

    long long int res = 1;
    map<int, int> amount;
    int x;

    for(int i = 0; i < Q; i++){
        cin >> x;
        amount[x]++;
    }

    for(auto it: amount){
        int value = it.second;

        res = (res * (value + 1)) % MOD;
    }

    cout << (res - 1) << '\n';
    return 0;
}
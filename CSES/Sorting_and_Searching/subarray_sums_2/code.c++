#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll N, target;
    cin >> N >> target;

    map<ll, ll> prefxs;
    ll x, res = 0, acc = 0;

    prefxs[0] = 1;

    for(ll i = 0; i < N; i++){
        cin >> x;
        acc += x;

        res += prefxs[acc - target];

        prefxs[acc] += 1;
    }

    cout << res << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int N;
    cin >> N;

    map<ll, ll> nums;
    ll sum = 0, res = 0;
    int v;

    nums[0] = 1;

    for(int i = 0; i < N; i++){
        cin >> v;

        sum += v;

        int rest = ((sum % N) + N) % N;
        
        res += nums[rest];
        
        nums[rest] += 1;
    }

    cout << res << '\n';

    return 0;
}
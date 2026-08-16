#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    int N, T;
    cin >> N >> T;

    vector<int> products(N);
    for(int& p: products) cin >> p;

    ll low = 0, high = 1e18;
    ll ans = 0;
    
    while(low <= high){
        ll acc = 0, mid = (high + low) / 2;
        for(int p: products){
            acc += (mid / p);
            if(acc >= T) break;
        }

        if(acc >= T){
            high = mid - 1;
            ans = mid;

        } else low = mid + 1;
    }

    cout << ans << '\n';
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int Q;
    cin >> Q;

    multiset<int> nums;
    int x;

    for(int i = 0; i < Q; i++){
        cin >> x;
        nums.insert(x);
    }

    auto it = nums.begin();
    advance(it, Q/2);

    long long diff = *it, res = 0;

    for(int n: nums){
        res += abs(n-diff);
    }

    cout << res << endl;
    return 0;
}
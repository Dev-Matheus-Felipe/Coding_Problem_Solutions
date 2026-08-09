#include <bits/stdc++.h>
using namespace std;

int main(){
    int Q;
    cin >> Q;

    int x, left = 0, right = -1;
    long long int res = 0;

    vector<int> arry(Q);
    map<int, int> mp;

    for(int i = 1; i <= Q; i++){
        cin >> x;
        
        arry[i-1] = x;
        right++;

        if(mp[x]){
            left = max(left, mp[x]);
        }

        
        res += right - left + 1;
        mp[x] = i;

    }

    cout << res << '\n';

    return 0;
}
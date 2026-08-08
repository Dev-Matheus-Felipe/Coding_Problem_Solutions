#include <bits/stdc++.h>
using namespace std;

int main(){
    int Q;
    cin >> Q;

    int x, longest = 0, count = 0, lastIndex = 0;
    map<int, int> mp;

    for(int i = 1; i <= Q; i++){
        cin >> x;

        if(mp[x] && mp[x] > lastIndex){
            count = i - mp[x];
            lastIndex = mp[x];
            
        } else  count++;


        mp[x] = i;

        longest = max(longest, count);

    }

    cout << longest << '\n';
    return 0;
}
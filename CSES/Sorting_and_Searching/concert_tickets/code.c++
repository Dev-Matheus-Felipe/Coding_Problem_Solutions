#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    multiset<int> ms;
    int x;

    while(N--){
        cin >> x;
        ms.insert(x);
    }

    while(M--){
        cin >> x;
        auto it = ms.upper_bound(x);

        if(it == ms.begin()){
            cout << -1 << '\n';
            continue;
        }
        
        --it;
        cout << *it << '\n';
        ms.erase(it);
    }
    
    return 0;
}
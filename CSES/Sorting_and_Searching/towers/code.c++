#include <bits/stdc++.h>
using namespace std;

int solve(int N){
    multiset<int> s;
    int x;

    while(N--){
        cin >> x;

        auto it = s.upper_bound(x);

        if(it != s.end()){
            s.erase(it);
        }
        
        s.insert(x);
    }

    return (int)s.size();
}


int main(){
    int N;
    cin >> N;

    cout << solve(N) << '\n';
    return 0;
}
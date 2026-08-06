#include <bits/stdc++.h>
using namespace std;

int main(){
    int Q;
    cin >> Q;
    
    multiset<int> s;
    int x;

    for(int i = 0; i < Q; i++){
        cin >> x;
        s.insert(x);
    }

    long long sum = 0;
    for(int n: s){
        if(n > sum + 1) break;

        sum += n;
    }

    cout << sum + 1 << endl;

    return 0;
}
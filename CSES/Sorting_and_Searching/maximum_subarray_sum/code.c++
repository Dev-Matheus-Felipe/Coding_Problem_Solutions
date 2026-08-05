#include <bits/stdc++.h>
using namespace std;

#define lli long long int
const lli INF = -1e18;

lli solve(int N){
    lli biggest;
    lli count;

    cin >> count;
    biggest = count;
    N--;

    lli x;
    while(N--){
        cin >> x;
        count = max(count + x, x);
        biggest = max(biggest, count);
    }

    return biggest;
}

int main(){
    int N; 
    cin >> N;

    cout << solve(N) << '\n';
    return 0;
}
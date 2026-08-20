#include <bits/stdc++.h>
using namespace std;

#define lli long long int

int main(){
    lli x;
    cin >> x;
    x *= 8000000;

    int res;
    for(res = 0; (1LL << res) < x; res++);
    cout << res << endl;
}
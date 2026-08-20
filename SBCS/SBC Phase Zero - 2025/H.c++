#include <bits/stdc++.h>
using namespace std;

#define lli long long int

lli func(lli x){
    if(x == 1)
        return 1;

    int pos;
    for(pos = 0; (1LL << (pos + 1)) <= x; pos++);

    if((1LL << pos) == x)
        return x - 1;

    lli result = (1LL << pos) + 1, inc;

    for(int i = pos-1; i >= pos - i; i--){
        inc = (1LL << i);

        if(i > pos - i) inc += (1LL << (pos - i));
        if(result + inc <= x)
            result += inc;
        
    }

    return result;
}


int main() {
    lli x;
    cin >> x;

    cout << func(x) << endl;
    return 0;
}
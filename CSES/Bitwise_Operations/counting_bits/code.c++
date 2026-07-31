#include <bits/stdc++.h>
using namespace std;

#define lli long long

int main() {
    lli B;
    cin >> B;

    lli acc = 0;

    for (lli pos = 0; (1LL << pos) <= B; pos++) {
        lli half = 1LL << pos;
        lli block_count = half * 2;

        lli blocks_amount = (B + 1) / block_count;

        acc += blocks_amount * half;

        lli res = (B + 1) % block_count;

        acc += max(0LL, res - half);
    }

    cout << acc << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, X;
    cin >> N >> X;

    multiset<long long> ms;
    int count = 0, v;

    while(N--){
        cin >> v;
        ms.insert(v);
    }

    auto left = ms.begin(), right = --ms.end();
    int l = 0, r = ms.size() -1;

    while(l <= r){
        if(*left + *right <= X){
            right--, r--;
            left++, l++;

        } else right--, r--;

        count++;
    }

    cout << count << endl;
    return 0;
}
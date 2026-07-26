#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    float isolated = 0, normal = 0;

    for(int i = 0; i < N; i++){
        char x; cin >> x;
        if(x == '*') isolated++;
    }

    for(int i = 0; i < N; i++){
        char x; cin >> x;
        if(x == '*') normal++;
    }

    cout << fixed << setprecision(2);
    cout << 1 - (normal / isolated) << endl;
}
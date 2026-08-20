#include <bits/stdc++.h>
using namespace std;

int main(){
    int C, G;
    cin >> C >> G;

    if(C == 1) cout << "vivo e morto";
    else {
        cout << (G == 1 ? "vivo" : "morto");
    }

    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int Y, K;
    cin >> Y >> K;

    vector<int> divisores;

    for(int i = 1; i * i <= Y; i++){
        if(Y % i == 0){
            divisores.push_back(i);

            if(i != Y / i){
                divisores.push_back(Y / i);
            }
        }
    }

    sort(divisores.begin(), divisores.end());

    long long x = 1;

    for(int d: divisores){
        if(divisores[0] == d) continue;

        if(d % x == 0){
            
            if(K - (( d / x ) - 1) >= 0){
                K -= ((d/x) - 1);
                x = d;
            }

            else {
                break;
            }
        }
    }

    x += x * K;
    
    cout << x << endl;
    return 0;
}
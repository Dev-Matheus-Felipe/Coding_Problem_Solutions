#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, K;
    cin >> N >> M >> K;

    multiset<long long> applicants, apartments;
    int x;

    for(int i = 0; i < N; i++){
        cin >> x;
        applicants.insert(x);
    }

    int count = 0;
    
    while(M--){
        cin >> x;
        apartments.insert(x);
    }

    for(auto i = apartments.begin(); i != apartments.end(); i++){

        long long ap = *i;
        auto it = applicants.lower_bound(ap - K);
        
        if(it != applicants.end() && *it <= *i + K){
            applicants.erase(it);
            count++;
        }
    }

    cout << count << endl;
    return 0;
}

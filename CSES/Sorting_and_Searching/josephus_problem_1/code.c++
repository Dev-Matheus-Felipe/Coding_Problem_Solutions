#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    set<int> s;

    for(int i = 1; i <= N; i++){
        s.insert(i);
    }

    auto it = s.begin();
    while(!s.empty()){
        ++it;

        if(it == s.end()){
            it = s.begin();
        }

        cout << *it << " ";
        it = s.erase(it);

        if(it == s.end() && !s.empty()) it = s.begin();
    }


    cout << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

int main(){
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> e, s;

    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;

        e.push(x);
        s.push(y);
    }

    int biggest = 0, count = 0;

    while(!e.empty()){
        int ce = e.top();
        int cs = s.top();

        if(ce < cs){
            count++;
            e.pop();
            
        } else {
            s.pop();
            count--;
            
        }
        
        biggest = max(biggest, count);
    }

    cout << biggest << endl;
    return 0;
}
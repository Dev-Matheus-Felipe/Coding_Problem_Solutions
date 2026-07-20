#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, Q, index = 1;

    while(cin >> N >> Q && (N != 0 && Q != 0)){
        vector<int> nums(N);
        
        for(int i = 0; i < N; i++){
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());

        map<int, int> pos;
        int j = 1;
        for(int n: nums){
            if(!pos[n]) pos[n] = j;
            j++;
        }

        cout << "CASE# " << index << ":\n";

        while(Q--){
            int s; cin >> s;

            if(pos[s]){
                cout << s << " found at " << pos[s] << endl;
            
            } else cout << s << " not found\n";
        }

        index++;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin >> N;

    vector<int> nums(N);
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        nums[--x] = i;
    }

    int count = 1;
    for(int i = 1; i < N; i++){
        if(nums[i] < nums[i-1]) count++;
    }

    cout << count << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, target;
    cin >> N >> target;

    vector<int> nums(N);
    for(int& n: nums) cin >> n;

    int i = 0, j = 0, sum = 0;
    int res = 0;

    while(i < N){
        sum += nums[i];

        while(sum > target){
            sum -= nums[j++];
        }

        if(sum == target) res++;
        i++;
    }

    cout << res << '\n';
    return 0;
}
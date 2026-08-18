#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> nums(N);
    for(int&n: nums) cin >> n;
    
    sort(nums.begin(), nums.end());

    int i = N - 2, j = N - 1;

    int biggest = nums[j];
    long long res = nums[j];
    bool valid = true;

    while(i >= 0){
        biggest -= nums[i];

        if(biggest < 0){
            res += abs(biggest);
            valid = false;
            biggest = 0;
        }

        i--;
    }

    if(valid){
        cout << 2 * nums[N-1] << '\n';
    
    } else cout << (res + nums[N-1]) << '\n';
    
    return 0;
}
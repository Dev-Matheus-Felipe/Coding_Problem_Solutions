#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, target;
    cin >> N >> target;

    vector<ii> nums(N);
    int v;
    
    for(int i = 0; i < N; i++){
        cin >> v;
        nums[i] = {v, i+1};
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < N - 2; i++){
        int rest = target - nums[i].first;
        int left = i + 1, right = N - 1;
        
        if(rest <= 0) continue;

        while(left < right){
            int sum = nums[left].first + nums[right].first;

            if(sum == rest){
                cout << nums[i].second << " " << nums[left].second << " " << nums[right].second << '\n';
                return 0;
            }
            
            if(sum > rest) right--;
            else left++;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
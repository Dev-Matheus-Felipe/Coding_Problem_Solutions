class Solution {
public:

    #define ii pair<int, int>

    int jump(vector<int>& nums) {
        int size = nums.size();

        vector<bool> dp(size, false);
        queue<ii> q;

        q.push({0, 0});
        dp[0] = true;

        while(!q.empty()){
            ii top = q.front();
            q.pop();
            
            if(top.first == size - 1) return top.second;

            for(int i = 1; i <= nums[top.first]; i++){
                if(top.first + i < size && !dp[top.first + i]){
                    q.push({top.first + i, top.second + 1});
                    dp[top.first + i] = true;
                }
            }
        }

        return 0;
    }
};
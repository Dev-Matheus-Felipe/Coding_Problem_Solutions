class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        if(amount == 0) return 0;

        for(int coin : coins){
            for(int v = coin; v <= amount; v++){
                if(dp[v - coin] != INF){
                    dp[v] = min(dp[v], dp[v - coin] + 1);
                }
            }
        }

        return (dp[amount] == INF ? -1 : dp[amount]);
    }
};
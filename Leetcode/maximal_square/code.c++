class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int size_x = matrix.size(), size_y = matrix[0].size();
        vector<vector<int>> dp(size_x + 1, vector<int>(size_y + 1, 0));
        int r = 0;

        for(int i=1; i <= size_x; i++){
            for(int j=1; j <= size_y; j++){
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    r = max(r, dp[i][j]);
                }
            }
        }

        return r * r;
    }
};
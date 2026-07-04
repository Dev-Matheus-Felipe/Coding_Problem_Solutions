class Solution {
public:

    int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

    bool DFS_VISITA(
        vector<vector<char>>& board, 
        vector<vector<bool>>& dp, 
        string word, 
        int index,
        int x,
        int y
    ){

        dp[x][y] = true;

        if(index == word.size())
            return true;
        

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size() && 
            !dp[nx][ny] && board[nx][ny] == word[index]){

                if(DFS_VISITA(board, dp, word, index + 1, nx, ny))
                    return true;
            } 
        }

        dp[x][y] = false;
        return false;
    }

    bool DFS(vector<vector<char>>& board, string word){
        int sizeX = board.size(), sizeY = board[0].size();

        for(int i = 0; i < sizeX; i++)
            for(int j = 0; j < sizeY; j++)
                if(board[i][j] == word[0]){
                    vector<vector<bool>> dp(sizeX, vector<bool>(sizeY, false));
                    if(DFS_VISITA(board, dp, word, 1, i, j)) 
                        return true;
                }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        return DFS(board, word);
    }
};
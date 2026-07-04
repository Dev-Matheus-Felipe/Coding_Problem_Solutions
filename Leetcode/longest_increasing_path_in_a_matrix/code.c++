class Solution {
public:
    int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

    int DFS_VISITA(vector<vector<int>>& m, vector<vector<int>>& memo, int x, int y){
        int best = 1;

        for(int i = 0; i < 4; i++){
            int nx = dx[i] + x, ny = dy[i] + y;
            if(nx < 0 || ny < 0 || nx >= m.size() || ny >= m[0].size() ||
            m[nx][ny] <= m[x][y]) continue;

            if(memo[nx][ny] != -1){
                best = max(best, memo[nx][ny]);
                continue;
            }

            memo[nx][ny] =  DFS_VISITA(m, memo, nx, ny) + 1;
            best = max(best, memo[nx][ny]);
        }

        return best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int sizeX = matrix.size(), sizeY = matrix[0].size();

        vector<vector<int>> memo(sizeX, vector<int>(sizeY, -1));
        int biggest = 0;

        for(int i = 0; i < sizeX; i++){
            for(int j = 0; j < sizeY; j++){                
                int acc = DFS_VISITA(matrix, memo, i, j);
                biggest = max(biggest, acc);
            }
        }

        return biggest;
    }
};
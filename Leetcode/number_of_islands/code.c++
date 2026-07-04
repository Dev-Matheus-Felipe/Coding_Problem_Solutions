class Solution {
public:

    vector<int> dy = {1,0,-1,0};
    vector<int> dx = {0,1,0,-1};

    int x = 0, y = 0;

    void DFS_VISITA(vector<vector<char>>& grid, int sy, int sx){
        grid[sy][sx] = '0';

        for(int i=0; i < dx.size(); i++){
            int nx = dx[i] + sx, ny = dy[i] + sy;

            if(nx >= 0 && nx < x && ny >=0 && ny < y && grid[ny][nx] == '1')
                DFS_VISITA(grid, ny, nx);
        }
    }

    int DFS(vector<vector<char>>& grid){
        int count = 0;

        for(int i=0; i < y; i++ )
            for(int j=0; j < x; j++)
                if(grid[i][j] == '1'){
                    DFS_VISITA(grid, i, j);
                    count++;
                }
            
        return count;
    }


    int numIslands(vector<vector<char>>& grid) {
        y = grid.size(), x = grid[0].size();
        int result = DFS(grid);
    
        return result;
    }
};
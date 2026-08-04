class Solution {
public:

    char letters[9] = {'1','2','3','4','5','6','7','8', '9'};
    unordered_set<char> rows[9], coluns[9], squares[9];
    bool solved = false;

    void solve(vector<vector<char>>& board, int x, int y){
        if(x == 9) solved = true;
        if(solved) return;

        int ny = (y + 1 >= 9) ? 0 : y + 1;
        int nx = (y + 1 >= 9) ? x + 1 : x;

        if(board[x][y] != '.') solve(board, nx, ny);

        else {
            int square = (x / 3) * 3 + (y / 3);

            for(char l: letters){  
                if(solved) break;

                if(!rows[x].count(l) && !coluns[y].count(l) 
                && !squares[square].count(l)){
                    board[x][y] = l;

                    rows[x].insert(l);
                    coluns[y].insert(l);
                    squares[square].insert(l);

                    solve(board, nx, ny);
                    if(solved) break;

                    rows[x].erase(l);
                    coluns[y].erase(l);
                    squares[square].erase(l);

                    board[x][y] = '.';
                }
            }
        }

    }

    void solveSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    char n = board[i][j];

                    int square = (i / 3) * 3 + (j / 3);

                    rows[i].insert(n);
                    coluns[j].insert(n);

                    squares[square].insert(n);
                }
            }
        }

        solve(board, 0, 0);
    }
};
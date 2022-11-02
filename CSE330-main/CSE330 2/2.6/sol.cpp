// User function Template for C++

class Solution{
private:
    bool isSafe(int r, int c, vector<vector<int>> &board, int n){
        int x = r;
        int y = c;
        
        // check for column
        while(x >= 0){
            if(board[x][y] == 1) return false;
            x--;
        }
        
        x = r, y = c;
        // check one diagonal
        if(x>0){
            while( x>=0 && y<n){
                if(board[x][y] == 1) return false;
                x--;
                y++;
            }
        }
        
        x = r, y = c;
        // check another diagonal
        if(y>0){
            while( x>=0 && y>=0){
                if(board[x][y] == 1) return false;
                x--;
                y--;
            }
        }
        
        return true;
    }
private:
    void solve(int row,  vector<vector<int>> &board,  vector<vector<int>> &ans, int n){
        // base case
        if(row == n){
            vector<int> temp;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(board[i][j] == 1) temp.push_back(j+1);
                }
            }
            ans.push_back(temp);
            return;
        }
        
        for(int col=0; col<n; col++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 1;
                solve(row+1, board, ans, n);
                board[row][col] = 0;
            }
        }
        
    }
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<vector<int>> board(n, vector<int>(n,0));
        solve(0,board,ans,n);
        return ans;
    }
};
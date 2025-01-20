class Solution {
public:
    vector<vector<string>> result;
    int N;


    bool isValid(vector<string>& board,int row,int col){
        //look forward 
      for(int i=row-1;i>=0;i--){
        if(board[i][col]=='Q'){
            return false;
        }
      }

      //look diaganol upward right
       for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
      }
       
       //for diagonal right 
       for(int i=row-1,j=col+1;i>=0&&j<N;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
      }

      //kahi se return false nhi mila the return true 
      return true;


    }
    void solve(vector<string>& board,int row){
     if(row>=N){
        result.push_back(board);
     }
     for(int col=0;col<N;col++){
        if(isValid(board,row,col)){
            board[row][col]='Q';
            solve(board,row+1);
            board[row][col]='.';
        }
     }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        N=n;
        vector<string> board(n,string(n,'.'));
        solve(board,0);
        return result;
    }
};
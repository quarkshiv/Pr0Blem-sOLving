class Solution {
public:
      bool f(int i,int j,int k,vector<vector<char>>& board,string word){
           int n = board.size();
           int m = board[0].size();
           if(k==word.size()){
            return true;
           }
            if(i<0 || j<0 || i>=n || j>=m|| board[i][j]!=word[k] || board[i][j]=='!'){
                     return false;
            }
            char c = board[i][j];
             board[i][j]='!';
            bool op1 = f(i+1,j,k+1,board,word);
            bool op2 = f(i,j+1,k+1,board,word);
            bool op3 = f(i,j-1,k+1,board,word);
            bool op4 = f(i-1,j,k+1,board,word);
            board[i][j]=c;
        return op1 || op2 || op3 || op4;
      }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
              for(int j=0;j<board[0].size();j++){
                     if(board[i][j]==word[0]){
                           if(f(i,j,0,board,word))return true;
                     }
              }
        }
        return false;
    }
};
class Solution {
public:
     bool f(int i,int j,vector<vector<char>>& board, string word,int k){
         int n = board.size();
        int m = board[0].size();
        if(k==word.size()){
            return true;
        }
        if(i<0 || j<0 || j==m || i==n || board[i][j]!=word[k] || board[i][j]=='!'){
            return false;
        }
        char c= board[i][j];
        board[i][j]='!';
        bool op1= f(i+1,j,board,word,k+1);
        bool op2= f(i-1,j,board,word,k+1);
        bool op3 = f(i,j+1,board,word,k+1);
        bool op4 = f(i,j-1,board,word,k+1);
        board[i][j]=c;
        return op1 || op2 || op3 || op4;
     }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(f(i,j,board,word,0)) return true;
                }
            }
        }
        return false;
    }
};
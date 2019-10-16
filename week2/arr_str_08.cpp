class Solution {
    int m,n,len;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
public:
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        len=word.length();
        vector<vector<bool>>visit;
        visit.resize(m, vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word.at(0)){
                    visit[i][j]=true;
                    if(dfs(i,j,1,board,word,visit))
                        return true;
                    visit[i][j]=false;
                }
            }
        }
        return false;
    }
    
    bool dfs(int &x, int &y, int indx, vector<vector<char>>& board, string &word, vector<vector<bool>>&visit){
        if(indx==len)
            return true;
        for(int i=0;i<4;i++){
            int xi=x+dx[i];
            int yi=y+dy[i];
            if(xi>=0 && xi<m && yi>=0 && yi<n){
                if(!visit[xi][yi] && board[xi][yi]==word.at(indx)){
                    visit[xi][yi]=true;
                    if(dfs(xi,yi,indx+1, board, word,visit))return true;
                    visit[xi][yi]=false;
                }
            }
        }
        return false;
    }
};

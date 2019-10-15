class Solution {
    int m,n,len;
    string str;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};  
    vector<vector<char>>bo;
    vector<vector<bool>>visit;
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        len=word.length();
        m=board.size();
        n=board[0].size();
        str=word;
        
        visit.resize(m, vector<bool>(n));
        bo.resize(m, vector<char>(n));
        copy(board.begin(), board.end(), bo.begin());
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word.at(0)){
                    visit[i][j]=true;
                    if(dfs(i,j,1))
                        return true;
                    visit[i][j]=false;
                }
            }
        }
        return false;
    }  
    
    bool dfs(int x, int y, int indx){
        if(indx==len)
            return true;
        for(int i=0;i<4;i++){
            int xi=x+dx[i];
            int yi=y+dy[i];
            if(xi>=0 && xi<m && yi>=0 && yi<n){
                if(!visit[xi][yi] && bo[xi][yi]==str.at(indx)){
                    visit[xi][yi]=true;
                    if(dfs(xi,yi,indx+1))return true;
                    visit[xi][yi]=false;
                }
            }  
        }
        return false;
    }
};

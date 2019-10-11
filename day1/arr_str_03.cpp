class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        
        int dx[8]={-1,-1,-1,0,1,1,1,0};
        int dy[8]={-1,0,1,1,1,0,-1,-1};
        
        vector<vector<int>>ans;
        
        ans.resize(m);
        for(int i=0;i<m;i++){
            ans[i].resize(n);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int live=0;
                int die=0;
                for(int k=0;k<8;k++){
                    int xpos=i+dx[k];
                    int ypos=j+dy[k];
                    
                    if(xpos<0 || xpos>=m || ypos<0 || ypos>=n)continue;
                    
                    if(board[xpos][ypos]==1)
                        live++;
                    else
                        die++;
                }
                if(board[i][j]==1){
                    if(live<2)
                        ans[i][j]=0;
                    else if(live==2 || live==3)
                        ans[i][j]=1;
                    else
                        ans[i][j]=0;
                }
                else if(live==3)
                    ans[i][j]=1;
                else
                    ans[i][j]=0;
            }
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                board[i][j]=ans[i][j];
        
    }
};

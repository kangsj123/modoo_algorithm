class Solution {
public:
    vector<vector<string>>ans;
    
    vector<vector<string>> solveNQueens(int n) {
        vector<int>pos;
        pos.resize(n);
        dfs(pos,0,n);
        return ans;
    }
    
    void dfs(vector<int>&pos, int cur_indx,int n){
        if(cur_indx==n){
            ans.push_back(toString(pos));
            return;
        }
        
        for(int i=1;i<=n;i++){
            bool possible=true;
            pos[cur_indx]=i;
            for(int j=0;j<cur_indx;j++){
                if(pos[j]==i)
                    possible=false;
                if(abs(pos[j]-i)==abs(cur_indx-j))
                    possible=false;
            }
            if(possible)
                dfs(pos,cur_indx+1,n);
        }
        
    }
    
    vector<string> toString(vector<int>&pos){
        int n=pos.size();
        vector<string>ret;
        for(int i=0;i<n;i++){
            string tmp="";
            for(int j=1;j<=n;j++){
                if(j==pos[i])
                    tmp+="Q";
                else
                    tmp+='.';
            }
            // cout<<tmp;
            ret.push_back(tmp);
        }
        return ret;
    }
    
};

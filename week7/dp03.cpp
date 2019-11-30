class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int sz=arr.size();
        int dp[sz][sz];
        int max_table[sz][sz];
        for(int i=0;i<sz;i++){
            max_table[i][i]=arr[i];
            dp[i][i]=0;
            for(int j=i+1;j<sz;j++){
                dp[i][j]=0;
                max_table[i][j]=max(max_table[i][j-1],arr[j]);
            }
        }
        
        for(int i=0;i<sz;i++){
            for(int j=i-1;j>=0;j--){
                for(int k=j;k<i;k++){
                    if(dp[j][i]==0)
                        dp[j][i]=max_table[j][k]*max_table[k+1][i]+dp[j][k]+dp[k+1][i];
                    else
                        dp[j][i]=min(dp[j][i],max_table[j][k]*max_table[k+1][i]+dp[j][k]+dp[k+1][i]);
                }
            }
        }
        return dp[0][sz-1];
    }
};

class Solution {
    // time complexity : O(NK)
    // space complexity : O(N)
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        
        int sz=A.size();
        int dp[sz]={};
        
        int max_val=0;
        for(int i=0;i<K;i++){
            max_val=max(max_val,A[i]);
            dp[i]=max_val*(i+1);   
        }
        
        for(int i=K;i<sz;i++){
            max_val=0;
            for(int j=i;j>=i-K+1;j--){
                max_val=max(max_val,A[j]);
                dp[i]=max(dp[j-1]+max_val*(i-j+1),dp[i]);
            }
        }
        
        return dp[sz-1];
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int len=0;
        int sz=nums.size();
        if(sz==0)
            return 0;
        
        int dp[sz];
        for(int i=0;i<sz;i++){
            auto pos=lower_bound(dp,dp+len,nums[i]);
            *pos=nums[i];
            if(pos==dp+len){
               len++;
            }
        }
        return len; 
    }
};

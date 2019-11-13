class Solution {
public:
    int rob(vector<int>& nums) {
        
        int sz=nums.size();
        vector<int>dp;
        dp.resize(sz);
        
        int ans=0;
        
        for(int i=0;i<sz;i++){
            dp[i]=nums[i];
            if(i-2>=0)
                dp[i]=max(dp[i-2]+nums[i],dp[i]);
            if(i-3>=0)
                dp[i]=max(dp[i-3]+nums[i],dp[i]);
            if(ans<dp[i])
                ans=dp[i];
        }
       
        return ans;
    }
};

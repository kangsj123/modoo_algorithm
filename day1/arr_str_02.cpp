class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>before;
        vector<int>after;
        vector<int>ans;
        
        before.resize(n);
        after.resize(n);
        
        for(int i=0;i<n;i++){
            before[i]=nums[i];
            if(i>0)
                before[i]*=before[i-1];
        }
        
        for(int i=n-1;i>=0;i--){
            after[i]=nums[i];
            if(i<n-1)
                after[i]*=after[i+1];
        }
        
        for(int i=0;i<n;i++){
            int num=1;
            if(i>0)
                num*=before[i-1];
            if(i<n-1)
                num*=after[i+1];
            ans.push_back(num);
        }
        return ans;
    }
};

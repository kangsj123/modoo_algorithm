class Solution {
public:
    int firstMissingPositive2(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int indx=i;
            int val=nums[indx];
            if(val==(indx+1))continue;
            
            nums[indx]=0;
            while(true){
                if(val<=0 || val>n || val==(indx+1))break;
                
                indx=val-1;
                int tmp=nums[indx];
                nums[val-1]=val;
                val=tmp;
            }
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                return i+1;
        }
        return n+1; 
    }
    
    int firstMissingPositive1(vector<int>& nums) {
        int n=nums.size();
        int frequency[n+1];
        for(int i=0;i<=n;i++)
            frequency[i]=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n)continue;
            frequency[nums[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(frequency[i]==0)
                return i;
        }
        return n+1;
            
    }
};

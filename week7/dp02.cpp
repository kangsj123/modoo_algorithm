class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int max_product=-0xfffffff, sz=nums.size();
        int positive=1,negative=1;
        
        for(int i=0;i<sz;i++){
            if(nums[i]>0){//plus
                positive*=nums[i];
                negative*=nums[i];
                max_product=max(positive,max_product);
            }
            else if(nums[i]<0){//minus
                if(negative<0){
                    int tmp=positive*nums[i];
                    positive=negative*nums[i];
                    negative=tmp;
                    max_product=max(positive,max_product);
                }
                else{
                    negative=positive*nums[i];
                    positive=1;
                    max_product=max(negative,max_product);
                }
            }
            else{//zero
                max_product=max(max_product,0);
                positive=1,negative=1;
            }
        }
        
        return max_product;
    }
};

class Solution {
public:
    
    struct s{
        vector<int>nums;
        int sum=0;
        int index=0;
    };
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int sz=candidates.size();
        vector<vector<int>>ans;
        
        vector<s>v;
        v.push_back({{},0,0});
        
        while(!v.empty()){
            vector<int>numbers=v.back().nums;
            int sum=v.back().sum;
            int ind=v.back().index;
            v.pop_back();
            
            if(sum==target){
                ans.push_back(numbers); 
                continue;
            }
            
            for(int i=ind;i<sz;i++){
                if(sum+candidates[i]<=target){
                    numbers.push_back(candidates[i]);
                    v.push_back({numbers,sum+candidates[i],i});
                    numbers.pop_back();
                }
            }
        }
        return ans;
    }
};

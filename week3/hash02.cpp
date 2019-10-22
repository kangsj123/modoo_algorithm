class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int,vector<pair<int,int>>>um;
        vector<vector<int>>ans;
        int sz=nums.size();
        
        for(int i=2;i<sz;i++){
            for(int j=0;j<i-1;j++)
                um[nums[i-1]+nums[j]].push_back(make_pair(nums[j],nums[i-1]));
            for(int k=i+1;k<sz;k++){
                int tmp=target-nums[i]-nums[k];
                for(auto l: um[tmp]){
                    vector<int> t={l.first,l.second,nums[i],nums[k]};
                    sort(t.begin(),t.end());
                    ans.push_back(t);
                }
            }
        }
        sort(ans.begin(),ans.end());//to use unique function
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};

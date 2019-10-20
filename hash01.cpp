class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int cnt, sz=nums.size();
        vector<pair<int,int>>freq;
        vector<int> ans;
        
        freq.reserve(sz);
        ans.reserve(sz);
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<sz;i+=cnt){
            int indx=i;
            while(indx+1<sz && nums[i]==nums[indx+1])
                indx++;
            cnt=indx-i+1;
            freq.push_back(make_pair(-cnt,nums[i]));
        }
        sort(freq.begin(),freq.end());
        
        for(int i=0;i<k;i++)
            ans.push_back(freq[i].second);
        
        return ans;
    }
};

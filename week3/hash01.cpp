typedef pair<int,int> pii;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int cnt, sz=nums.size();
        unordered_map<int,int>freq;
        vector<int> ans;
        vector<pii>vec;
        
        for(int i=0;i<sz;i++){
            if(freq.find(nums[i])!=freq.end())
                freq[nums[i]]=freq[nums[i]]+1;
            else
                freq[nums[i]]=1;
        }
        
        //sort unordered map by value
        copy(freq.begin(),freq.end(),back_inserter<vector<pii>>(vec));
        sort(vec.begin(),vec.end(),[](const pii& l, const pii& r){
            return l.second>r.second;
        });
        
        for(int i=0;i<k;i++)
            ans.push_back(vec[i].first);
        
        return ans;
    }
};
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

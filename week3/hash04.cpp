class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int sz=words.size();
        vector<int>dp;
        dp.resize(sz,1);
        sort(words.begin(),words.end(),[](string &a, string &b){
           return a.length()>b.length(); 
        });
        
        int longest=1;
        for(int i=0;i<sz;i++){
            int pre_sz=words[i].length();
            for(int k=0;k<pre_sz;k++){
                string removed=words[i];
                removed.erase(k,1);
                for(int j=i+1;j<sz;j++){
                    if(pre_sz>words[j].length()+1)break;
                    if(pre_sz<words[j].length()+1)continue;
                    if(removed==words[j] && dp[j]<dp[i]+1){
                        dp[j]=dp[i]+1;
                        if(longest<dp[j])
                            longest=dp[j];
                    }       
                }
            }
        }
        return longest;
    }
};

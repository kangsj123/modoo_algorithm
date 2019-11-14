class Solution {
public:
    int countSubstrings(string s) {
        
        int len=s.length();
        int ans=len;
        
        for(int i=0;i<len;i++){
            
            int left=i-1;
            int right=i+1;
            
            while(left>=0 && right<len && s[left]==s[right]){
                left--;
                right++;
                ans++;
            }
            
            left=i;
            right=i+1;
            
            while(left>=0 && right<len && s[left]==s[right]){
                left--;
                right++;
                ans++;
            }
        }
        return ans;  
    }
};
